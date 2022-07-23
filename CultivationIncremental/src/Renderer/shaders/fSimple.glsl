#version 330 core

in vec2 TexCoords;
out vec4 Fragcolor;


uniform sampler2D Texture1;

void main() {

Fragcolor = texture(Texture1, TexCoords);

}