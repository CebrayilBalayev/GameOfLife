cmake_minimum_required(VERSION 3.0)

project(game LANGUAGES C)

add_library ( ${PROJECT_NAME} "")
target_sources(${PROJECT_NAME} PRIVATE actions.c actions.h table.c table.h neigh.c neigh.h)

target_include_directories (${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

install(TARGETS ${PROJECT_NAME} DESTINATION lib)

install(FILES actions.h DESTINATION include)
install(FILES table.h DESTINATION include)
install(FILES neigh.h DESTINATION include)