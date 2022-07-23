target_sources(app
PRIVATE
    extern.cpp 
    main.cpp
PUBLIC
    extern.h
)


target_precompile_headers(app PUBLIC extern.h)

add_subdirectory(Cultivation)
add_subdirectory(fmt)
target_link_libraries(app fmt::fmt)
add_subdirectory(Renderer)
add_subdirectory(Util)


FILE(GLOB IMAGES images/*.png)

foreach(img IN LISTS IMAGES)
    FILE(COPY "${img}" DESTINATION "${CMAKE_BINARY_DIR}/images")
endforeach()

FILE(GLOB SCRIPTS scripts/*.txt)


foreach(script IN LISTS SCRIPTS)
    FILE(COPY "${script}" DESTINATION "${CMAKE_BINARY_DIR}/scripts")
endforeach()
