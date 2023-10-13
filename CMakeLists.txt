cmake_minimum_required(VERSION 3.0.0)
project(ExceptionHandler VERSION 0.1.0 LANGUAGES C CXX)
project(Underlying VERSION 0.1.0 LANGUAGES C CXX)

add_subdirectory(./5_XML-Processor)

add_executable(ExceptionHandler ./1_ExceptionHandling/exception_handle.cpp)
add_executable(Underlying ./2_toUnderlying/to_underlying_example.cpp)
add_executable(DataLogging ./3_DataLogging/main.cpp)
add_executable(FF_Converter ./4_FloatingFixed-Converter/main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
