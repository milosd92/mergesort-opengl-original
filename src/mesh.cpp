#include "mesh.h"
#include <vector>
#include <iostream>
#include <SDL2/SDL.h>

Mesh::Mesh(const std::vector<Vertex>& tacke ,unsigned int brTacaka)
{
	m_brojacCrtanja = brTacaka;

	// Generisanje niza za podatke tacaka (vertex)
	glGenVertexArrays(1, &m_vertexArrayObject);
	glBindVertexArray(m_vertexArrayObject);		// spajanje

	std::vector<Vertex> pozicije;
	pozicije.reserve(brTacaka);

	// Ubacivanje atributa za poziciju u vector pozicije
	for(unsigned int i=0; i<brTacaka; i++)
	{
		pozicije.push_back(tacke[i]);
	}

	// Generisanje bafera
	glGenBuffers(BROJ_VB, m_vertexArrayBuffers);

	// Bafer za pozicije
	glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[POZICIJA_VB]);

	// Slanje podataka u bafer
	glBufferData(GL_ARRAY_BUFFER, brTacaka * sizeof(pozicije[0]), &pozicije[0], GL_DYNAMIC_DRAW);

	// Ukljucivanje prvog niza atributa
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Rastavljanje
	glBindVertexArray(0);
}

void Mesh::Draw()
{
	// Spajanje
	glBindVertexArray(m_vertexArrayObject);

	glDrawArrays(GL_QUADS, 0, m_brojacCrtanja);

	// Rastavljanje
	glBindVertexArray(0);

}

void Mesh::Redraw(std::vector<int>& arr)
{
	std::vector<Vertex> tacke;
	Vertex::UcitajTacke(tacke, arr.size(), arr);

	this->Update(tacke, tacke.size());
	this->Draw();
}


void Mesh::Update(const std::vector<Vertex>& tacke ,unsigned int brTacaka)
{
	std::vector<Vertex> pozicije;
	pozicije.reserve(brTacaka);

	for(unsigned int i=0; i<brTacaka; i++)
	{
		pozicije.push_back(tacke[i]);
	}

	// Slanje podataka u bafer
	glBufferSubData(GL_ARRAY_BUFFER, 0 , brTacaka * sizeof(pozicije[0]), &pozicije[0]);

	// Ukljucivanje prvog niza atributa
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

	// Rastavljanje
	glBindVertexArray(0);
}

Mesh::~Mesh(void)
{
	// Brisanje podataka
	glDeleteVertexArrays(1, &m_vertexArrayObject);
	delete this;
}