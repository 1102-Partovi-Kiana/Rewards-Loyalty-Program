file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(foodTests ${SRCS})
TARGET_LINK_LIBRARIES(foodTests libgtest libgmock food customer menuItem helperFunctions)
add_test(NAME foodTests COMMAND foodTests)