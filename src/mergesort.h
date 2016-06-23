#pragma once
#include <vector>
#include "mesh.h"
class Sorting_class
{

public:

	// *\ Constructor
	// *\param unsigned int delay
	Sorting_class(unsigned int delay){ this->delay = delay; }

	// *\brief Preko ove metode se poziva metoda MergeSort
	//          metoda za sortiranje niza
	//          Stampa nesortiran niz na pocetku i
	//			sortiran kada se zavrsi
	// *\param std::vector<int> niz
	// *\param Mesh mreza
	// *\param Prozor prozor
	// *\return void
	void Sort(std::vector<int>& niz, Mesh *mreza, Prozor *prozor);

	// *\brief Proverava da li je niz sortiran
	// *\param std::vector<int> niz
	// *\return bool (true) ako je sortiran
	bool jeSortiran(const std::vector<int>& niz);

	// *\ Destructor
	// *\param void
	virtual ~Sorting_class(void) {};
	
protected:

	// *\brief Sortiranje pomocu rekurzije.
	//			Zadati vector(niz) je sortiran pomocu Mergesort algoritma
	// *\param std::vector<int> niz Nesortiran niz
	// *\param std::vector<int> temp Privremeni niz
	// *\param int low pocetak niza
	// *\param int high kraj niza
	// *\param Mesh mreza
	// *\param Prozor prozor
	// *\return void
	void MergeSort(std::vector<int>& niz, std::vector<int>& temp, int low, int high,
				   Mesh* mreza, Prozor *prozor);

private:

	// *\brief Spaja dva sortirana podniza u jedan
	// *\param std::vector<int> niz
	// *\param std::vector<int> temp
	// *\param int low pocetak niza
	// *\param int middle sredina niza
	// *\param int high kraj niza
	// *\param Mesh mreza
	// *\param Prozor prozor
	// *\funk Private metoda
	// *\return void
	void Merge(std::vector<int>& niz, std::vector<int>& temp, int low, int middle, int high,
				Mesh* mreza, Prozor *prozor);

	unsigned int delay;		// kasnjenje
};