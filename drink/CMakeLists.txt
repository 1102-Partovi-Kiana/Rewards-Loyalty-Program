set(drink_SRCS drink.h drink.cpp)
add_library(drink STATIC ${drink_SRCS})
target_link_libraries(drink menuItem)
target_include_directories(drink PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})