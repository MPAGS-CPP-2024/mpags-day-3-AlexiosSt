# - Build sub-script for the MPAGSCipher library unit tests

# - Most basic test
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)

# - First catch-based test
add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test-catch COMMAND testCatch)

# - Test the transliteration function
add_executable(testTransformChar testTransformChar.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
target_link_libraries(testTransformChar PRIVATE MPAGSCipher)
add_test(NAME test-transformchar COMMAND testTransformChar)