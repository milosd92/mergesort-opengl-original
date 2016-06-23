#include "cameraHandler.h"

const unsigned int size10 = 10;
const unsigned int size20 = 20;
const unsigned int size50 = 50;
const unsigned int size100 = 100;
const unsigned int size200 = 200;
const unsigned int size500 = 500;
const unsigned int size1000 = 1000;

glm::vec3 CameraHandler::getPos(unsigned int modelSize)
{
	switch(modelSize){
	case size10:
		return glm::vec3(-1.5,   1.5,   -3);
		break;
	case size20:
		return glm::vec3(-3.5,   3.0,   -3);
		break;
	case size50:
		return glm::vec3(-9.5,  7.0,   -3);
		break;
	case size100:
		return glm::vec3(-20.0,  15.0,  -3);
		break;
	case size200:
		return glm::vec3(-40.0,  30.0,  -3);
		break;
	case size500:
		return glm::vec3(-100.0, 70.0,  -3);
		break;
	case size1000:
		return glm::vec3(-200.0, 140.0, -3);
		break;
	default:
		return glm::vec3(-1.5,   1.5,   -3);
		break;
	}
}

float CameraHandler::getFov(unsigned int modelSize)
{
	switch(modelSize){
	case size10:
		return 70.0f;
		break;
	case size20:
		return 100.0f;
		break;
	case size50:
		return 502.0f;
		break;
	case size100:
		return 520.0f;
		break;
	case size200:
		return 530.0f;
		break;
	case size500:
		return 536.0f;
		break;
	case size1000:
		return 538.0f;
		break;
	default:
		return 70.0f;
		break;
	}
}

CameraHandler::~CameraHandler(void) {}