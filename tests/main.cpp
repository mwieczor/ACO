#include <gtest/gtest.h>

int main( int argc, char * argv[] )
{
    // Init gtest.
    testing::InitGoogleTest( & argc, argv );
    // Run all tests.
    return RUN_ALL_TESTS();
}
