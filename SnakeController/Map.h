//
// Created by student on 23.10.2020.
//

#ifndef REFACTORINGWORKSHOP_MAP_H
#define REFACTORINGWORKSHOP_MAP_H

#include <utility>
#include <algorithm>
#include <list>

enum Direction
{
    Direction_UP    = 0b00,
    Direction_DOWN  = 0b10,
    Direction_LEFT  = 0b01,
    Direction_RIGHT = 0b11
};

struct Segment
{
    int x;
    int y;
};

class Map {
    Direction m_currentDirection;
    std::pair<int, int> m_mapDimension;
    std::list<Segment> m_segments;
public:
    bool isPositionOutsideMap(int x, int y) const;
    bool isSegmentAtPosition(int x, int y) const;
    bool isHorizontal(Direction direction) const;
    bool isVertical(Direction direction) const;
    bool isPositive(Direction direction) const;
    bool perpendicular(Direction dir1, Direction dir2);
};


#endif //REFACTORINGWORKSHOP_MAP_H
