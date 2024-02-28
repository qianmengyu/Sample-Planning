#ifndef MAP_H
#define MAP_H

#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>  // rand() srand()
#include <unordered_set>

#include "Point.h"

class Map 
{
private:
    int width, height;
    int obstacleCount;                    // 障碍物数量
    // std::vector<Point> obstaclePoints;    // 障碍物坐标
    std::unordered_set<Point> obstaclePoints;
    Point startPoint, targetPoint;

public:
    Map(int width, int height);
    Map(int width, int height, double rateOFobstacle);

    void generateObstacles();
    void generateTarget();
    
    bool isObstacle(int x, int y);
    bool isStart(int x, int y);
    bool isTarget(int x, int y);

    void printMap();

    // get
    int getWidth();
    int getHeight();
    Point getStart();
    Point getTarget();


};


#endif // MAP_H