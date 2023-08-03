cmake_minimum_required(VERSION 3.0.0)
project(ExceptionHandler VERSION 0.1.0 LANGUAGES C CXX)
project(Underlying VERSION 0.1.0 LANGUAGES C CXX)

add_executable(ExceptionHandler ./1_ExceptionHandling/exception_handle.cpp)
add_executable(Underlying ./2_toUnderlying/to_underlying_example.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})