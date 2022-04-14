#pragma once
#include <string>
#include <vector>

#include <GLM/glm.hpp>
#include <assimp/scene.h>

#include "../GameObject.h"
#include "../Util/Event.h"

class Mesh;
class Shader;
class Camera;
class Model : public GameObject {
	std::vector<Mesh*> meshes;
	Shader* shaderProgram;
	std::vector<glm::mat4> modelInstances;

	std::vector < Camera*> associatedCameras;

		void LoadModel();
	void LoadTextures(aiTexture** textures, unsigned int size);

	Model();
	Model(const std::string& objPath, const std::string& matPath, Shader* shaderProgram);

	~Model();

public:
	friend Camera;

	void AddMesh(Mesh* mesh);
	void OnDestroy();
	int CreateInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 GetTransform(int index) const;
	std::vector<glm::mat4> GetInstances() const;

	void Render(Camera* camera);
};