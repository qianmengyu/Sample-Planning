#ifndef ASTAR_H
#define ASTAR_H

#include <iostream>
#include <queue>
#include <vector>
#include <limits>
#include <functional> // for std::greater
#include <iomanip>


#include "Map.h"

class AStar {
private:
    Map& map;
    int dp[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    AStar(Map &map);
    int heuristic(const Point &current, const Point &target);
    std::vector<std::vector<int>> run(const Point &start, const Point &target);

};

#endif // ASTAR_H