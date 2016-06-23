#include "mergesort.h"
#include <iostream>
#include <SDL2/SDL.h>

void Sorting_class::Sort(std::vector<int>& niz, Mesh *mreza, Prozor *prozor)
{
	std::vector<int> tempArray(niz);
	MergeSort(niz, tempArray, 0, niz.size()-1, mreza, prozor);
}


void Sorting_class::Merge(std::vector<int>& data, std::vector<int>& tempArray, int low, int middle, int high, Mesh* mreza, Prozor *prozor)
{
	// Kopiraj niz u privremeni pomocni niz
    for (int i = low; i <= high; i++) {
		tempArray[i] = data[i];
    }
 
    int i = low;	// pocetak levog podniza
    int j = middle + 1; // pocetak desnog podniza
    int k = low;
	// Kopiraj najmanju vrednost iz levog ili desnog podniza
	// u prvobitan niz
    while (i <= middle && j <= high) {
		if (tempArray[i] <= tempArray[j]) {
			data[k] = tempArray[i];
            i++;
		} else {
			data[k] = tempArray[j];
			j++;
		}
		k++;

		prozor->Ocisti(0.0f, 0.0f, 0.0f, 1.0f);
		mreza->Redraw(data);
		prozor->Osvezi();
		SDL_Delay(delay);
	}
	// Kopiraj ostatak u prvobitan niz
	while (i <= middle) {
		data[k] = tempArray[i];
		k++; i++;

		prozor->Ocisti(0.0f, 0.0f, 0.0f, 1.0f);
		mreza->Redraw(data);
		prozor->Osvezi();
		SDL_Delay(delay);
	}

	std::cout << "   Merge korak (pocetak:" << low << ",sredina:" << middle << ",kraj:" << high << ")" << std::endl;
	std::cout << std::endl;

}


void Sorting_class::MergeSort(std::vector<int>& niz, std::vector<int>& temp, int low, int high,
				   Mesh* mreza, Prozor *prozor)
{

	if (low < high) {
 
        int middle = (low + high) / 2;	// sredina

		std::cout << " Divide korak -  pocetak: " << low << " sredina: " << middle << " kraj: " << high << std::endl;
 
        /** Rekurzivno sortiraj levu stranu podniza **/
        this->MergeSort(niz, temp, low, middle, mreza, prozor);

        /** Rekurzivno sortiraj desnu stranu podniza **/
        this->MergeSort(niz, temp, middle + 1, high, mreza, prozor);
		
        /** Spoj sortirane podnizove **/
        this->Merge(niz, temp, low, middle, high, mreza, prozor);
    }
}


bool Sorting_class::jeSortiran(const std::vector<int>& niz)
{
	for(unsigned i=0; i<niz.size()-1; i++)
	{
		if(niz[i] > niz[i+1])
		{
			return false;
		}
	}
	return true;
}