#include "world.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>

#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#define TINYOBJLOADER_IMPLEMENTATION // define this in only *one* .cc
#include "objl/tiny_obj_loader.h"

World::World(int width, int height) {
	//init glfw
	SetupGLFW(width, height);

	// load model
	LoadModel();

	//read from file and update models and transformations
	camera = Camera(width, height);
}

void World::SetupGLFW(int width, int height) {
	if (!glfwInit())
		std::cout << "glfw init failed" << std::endl;

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(width, height, "Hello world", NULL, NULL);
	if (!window) {
		std::cout << "glfw window creation failed" << std::endl;
		glfwTerminate();
	} 
	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

	if (gl3wInit()) {
		std::cout << "gl3w init failed" << std::endl;
		glfwTerminate();
	}
}

void World::LoadShader(std::string &vertex_shader_code, std::string &fragment_shader_code) {

	std::ifstream vertex_shader_is;
	vertex_shader_is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		vertex_shader_is.open("./models/vertex");
		std::stringstream vertex_shader_stream;
		vertex_shader_stream << vertex_shader_is.rdbuf();
		vertex_shader_is.close();
		vertex_shader_code = vertex_shader_stream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cout << "ERROR::SHADER::FILE_NOT_READ" << std::endl;
	}

	std::ifstream fragment_shader_is;
	fragment_shader_is.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	try {
		fragment_shader_is.open("./models/fragment");
		std::stringstream fragment_shader_stream;
		fragment_shader_stream << fragment_shader_is.rdbuf();
		fragment_shader_is.close();
		fragment_shader_code = fragment_shader_stream.str();
	}
	catch (std::ifstream::failure& e) {
		std::cout << "ERROR::SHADER::FILE_NOT_READ" << std::endl;
	}
}


void World::LoadModel(){

	float* vertices;
	unsigned int* indices;
	int vertices_num;
	int indices_num;

	std::string vertex_shader_code;
	std::string fragment_shader_code;



	std::string inputfile = "./models/model.obj";
	tinyobj::attrib_t attrib;
	std::vector<tinyobj::shape_t> shapes;
	std::vector<tinyobj::material_t> materials;

	std::string warn;
	std::string err;

	bool ret = tinyobj::LoadObj(&attrib, &shapes, &materials, &warn, &err, inputfile.c_str());

	if (!warn.empty()) {
	  std::cout << warn << std::endl;
	}

	if (!err.empty()) {
	  std::cerr << err << std::endl;
	}

	if (!ret) {
	  exit(1);
	}


	if (!ret) { std::cout << "."; exit(EXIT_FAILURE); }
	else {

		vertices_num = attrib.vertices.size();
		vertices = new float[vertices_num];

		for (int i = 0; i < vertices_num; i++) {
			vertices[i] = attrib.vertices[i];
		}
		
		indices_num = shapes[0].mesh.indices.size(); 
		indices = new unsigned int[indices_num];

		for (int i = 0; i < indices_num; i++) {
			indices[i] = shapes[0].mesh.indices[i].vertex_index;
		}
	}


	LoadShader(vertex_shader_code, fragment_shader_code);
	models.push_back(Model(vertex_shader_code.c_str(), fragment_shader_code.c_str(), vertices, vertices_num*4, indices, indices_num*4));

	delete [] vertices;
	delete [] indices;
}
	
void World::Draw() {
	//for (auto i = 0; i < num_of_models; i++) {
	//std::cout << "debug"; 
		models[0].UseModelProgram();

		int program_id = models[0].GetProgramID();
		
		unsigned int loc = glGetUniformLocation(program_id, "projection");
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(camera.GetProjection()));
		//glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

		loc = glGetUniformLocation(program_id, "view");
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(camera.GetView()));
		//glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

		loc = glGetUniformLocation(program_id, "model");
		glm::mat4 model(1.0f);
		model = glm::scale(model, glm::vec3(0.5f, 0.5f, 0.5f));
		glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(model));
		
		//glUniformMatrix4fv(loc, 1, GL_FALSE, glm::value_ptr(glm::mat4(1.0f)));

		models[0].Draw();
	//}
}

void World::ProcessKey(float delta_time) {
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
		glfwSetWindowShouldClose(window, true);

	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_W, delta_time);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_A, delta_time);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_S, delta_time);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_D, delta_time);

	if (glfwGetKey(window, GLFW_KEY_I) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_I, delta_time);
	if (glfwGetKey(window, GLFW_KEY_J) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_J, delta_time);
	if (glfwGetKey(window, GLFW_KEY_K) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_K, delta_time);
	if (glfwGetKey(window, GLFW_KEY_L) == GLFW_PRESS)
		camera.UpdateCameraLocation(CAMERA_INTERNAL_L, delta_time);
		
	if (glfwGetKey(window, GLFW_KEY_1) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
	if (glfwGetKey(window, GLFW_KEY_2) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	if (glfwGetKey(window, GLFW_KEY_3) == GLFW_PRESS)
		glPolygonMode(GL_FRONT_AND_BACK, GL_POINT);
}


GLFWwindow* World::GetWindow() { return window; }
