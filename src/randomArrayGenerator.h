#pragma once
#include <vector>
#include <iostream>
#include <string>
#include <time.h>

// *\brief Vraca niz od nasumicno generisanih brojeva
//         bez ponavljanja
// *\param unsigned int size
// *\return std::vector<int>
std::vector<int> randomArrayGen(unsigned int size)
{
	std::vector<int> randArray;
	randArray.reserve(size);
	srand(time(NULL));

	for(unsigned int i=0; i<size; i++)
	{
		bool check; //varijabla za proveru
		int number; //varijabla za cuvanje generisanog broja
		do {
			 number = rand() % size + 1;
			 check = true;
			 for (unsigned int j=0; j<i; j++)
			 {
				 if (number == randArray[j]) //ako je broj iskoriscen
				 {
					 check=false; //sada je false
					 break; //i ne treba da se proveravaju ostali clanovo niza
				 }
			 }
		 } while (!check); //dok se ne pojavi novi unikatni broj
		randArray.push_back(number); //cuvaj u nizu brojeve koji su prosli
	}

	//StampajNiz(randArray, "RND: ");
	return randArray;
}