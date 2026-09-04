cmake_minimum_required(VERSION 3.11)
project(CastleEscape)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(ftxui
  GIT_REPOSITORY https://github.com/ArthurSonzogni/ftxui.git
  GIT_TAG v5.0.0
)
FetchContent_MakeAvailable(ftxui)

file(GLOB SOURCES "*.cpp")
add_executable(game ${SOURCES}
  inventory.cpp)

target_link_libraries(game
  PRIVATE ftxui::screen
  PRIVATE ftxui::dom
  PRIVATE ftxui::component
)