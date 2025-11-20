cmake_minimum_required(VERSION 3.10)

project(TextovaHra)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp")
file(GLOB ITEMS "src/Items/*.cpp" "src/Items/*.hpp")



add_executable(TextovaHra
        ${SOURCES}
        ${ITEMS})

add_executable(ItemTest
        ${ITEMS})


include(cmake/CPM.cmake)
find_package(Threads REQUIRED)

CPMAddPackage("gh:ArthurSonzogni/FTXUI#e0d98fe")
target_link_libraries(TextovaHra
        ftxui::component
        ftxui::dom
        ftxui::screen
        Threads::Threads
)

target_link_libraries(ItemTest
        ftxui::dom
        ftxui::screen
)

add_custom_target(copy_assets ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "${CMAKE_BINARY_DIR}/assets"
        COMMENT "Copying assets directory")

add_dependencies(TextovaHra copy_assets)
add_dependencies(ItemTest copy_assets)


