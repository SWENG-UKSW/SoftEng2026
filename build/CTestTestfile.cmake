# CMake generated Testfile for 
# Source directory: C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026
# Build directory: C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
if(CTEST_CONFIGURATION_TYPE MATCHES "^([Dd][Ee][Bb][Uu][Gg])$")
  add_test(test_shape1 "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/build/Debug/test_shape1.exe")
  set_tests_properties(test_shape1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;46;add_test;C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ee][Aa][Ss][Ee])$")
  add_test(test_shape1 "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/build/Release/test_shape1.exe")
  set_tests_properties(test_shape1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;46;add_test;C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Mm][Ii][Nn][Ss][Ii][Zz][Ee][Rr][Ee][Ll])$")
  add_test(test_shape1 "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/build/MinSizeRel/test_shape1.exe")
  set_tests_properties(test_shape1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;46;add_test;C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;0;")
elseif(CTEST_CONFIGURATION_TYPE MATCHES "^([Rr][Ee][Ll][Ww][Ii][Tt][Hh][Dd][Ee][Bb][Ii][Nn][Ff][Oo])$")
  add_test(test_shape1 "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/build/RelWithDebInfo/test_shape1.exe")
  set_tests_properties(test_shape1 PROPERTIES  _BACKTRACE_TRIPLES "C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;46;add_test;C:/Users/Dawid/Desktop/SoftEng2026/SoftEng2026/CMakeLists.txt;0;")
else()
  add_test(test_shape1 NOT_AVAILABLE)
endif()
subdirs("externals/googletest")
