cmake_minimum_required(VERSION 2.4.7)
PROJECT(odroid_indi_roof CXX C)

set(CMAKE_CXX_FLAGS "-o -lwiringPi -lpthread  -std=c++0x ${CMAKE_CXX_FLAGS}")

set(CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake_modules/")
set (VERSION_MAJOR 0)
set (VERSION_MINOR 2)

find_package(INDI REQUIRED)
find_package(Nova REQUIRED)
# Locate libraries and headers
find_package(WiringPi REQUIRED)
find_package(Threads REQUIRED)

# Include headers
include_directories(${WIRINGPI_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
include_directories(${INDI_INCLUDE_DIR})
include_directories(${NOVA_INCLUDE_DIR})

################ Roll Off ################
set(gpiorolloff_SRCS
        ${CMAKE_CURRENT_SOURCE_DIR}/gpioroof.cpp
   )

cmake_policy(SET CMP0003 OLD)
add_executable(indi_roof_gpio ${gpiorolloff_SRCS})
target_link_libraries(indi_roof_gpio ${INDI_DRIVER_LIBRARIES})
target_link_libraries(indi_roof_gpio ${WIRINGPI_LIBRARIES} rt)
target_link_libraries(indi_roof_gpio ${CMAKE_THREAD_LIBS_INIT})
install(TARGETS indi_roof_gpio RUNTIME DESTINATION bin )
install(FILES indi_roof_gpio.xml DESTINATION ${INDI_DATA_DIR})

