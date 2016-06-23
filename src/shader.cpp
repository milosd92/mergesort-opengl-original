#include "shader.h"
#include <fstream>
#include <iostream>

// *\brief Ucitava Shader iz fajla
// *\param nazivFajla std::string naziv fajla u kom se nalazi GLSL kod za shader
// *\return std::string Naziv fajla ako postoji
// *\! Ako ne postoji fajl sa tim nazivom, ispisuje gresku
static std::string UcitajShader(const std::string& nazivFajla);

// *\brief Proverava da li se shader kompajlovao, zasto ne?
// *\param shader Koji shader (vertex, fragment..)
// *\param flag Sta proverava? GL_COMPILE_STATUS, GL_LINK_STATUS, GL_VALIDATE_STATUS
// *\param jeProgram Da li je shader ili m_program (tip bool)
// *\param porukaGreske String koji ce ispisati u slucaju greske
// *\return void
static void ProveriShaderGreske(GLuint shader, GLuint flag, bool jeProgram, const std::string& porukaGreske);

// *\brief Konstruise shadere, linkuje, kompajluje..
// *\param text Nziv shader-fajla (tip std::string) 
// *\param tipShadera Tip shadera koji se pravi, GL_VERTEX_SHADER, GL_FRAGMENT_SHADER...
// *\return GLuint
static GLuint NapraviShader(const std::string& text, GLenum tipShadera);


Shader::Shader(const std::string& nazivFajla)
{
	// Kreiranje shader programa
	m_program = glCreateProgram();
	// Pravljenje Vertex i Fragment shader-a
    m_shaders[0] = NapraviShader(UcitajShader(nazivFajla + ".vs"), GL_VERTEX_SHADER);
	m_shaders[1] = NapraviShader(UcitajShader(nazivFajla + ".fs"), GL_FRAGMENT_SHADER);

//    std::string kvadrat_vertex_shader_prog = "#version 120\n"
//            "\n"
//            "attribute vec3 pozicija;\n"
//            "\n"
//            "uniform mat4 transform;\n"
//            "\n"
//            "void main()\n"
//            "{\n"
//            "\tgl_Position = transform * vec4(pozicija, 1.0);\n"
//            "}";
//
//    std::string kvadrat_fragment_shader_prog = "#version 120\n"
//            "\n"
//            "void main()\n"
//            "{\n"
//            "\tgl_FragColor = vec4(1.0, 0.0, 0.0, 1.0);\n"
//            "}";
//
//    m_shaders[0] = NapraviShader(kvadrat_vertex_shader_prog, GL_VERTEX_SHADER);
//	m_shaders[1] = NapraviShader(kvadrat_fragment_shader_prog, GL_FRAGMENT_SHADER);

	// Spajanje atributa iz shader fajla
	glBindAttribLocation(m_program, 0, "pozicije");

	// Spajanje svih shader-a u program	(binding)
	for(unsigned int i=0; i<BROJ_SHADERA; i++)
		glAttachShader(m_program, m_shaders[i]);

	// Vezivanje shadera u program (linking)
	glLinkProgram(m_program);
	// Provera vezivanja-spajanja
	ProveriShaderGreske(m_program, GL_LINK_STATUS, true, "Greska: Vezivanje programa neuspesno!");

	// Potvrda i provera posle vezivanja
	glValidateProgram(m_program);
	ProveriShaderGreske(m_program, GL_VALIDATE_STATUS, true, "Greska: Program nije validan!");

	// za transform.h, glGetUniformLocation(shader_program, promenljiva u GLSL vertex shader-u)
    m_uniforms[TRANSFORM_U] = glGetUniformLocation(m_program, "transform");

}

void Shader::Spoj()
{
	glUseProgram(m_program);
}

void Shader::Azuriraj(const Camera& camera)
{
	glm::mat4 modelViewProjection = camera.GetViewProjection();
	glUniformMatrix4fv(m_uniforms[TRANSFORM_U], 1, GL_FALSE, &modelViewProjection[0][0]);
}

Shader::~Shader(void)
{
	// Brisanje shader programa
	glDeleteProgram(m_program);

	for(unsigned int i=0; i<BROJ_SHADERA; i++)
	{
		// Otkaci sve shadere od shader programa
		glDetachShader(m_program, m_shaders[i]);
		// Obrisi sve shadere
		glDeleteShader(m_shaders[i]);
	}
}

static std::string UcitajShader(const std::string& nazivFajla)
{
	std::ifstream file;
    file.open((nazivFajla).c_str());

    std::string rezultat;
    std::string line;

    if(file.is_open())
    {
        while(file.good())
        {
            getline(file, line);
            rezultat.append(line + "\n");
        }
    }
    else
    {
        std::cerr << "Nije moguce ucitati shader: " << nazivFajla <<  " err: " << file.rdstate() << std::endl;
    }

    return rezultat;
}

static void ProveriShaderGreske(GLuint shader, GLuint flag, bool jeProgram, const std::string& porukaGreske)
{
	GLint uspeh = 0;
	GLchar greska[1024] = { 0 };

	if(jeProgram)
		glGetProgramiv(shader, flag, &uspeh);
	else
		glGetShaderiv(shader, flag, &uspeh);

	if(uspeh == GL_FALSE)
	{
		if(jeProgram)
			glGetProgramInfoLog(shader, sizeof(greska), NULL, greska);
		else
			glGetShaderInfoLog(shader, sizeof(greska), NULL, greska);

		std::cerr << porukaGreske << ": " << "'" << std::endl;
	}
}

static GLuint NapraviShader(const std::string& text, GLenum tipShadera)
{
	// Kreiranje shadera
	GLuint shader = glCreateShader(tipShadera);

	// Kreiranje nije uspelo, GLuint shader je 0
	if(shader == 0)
		std::cerr << "Greska: Kreiranje shadera neuspesno!" << std::endl;

	const GLchar* izvorShadera_Strings[1];
	GLint izvorShadera_StringsDuzina[1];

	// Moramo konvertovati u c.str
	izvorShadera_Strings[0] = text.c_str();
	izvorShadera_StringsDuzina[0] = text.length();

	// Kompajlovanje shader-a
	glShaderSource(shader, 1, izvorShadera_Strings, izvorShadera_StringsDuzina);
	glCompileShader(shader);

	// Provera: da li postoje greske tokom kompajlovanja
	ProveriShaderGreske(shader, GL_COMPILE_STATUS, false, "Greska: Kompalacija neuspesna!");

	return shader;
}