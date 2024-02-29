#include "../include/AStar.h"

AStar::AStar(Map &map) : map(map)
{ 
}

// Manhattan distance heuristic
int AStar::heuristic(const Point& current, const Point& target) {
    return abs(current.getX() - target.getX()) + abs(current.getY() - target.getY());
}

struct Status
{
    /* data */
    int g;  // 到起点代价
    int h;  // 到终点预估代价
    // int f;  // 总代价
    Point p;

    // 小于运算符重载函数
    bool operator<(const Status& other) const {
        // 按照距离进行比较
        return g + h < other.g + other.h;
    }
    bool operator>(const Status& other) const {
        // 按照距离进行比较
        return g + h > other.g + other.h;
    }

    // 不写报错，应该是后面用到了。单纯不操作的话会导致一直出栈的是第二个元素？
    Status& operator=(const Status& other) {
        g = other.g;
        h = other.h;
        // f = other.f;
        p = other.p;
        return *this;
    }
};


// f(n) = g(n) + h(n)
// 起点开始的代价为g(n)，与Dijkstra类似
// 使用曼哈顿距离作为启发函数h(n)
std::vector<std::vector<int>> AStar::run(const Point& start, const Point& target) {
    int width = map.getWidth();
    int height = map.getHeight();
    std::vector<std::vector<int>> dist(width, std::vector<int>(height, std::numeric_limits<int>::max())); // 初始化距离数组为无穷大

    std::priority_queue<Status, std::vector<Status>, std::greater<Status>> openList;
    std::vector<std::vector<int>> closeSet(width, std::vector<int>(height, 0));

    openList.push(Status{0, heuristic(start, target), start});

    while (!openList.empty()) {
        Status current = openList.top();
        openList.pop();

        // 到达目标
        if (current.p.getX() == target.getX() && current.p.getY() == target.getY()) {
            // reconstructPath(current);
            break;
        }

        // 未到，节点放置closd集合
        closeSet[current.p.getX()][current.p.getY()] = 1;

        for(int i = 0; i < 4; i++) {
            int nx = current.p.getX() + dp[i][0];
            int ny = current.p.getY() + dp[i][1];

            if(nx >= 0 && nx < width && ny >= 0 && ny < height && !map.isObstacle(nx, ny) && !closeSet[nx][ny]) {
                int newG = current.g + 1; // 假设每个相邻点的代价都是1
                int newH = heuristic(Point{nx, ny}, target);
                int newF = newG + newH;

                if (newG < dist[nx][ny]) {
                    dist[nx][ny] = newG;
                    openList.push(Status{newG, newH, Point{nx, ny}});

                }


            }
        }
    }

    return dist;
}

