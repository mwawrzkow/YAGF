cmake_minimum_required(VERSION 3.7.2)

project(RPG_ENGINE)
# set(CMAKE_CXX_STANDARD 17)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_subdirectory(Core)

file(COPY "shaders/" DESTINATION "Core/")
file(COPY "exampleimgs/" DESTINATION "Core/")

