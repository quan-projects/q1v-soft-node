include_directories(${CMAKE_CURRENT_SOURCE_DIR}/q1v/external/miniupnpc-2.2.7/lib/cmake)

find_package (miniupnpc REQUIRED PATHS ${CMAKE_CURRENT_SOURCE_DIR}/q1v/external/miniupnpc-2.2.7 NO_DEFAULT_PATH)

if (TARGET miniupnpc::miniupnpc)
    message(STATUS "libminiupnpc loaded")
endif()