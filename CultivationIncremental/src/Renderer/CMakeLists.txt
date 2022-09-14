target_sources(app
PRIVATE 
    Camera.cpp 
    Renderer.cpp 
    RenderText.cpp 
    Shader.cpp 
    Sprite.cpp 
    Renderer.h 
    renderlib.h 
    RenderText.h 
    Shader.h 
    Sprite.h
    Camera.h 
    Animation2D.cpp
    Animation2D.h
PUBLIC 
    core.h 
)

FILE(GLOB FONTS fonts/*.ttf)
FILE(GLOB SHADERS shaders/*.glsl)

foreach(font IN LISTS FONTS)
    FILE(COPY "${font}" DESTINATION "${CMAKE_BINARY_DIR}/fonts")
endforeach()

foreach(shader IN LISTS SHADERS)
    FILE(COPY "${shader}" DESTINATION "${CMAKE_BINARY_DIR}/shaders")
endforeach()

add_subdirectory(lib)