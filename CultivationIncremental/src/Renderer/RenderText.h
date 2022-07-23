#pragma once
#define _WINDOWS
#undef __APPLE__
#include "renderlib.h"
#include "Shader.h"
#include "Camera.h"
#include "ft2build.h"
#include FT_FREETYPE_H  

namespace Render {
	struct Character {
		unsigned int texture;
		glm::ivec2 size;
		glm::ivec2 bearing;
		unsigned int advance;
	};
	typedef std::map<char, Character> Font;

	class TextRenderer {
	public:
		TextRenderer(std::string font, unsigned int height);
		~TextRenderer();


		void RenderText(Shader& s, std::string text, float x, float y, float scale, glm::vec3 color);
	
		const Font GetFont() { return f; }
	private:
		Font f;
		unsigned int VAO, VBO;
	};
}

