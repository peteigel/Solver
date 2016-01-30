//
//  possiblities_tests.cpp
//  solver2
//
//  Created by Pete Eigel on 8/23/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "catch.hpp"
#include "possibilities.h"

SCENARIO("A new Possibilites object is constructed") {
    WHEN("Only max is given") {
        Possibilities testP {13};
        
        THEN("0 to max are impossible") {
            for (short i = 0; i <= 13; i++) {
                REQUIRE(! testP.isPossible(i));
            }
        }
    }
    
    WHEN("min and max are given") {
        Possibilities testP {3, 12};
        
        THEN("min to max are impossible") {
            for (short i = 3; i <= 12; i++) {
                REQUIRE(! testP.isPossible(i));
            }
        }
    }
    
    WHEN("setAll(true)") {
        Possibilities testP {1, 9};
        testP.setAll(true);
        
        THEN("min to max are possible") {
            for (short i = 1; i <= 9; i++) {
                REQUIRE(testP.isPossible(i));
            }
        }
    }
    
    WHEN("setPossible(n)") {
        Possibilities testP {1, 9};
        testP.setPossible(4);
        
        THEN("n is possible") {
            REQUIRE(testP.isPossible(4));
        }
        
        THEN("Other values is impossible") {
            REQUIRE(! testP.isPossible(1));
            REQUIRE(! testP.isPossible(9));
            REQUIRE(! testP.isPossible(3));
            REQUIRE(! testP.isPossible(5));
            REQUIRE(! testP.isPossible(2));
        }
        
        THEN("firstPossible() returns n") {
            REQUIRE(testP.firstPossible() == 4);
        }
    }
    
    WHEN("setImpossible(n)") {
        Possibilities testP {1, 9};
        testP.setPossible(4);
        testP.setPossible(1);
        testP.setPossible(6);
        
        testP.setImpossible(6);
        
        THEN("n is impossible") {
            REQUIRE(! testP.isPossible(6));
        }
        
        THEN("Other values are unaffected") {
            REQUIRE(testP.isPossible(1));
            REQUIRE(testP.isPossible(4));
            
            REQUIRE(! testP.isPossible(9));
            REQUIRE(! testP.isPossible(5));
            REQUIRE(! testP.isPossible(2));
        }
    }
    
    WHEN("n values are set possible") {
        Possibilities testP {1, 9};
        
        testP.setPossible(4);
        testP.setPossible(1);
        testP.setPossible(9);
        
        THEN("n values are possible") {
            REQUIRE(testP.numPossible() == 3);
        }
    }
}