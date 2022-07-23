#version 330 core


layout (location = 0) in vec4 pos;


out vec2 TexCoords;

uniform mat4 projection;


void main() {

	gl_Position = projection * vec4(pos.x, pos.y, 0.0f, 1.0f);
	TexCoords = pos.zw;
}