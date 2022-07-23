
#add_library(freetype)
#add_subdirectory(FREETYPE)
#target_link_libraries(app freetype)

find_package(Freetype)
target_include_directories(app PUBLIC "${FREETYPE_INCLUDE_DIRS}")
target_link_libraries(app ${FREETYPE_LIBRARY})

add_library(glad)
add_subdirectory(GLAD)
target_link_libraries(app glad)

add_subdirectory(GLFW)
include_directories(GLFW/include)
target_link_libraries(app glfw ${GLFW_LIBRARIES})

add_subdirectory(GLM)
include_directories(GLM/glm)
target_link_libraries(app glm)

add_subdirectory(STBIMAGE)
target_include_directories(app PUBLIC STBIMAGE)
