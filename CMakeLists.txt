# Copyright (C) Denys Valchuk - All Rights Reserved
# ZHZhbGNodWtAZ21haWwuY29tCg==

cmake_minimum_required(VERSION 3.23)

project(algolc VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(WITH_TESTS "build tests?" ON)
set(LC_ONLY "" CACHE STRING "Regex to restrict configured problems (e.g. 0001)")

# Shared header-only helpers, reached as <dv/lc.hpp>.
add_library(common INTERFACE)
target_include_directories(common INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/common/include)

if(WITH_TESTS)
  list(APPEND CMAKE_CTEST_ARGUMENTS "--output-on-failure")
  enable_testing()

  find_package(GTest)
  include(GoogleTest)

  file(GLOB problem_dirs RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/problems
       ${CMAKE_CURRENT_SOURCE_DIR}/problems/*)
  list(SORT problem_dirs)

  foreach(dir IN LISTS problem_dirs)
    set(probdir ${CMAKE_CURRENT_SOURCE_DIR}/problems/${dir})
    if(NOT IS_DIRECTORY ${probdir})
      continue()
    endif()
    if(NOT EXISTS ${probdir}/test.cpp)
      continue()
    endif()
    if(LC_ONLY AND NOT dir MATCHES "${LC_ONLY}")
      continue()
    endif()

    string(MAKE_C_IDENTIFIER "p_${dir}" tgt)
    add_executable(${tgt} ${probdir}/test.cpp)
    target_include_directories(${tgt} PRIVATE ${probdir})
    target_link_libraries(${tgt} PRIVATE common gtest::gtest)
    gtest_discover_tests(${tgt})
  endforeach()
endif()
