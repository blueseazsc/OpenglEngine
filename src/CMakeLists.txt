project( Test )

add_executable( main scene.cpp util.cpp vector3.cpp skybox.cpp model.cpp ground.cpp light.cpp camera.cpp sprite.cpp particle.cpp )
# add_executable( main scene_line_triangle.cpp util.cpp )

target_include_directories(main PUBLIC ${OPENGL_INCLUDE_DIR} ${GLFW_INCLUDE_DIRS} ${GLEW_INCLUDE_DIRS} ${SOIL_INCLUDE_DIRS})

target_link_libraries(main ${OPENGL_LIBRARIES} ${GLUT_LIBRARIES} ${GLFW_LDFLAGS} ${GLEW_LIBRARIES} ${SOIL_LIBRARIES})
