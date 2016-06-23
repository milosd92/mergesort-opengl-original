#pragma once

#include <string>
#include <SDL2/SDL.h>

class Prozor
{
public:
	// *\ Constructor
	// *\brief Pravljenje prozora za crtanje u OpenGL-u
	// *\param sirina Sirina prozora
	// *\param visina Visina prozora
	// *\param naziv  Naziv(title) prozora
	// *\sa ~Prozor(void)
	Prozor(int sirina, int visina, const std::string& naziv);

	// *\brief Cisti ili brise sliku sa prozora, uklanja sve boje
	// *\param r RED (crvena)
	// *\param g GREEN (zelena)
	// *\param b BLUE (plava)
	// *\param a ALPHA (prozirnost)
	// *\return void
	void Ocisti(float r, float g, float b, float a);

	// *\brief Zamenjuje trenutnu sliku sa slikom koja se iscrtala u pozadini
	// *\return void
	void Osvezi();

	// *\brief Proverava da li je prozor zatvoren
	// *\return TRUE u slucaju da je zatvoren
	// *\return FALSE u suprotnom
	bool jeZatvoren();

	// *\ Destructor
	virtual ~Prozor(void);

protected:
private:

	SDL_Window* m_prozor;
	SDL_GLContext m_GLContext;

	bool m_jeZatvoren;

};