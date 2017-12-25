project( Test )

add_executable( main main.cpp )
target_include_directories(main PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${GLM_INCLUDE_DIRS})

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLFW_LDFLAGS} ${GLEW_LIBRARIES})
