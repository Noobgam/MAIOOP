cmake_minimum_required(VERSION 2.8)

project(MAIOOP2)

include_directories(${BIGINT_SOURCE_DIR})

add_executable(main
              main.cpp  Hexagon.cpp  HexagonList.cpp  HexagonListItem.cpp)

if(CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -fno-exceptions -std=c++11 -pedantic -fexceptions")
  set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -fexceptions -fsanitize=address,undefined")
endif()

target_link_libraries(main -lpthread)
