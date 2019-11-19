find_package(OpenGL)
find_package(GLUT)

add_library(
    Space SHARED
    system/monitor/monitor.cpp
    core/window/window.cpp
)

target_include_directories(
    Space PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/system/monitor
    ${CMAKE_CURRENT_SOURCE_DIR}/core/window
)

target_link_libraries(
    Space
    glfw
    ${OPENGL_gl_LIBRARY}
    ${GLUT_LIBRARIES}
)

message(
    STATUS
    "Open GL Library : ${OPENGL_gl_LIBRARY}"
)

if(GLUT_LIBRARIES)
    message(
    STATUS
    "GLUT Library : ${GLUT_LIBRARIES}"
)
endif()