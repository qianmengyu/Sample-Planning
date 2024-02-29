#include "../include/Utility.h"

void printDist(std::vector<std::vector<int>> &dist, Map &map)
{
    int width = map.getWidth();
    int height = map.getHeight();
    
    std::cout << "Show Dist: ----------------" << std::endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (map.isObstacle(x, y)) {
                std::cout << " # "; // 障碍物
            }
            else if(map.isStart(x, y)) {
                std::cout << " 0S";
            }
            else if(map.isTarget(x, y)) {
                std::cout << std::setw(2) << dist[x][y] << "E" ;
            }
            else {
                if(dist[x][y] >= width * height * 2) {
                    std::cout << " - ";
                }
                else {
                    std::cout << std::setw(2) << dist[x][y] << " ";
                }
            }
        }
        std::cout << std::endl;
    }
}