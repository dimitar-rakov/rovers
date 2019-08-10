#include "map.h"

Map::Map(){}

void Map::setRoverPositionOnMap(navigation::Position roverPos, std::string roverID){
  if (isCellFree(roverPos)){
    grid_[roverPos.x][roverPos.y] = true;
    roversPositions_[roverID] = roverPos;
  }

}
