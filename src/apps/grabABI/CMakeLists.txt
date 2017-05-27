# minimum cmake version supported
cmake_minimum_required (VERSION 2.6)

# project
project (grabABI)

# c++ compilation flags used everywhere
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall -O2 -stdlib=libc++")

# Libraries shared by all the modules
set(PROJECT_LIBS_PATH "${CMAKE_SOURCE_DIR}/libs")
file(GLOB PROJECT_STATIC_LIBS "${PROJECT_LIBS_PATH}/*.a")
set(PROJECT_INCLUDES "${PROJECT_LIBS_PATH}/include")
include_directories(${PROJECT_INCLUDES})

# The sources to be used
file(GLOB SOURCE_FILES "*.cpp")

# Output
set(EXECUTABLE_OUTPUT_PATH "${CMAKE_SOURCE_DIR}/../bin")

# Define the executable to be generated
add_executable(grabABI ${SOURCE_FILES})

# We will require the CURL library installed 
# If found add its include path to includes section and link with it
find_package (CURL REQUIRED)
if (CURL_FOUND)
        include_directories(${CURL_INCLUDE_DIRS})
        target_link_libraries (grabABI ${CURL_LIBRARIES})
endif (CURL_FOUND)

# Add the project static libs at linking
target_link_libraries (grabABI ${PROJECT_STATIC_LIBS})

# plint target
set(CURRENT_TOOL_PATH "${CMAKE_SOURCE_DIR}/apps/grabABI")
add_custom_target(${LINT_TARGET}
        COMMAND ${PYLINT_CMD} ${SOURCE_FILES}
        WORKING_DIRECTORY ${CURRENT_TOOL_PATH}
        COMMENT "Running pylint for ${TOOL_NAME}"
        VERBATIM)
