#include "AssetImporter.h"

#include <iostream>

#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>

void AssetImporter::PostProcessing() {}

void AssetImporter::LoadMaterial(const std::string& fileName) {}

void AssetImporter::LoadMaterialLibrary(const std::string& fileName) {}

AssetImporter::AssetImporter() {

}

AssetImporter::~AssetImporter() {
	vertices.clear();
	normals.clear();
	textureCoords.clear();
	indices.clear();
	normalIndices.clear();
	textureIndices.clear();
	meshVertices.clear();
	meshes.clear();
}

bool AssetImporter::LoadModel(const std::string& fileName) {
	bool err = false;

	const aiScene* scene = aiImportFile("../skull.obj", aiProcessPreset_TargetRealtime_MaxQuality);

	std::cout << "Meshes " << scene->mMeshes[0]->mNumVertices << std::endl;

	scene->mNumMeshes;

	delete scene;
	scene = nullptr;

	return !err;
}

bool AssetImporter::LoadModel(const std::string& fileName, const std::string& matName) {
	return false;
}

int AssetImporter::LoadTexture(const std::string& fileName) {
	return 0;
}

std::vector<Vertex> AssetImporter::GetVerts() {
	return meshVertices;
}

std::vector<int> AssetImporter::GetIndices() {
	return indices;
}

std::vector<SubMesh> AssetImporter::GetSubMeshes() {
	return meshes;
}
