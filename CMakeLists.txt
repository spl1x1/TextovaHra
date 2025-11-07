cmake_minimum_required(VERSION 3.10)

project(TextovaHra)

set(CMAKE_CXX_STANDARD 14)

file(GLOB SOURCES "src/*.cpp")

add_executable(TextovaHra ${SOURCES})

include(cmake/CPM.cmake)

CPMAddPackage("gh:ArthurSonzogni/FTXUI#e0d98fe")
target_link_libraries(TextovaHra
    ftxui::component
    ftxui::dom
    ftxui::screen
)
