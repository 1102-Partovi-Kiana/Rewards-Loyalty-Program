
set(helperFunctions_SRCS helperFunctions.h helperFunctions.cpp)
add_library(helperFunctions STATIC ${helperFunctions_SRCS})
target_link_libraries(helperFunctions customer drink food menuItem)
target_include_directories(helperFunctions PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})