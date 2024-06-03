set(menuItem_SRCS menuItem.h menuItem.cpp)
add_library(menuItem STATIC ${menuItem_SRCS})
target_link_libraries(menuItem)
target_include_directories(menuItem PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})