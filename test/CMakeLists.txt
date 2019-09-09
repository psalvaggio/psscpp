include_directories(${CMAKE_SOURCE_DIR}/include)

include(ExternalProject)
find_package(Git REQUIRED)

ExternalProject_Add(
  doctest
  PREFIX ${CMAKE_BINARY_DIR}/test/doctest
  GIT_REPOSITORY https://github.com/onqtam/doctest
  TIMEOUT 10
  UPDATE_COMMAND ${GIT_EXECUTABLE} pull
  CONFIGURE_COMMAND ""
  BUILD_COMMAND ""
  INSTALL_COMMAND ""
  LOG_DOWNLOAD ON
)

# Everything in this directory gets can include doctest
ExternalProject_Get_Property(doctest source_dir)
include_directories(${source_dir})

add_executable(AlgorithmTest algorithm_test.cpp)
add_executable(TypeTraitsTest type_traits_test.cpp)
