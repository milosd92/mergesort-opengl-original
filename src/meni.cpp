#include "meni.h"
#include <iostream>

using namespace std;

Meni::Meni(void)
{
	// Dva znaka \\ za znak backslash(\)
	cout << " __  __                        _____            _   "		<< endl;
	cout << "|  \\/  |                      / ____|          | |  "		<< endl;
	cout << "| \\  / | ___ _ __ __ _  ___  | (___   ___  _ __| |_ "		<< endl;
	cout << "| |\\/| |/ _ \\ '__/ _` |/ _ \\  \\___ \\ / _ \\| '__| __|"<< endl;
	cout << "| |  | |  __/ | | (_| |  __/  ____) | (_) | |  | |_ "		<< endl;
	cout << "|_|  |_|\\___|_|  \\__, |\\___| |_____/ \\___/|_|   \\__|" << endl;
	cout << "                  __/ |                             "		<< endl;
	cout << "                 |___/                              "		<< endl; 
	cout << endl;
	cout << "////////////////////////////////////////////////////"		<< endl;
	cout << endl;

	cout << "Vizuelni prikaz Merge Sort algoritma za sortiranje" << endl;
	cout << endl;

}

unsigned int Meni::MeniVelicinaNiza(void)
{

	cout << "Odaberite broj odabiraka, tj. velicinu niza: ";
	cout << "Unesite broj za:" << endl;
	cout << "1) 10 odabiraka" << endl;
	cout << "2) 20 odabiraka" << endl;
	cout << "3) 50 odabiraka" << endl;
	cout << "4) 100 odabiraka" << endl;
	cout << "5) 200 odabiraka" << endl;
	cout << "6) 500 odabiraka" << endl;
	cout << "7) 1000 odabiraka" << endl;
	cout << endl;

	cin >> brOdabiraka;
	return this->caseHandler(brOdabiraka);
}

unsigned int Meni::MeniOdabirDelay(void)
{
	cout << endl;
	cout << "Unesite DELAY (ms) izmedju svakog koraka izvrsavanja algoritma" << endl;
	cout << " od 5000 za veoma sporo" << endl;
	cout << " do 3000 za sporo (preporuka za male nizove)" << endl;
	cout << " do 1000 za srednju brzinu" << endl;
	cout << " do 300 za brzo izvrsavanje " << endl;
	cout << " do 50 za veoma brzo izvrsavanje (za velike nizove)" << endl;
	cout << " od 0 (bez DELAY-a)" << endl;
	cout << "Napomena: Realno vreme - vreme potrebno da se iscrtaju svi elementi" << endl;
	cout << endl;

	cin >> delay;
	return delay;
}

// Uzima broj koji je unet od strane korisnika i vraca
// velicinu niza koji odgorava tom broju
unsigned int Meni::caseHandler(unsigned int broj)
{
	switch(broj){

		case 1:
			return 10;
			break;
		case 2:
			return 20;
			break;
		case 3:
			return 50;
			break;
		case 4:
			return 100;
			break;
		case 5:
			return 200;
			break;
		case 6:
			return 500;
			break;
		case 7:
			return 1000;
			break;
		default:
			return 10;
	}
}

Meni::~Meni(void) {}