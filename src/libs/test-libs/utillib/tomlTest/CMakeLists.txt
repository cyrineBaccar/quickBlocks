# minimum cmake version supported
cmake_minimum_required (VERSION 2.6)

# application project
project (tomlTest)

# The sources to be used
file(GLOB SOURCE_FILES "*.cpp")

# Output
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/../bin/test")

# Define the executable to be generated
set(TOOL_NAME "tomlTest")
set(PROJ_NAME "libs/utillib")
add_executable(${TOOL_NAME} ${SOURCE_FILES})

# Add the project static libs at linking
target_link_libraries (${TOOL_NAME} wallet token ${BASE_LIBS})

# Testing
# Define paths to test folder and gold folder
set(TEST_EXE "${EXECUTABLE_OUTPUT_PATH}/${TOOL_NAME}")
set(TEST_PATH "${TEST_PATH}/${PROJ_NAME}/${TOOL_NAME}")
set(GOLD_PATH "${GOLD_PATH}/${PROJ_NAME}/${TOOL_NAME}")

# Additional target to make the README.md
build_readme(${CMAKE_CURRENT_SOURCE_DIR} ${TOOL_NAME})

# Function to run an special or slow test case
function(run_special_test testName)
    run_the_special_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_special_test)

# Function to run an individual test case
function(run_test testName)
     run_the_test(${TEST_PATH} ${GOLD_PATH} ${testName} ${TEST_EXE} ${ARGN})
endfunction(run_test)

# Enter one line for each individual test
#
#   NOTE: OTHER THAN EMPTY.TOML, THESE FILES HAVE NO
#   PARTICULAR MEANING. I JUST COLLECTED THEM
#
run_test("tomlTest_empty"  "empty.toml")
run_test("tomlTest_test00" "test00.toml")
run_test("tomlTest_test01" "test01.toml")
run_test("tomlTest_test02" "test02.toml")
run_test("tomlTest_test03" "test03.toml")
run_test("tomlTest_test04" "test04.toml")
run_test("tomlTest_test05" "test05.toml")
run_test("tomlTest_test06" "test06.toml")
run_test("tomlTest_test07" "test07.toml")
run_test("tomlTest_test08" "test08.toml")
run_test("tomlTest_test09" "test09.toml")
run_test("tomlTest_test10" "test10.toml")
run_test("tomlTest_test11" "test11.toml")
run_test("tomlTest_test12" "test12.toml")
run_test("tomlTest_test13" "test13.toml")
run_test("tomlTest_test14" "test14.toml")
