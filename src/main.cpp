#include <iostream>
///*
#include "gl3w/gl3w.h"
#include "glfw/glfw3.h"
#include "glm/glm.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "world.hpp"

float lastTime = 0.0f;
float deltaTime = 0.0f;

float last_x, last_y;
bool first_time = true;

World world(1200, 1200);

void ProcessMouse(GLFWwindow *window, double xpos, double ypos) {
	if (first_time) {
		last_x = xpos;
		last_y = ypos;
		first_time = false;
	}

	float xoffset = -(xpos - last_x);
	float yoffset = -(ypos - last_y);

	last_x = xpos;
	last_y = ypos;

	world.camera.ProcessMouse(xoffset, yoffset);
}


int main(void) {

	glfwSetCursorPosCallback(world.GetWindow(), ProcessMouse);

	while (!glfwWindowShouldClose(world.GetWindow())) {

		float currentTime = glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		world.ProcessKey(deltaTime);

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		world.Draw();

		glfwSwapBuffers(world.GetWindow());
		glfwPollEvents();

	}

	return 0;
}

