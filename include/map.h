#ifndef MAP_H
#define MAP_H

#include "data_types.hpp"
#include <vector>
#include <map>
class Map
{
public:
  Map();
  /// Upper right corner of the grid map
  navigation::Position lowerLeftCorner_;

  /// Upper right corner of the grid map
  navigation::Position upperRightCorner_;


  /**
   * Check if the desPose is in the map \todo {bind the variable in doxygen}
   * @return true if in range
   */
  inline bool checkLimits(const navigation::Pose &desPose){
    return desPose.pos.x>=lowerLeftCorner_.x && desPose.pos.x<=upperRightCorner_.x &&
           desPose.pos.y>=lowerLeftCorner_.y && desPose.pos.y<=upperRightCorner_.y;
  }


  /**
   * @brief isCellFree if the map cell with coordinates cellCoord is free  \todo {bind the variable in doxygen}
   * @return true if in range
   */
  bool isCellFree(navigation::Position cellCoord);

  /**
   * @brief setRoverPositionOnMap Set rover position on the map
   * @param roverPos Rover position
   * @param roverID Rover ID
   */
  void setRoverPositionOnMap(navigation::Position roverPos, std::string roverID);

 private:
  std::vector<std::vector<bool>> grid_;
  std::map<std::string, navigation::Position> roversPositions_;
};

#endif // MAP_H
