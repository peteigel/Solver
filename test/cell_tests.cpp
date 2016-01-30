//
//  cell_tests.cpp
//  solver2
//
//  Created by Pete Eigel on 8/12/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "catch.hpp"
#include "cell.h"

SCENARIO("A cell is constructed", "[cell]") {
    WHEN("No value is given") {
        Cell testCell {};
        
        THEN("Value is defaulted to zero") {
            REQUIRE(testCell.getValue() == 0);
        }
        
        THEN("1 through 9 are possible") {
            for (short i = 1; i <= 9; i++) {
                REQUIRE(testCell.isPossible(i));
            }
        }
        
        THEN("Nine values are possible") {
            REQUIRE(testCell.numPossible() == 9);
            
        }
    }
    
    WHEN("Value is given") {
        Cell testCell {4};
        
        THEN("Value is what we set") {
            REQUIRE(testCell.getValue() == 4);
        }
        
        THEN("The value we set is possible") {
            REQUIRE(testCell.isPossible(4));
        }
        
        THEN("Other values aren't possible") {
            REQUIRE(! testCell.isPossible(1));
            REQUIRE(! testCell.isPossible(3));
            REQUIRE(! testCell.isPossible(5));
            REQUIRE(! testCell.isPossible(8));
            REQUIRE(! testCell.isPossible(9));
        }
        
        THEN("Only one value is possilbe") {
            REQUIRE(testCell.numPossible() == 1);
        }
    }
}
