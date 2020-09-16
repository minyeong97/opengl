#ifndef __MODEL_H__
#define __MODEL_H__

#include <iostream>

#include "gl3w/gl3w.h"
#include "glfw/glfw3.h"

class Model {
private:
	unsigned int vao;	
	unsigned int element_num;
	int program_id;
public:
	// constructor
	Model(const char* vertex_shader_source, const char* fragment_shader_source, float* vertices, int size_of_vertices, unsigned int* indices, int size_of_indices) {

		element_num = size_of_indices/4;
		std::cout << "Now element_num is " << element_num << std::endl;

		std::cout << "vs source::" << std::endl;
		std::cout << *vertex_shader_source << std::endl;

		std::cout << "fs source::" << std::endl;
		std::cout << *fragment_shader_source << std::endl;

		std::cout << "vertices::" << std::endl;
		for (int i = 0; i < size_of_vertices/4; i++)
			std::cout << *(vertices + i) << " ";
		std::cout << std::endl;
		
		std::cout << "indices::" << std::endl;
		for (int i = 0; i < size_of_indices/4; i++)
			std::cout << *(indices + i) << " ";
		std::cout << std::endl;

		int vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_source, NULL);
		glCompileShader(vertex_shader);

		int success;
		char infolog[512];
		glGetShaderiv(vertex_shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {
			glGetShaderInfoLog(vertex_shader, 512, NULL, infolog);
			std::cout << "ERROR::SHADER::VERTEX\n" << infolog << std::endl;
		}


		int fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_source, NULL);
		glCompileShader(fragment_shader);

		glGetShaderiv(fragment_shader, GL_COMPILE_STATUS, &success);
		if (success == GL_FALSE) {
			glGetShaderInfoLog(fragment_shader, 512, NULL, infolog);
			std::cout << "ERROR::SHADER::FRAGMENT\n" << infolog << std::endl;
		}

		
		program_id = glCreateProgram();
		std::cout << "creating program: " << program_id << std::endl;
		glAttachShader(program_id, vertex_shader);
		glAttachShader(program_id, fragment_shader);
		glLinkProgram(program_id);

		glGetProgramiv(program_id, GL_LINK_STATUS, &success);
		if (success == GL_FALSE) {
			glGetProgramInfoLog(program_id, 512, NULL, infolog);
			std::cout << "ERROR::PROGRAM\n" << infolog << std::endl;
		}

		glDeleteShader(vertex_shader);
		glDeleteShader(fragment_shader);

		unsigned int vbo, ebo;

		glGenVertexArrays(1, &vao);
		glGenBuffers(1, &vbo);
		glGenBuffers(1, &ebo);

		std::cout << "gen vao: " << vao << " gen vbo&ebo: " << vbo << " " << ebo << std::endl;

		glBindVertexArray(vao);

		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, size_of_vertices, vertices, GL_STATIC_DRAW);

		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ebo);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, size_of_indices, indices, GL_STATIC_DRAW);

		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GL_FLOAT), (void*)0);
		glEnableVertexAttribArray(0);

		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glBindVertexArray(0);
	}

	void UseModelProgram() {
		//std::cout << "use program: " << program_id << std::endl;
		glUseProgram(program_id);
	}

	int GetProgramID() {
		return program_id;
	}
	
	void Draw() {
		//std::cout << "drawing vao: " << vao << std::endl;
		glBindVertexArray(vao);
		glDrawElements(GL_TRIANGLES, element_num, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
	}
private:
};

#endif
