 include(FetchContent)

# 下载 GoogleTest
 FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)
FetchContent_MakeAvailable(googletest)

# 添加测试可执行文件
add_executable(test_Validator test_Validator.cpp)
# 链接gtest库
target_link_libraries(test_Validator GTest::gtest_main)
add_test(NAME test_Validator COMMAND test_Validator)

add_executable(test_binarySearch ./Search/binarySearch/test_binarySearch.cpp)
target_link_libraries(test_binarySearch GTest::gtest_main)
add_test(NAME test_binarySearch COMMAND test_binarySearch)

add_executable(test_bubbleSort ./Sort/bubbleSort/test_bubbleSort.cpp)
target_link_libraries(test_bubbleSort GTest::gtest_main)
add_test(NAME test_bubbleSort COMMAND test_bubbleSort)

add_executable(test_insertSort ./Sort/insertSort/test_insertSort.cpp)
target_link_libraries(test_insertSort GTest::gtest_main)
add_test(NAME test_insertSort COMMAND test_insertSort)

add_executable(test_selectSort ./Sort/selectSort/test_selectSort.cpp)
target_link_libraries(test_selectSort GTest::gtest_main)
add_test(NAME test_selectSort COMMAND test_selectSort)