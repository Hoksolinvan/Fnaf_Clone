cmake_minimum_required(VERSION 3.20)

project(fnaf_1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)



list(APPEND CMAKE_PREFIX_PATH
 "${CMAKE_SOURCE_DIR}/external/SDL3"
 "${CMAKE_SOURCE_DIR}/external/SDL3_image"
 "${CMAKE_SOURCE_DIR}/external/SDL3_ttf/SDL3_ttf.framework/Versions/A/Resources/CMake"
 "${CMAKE_SOURCE_DIR}/external/SDL3_mixer/SDL3_mixer.framework/Versions/A/Resources/CMake"

)


find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_mixer REQUIRED)

add_executable(fnaf_1 src/main.cpp src/mainmenu.cpp src/mainoffice.cpp)
file(COPY ${CMAKE_SOURCE_DIR}/assets DESTINATION ${CMAKE_BINARY_DIR})
file(COPY ${CMAKE_SOURCE_DIR}/external/textfiles
     DESTINATION ${CMAKE_BINARY_DIR}/external)
target_link_libraries(fnaf_1 PRIVATE SDL3::SDL3 SDL3_image::SDL3_image "${CMAKE_SOURCE_DIR}/external/SDL3_ttf/SDL3_ttf.framework/SDL3_ttf"
"${CMAKE_SOURCE_DIR}/external/SDL3_mixer/SDL3_mixer.framework/SDL3_mixer")