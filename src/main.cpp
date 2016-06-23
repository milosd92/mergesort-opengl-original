#include <iostream>
#include <vector>
#include "randomArrayGenerator.h"
#include "mergesort.h"
#include "prozor.h"
#include "mesh.h"
#include "shader.h"
#include "camera.h"
#include "meni.h"

#define SIRINA 800
#define VISINA 600

int main(int argc, char** argv)
{
	unsigned int arraySize;
	unsigned int delay;

	Meni meni;
	arraySize = meni.MeniVelicinaNiza();
	delay = meni.MeniOdabirDelay();

	std::vector<int> niz;
	niz = randomArrayGen(arraySize);

	std::vector<Vertex> tacke;
	Vertex::UcitajTacke(tacke, arraySize, niz);

	// Pravljenje prozora
	Prozor *mergeSortOpenGL = new Prozor(SIRINA, VISINA, "MergeSort OpenGL");
	// Ucitavanje tacaka
	Mesh *mreza = new Mesh(tacke, tacke.size());
	// Postavljanje shader-a
	Shader quad("./res/kvadrat");
	// Postavljanje pogleda-kamere
	Camera kamera(arraySize, (float)SIRINA/(float)VISINA, 0.01f, 1000.0f);

	Sorting_class mergesort(delay);

	mreza->Draw();
	while(!mergesort.jeSortiran(niz))
	{
		mergeSortOpenGL->Ocisti(0.0f, 0.0f, 0.0f, 1.0f);
		quad.Spoj();
		quad.Azuriraj(kamera);
		mergesort.Sort(niz, mreza, mergeSortOpenGL);
	}

	SDL_Delay(10000);  // Zaustavi izvrsavanje na kraju na 10sec
	return 0;
}