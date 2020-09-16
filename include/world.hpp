#ifndef __WORLD_H__
#define __WORLD_H__

#include <vector>
#include <string>

#include "model.hpp"
#include "camera.hpp"

class World {
private:
	std::vector<Model> models;
	//vector<glm::mat4> transformations;
	GLFWwindow* window;

public:
	Camera camera;

	World(int width, int height);

	void Draw();

	GLFWwindow* GetWindow();
	void ProcessKey(float);

private:
	void SetupGLFW(int width, int height);
	void LoadModel();
	void LoadShader(std::string &vertex_shader_code, std::string &fragment_shader_code);
};


#endif
