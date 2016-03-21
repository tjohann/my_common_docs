cmake_minimum_required(VERSION 2.8)
project(tutorial)
# NOTE:
# for using a specific config use this lines (save configure time)
#project(tutorial CXX)
#project(tutorial C)
#project(tutorial) -> use both

# here are my source files
set(SOURCE_FILES tutorial.cc)

set(CMAKE_CXX_FLAGS "-g -Wall -std=c++11")
set(CMAKE_C_FLAGS "-g -Wall -std=c11")

set(tutorial_VERSION_MAJOR 1)
set(tutorial_VERSION_MINOR 0)
set(tutorial_VERSION_BUGFIX 0)

# use my math_functions ?
option (USE_MYMATH "Use my math function library" ON)

configure_file (
"${PROJECT_SOURCE_DIR}/config.h.in"
"${PROJECT_BINARY_DIR}/config.h"
)

# add binary to include path
include_directories("${PROJECT_BINARY_DIR}")

# for general setting ... only one works
#set(BUILD_SHARED_LIBS ON)
#set(BUILD_STATIC_LIBS ON)

# check needed includes
include(CheckIncludeFile)
check_include_file(unistd.h HAVE_UNISTD)

if (USE_MYMATH)
# add my math_function lib
  include_directories("${PROJECT_SOURCE_DIR}/math_functions")
  add_subdirectory(math_functions)
# NOTE:
# if you want to use static or shared libs ... set the correct
# dont forget to take a look at the math_functions/CMakeList.txt
# set(EXTRA_LIBS ${EXTRA_LIBS} math_functions-static)
# set(EXTRA_LIBS ${EXTRA_LIBS} math_functions)
# NOTE:
# ${EXTRA_LIBS} is empty because this is the first content
# so i dont read it because it generates warnings with cmake-gui ...
# next libs add must use the lines above
  set(EXTRA_LIBS math_functions)
endif(USE_MYMATH)

# create executable
add_executable(${PROJECT_NAME} ${SOURCE_FILES})
target_link_libraries(${PROJECT_NAME} ${EXTRA_LIBS})

# install all
install(TARGETS ${PROJECT_NAME} DESTINATION bin)
