#include "renderlib.h"
#include "RenderText.h"

Render::TextRenderer::TextRenderer(Window& w, std::string font, unsigned int height) : w(w), cam(0.0f, 0.0f, (float)w.width, (float)w.height)
{
	//load font library--------------------------
	FT_Library ft;

	if (FT_Init_FreeType(&ft)) {
		std::cout << "ERROR: Freetype failed to initialize" << std::endl;
	}

	FT_Face face;
	if (FT_New_Face(ft, "fonts/arial.ttf", 0, &face)) {
		std::cout << "ERROR: font failed to load" << std::endl;
	}

	FT_Set_Pixel_Sizes(face, 0, height);

	glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
	

	for (unsigned char c = 0; c < 128; c++) {
		//load char into face
		if (FT_Load_Char(face, c, FT_LOAD_RENDER)) {
			std::cout << "ERROR: Character " << c << " failed to load" << std::endl;
			continue;
		}

		//generate texture
		unsigned int texture;
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexImage2D(GL_TEXTURE_2D,
			0,
			GL_RED,
			face->glyph->bitmap.width,
			face->glyph->bitmap.rows,
			0,
			GL_RED,
			GL_UNSIGNED_BYTE,
			face->glyph->bitmap.buffer
		);

		//texture options
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

		//store character into memory
		Character character = {
		texture,
		glm::ivec2(face->glyph->bitmap.width, face->glyph->bitmap.rows),
		glm::ivec2(face->glyph->bitmap_left, face->glyph->bitmap_top),
		face->glyph->advance.x
		};
		
		f.insert(std::pair<char, Character>(c, character));

	}
	FT_Done_Face(face);
	FT_Done_FreeType(ft);
	
	//Setup VAO (rendering state set, attribute pointers created, etc.)
	const unsigned int indicies[] = {
	0, 1, 3,
	1, 2, 3
	};
	
	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(float) * 4 * 6, NULL, GL_DYNAMIC_DRAW);
	glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, sizeof(float) * 4, 0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}

Render::TextRenderer::~TextRenderer()
{
	glDeleteBuffers(1, &VBO);
	glDeleteVertexArrays(1, &VAO);
}

void Render::TextRenderer::RenderText(Shader& s, std::string text, float x, float y, float scale, glm::vec3 color)
{
	s.Use();
	s.SetMat4("view", cam.GetView());
	s.SetMat4("projection", glm::ortho(0.0f, (float)w.width, (float)w.height, 0.0f, -1.0f, 1.0f));
	s.SetVec3("textColor", color);
	glBindVertexArray(VAO);
	glActiveTexture(GL_TEXTURE0);
	float ox = x;
	float oy = y;

	std::string::const_iterator c;
	for (c = text.begin(); c != text.end(); c++) {
		if (*c == *"\n") {
			y += f['H'].bearing.y;
			x = ox;
			continue;
		}
		
		Character ch = f[*c];

		float xpos = x + ch.bearing.x * scale;
		float ypos = y + (f['H'].bearing.y - ch.bearing.y) * scale;

		float w = ch.size.x * scale;
		float h = ch.size.y * scale;

		float verticies[6][4] = {
			{ xpos,     ypos + h,   0.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 0.0f },
			{ xpos,     ypos,       0.0f, 0.0f },

			{ xpos,     ypos + h,   0.0f, 1.0f },
			{ xpos + w, ypos + h,   1.0f, 1.0f },
			{ xpos + w, ypos,       1.0f, 0.0f }
		};
		glBindTexture(GL_TEXTURE_2D, ch.texture);
		glBindBuffer(GL_ARRAY_BUFFER, VBO);
		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(verticies), verticies);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glDrawArrays(GL_TRIANGLES, 0, 6);

		x += (ch.advance >> 6) * scale;
	}
	glBindVertexArray(0);
	glBindTexture(GL_TEXTURE_2D, 0);

}
