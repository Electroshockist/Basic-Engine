#include "AssetImporter.h"

#include <iostream>

#include <assimp/scene.h>
#include <assimp/cimport.h>
#include <assimp/postprocess.h>

AssetImporter::AssetImporter() {
	const aiScene* scene = aiImportFile("../skull.obj", aiProcessPreset_TargetRealtime_MaxQuality);

	std::cout << "Meshes " << scene->mMeshes[0]->mNumVertices << std::endl;
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

std::vector<Vertex> AssetImporter::GetVerts() {
	return meshVertices;
}

std::vector<int> AssetImporter::GetIndices() {
	return indices;
}

std::vector<SubMesh> AssetImporter::GetSubMeshes() {
	return meshes;
}
