#pragma once
#include <glm/glm.hpp>
#include <GL/glew.h>
#include <vector>
#include <iostream>
#include "prozor.h"

class Vertex
{
public:

	// *\ Constructor
	// *\param void
	Vertex(void) {}

	// *\brief Ucitava tacke.
	//			Prosledi se niz, i generisu se x,y,z tacke za vrednost tog niza
	// *\param std::vector<Vertex> tacke
	// *\param unsigned int brPozicija velicina niza
	// *\param std::vector<int> niz 
	// *\return void
	void static UcitajTacke(std::vector<Vertex>& tacke, unsigned int brPozicija,
					std::vector<int>& niz)
	{
		Vertex pozicija;
		for(unsigned int i=0; i<brPozicija; i++)
		{

			pozicija.x = 0.1f-(i*0.4f); 
			pozicija.y = 0.1f;
			pozicija.z = 0.0f;
			tacke.push_back(pozicija);

			pozicija.x = 0.1f-(i*0.4f);
			pozicija.y = (float)3*niz[i]/10;
			pozicija.z = 0.0f;
			tacke.push_back(pozicija);

			pozicija.x = 0.5f-(i*0.4f);
			pozicija.y = (float)3*niz[i]/10;
			pozicija.z = 0.0f;
			tacke.push_back(pozicija);

			pozicija.x = 0.5f-(i*0.4f);
			pozicija.y = 0.1f;
			pozicija.z = 0.0f;
			tacke.push_back(pozicija);
		}
	} 

protected:
private:
	GLfloat x, y, z;	// tacke
};

class Mesh
{
public:
	// *\ Constructor
	// *\brief Generise Vertex bafer i salje podatke u bafer
	// *\param std::vector<Vertex> tacke,
	// *\param unsigned int brTacaka
	Mesh(const std::vector<Vertex>& tacke, unsigned int brTacaka);

	// *\brief Crta OpenGL model na na ekranu (GL_QUAD)
	// *\param void
	// *\return void
	void Draw(void);

	// *\brief Ponovno ucitavanje tacaka, azuriranje bafera i iscrtavanje
	// *\param std::vector<int> arr
	// *\return void
	void Redraw(std::vector<int>& arr);

	// *\brief Azuriranje bafera sa novim tackama
	// *\param std::vector<Vertex> tacke
	// *\param unsigned int brTacaka
	// *\return void
	void Update(const std::vector<Vertex>& tacke, unsigned int brTacaka);

	// *\ Destructor
	// *\param void
	virtual ~Mesh(void);

protected:
private:
	// Broj Vertex bafera
	// Trenutno samo jedan, za poziciju
	enum { POZICIJA_VB, BROJ_VB };

	GLuint m_vertexArrayObject;				// Vertex Objekat
	GLuint m_vertexArrayBuffers[BROJ_VB];	// Vertex Baferi
	unsigned int m_brojacCrtanja;			
};