#pragma once
#include <string>
#include <map>

#include <GLEW/glew.h>
#include <GLM/glm.hpp>

class Shader {
	friend class ShaderManager;

	Shader();
	~Shader();

	inline const GLuint& GetID() const {
		return ID;
	}

	Shader& Use();

	// Utility functions
	///floats
	///glUniform1f
	void SetUniformData(const GLchar* name, GLfloat value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec2& value, bool performUniformCheck = true, bool useShader = false);
	///glUinform3f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec3& value, bool performUniformCheck = true, bool useShader = false);
	///glUniform4f
	void SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const glm::vec4& value, bool performUniformCheck = true, bool useShader = false);

	///ints
	///glUniform1i
	void SetUniformData(const GLchar* name, GLint value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2i
	void SetUniformData(const GLchar* name, GLint x, GLint y, bool performUniformCheck = true, bool useShader = false);
	///glUniform3i
	void SetUniformData(const GLchar* name, GLint x, GLint y, GLint z, bool performUniformCheck = true, bool useShader = false);
	///glUniform4i
	void SetUniformData(const GLchar* name, GLint x, GLint y, GLint z, GLint w, bool performUniformCheck = true, bool useShader = false);

	///unsigned ints
	///glUniform1ui
	void SetUniformData(const GLchar* name, GLuint value, bool performUniformCheck = true, bool useShader = false);
	///glUniform2ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, bool performUniformCheck = true, bool useShader = false);
	///glUniform3ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, GLuint z, bool performUniformCheck = true, bool useShader = false);
	///glUniform4ui
	void SetUniformData(const GLchar* name, GLuint x, GLuint y, GLuint z, GLuint w, bool performUniformCheck = true, bool useShader = false);

	void SetUniformData(const GLchar* name, const GLfloat* value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const GLint* value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);
	void SetUniformData(const GLchar* name, const GLuint* value, const GLenum type, int vectorSize = 1, GLsizei count = 1, bool performUniformCheck = true, bool useShader = false);

	void SetUniformData(const GLchar* name, const glm::mat4& matrix, bool performUniformCheck = true, bool useShader = false);

	void BindTexture(const GLchar* name, GLenum textureType, GLenum textureNum, GLuint data);
private:
	// ID
	GLuint ID;
	//Name
	std::string name;

	void CreateUniform(const GLchar* name);

	static GLuint GetTextureNum(GLenum textureNum);

	bool ItemExists(std::string name) const;

	std::map<std::string, GLuint> uniforms;
};

