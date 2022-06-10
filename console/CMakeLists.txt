cmake_minimum_required(VERSION 3.0)

project(console LANGUAGES C)

add_library ( ${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE console.c console.h)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2 SDL2main)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

install(FILES console.h DESTINATION include)
