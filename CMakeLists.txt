# Minimum version of CMake required
cmake_minimum_required(VERSION 3.10)

# Project name and version
project(CAPai VERSION 1.0)

# Specify the C++ standard (C++14 or later for better features)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the include directory
include_directories(${CMAKE_SOURCE_DIR}/include/matrix)

# Add source files
set(SOURCES
    src/matrix/Matrix.cpp
    src/main.cpp
)

# Define the executable (name of the output binary)
add_executable(CAPai ${SOURCES})



#####################
###    Testing    ###
#####################

# Google Test
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Add test executable
add_executable(MatrixTest ${CMAKE_CURRENT_SOURCE_DIR}/tests/matrix/MatrixTest.cpp ${CMAKE_CURRENT_SOURCE_DIR}/src/matrix/Matrix.cpp)
target_link_libraries(MatrixTest ${GTEST_LIBRARIES} pthread)

set(CTEST_OUTPUT_ON_FAILURE TRUE)

# Add tests
add_test(NAME MatrixTest COMMAND MatrixTest)

# Custom target to run tests with verbose output
add_custom_target(run_tests
    COMMAND ${CMAKE_CTEST_COMMAND} -V
    DEPENDS MatrixTest
    WORKING_DIRECTORY ${CMAKE_BINARY_DIR}
)


#####################
### Documentation ###
#####################

# Find Doxygen package
find_package(Doxygen)

# message("Source dir: " ${CMAKE_CURRENT_SOURCE_DIR}/docs)

# find_package(Doxygen)
# option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" ${DOXYGEN_FOUND})

# if(BUILD_DOCUMENTATION)
#     if(NOT DOXYGEN_FOUND)
#          message(FATAL_ERROR "Doxygen is needed to build the documentation.")
#     endif()

#     set(DOXYGEN_IN ${CMAKE_CURRENT_SOURCE_DIR}/Doxyfile.in)
#     set(DOXYGEN_OUT ${CMAKE_CURRENT_BINARY_DIR}/Doxyfile)

#     configure_file(${DOXYGEN_IN} ${DOXYGEN_OUT} @ONLY)

#     message("Doxygen build started.")

#     add_custom_target(
#         doc_doxygen ALL
#         COMMAND ${CMAKE_COMMAND} -E make_directory ${CMAKE_SOURCE_DIR}
#         # COMMAND $<$<CONFIG:Release>:${DOXYGEN_EXECUTABLE} ${doxyfile_in}>
#         COMMAND ${DOXYGEN_EXECUTABLE} ${DOXYGEN_OUT}
#         WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
#         COMMENT "Generating API documentation with Doxygen"
#         VERBATIM
#     )

#     #    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/html DESTINATION     share/doc)
# endif()
