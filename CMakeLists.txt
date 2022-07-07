cmake_minimum_required(VERSION 2.8.9)

project(proj_5)

include_directories(include)

set(CAR_SOURCES src/Car/Car.cpp)

add_library(Car ${CAR_SOURCES}) 

set(VEHICLE_SOURCES src/Vehicle/Vehicle.cpp)

add_library(Vehicle ${VEHICLE_SOURCES})

add_executable(proj5 src/proj5.cpp)

target_link_libraries(proj5 Vehicle Car)

install(TARGETS proj5 Vehicle Car
	RUNTIME DESTINATION ${PROJECT_SOURCE_DIR}/devel/bin
	LIBRARY DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib
	ARCHIVE DESTINATION ${PROJECT_SOURCE_DIR}/devel/lib/static)

install(DIRECTORY ${PROJECT_SOURCE_DIR}/include/
	DESTINATION ${PROJECT_SOURCE_DIR}/devel/include
	FILES_MATCHING PATTERN "*.h" PATTERN "*.hpp")