enable_testing()

add_subdirectory(../../external/googletest external/googletest)

set(TEST_SOURCES
    Kalkulator_dla_elektronikow_GTest.cpp
)

add_executable(KalkulatorGTest ${TEST_SOURCES})

target_link_libraries(KalkulatorGTest
    gtest
    gtest_main
    KalkulatorLib 
)

add_test(NAME KalkulatorUnitTests COMMAND KalkulatorGTest)
