#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <iostream>
#include <queue>
#include <vector>
#include <limits>

#include "Map.h"

class Dijkstra {
private:
    Map& map;

    int dp[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

public:
    Dijkstra(Map& map);
    int distance(const Point& a, const Point& b);
    std::vector<std::vector<int>> run(const Point& start, const Point& target);
};

#endif // DIJKSTRA_H