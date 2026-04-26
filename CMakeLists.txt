cmake_minimum_required(VERSION 3.10)
project(ShapeLib)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Konfiguracja flag kompilatora dla MSVC i innych
if(MSVC)
    set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /MDd")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MDd")
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MD")
    add_definitions(-D_CRT_SECURE_NO_WARNINGS)
else()
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fPIC -Wall -Wextra")
endif()

# Pobieranie plików źródłowych (bez testów!)
file(GLOB SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.cpp")
file(GLOB HEADERS CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/src/*.h")

# Tworzenie biblioteki głównej
add_library(ShapeLib STATIC ${SOURCES} ${HEADERS})
target_include_directories(ShapeLib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Konfiguracja GoogleTest
enable_testing()
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
# Upewnij się, że ścieżka do externals jest poprawna
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/externals/googletest/CMakeLists.txt")
    add_subdirectory(externals/googletest)
endif()

# Tworzenie wykonywalnego pliku testowego
# Łączymy test_shape1.cpp i Twój nowy test_hex.cpp
add_executable(test_shape1 
    src/tests/smoke/test_shape1.cpp 
    src/tests/smoke/test_hex.cpp
)

# Linkowanie bibliotek i ustawienie inkludów
target_link_libraries(test_shape1 PRIVATE gtest gtest_main ShapeLib)
target_include_directories(test_shape1 PRIVATE ${PROJECT_BINARY_DIR})

# Rejestracja testu w systemie ctest
add_test(NAME test_shape1 COMMAND test_shape1)