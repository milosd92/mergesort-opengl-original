#pragma once
class Meni
{
public:
	// *\brief Kreira pocetni meni
	// *\param void
	// *\constructor
	Meni(void);

	// *\brief Virtual destructor
	virtual ~Meni(void);

	// *\brief Meni za odabir velicine niza
	// *\param void
	// *\return unsigned int velicina niza
	unsigned int MeniVelicinaNiza(void);

	// *\brief Meni za odabir kasnjenja
	// *\param void
	// *\return unsigned int delay
	unsigned int MeniOdabirDelay(void);

protected:
private:

	// *\brief Pomocna privatna metoda 
	// *\param unsigned int brOdabiraka
	// *\return unsigned int broj
	unsigned int caseHandler(unsigned int brOdabiraka);

	unsigned int brOdabiraka;
	unsigned int delay;
};