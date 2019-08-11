#ifndef MAP_H
#define MAP_H

#include "data_types.hpp"
#include <vector>
#include <map>

namespace nav_map
{
class Map
{
public:
  Map();
  /// Upper right corner of the grid map
  navigation::Position lowerLeftCorner_;

  /// Upper right corner of the grid map
  navigation::Position upperRightCorner_;
  std::array<std::array<bool, 100>, 100> grid_;
  std::map<std::string, navigation::Position> roversPositions_;


  /**
   * Check if the desPose is in the map \todo {bind the variable in doxygen}
   * @return true if in range
   */
  inline void initCorners(const navigation::Position lowerLeftCornerPos,
                          const navigation::Position upperRightCornerPos){
    lowerLeftCorner_ = lowerLeftCornerPos;
    upperRightCorner_= upperRightCornerPos;
  }

  /**
   * Check if the desPose is in the map \todo {bind the variable in doxygen}
   * @return true if in range
   */
  inline bool checkLimits(const navigation::Position &desPos){
    return desPos.x>=lowerLeftCorner_.x && desPos.x<=upperRightCorner_.x &&
           desPos.y>=lowerLeftCorner_.y && desPos.y<=upperRightCorner_.y;
  }

  /**
   * @brief isCellFree if the map cell with coordinates cellCoord is free  \todo {bind the variable in doxygen}
   * @return true if it is not occupied
   */
  inline bool isCellFree(navigation::Position cellCoord){
    if(!checkLimits(cellCoord))
      return false;
    else
      return !grid_[cellCoord.x][cellCoord.y];
  }

  /**
   * @brief setRoverPositionOnMap Set rover position on the map
   * @param roverPos Rover position
   * @param roverID Rover ID
   */
  void setRoverPositionOnMap(navigation::Position roverPos, std::string roverID);

 private:

};
}
#endif // MAP_H
