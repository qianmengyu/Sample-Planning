#include "../include/Map.h"

Map::Map(int width, int height)
{
    if(width < 6 || height < 6) {
        std::cout << "Warning: Too Small Size!" << std::endl;
    }
    this -> width = width;
    this -> height = height;
    int obstacles = 0.1 * width * height;
    this -> obstacleCount = obstacles;

    generateObstacles();
    generateTarget();
}

Map::Map(int width, int height, double rateOFobstacle)
{
    if(width < 6 || height < 6) {
        std::cout << "Warning: Too Small Size!" << std::endl;
    }
    this -> width = width;
    this -> height = height;
    int obstacles = rateOFobstacle * width * height;
    this -> obstacleCount = obstacles;

    generateObstacles();
    generateTarget();
}

void Map::generateObstacles()
{
    // Generate an obstacle in the middle
    obstaclePoints.insert(Point(width / 2, height / 2));
    obstaclePoints.insert(Point(width / 2 + 1, height / 2));
    obstaclePoints.insert(Point(width / 2 - 1, height / 2));
    obstaclePoints.insert(Point(width / 2, height / 2 + 1));
    obstaclePoints.insert(Point(width / 2, height / 2 - 1));
    
    // generate others
    for (int i = 0; i < obstacleCount - 5; ++i) {
        int x = rand() % width;
        int y = rand() % height;
        obstaclePoints.insert(Point(x, y));

        if (rand() < RAND_MAX / 4) {
            for (int l = 0; l < 3; ++l) {
                if(y + l < height) {
                    obstaclePoints.insert(Point(x, y + l));
                }
            }
        } else {
            for (int l = 0; l < 4; ++l) {
                if(x + l < width) {
                    obstaclePoints.insert(Point(x + l, y));
                }
            }
        }
    }
}

void Map::generateTarget()
{
    int x = rand() % width;
    int y = rand() % height;
    while(isObstacle(x, y)) {
        x = rand() % width;
        y = rand() % height;
    }
    startPoint = Point(x, y);

    while(isObstacle(x, y) || (x == startPoint.getX() && y == startPoint.getY())) {
        x = rand() % width;
        y = rand() % height;
    }
    targetPoint = Point(x, y);

}
bool Map::isObstacle(int x, int y)
{
    Point p(x, y);
    if(obstaclePoints.find(p) != obstaclePoints.end()) {
        return true;
    }
    return false;
}

bool Map::isStart(int x, int y)
{
    return x == startPoint.getX() && y == startPoint.getY();
}
bool Map::isTarget(int x, int y)
{
    return x == targetPoint.getX() && y == targetPoint.getY();
}
void Map::printMap()
{
    std::cout << "Show Map: -----------------" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (isObstacle(x, y)) {
                std::cout << "# "; // 障碍物
            }
            else if(isStart(x, y)) {
                std::cout << "S ";
            }
            else if(isTarget(x, y)) {
                std::cout << "E ";
            }
            else {
                std::cout << ". "; // 空地
            }
        }
        std::cout << std::endl;
    }
}

int Map::getWidth()
{
    return width;
}

int Map::getHeight()
{
    return height;
}

Point Map::getStart()
{
    return startPoint;
}

Point Map::getTarget()
{
    return targetPoint;
}
