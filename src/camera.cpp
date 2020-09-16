#include <iostream>
#include "camera.hpp"

#include "glm/gtc/type_ptr.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

Camera::Camera( int width_p, 
		int height_p, 
		float close_p, 
		float far_p, 
		float mas_p,
		float las_p,
		glm::vec3 worldup_p,
		glm::vec3 location_p, 
		float pitch_p,
		float yaw_p)
{
	width = width_p;
	height = height_p; 
	close = close_p; 
	far = far_p; 
	mas = mas_p;
	las = las_p;
	worldup = worldup_p;
	location = location_p; 
	pitch = pitch_p;
	yaw = yaw_p;

	std::cout << "perspective: " << width << ", " << height << ", " << close << ", " << far << std::endl;
	projection =  glm::perspective(glm::radians(30.0f), (float)width / (float)height, close, far);
	UpdateCameraVector();	
}

glm::mat4 Camera::GetProjection() {
	return projection;
	//return glm::mat4(1.0f);
}

glm::mat4 Camera::GetView() {
	return glm::lookAt(location, location + front, up);
	//return glm::mat4(1.0f);
}

void Camera::UpdateCameraLocation(enum KEY key, float delta_time) {
	if (key == CAMERA_INTERNAL_W )
		location += worldfront * delta_time * mas;
	if (key == CAMERA_INTERNAL_A )
		location -= right * delta_time * mas;
	if (key == CAMERA_INTERNAL_S )
		location -= worldfront * delta_time * mas;
	if (key == CAMERA_INTERNAL_D )
		location += right * delta_time * mas;
		
	if (key == CAMERA_INTERNAL_I )
		pitch += delta_time * las;
	if (key == CAMERA_INTERNAL_J )
		yaw += delta_time * las;
	if (key == CAMERA_INTERNAL_K )
		pitch -= delta_time * las;
	if (key == CAMERA_INTERNAL_L )
		yaw -= delta_time * las;

	UpdateCameraVector();
}

void Camera::ProcessMouse(float yaw_offset, float pitch_offset) {
	yaw += yaw_offset * las;
	pitch += pitch_offset * las;

	if (pitch > 89.0f) pitch = 89.0f;
	if (pitch < -89.0f) pitch = -89.0f;

	UpdateCameraVector();
}


void Camera::printVector(glm::vec3 vec) {
	std::cout << vec.x << ", " << vec.y << ", " << vec.z << " | ";
}

void Camera::UpdateCameraVector() {
	front.z = -cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	front.y = sin(glm::radians(pitch));
	front.x = -cos(glm::radians(pitch)) * sin(glm::radians(yaw));
	front = glm::normalize(front);

	right = glm::normalize(glm::cross(front, worldup));
	up = glm::normalize(glm::cross(right, front));
	worldfront = glm::normalize(glm::cross(worldup, right));

	//printVector(front);
	//printVector(location);
	//printVector(up);
	//printVector(right);
	//std::cout << std::endl;
}
