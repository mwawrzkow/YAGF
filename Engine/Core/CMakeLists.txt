cmake_minimum_required(VERSION 3.7.2)
add_compile_options(-Wall)
add_executable(main main.cpp)

if(WIN32)
        add_compile_definitions(GLEW_STATIC)
endif()
add_library(gl_Core 
        core/base/vertexHandler.cpp 
        core/base/Primitive.cpp 
        core/WindowProperties.cpp 
        core/primitives/Square.cpp 
        # core/primitives/PrimitivesManager.cpp
        # core/primitives/Lights.cpp
        # core/primitives/Light/DirectLight.cpp
        # core/primitives/Light/SphericalLight.cpp
        # core/primitives/Light/GlobalLight.cpp #TODO: add when starts working
        # core/Line.cpp
        core/OpenGLArrays/ArrayHandler.cpp 
        core/base/Texture.cpp
        core/base/OpenGLStart.cpp
)

target_include_directories(gl_Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include )
target_include_directories(gl_Core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include )

# set(GL_DEF glfw 
#         glew_static)
# set(LIBS ${engineLibs} ${GL_DEF})
add_subdirectory(glfw)
add_subdirectory(glew)
set(GL_DEF glfw 
glew_static)
# add_subdirectory(core/FastMath)
set(engineLibs gl_Core)
target_link_libraries(gl_Core ${GL_DEF})

# if(A_Engine_debug)
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glfw/include )
target_include_directories(main PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/glew/include )
target_link_libraries(main gl_Core)
# endif()

