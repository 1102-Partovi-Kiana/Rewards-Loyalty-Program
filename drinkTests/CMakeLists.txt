file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(drinkTests ${SRCS})
TARGET_LINK_LIBRARIES(drinkTests libgtest libgmock drink menuItem helperFunctions customer food)
add_test(NAME drinkTests COMMAND drinkTests)