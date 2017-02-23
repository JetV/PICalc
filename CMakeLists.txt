cmake_minimum_required(VERSION 2.8)

project(PICalc)
add_executable(${PROJECT_NAME} "main.cpp" Abstract_solver.cpp Abstract_solver.h PIC_solver.cpp PIC_solver.h Particle_type.cpp Particle_type.h constants.h Particle.cpp Particle.h Grid.cpp Grid.h math_functions.cpp math_functions.h)
