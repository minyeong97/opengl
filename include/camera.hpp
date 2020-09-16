#ifndef __CAMERA_H__
#define __CAMERA_H__


#include "glm/glm.hpp"
enum KEY {
	CAMERA_INTERNAL_W,
	CAMERA_INTERNAL_A,
	CAMERA_INTERNAL_S,
	CAMERA_INTERNAL_D,
	CAMERA_INTERNAL_I,
	CAMERA_INTERNAL_J,
	CAMERA_INTERNAL_K,
	CAMERA_INTERNAL_L,
};

class Camera {
private:
	// initial setings
	int width, height;
	float close, far;
	float mas, las; // move around sensitivity, look around sensitivity
	glm::vec3 worldup;

	// initialized only once internally
	glm::mat4 projection;

	// updates constantly externally
	glm::vec3 location;
	float pitch, yaw;	
	
	// updated constantly internally
	glm::vec3 front;
	glm::vec3 right;
	glm::vec3 up;
	glm::vec3 worldfront;

public:
	Camera( int width_p = 800, 
			int height_p = 600, 
			float close_p = 0.1f, 
			float far_p = 100.0f, 
			float mas_p = 8.0f,
			float las_p = 0.05f,
			glm::vec3 worldup_p = glm::vec3(0.0f, 1.0f, 0.0f),
			glm::vec3 location_p = glm::vec3(0.0f, 1.0f, 3.0f), 
			float pitch_p = 0.0f,
			float yaw_p = 0.0f);

	glm::mat4 GetProjection();
	glm::mat4 GetView();

	void UpdateCameraLocation(enum KEY key, float delta_time);
	void ProcessMouse(float yaw_offset, float pitch_offset);
	
private:
	void printVector(glm::vec3 vec);
	void UpdateCameraVector();
};


#endif
