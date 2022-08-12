target_sources(app
PRIVATE
    Cultivation.cpp
    util.cpp
PUBLIC
    Cultivation.h
    util.h
)

add_subdirectory(Physical)
add_subdirectory(Spiritual)
