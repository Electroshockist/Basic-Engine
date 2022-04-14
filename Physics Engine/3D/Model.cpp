#include "Model.h"

#include <iostream>

#include <assimp/cimport.h>
#include <assimp/postprocess.h>

#include "Camera/Camera.h"
#include "Shaders/Shader.h"
#include "../Util/Utils.h"

void Model::LoadModel() {
	//for each(const auto& subMeshList : modelLoader.) {

	//}
}

void Model::LoadTextures(aiTexture** textures, unsigned int size) {
	for(size_t i = 0; i < size; i++) {
		std::cout << textures[i]->mFilename.C_Str() << std::endl;
	}
}

Model::Model() : shaderProgram(new Shader()) {
}

Model::Model(const std::string& objPath, const std::string& matPath, Shader* shaderProgram) : shaderProgram(shaderProgram) {
	const aiScene* scene = aiImportFile(objPath.c_str(), aiProcessPreset_TargetRealtime_MaxQuality);

	if(scene->HasMaterials()) {
		for(size_t i = 0; i < scene->mNumMaterials; i++) {
			//scene->mMaterials[0]->GetTexture()
		}
	}

	if(scene->HasTextures()) {
		LoadTextures(scene->mTextures, scene->mNumTextures);
	}

	if(scene->HasCameras()) {
		for(size_t i = 0; i < scene->mNumCameras; i++) {
			const aiCamera* cam = scene->mCameras[i];
			Camera::LoadCamera(glm::vec3(cam->mPosition.x, cam->mPosition.y, cam->mPosition.z), cam->mHorizontalFOV, cam->mClipPlaneNear, cam->mClipPlaneFar)->AddModel(this);			
		}
	}

	if(scene->HasLights()) {

	}
}

Model::~Model() {
	Model* model = this;
	onDeleted.Invoke(model);
	OnDestroy();
}

void Model::AddMesh(Mesh* mesh) {
	meshes.push_back(mesh);
}

void Model::OnDestroy() {
	if(meshes.size() > 0) {
		for(auto m : meshes) {
			delete m;
			m = nullptr;
		}
		meshes.clear();
	}
	modelInstances.clear();
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
