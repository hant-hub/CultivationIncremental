target_sources(app
PRIVATE
    scultivation.cpp 
    resources.h
    ticks.h
    actions.h
PUBLIC 
    scultivation.h  
)

add_subdirectory(Techniques)