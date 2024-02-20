# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
#Boost 1.82 requires CMake 3.27.0 or newer.
cmake_minimum_required (VERSION 3.27.0)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

#include(CMakePrintHelpers)

project ("Classifier" VERSION 1.0)

# Include sub-projects.
add_subdirectory ("Classifier")

#boost
set(Boost_USE_STATIC_LIBS        ON)
set(Boost_USE_DEBUG_LIBS         ON)
set(Boost_USE_RELEASE_LIBS       ON)
set(Boost_USE_MULTITHREADED      ON)
set(Boost_USE_STATIC_RUNTIME    OFF)
find_package(Boost 1.82.0 COMPONENTS date_time filesystem system)
if(Boost_FOUND)
  target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})
  #cmake_print_variables(Boost_LIBRARIES)
  target_link_libraries(Classifier ${Boost_LIBRARIES})
endif()