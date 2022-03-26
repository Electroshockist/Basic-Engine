#pragma once
#include <string>
#include <vector>

#include <GLM/glm.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "../GameObject.h"
#include "AssetImporter.h"

class Mesh;
class Shader;
class Camera;
class Model : public GameObject {
	std::vector<Mesh*> meshes;
	Shader* shaderProgram;
	std::vector<glm::mat4> modelInstances;
	AssetImporter* assetImporter;

	void LoadModel();

public:
	Model(const std::string& objPath, const std::string& matPath, Shader* shaderProgram);
	~Model();
	void AddMesh(Mesh* mesh);
	void OnDestroy();
	int CreateInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale);
	glm::mat4 GetTransform(int index) const;
	std::vector<glm::mat4> GetInstances() const;

	void Render(Camera* camera);
};

