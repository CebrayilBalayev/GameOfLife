cmake_minimum_required(VERSION 3.0)

project(Game_of_Life LANGUAGES C)

add_executable ( ${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE main.c)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)

target_link_libraries(${PROJECT_NAME} PRIVATE game)
target_link_libraries(${PROJECT_NAME} PRIVATE console)

add_subdirectory(game)
add_subdirectory(console)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
