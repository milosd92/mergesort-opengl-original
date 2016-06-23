#include "prozor.h"
#include <GL/glew.h>
#include <iostream>


Prozor::Prozor(int sirina, int visina, const std::string& naziv)
{
	SDL_Init(SDL_INIT_EVERYTHING);		// Inicijalizacija SDL-a

	// Postavka atributa za OpenGL pre pravljenja prozora
	SDL_GL_SetAttribute(SDL_GL_RED_SIZE, 8);		// 2^8 nijansi crvene boje (color-depth)
	SDL_GL_SetAttribute(SDL_GL_GREEN_SIZE, 8);		// 2^8 nijansi zelene boje (color-depth)
	SDL_GL_SetAttribute(SDL_GL_BLUE_SIZE, 8);		// 2^8 nijansi plave boje (color-depth)
	SDL_GL_SetAttribute(SDL_GL_ALPHA_SIZE, 8);		// 2^8 nijansi transparentnosti (alpha)
	SDL_GL_SetAttribute(SDL_GL_BUFFER_SIZE, 32);	// 2^32 boja (8+8+8+8)
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);	// bafer za iscrtavanje u pozadini

	// Kreiranje prozora
	m_prozor = SDL_CreateWindow(naziv.c_str(), SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, sirina, visina, SDL_WINDOW_OPENGL);

	// Kreiranje kontekst-a
	m_GLContext = SDL_GL_CreateContext(m_prozor);

	// Inicijalizacija GLEW-a
	GLenum status = glewInit();
	if(status != GLEW_OK)
		std::cerr << "Greska tokom inicijalizacije GLEW-a" << std::endl;

	// Nije zatvoren
	m_jeZatvoren = false;

}

void Prozor::Ocisti(float r, float g, float b, float a)
{
	glClearColor(r,g,b,a);			// Brise RGBA boje
	glClear(GL_COLOR_BUFFER_BIT);	// Praznjenje bafera za boje
}

void Prozor::Osvezi()
{
	// Zamena prozora
	SDL_GL_SwapWindow(m_prozor);
	SDL_GL_SetSwapInterval(1);		// V-sync on

	// Unistavanje prozora, iskljucivanje
	SDL_Event dogadjaj;
	while(SDL_PollEvent(&dogadjaj))
	{
		if(dogadjaj.type == SDL_QUIT)
			m_jeZatvoren = true;
	}

}

bool Prozor::jeZatvoren()
{
	return m_jeZatvoren;
}

Prozor::~Prozor(void)
{
	SDL_GL_DeleteContext(m_GLContext);		// Brisanje konteksta
	SDL_DestroyWindow(m_prozor);			// Unistavanje prozora
	SDL_Quit();								// Brise sve Init vrednosti
	delete this;
}