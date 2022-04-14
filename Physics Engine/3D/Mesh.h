#pragma once
#include <map>
#include <vector>

#include <GLM/glm.hpp>
#include <GLEW/glew.h>

#include "Shaders/Shader.h"
#include "Shaders/UniformParameter.h"
#include "Camera/Camera.h"

struct Texture {
	unsigned int id;
	std::string type;
};

struct Vertex {
	glm::vec3 position;
	glm::vec3 normal;
	glm::vec2 texCoords;
	glm::vec3 colour;
};

struct SubMesh {
	std::vector<Vertex> vertices;
	std::vector<unsigned int> vertexIndices;
};

class Mesh {
	void GenerateBuffers(GLenum usage);
	GLuint VAO, VBO;
	Shader* shaderProgram;
	SubMesh subMesh;
public:
	std::vector<UniformParameter> uniforms;

	Mesh(SubMesh submesh, Shader* shaderProgram, GLenum shaderUsage = GL_STATIC_DRAW);
	~Mesh();

	void Render(Camera* camera, std::vector<glm::mat4>& instances_);
	void Destroy();
};

