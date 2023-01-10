cmake_minimum_required(VERSION 3.10)
project(mts-status VERSION 1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)

add_executable(${PROJECT_NAME}
               src/main.cpp
               libs/MTS-ESP/Client/libMTSClient.cpp
               libs/MTS-ESP/Master/libMTSMaster.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC libs/MTS-ESP/Client libs/MTS-ESP/Master)

if (UNIX AND NOT APPLE)
   target_link_libraries(${PROJECT_NAME} PUBLIC dl)
endif()
               
