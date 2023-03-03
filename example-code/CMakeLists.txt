add_executable(yavl_cpp_example checker.cpp)
target_link_libraries(yavl_cpp_example PUBLIC yaml-cpp yavl-cpp)

install(TARGETS yavl_cpp_example RUNTIME DESTINATION "${CMAKE_INSTALL_BINDIR}")
