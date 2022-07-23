#pragma once
#include "renderlib.h"

namespace Render {
	class Shader
	{
	public:
		Shader(const char* VertexPath, const char* FragmentPath);
		~Shader();

		const void Use() { glUseProgram(ID); }


		//uniform functions
		//inteagers
		const void SetInt(const std::string& name, const int value) { glUseProgram(ID);  glUniform1i(glGetUniformLocation(ID, name.c_str()), value); }
		const void SetFloat(const std::string& name, const float value) { glUseProgram(ID); glUniform1f(glGetUniformLocation(ID, name.c_str()), value); }
		const void SetBool(const std::string& name, const bool value) { glUseProgram(ID); glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value); }

		//vectors

		//direct
		const void SetVec2(const std::string& name, const float v1, const float v2) { glUseProgram(ID); glUniform2f(glGetUniformLocation(ID, name.c_str()), v1, v2); }
		const void SetVec3(const std::string& name, const float v1, const float v2, const float v3) { glUseProgram(ID); glUniform3f(glGetUniformLocation(ID, name.c_str()), v1, v2, v3); }
		const void SetVec4(const std::string& name, const float v1, const float v2, const float v3, const float v4) { glUseProgram(ID); glUniform4f(glGetUniformLocation(ID, name.c_str()), v1, v2, v3, v4); }

		//glm
		const void SetVec2(const std::string& name, const glm::vec2 value) { glUseProgram(ID); glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); }
		const void SetVec3(const std::string& name, const glm::vec3 value) { glUseProgram(ID); glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); }
		const void SetVec4(const std::string& name, const glm::vec4 value) { glUseProgram(ID); glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); }

		//matricies
		const void SetMat2(const std::string& name, const glm::mat2 value) { glUseProgram(ID); glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]); }
		const void SetMat3(const std::string& name, const glm::mat3 value) { glUseProgram(ID); glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]); }
		const void SetMat4(const std::string& name, const glm::mat4 value) { glUseProgram(ID); glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &value[0][0]); }


	private:
		unsigned int ID;


		void CheckErrors(unsigned int id, std::string type){
			GLint success;
			GLchar info[1024];

			if (type != "Program")
			{
				glGetShaderiv(id, GL_COMPILE_STATUS, &success);
				if (!success)
				{
					glGetShaderInfoLog(id, 1024, NULL, info);
					std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << info << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}
			else
			{
				glGetProgramiv(id, GL_LINK_STATUS, &success);
				if (!success)
				{
					glGetProgramInfoLog(id, 1024, NULL, info);
					std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << info << "\n -- --------------------------------------------------- -- " << std::endl;
				}
			}
		

		}
	};

}
