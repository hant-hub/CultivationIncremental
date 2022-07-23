#include "Sprite.h"


namespace Render {
	void CheckErrorStack(int i) {
	int code = glGetError();
	if (code) {
		std::cout << code << std::endl;
        std::cout << i << std::endl;
	}
}
	Sprite::Sprite(const char* filepath, float x, float y, float width, float height, float rot, Shader* s) {
		shader = s;
		position = glm::vec2(x, y);
		size = glm::vec2(width, height);
		rotation = rot;


		const float vertices[] = {
			// pos         //Texture Coords
			0.0f, 0.0f,     0.0f, 0.0f,     //bottom left
			1.0f, 0.0f,     1.0f, 0.0f,     //bottom right
			1.0f, 1.0f,     1.0f, 1.0f,     //top right
			0.0f, 1.0f,     0.0f, 1.0f,     //top left
			0.0f, 0.0f,     0.0f, 0.0f,
			1.0f, 1.0f,     1.0f, 1.0f
		};



		//texture
		int w, h, nrChannels;
		stbi_set_flip_vertically_on_load(true);
		unsigned char* data = stbi_load(filepath, &w, &h, &nrChannels, 4);

		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);

		//buffers
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &VBO);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 4, (void*)(2*sizeof(float)));
		glEnableVertexAttribArray(1);


		glBindVertexArray(0);

	}

	Sprite::~Sprite() {
		glDeleteBuffers(1, &VBO);
		glDeleteVertexArrays(1, &VAO);
		
	}

	void Sprite::Draw(Camera& camera){
		(*shader).Use();
		glm::mat4 model = glm::mat4(1.0f);

		model = glm::translate(model, glm::vec3(position, 0.0f));
		
		model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, -1.0f));
		model = glm::translate(model, glm::vec3(-size.x * 0.5, -size.y * 0.5, 0.0f));

		model = glm::scale(model, glm::vec3(size, 1.0f));
		
		(*shader).SetMat4("model", model);
		(*shader).SetMat4("view", camera.GetView());
		(*shader).SetMat4("projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
		
		glBindTexture(GL_TEXTURE_2D, texture);
		glBindVertexArray(VAO);
		CheckErrorStack(0);
		glDrawArrays(GL_TRIANGLES,0,6);
		glBindVertexArray(0);
		
	
	}

	const void Sprite::SetState(float x, float y, float rot)
	{
		position = glm::vec2(x, y);
		rotation = rot;
	}

	const void Sprite::SetState(float x, float y)
	{
		position = glm::vec2(x, y);
	}

	const void Sprite::SetState(float rot)
	{
		rotation = rot;
	}



}