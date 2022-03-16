#include "Model.h"

void Model::LoadModel() {
	//for each(const auto& subMeshList : modelLoader.) {

	//}
}

Model::Model(const std::string& objPath, const std::string& matPath, Shader* shaderProgram) {
}

Model::~Model() {
}

void Model::AddMesh(Mesh* mesh) {
}

void Model::OnDestroy() {
}

int Model::CreateInstance(glm::vec3 position, float angle, glm::vec3 rotation, glm::vec3 scale) {
	return 0;
}

glm::mat4 Model::GetTransform(int index) const {
	return glm::mat4();
}

std::vector<glm::mat4> Model::GetInstances() const {
	return std::vector<glm::mat4>();
}

void Model::Render(Camera* camera) {
}
