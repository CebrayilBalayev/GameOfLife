cmake_minimum_required(VERSION 3.0)

project(Game_of_Life LANGUAGES C)

add_executable ( ${PROJECT_NAME} "")
add_executable ( tests "")

target_sources(${PROJECT_NAME} PRIVATE main.c)
target_sources(tests PRIVATE tests.c)

target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)
target_link_libraries(tests PRIVATE cunit )

target_link_libraries(tests PRIVATE game)
target_link_libraries(tests PRIVATE console)

target_link_libraries(${PROJECT_NAME} PRIVATE game)
target_link_libraries(${PROJECT_NAME} PRIVATE console)

add_subdirectory(game)
add_subdirectory(console)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
install(TARGETS tests DESTINATION bin)