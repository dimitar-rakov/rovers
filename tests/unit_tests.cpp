#include <gtest/gtest.h>
#include <limits.h>
#include "data_types.hpp"
#include "helpers.h"

#include "map.h"
#include "controllers/sim_controller.h"
#include "data_parser.h"

class RoverTests :  public ::testing::Test {
     protected:
      virtual void SetUp() {  }
      virtual void TearDown() { }
};


/**  nav_map::Map tests **/
TEST_F(RoverTests, checkLimitsIn)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos(2,2);
    map.initCorners(left, right);
    EXPECT_TRUE(map.checkLimits(test_out_pos));
}

TEST_F(RoverTests, checkLimitsOutXNeg)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos(-1,2);
    map.initCorners(left, right);
    EXPECT_FALSE(map.checkLimits(test_out_pos));
}

TEST_F(RoverTests, checkLimitsOutXPos)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos(6,2);
    map.initCorners(left, right);
    EXPECT_FALSE(map.checkLimits(test_out_pos));
}

TEST_F(RoverTests, checkLimitsOutYNeg)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos(2,-1);
    map.initCorners(left, right);
    EXPECT_FALSE(map.checkLimits(test_out_pos));
}

TEST_F(RoverTests, checkLimitsOutYPos)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos(2,6);
    map.initCorners(left, right);
    EXPECT_FALSE(map.checkLimits(test_out_pos));
}

TEST_F(RoverTests, isCellFreeInMapAndFree)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos1(1,2);
    navigation::Position test_out_pos2(2,2);
    map.initCorners(left, right);
    map.setRoverPositionOnMap(test_out_pos1, "RoverX");
    EXPECT_TRUE(map.isCellFree(test_out_pos2));
}

TEST_F(RoverTests, isCellFreeInMapAndOccupied)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos1(2,2);
    navigation::Position test_out_pos2(2,2);
    map.initCorners(left, right);
    map.setRoverPositionOnMap(test_out_pos1, "RoverX");
    EXPECT_FALSE(map.isCellFree(test_out_pos2));
}

TEST_F(RoverTests, isCellFreeOutMap)
{
    nav_map::Map map;
    navigation::Position left(0,0);
    navigation::Position right(5,5);
    navigation::Position test_out_pos1(1,2);
    navigation::Position test_out_pos2(2,2);
    map.initCorners(left, right);
    map.setRoverPositionOnMap(test_out_pos1, "RoverX");
    EXPECT_FALSE(map.isCellFree(test_out_pos2));
}


/**  controller::SimController tests **/

//navigation::direction move='M';

TEST_F(RoverTests, calcNewPoseTurnLeftFromE){
  controllers::SimController sim_cntr;
  navigation::direction turnLeft='L';
  sim_cntr.setInitPose(navigation::Pose(2,2,'E'));
  navigation::Pose expectedPose(2,2,'N');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnLeft));
}

TEST_F(RoverTests, calcNewPoseTurnLeftFromS){
  controllers::SimController sim_cntr;
  navigation::direction turnLeft='L';
  sim_cntr.setInitPose(navigation::Pose(2,2,'S'));
  sim_cntr.calcNewPose(turnLeft);
  navigation::Pose expectedPose(2,2,'E');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnLeft));
}

TEST_F(RoverTests, calcNewPoseTurnLeftFromW){
  controllers::SimController sim_cntr;
  navigation::direction turnLeft='L';
  sim_cntr.setInitPose(navigation::Pose(2,2,'W'));
  sim_cntr.calcNewPose(turnLeft);
  navigation::Pose expectedPose(2,2,'S');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnLeft));
}

TEST_F(RoverTests, calcNewPoseTurnLeftFromN){
  controllers::SimController sim_cntr;
  navigation::direction turnLeft='L';
  sim_cntr.setInitPose(navigation::Pose(2,2,'N'));
  sim_cntr.calcNewPose(turnLeft);
  navigation::Pose expectedPose(2,2,'W');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnLeft));
}

TEST_F(RoverTests, calcNewPoseTurnRightFromE){
  controllers::SimController sim_cntr;
  navigation::direction turnRight='R';
  sim_cntr.setInitPose(navigation::Pose(2,2,'E'));
  navigation::Pose expectedPose(2,2,'S');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnRight));
}

TEST_F(RoverTests, calcNewPoseTurnRightFromS){
  controllers::SimController sim_cntr;
  navigation::direction turnRight='R';
  sim_cntr.setInitPose(navigation::Pose(2,2,'S'));
  sim_cntr.calcNewPose(turnRight);
  navigation::Pose expectedPose(2,2,'W');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnRight));
}

TEST_F(RoverTests, calcNewPoseTurnRightFromW){
  controllers::SimController sim_cntr;
  navigation::direction turnRight='R';
  sim_cntr.setInitPose(navigation::Pose(2,2,'W'));
  sim_cntr.calcNewPose(turnRight);
  navigation::Pose expectedPose(2,2,'N');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnRight));
}

TEST_F(RoverTests, calcNewPoseTurnRightFromN){
  controllers::SimController sim_cntr;
  navigation::direction turnRight='R';
  sim_cntr.setInitPose(navigation::Pose(2,2,'N'));
  sim_cntr.calcNewPose(turnRight);
  navigation::Pose expectedPose(2,2,'E');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(turnRight));
}

TEST_F(RoverTests, calcNewPoseMOveLeftFromE){
  controllers::SimController sim_cntr;
  navigation::direction move='M';
  sim_cntr.setInitPose(navigation::Pose(2,2,'E'));
  navigation::Pose expectedPose(3,2,'E');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(move));
}

TEST_F(RoverTests, calcNewPoseMoveDownFromS){
  controllers::SimController sim_cntr;
  navigation::direction move='M';
  sim_cntr.setInitPose(navigation::Pose(2,2,'S'));
  sim_cntr.calcNewPose(move);
  navigation::Pose expectedPose(2,1,'S');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(move));
}

TEST_F(RoverTests, calcNewPoseMoveRightFromW){
  controllers::SimController sim_cntr;
  navigation::direction move='M';
  sim_cntr.setInitPose(navigation::Pose(2,2,'W'));
  sim_cntr.calcNewPose(move);
  navigation::Pose expectedPose(1,2,'W');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(move));
}

TEST_F(RoverTests, calcNewPoseMoveUpFromN){
  controllers::SimController sim_cntr;
  navigation::direction move='M';
  sim_cntr.setInitPose(navigation::Pose(2,2,'N'));
  sim_cntr.calcNewPose(move);
  navigation::Pose expectedPose(2,3,'N');
  EXPECT_EQ( expectedPose, sim_cntr.calcNewPose(move));
}

TEST_F(RoverTests, ParserReadRightCornerFromFile){
  data_parser::DataParser dp;
  std::string filename = "nav_input_data.txt";
  std::ofstream file;
  file.open ("/tmp/"+ filename, std::ios::trunc );
  file << "5 5\n";
  file << "1 2 N\n";
  file << "LMLMLMLMM\n";
  file << "3 3 E\n";
  file << "MMRMMRMRRM\n";
  file.close();
  EXPECT_EQ( navigation::Position(5,5), dp.readRightCornerFromFile("/tmp/",filename));
}

TEST_F(RoverTests, ParserReadInitPosesFromFile){
  data_parser::DataParser dp;
  std::string filename = "nav_input_data.txt";
  std::ofstream file;
  file.open ("/tmp/"+ filename, std::ios::trunc );
  file << "5 5\n";
  file << "1 2 N\n";
  file << "LMLMLMLMM\n";
  file << "3 3 E\n";
  file << "MMRMMRMRRM\n";
  file.close();
  dp.readInitPosesFromFile("/tmp/",filename);
  EXPECT_EQ( navigation::Pose(1,2,'N'), dp.roversInitPoses()[0]);
  EXPECT_EQ( navigation::Pose(3,3,'E'), dp.roversInitPoses()[1]);
}

TEST_F(RoverTests, ParserReadDirectionsFromFile){
  data_parser::DataParser dp;
  std::string filename = "nav_input_data.txt";
  std::ofstream file;
  file.open ("/tmp/"+ filename, std::ios::trunc );
  file << "5 5\n";
  file << "1 2 N\n";
  file << "LMLMLMLMM\n";
  file << "3 3 E\n";
  file << "MMRMMRMRRM\n";
  file.close();
  dp.readDirectionsFromFile("/tmp/",filename);
  EXPECT_EQ( 'L', dp.roversDirSequences()[0][0]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[0][1]);
  EXPECT_EQ( 'L', dp.roversDirSequences()[0][2]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[0][3]);
  EXPECT_EQ( 'L', dp.roversDirSequences()[0][4]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[0][5]);
  EXPECT_EQ( 'L', dp.roversDirSequences()[0][6]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[0][7]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[0][8]);

  EXPECT_EQ( 'M', dp.roversDirSequences()[1][0]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[1][1]);
  EXPECT_EQ( 'R', dp.roversDirSequences()[1][2]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[1][3]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[1][4]);
  EXPECT_EQ( 'R', dp.roversDirSequences()[1][5]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[1][6]);
  EXPECT_EQ( 'R', dp.roversDirSequences()[1][7]);
  EXPECT_EQ( 'R', dp.roversDirSequences()[1][8]);
  EXPECT_EQ( 'M', dp.roversDirSequences()[1][9]);

}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
