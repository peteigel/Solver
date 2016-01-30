//
//  cellGroup_tests.cpp
//  solver2
//
//  Created by Pete Eigel on 8/24/15.
//  Copyright (c) 2015 Pete Eigel. All rights reserved.
//

#include "catch.hpp"
#include "cell.h"
#include "cellGroup.h"

SCENARIO("A CellGroup is constructed") {
    CellGroup testGroup;
    
    WHEN("filled with Cell pointers") {
        Cell cells[9];
        
        for (int i = 0; i < 9; i++) {
            testGroup.setCell(i, &cells[i]);
        }
        
        THEN("getCell() gives us the pointers we set") {
            for (int i = 0; i < 9; i++) {
                REQUIRE(testGroup.getCell(i) == &cells[i]);
            }
        }
        
        WHEN("A cell has a set value") {
            cells[2].setValue(3);
            
            THEN("that value is determined") {
                REQUIRE(testGroup.isDetermined(3));
            }
            
            THEN("other values are undetermined") {
                REQUIRE(!testGroup.isDetermined(6));
            }
        }
    }
}