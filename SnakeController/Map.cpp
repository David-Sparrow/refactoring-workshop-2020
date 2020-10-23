#include "Map.h"

bool Map::isPositionOutsideMap(int x, int y) const {
    return x < 0 or y < 0 or x >= m_mapDimension.first or y >= m_mapDimension.second;
}

bool Map::isSegmentAtPosition(int x, int y) const {
    return m_segments.end() !=  std::find_if(m_segments.cbegin(), m_segments.cend(),
                                             [x, y](auto const& segment){ return segment.x == x and segment.y == y; });
}

bool Map::isHorizontal(Direction direction) {
    return Direction_LEFT == direction or Direction_RIGHT == direction;
}

bool Map::isVertical(Direction direction) {
    return Direction_UP == direction or Direction_DOWN == direction;
}

bool Map::isPositive(Direction direction) {
    return (isVertical(direction) and Direction_DOWN == direction)
           or (isHorizontal(direction) and Direction_RIGHT == direction);
}

bool Map::perpendicular(Direction dir1, Direction dir2) {
    return isHorizontal(dir1) == isVertical(dir2);
}
