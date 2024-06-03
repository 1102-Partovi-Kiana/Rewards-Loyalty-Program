set(dynamicArray_SRCS dynamicArray.h dynamicArray.cpp)
add_library(dynamicArray STATIC ${dynamicArray_SRCS})
target_link_libraries(dynamicArray)
target_include_directories(dynamicArray PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})