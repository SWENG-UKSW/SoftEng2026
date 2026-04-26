cmake_minimum_required(VERSION 3.10)
project(ShapeLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC")
endif()

file(GLOB SOURCES CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.cpp"
)

file(GLOB HEADERS CONFIGURE_DEPENDS
     "${CMAKE_SOURCE_DIR}/src/*.h"
)

add_library(ShapeLib STATIC ${SOURCES} ${HEADERS})

target_compile_definitions(ShapeLib PRIVATE BUILDING_CLIENT_DLL)

enable_testing()

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
add_subdirectory(externals/googletest)

# Test Pyramid
add_executable(test_pyramid src/tests/smoke/test_pyramid.cpp)
target_link_libraries(test_pyramid gtest gtest_main ShapeLib)
target_include_directories(test_pyramid PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_pyramid COMMAND test_pyramid)

# Test Circle (z obsługą ujemnego promienia)
add_executable(test_circle src/tests/smoke/test_circle.cpp)
target_link_libraries(test_circle gtest gtest_main ShapeLib)
target_include_directories(test_circle PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_circle COMMAND test_circle)

# Test Performance (100 iteracji, < 1ms, multi-type, unique_ptr)
add_executable(test_performance src/tests/test_performance.cpp)
target_link_libraries(test_performance gtest gtest_main ShapeLib)
target_include_directories(test_performance PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src PRIVATE ${PROJECT_BINARY_DIR})
add_test(NAME test_performance COMMAND test_performance)
