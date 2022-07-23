#include "Shader.h"



Render::Shader::Shader(const char* VertexPath, const char* FragmentPath){

	std::string VertCode;
	std::string FragCode;

	std::ifstream VertFile;
	std::ifstream FragFile;

	
	VertFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	FragFile.exceptions(std::ifstream::failbit | std::ifstream::badbit);
	
	try {
		
		VertFile.open(VertexPath);
		printf("executed\n");
		FragFile.open(FragmentPath);
		
		std::stringstream VertBuff;
		std::stringstream FragBuff;

		VertBuff << VertFile.rdbuf();
		FragBuff << FragFile.rdbuf();

		VertFile.close();
		FragFile.close();

		VertCode = VertBuff.str();
		FragCode = FragBuff.str();

	}
	catch(std::ifstream::failure& e) {
		std::cout << "ERROR: Shader Failed to compile: " << e.what() << std::endl;
	}
	const char* vShaderCode = VertCode.c_str();
	const char* fShaderCode = FragCode.c_str();

	GLuint vert, frag;

	vert = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vert, 1, &vShaderCode, NULL);
	glCompileShader(vert);
	CheckErrors(vert, "VertexShader");
	
	
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(frag, 1, &fShaderCode, NULL);
	glCompileShader(frag);
	CheckErrors(frag, "FragmentShader");

	ID = glCreateProgram();
	glAttachShader(ID, vert);
	glAttachShader(ID, frag);
	glLinkProgram(ID);
	CheckErrors(ID, "Program");

	glDeleteShader(vert);
	glDeleteShader(frag);

}




Render::Shader::~Shader(){
	glDeleteProgram(ID);
}