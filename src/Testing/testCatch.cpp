//! Test that Catch works !
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

TEST_CASE("Simple addition", "[math]"){
    REQUIRE(1 + 1 == 2);
}