
#include <iostream>
#include <vector>

#include "include/Map.h"
#include "include/Dijkstra.h"
#include "include/AStar.h"
#include "include/Utility.h"

using namespace std;

int main()
{
    Map map(20, 20, 0.05);
    map.printMap();
    int width = map.getWidth();
    int height = map.getHeight();

    Point start = map.getStart(), target = map.getTarget();
    Dijkstra dijkstra(map);
    vector<vector<int>> dist = dijkstra.run(start, target);

    // AStar astar(map);
    // vector<vector<int>> dist = astar.run(start, target);

    cout << "Dist is: ---------" << endl;
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if(dist[x][y] > width * height * 2) {
                std::cout << " - ";
            }
            else {
                std::cout << std::setw(2) << dist[x][y] << " ";
            }
        }
        std::cout << std::endl;
    }
    cout << "Dist is: ---------" << endl;


    printDist(dist, map);

    return 0;
}