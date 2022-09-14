target_sources(app
PRIVATE
    pcultivation.cpp 
    resources.h
    ticks.h
    actions.h
PUBLIC 
    pcultivation.h  
)

add_subdirectory(Techniques)