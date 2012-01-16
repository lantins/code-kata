enable_testing()

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.c)
add_executable(unit-tests ${TEST_SRC_FILES})
target_link_libraries(unit-tests tic-tac-toe)