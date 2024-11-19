# - Build sub-script for the MPAGSCipher library unit tests

# - Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# - Create Interface Library for Catch
add_library(Catch INTERFACE)
target_include_directories(Catch INTERFACE ${CMAKE_CURRENT_LIST_DIR})
target_compile_features(Catch INTERFACE cxx_noexcept)

# - First catch-based test
add_executable(testCatch testCatch.cpp)
target_link_libraries(testCatch PRIVATE Catch)
add_test(NAME test-catch COMMAND testCatch)

# - Test the transliteration function
#add_executable(testTransformChar testTransformChar.cpp)
#target_link_libraries(testTransformChar PRIVATE Catch MPAGSCipher)
#add_test(NAME test-transformchar COMMAND testTransformChar)

# - Test the process command line code
add_executable(testProcessCmdLine testProcessCommandLine.cpp)
target_link_libraries(testProcessCmdLine PRIVATE Catch MPAGSCipher)
add_test(NAME test-processcmdline COMMAND testProcessCmdLine)

# - Test the process command line code - V2
add_executable(testProcessCmdLineV2 testProcessCommandLineV2.cpp)
target_link_libraries(testProcessCmdLineV2 PRIVATE Catch MPAGSCipher)
add_test(NAME test-processcmdlinev2 COMMAND testProcessCmdLineV2)