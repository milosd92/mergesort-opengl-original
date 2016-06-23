#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>

// Pomocna klasa
class CameraHandler
{
public:

	// *\ Constructor
	// *\param void
	CameraHandler(void) {};

	// *\brief Vraca poziciju prema velicini model-a
	// *\param unsigned int modelSize
	// *\return glm::vec3 pos
	glm::vec3 getPos(unsigned int modelSize);

	// *\brief Vraca FOV(Field-of-View) vidno polje
	//			prema velicini model-a
	// *\param unsigned int modelSize
	// *\return float fov
	float getFov(unsigned int modelSize);

	// *\ Destructor
	// *\param void
	virtual ~CameraHandler(void);

protected:
private:
	unsigned int modelSize;		// velicina model-a
};
