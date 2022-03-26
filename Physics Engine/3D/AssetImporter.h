#pragma once

#include "Mesh.h"
class Material {};

class AssetImporter {
	std::vector<glm::vec3> vertices, normals;
	std::vector<glm::vec2> textureCoords;
	std::vector<int> indices, normalIndices, textureIndices;
	std::vector<Vertex> meshVertices;
	std::vector<SubMesh> meshes;

	Material material;

	void PostProcessing();
	void LoadMaterial(const std::string& fileName);
	void LoadMaterialLibrary(const std::string& fileName);

public:
	AssetImporter();
	~AssetImporter();
	bool LoadModel(const std::string& fileName);
	bool LoadModel(const std::string& fileName, const std::string& matName);
	int LoadTexture(const std::string& fileName);
	std::vector<Vertex> GetVerts();
	std::vector<int> GetIndices();
	std::vector<SubMesh> GetSubMeshes();
};

