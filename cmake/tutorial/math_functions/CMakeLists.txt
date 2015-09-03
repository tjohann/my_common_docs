cmake_minimum_required(VERSION 2.8)
project(math_functions)

set(SOURCE_FILES mysqrt.cc) 
set(SOURCE_HEADERS math_functions.h)

# NOTE: 
# CMAKE_BINARY_DIR is the root BINARY_DIR 
# PROJECT_BINARY_DIR is the PROJECT root BINARY_DIR
include_directories("${CMAKE_BINARY_DIR}")

# build both ... funny that you need a new name for the static version
add_library(math_functions SHARED ${SOURCE_FILES})
add_library(math_functions-static STATIC ${SOURCE_FILES})

# set the correct names 
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-2_0")
set_target_properties(${PROJECT_NAME}-static PROPERTIES OUTPUT_NAME "${PROJECT_NAME}-2_0")

# create the needed links
set_target_properties(${PROJECT_NAME} PROPERTIES
				      VERSION ${tutorial_VERSION_MAJOR}.${tutorial_VERSION_MINOR}.${tutorial_VERSION_BUGFIX}
				      SOVERSION ${tutorial_VERSION_MAJOR}.${tutorial_VERSION_MINOR}
				      SOVERSION ${tutorial_VERSION_MAJOR})

# install all
install(TARGETS ${PROJECT_NAME} DESTINATION lib)
install(TARGETS ${PROJECT_NAME}-static DESTINATION lib)
install(FILES ${SOURCE_HEADERS} DESTINATION include)
