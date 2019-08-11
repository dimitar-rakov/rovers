#include <gtest/gtest.h>
#include "controllers/controller.h"
#include "controllers/sim_controller.h"

void  test();

int testRepeater(int a) { return a;}




class MapTest :  public ::testing::Test {
     protected:
      virtual void SetUp() {  }
      virtual void TearDown() { }
};

TEST_F(MapTest, testRepeater)
{
    EXPECT_EQ(42, testRepeater(42));
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
