#version 330 core


layout (location = 0) in vec2 pos;
layout (location = 1) in vec2 texcoords;


out vec2 TexCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;


void main() {

	gl_Position = projection * view * model * vec4(pos.x, pos.y, 0.0f, 1.0f);
	TexCoords = texcoords;
}