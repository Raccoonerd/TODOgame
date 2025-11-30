cmake_minimum_required(VERSION 3.28)
project(TODOapp
  VERSION 0.0.1
  DESCRIPTION "TODO app with rpg elements"
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

set(SOURCES
  src/main.cpp
  src/taskmanager.cpp
  src/filemanager.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR}/include
)
