cmake_minimum_required(VERSION 3.10)

project(TextovaHra)

set(CMAKE_CXX_STANDARD 23)

file(GLOB SOURCES "src/*.cpp" "src/*.hpp")

add_executable(TextovaHra ${SOURCES})

include(cmake/CPM.cmake)
find_package(Threads REQUIRED)

CPMAddPackage("gh:ArthurSonzogni/FTXUI#e0d98fe")
target_link_libraries(TextovaHra
        ftxui::component
        ftxui::dom
        ftxui::screen
        Threads::Threads
)
