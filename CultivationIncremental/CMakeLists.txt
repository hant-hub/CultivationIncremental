cmake_minimum_required(VERSION 3.22.5)

project("CultivationIncremental")


add_executable(app "")



add_subdirectory(src)



add_definitions("-pthread")

install(TARGETS app DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)