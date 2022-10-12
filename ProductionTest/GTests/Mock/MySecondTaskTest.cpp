#include "gtest/gtest.h"


extern "C" {
#include <stdio.h>
	// Header file from the production code project
//#include <MySecondTask.h>
}

// --- Create Mocks ---

// ---------------------------------------------------------------------
class MySecondTaskTest : public ::testing::Test {
protected:
	void SetUp() override {
		
	}

	void TearDown() override {}
};

// ---------------------------------------------------------------------
TEST_F(MySecondTaskTest, InitialisationIsCorrect) {
	
}


// ---------------------------------------------------------------------
TEST_F(MySecondTaskTest, InitIsCorrectFromTask) {
	
}


// ---------------------------------------------------------------------
TEST_F(MySecondTaskTest, runIsCorrectFromTask) {
	
}
