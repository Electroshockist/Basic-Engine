#include "Shader.h"

#include <iostream>

#define UNIFORMCHECKS(name, useShader)	if(useShader) this->Use(); if(!ItemExists(name)){printf("The uniform %s does not exist in the shader \"%s\".\n%s %i", std::string(name).c_str(),  this->name.c_str(), __FILE__, __LINE__);return;}

Shader& Shader::Use() {
	glUseProgram(this->ID);
	return *this;
}

void Shader::SetUniformData(const GLchar* name, GLfloat value, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);

	glUniform1f(uniforms.at(name), value);
}

void Shader::SetUniformData(const GLchar* name, GLint value, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform1i(uniforms.at(name), value);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2f(uniforms.at(name), x, y);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec2& value, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform2f(uniforms.at(name), value.x, value.y);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3f(uniforms.at(name), x, y, z);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec3& value, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform3f(uniforms.at(name), value.x, value.y, value.z);
}

void Shader::SetUniformData(const GLchar* name, GLfloat x, GLfloat y, GLfloat z, GLfloat w, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4f(uniforms.at(name), x, y, z, w);
}

void Shader::SetUniformData(const GLchar* name, const glm::vec4& value, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniform4f(uniforms.at(name), value.x, value.y, value.z, value.w);
}

void Shader::SetUniformData(const GLchar* name, const glm::mat4& matrix, bool performUniformCheck, bool useShader) {
	if(performUniformCheck) UNIFORMCHECKS(name, useShader);
	glUniformMatrix4fv(uniforms.at(name), 1, GL_FALSE, glm::value_ptr(matrix));
}

void Shader::BindTexture(const GLchar* name, GLenum textureType, GLenum textureNum, GLuint data) {
	SetUniformData(name, (int)GetTextureNum(textureNum));
	glActiveTexture(textureNum);

	glBindTexture(textureType, data);
}

void Shader::CreateUniform(const GLchar* name) {
	//store the name and location of the uniform
	uniforms[name] = glGetUniformLocation(ID, name);
}

bool Shader::ItemExists(std::string name) const {
	return uniforms.find(name) != uniforms.end();
}

GLuint Shader::GetTextureNum(GLenum textureNum) {
	//glenums are ordered contiguously, so treat GL_TEXTURE0 as 0
	return textureNum - GL_TEXTURE0;
}

