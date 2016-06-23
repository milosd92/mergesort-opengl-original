#pragma once
#include <string>
#include <GL/glew.h>
#include "camera.h"

class Shader
{
public:
	// *\ Constructor
	// *\brief Kreira shader program, linkuje, kompajluje, proverava greske
	// *\param nazivFajla Naziv fajla gde se nalazi GLSL kod za kreiranje Shader-a
	Shader(const std::string& nazivFajla);

	// *\brief Vezuje shader program
	// *\return void
	void Spoj();

	// *\brief Aruzira objekat, skaliranje, rotacija, transformacija, kamera
	// *\param camera
	// *\return void
	void Azuriraj(const Camera& camera);

	// *\ Destructor
	// *\brief Brise shader program
	// *\param void
	virtual ~Shader(void);
protected:
private:

	static const unsigned int BROJ_SHADERA = 2;

	enum { TRANSFORM_U, NUM_UNIFORMS };

	GLuint m_program;
	GLuint m_shaders[BROJ_SHADERA];
	GLuint m_uniforms[NUM_UNIFORMS];
};