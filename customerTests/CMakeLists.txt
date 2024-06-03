file(GLOB SRCS *.cpp)
ADD_EXECUTABLE(customerTests ${SRCS})
TARGET_LINK_LIBRARIES(customerTests libgtest libgmock customer menuItem food drink helperFunctions)
add_test(NAME customerTests COMMAND customerTests)
#target_link_libraries(customerTests gtest_main customer)



