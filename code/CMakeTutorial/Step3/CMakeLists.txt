cmake_minimum_required (VERSION 2.6)

project (Tutorial_CodeTestingInstall)

# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

# should we use our own math functions
option(USE_MYMATH "Use tutorial provided math implementation" ON)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file (
  "${PROJECT_SOURCE_DIR}/TutorialConfig.h.in"
  "${PROJECT_BINARY_DIR}/TutorialConfig.h"
  )

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories ("${PROJECT_BINARY_DIR}")

# add the MathFunctions library?
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/MathFunctions")
  add_subdirectory (MathFunctions)
  set (EXTRA_LIBS ${EXTRA_LIBS} HomeBrewedMathLib)
endif ()

# add the executable
add_executable (dansTutorial tutorial.cxx)
target_link_libraries (dansTutorial  ${EXTRA_LIBS})

# add the install targets
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX "/c/Users/negrut/bin" CACHE PATH "overwrite default" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

install (TARGETS dansTutorial DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)

# enable testing
enable_testing ()

# does the application run
add_test (TutorialRuns dansTutorial 25)

# does it do sqrt of 25?
add_test (TutorialComp25 dansTutorial 25)
set_tests_properties (TutorialComp25
  PROPERTIES PASS_REGULAR_EXPRESSION "25 is 5"
  )

# does it handle negative numbers?
add_test (TutorialNegative dansTutorial -25)
set_tests_properties (TutorialNegative
  PROPERTIES PASS_REGULAR_EXPRESSION "-25 is 0"
  )

# does it handle small numbers?
add_test (TutorialSmall dansTutorial 0.0001)
set_tests_properties (TutorialSmall
  PROPERTIES PASS_REGULAR_EXPRESSION "0.0001 is 0.01"
  )

# does the usage message work?
add_test (TutorialUsage dansTutorial)
set_tests_properties (TutorialUsage
  PROPERTIES
  PASS_REGULAR_EXPRESSION "Usage:.*number"
  )
