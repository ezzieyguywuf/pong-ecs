cmake_minimum_required(VERSION 3.7)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS} "-Wall -Wno-long-long -pedantic -pg")
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_BUILD_TYPE "Debug")
#set_property(
    #GLOBAL PROPERTY 
    #RULE_LAUNCH_COMPILE 
    #"gccfilter -r -c -p -w")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

project(pong)

#set(SFML_DIR "/home/wolfie/Program/FunProjects/SFML-2.4.2/")
set(SFML_DIR "/usr/include/SFML")
#set(JPEG_DIR "/home/wolfie/Program/FunProjects/libjpeg-turbo/build")

include_directories(
    #"${SFML_DIR}/include"
    "${SFML_DIR}"
    "src"
)
link_directories(
    #"${SFML_DIR}/lib"
)

add_subdirectory("src")
