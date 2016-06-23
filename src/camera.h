#pragma once
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include "cameraHandler.h"
 
class Camera : public CameraHandler
{
public:

	// *\ Constructor
	// *\brief Perspektiva kamere se menja prema modelu (npr. velicini niza)
	// *\param unsigned int modelSize
	// *\param float aspect
	// *\param float zNear
	// *\param float zFar
	Camera(unsigned int modelSize, float aspect, float zNear, float zFar)
	{
		CameraHandler handler;
		fov = handler.getFov(modelSize);
		m_perspective = glm::perspective(fov, aspect, zNear, zFar);
		m_position = handler.getPos(modelSize);
		m_forward = glm::vec3(0,0,1);   // kamera gleda po z-osi, pravo napred
        m_up = glm::vec3(0,1,0);        // kamera gleda po y-osi, gore
	}
 
	// *\brief Projekcija kamere
	// *\param void
	// *\return glm::mat4
    inline glm::mat4 GetViewProjection(void) const
    {
        /// rotacija kamere
        return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
    }
 
protected:
private:
    glm::mat4 m_perspective;    // matricna perspektiva
    glm::vec3 m_position;       // pozicija kamere
 
    /// rotacija, predstavljena sa dva vektora
    glm::vec3 m_forward;
    glm::vec3 m_up;

	float fov;
};