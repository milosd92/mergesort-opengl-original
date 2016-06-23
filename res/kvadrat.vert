#version 120

attribute vec3 pozicija;

uniform mat4 transform;

void main()
{
	gl_Position = transform * vec4(pozicija, 1.0);
}