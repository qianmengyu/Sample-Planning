#include "../include/Dijkstra.h"


Dijkstra::Dijkstra(Map &map) : map(map)
{
}

int Dijkstra::distance(const Point &a, const Point &b)
{
    return std::abs(a.getX() - b.getX()) + std::abs(a.getY() - b.getY());
}

struct Status
{
    /* data */
    int dist;
    int id;
    Point p;
    
    // 小于运算符重载函数
    bool operator<(const Status& other) const {
        // 按照距离进行比较
        return dist < other.dist;
    }

    // 不写报错，应该是后面用到了。单纯不操作的话会导致一直出栈的是第二个元素？
    Status& operator=(const Status& other) {
        dist = other.dist;
        id = other.id;
        p = other.p;
        return *this;
    }
};


// 执行 Dijkstra 算法并返回从起点到终点的最短距离
std::vector<std::vector<int>> Dijkstra::run(const Point& start, const Point& target)
{
    int width = map.getWidth();
    int height = map.getHeight();
    std::vector<std::vector<int>> dist(width, std::vector<int>(height, std::numeric_limits<int>::max())); // 初始化距离数组为无穷大
    // 优先队列，用于按距离从小到大排序：参数分别为 单元类型（pair<int, int>） 存储底层形式（vector） 排序（小的先出）
    // std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    std::priority_queue<Status> pq;

    // 初始化
    dist[start.getX()][start.getY()] = 0;                           // 起始节点到自身的距离为0
    pq.push(Status{0, start.getY() * width + start.getX(), start}); // 将起始节点入队

    // 迭代开始
    while (!pq.empty()) {
        Point u = pq.top().p; // 当前距离最小的节点
        pq.pop();

        int x = u.getX();
        int y = u.getY();

        // 遍历当前节点的邻居
        for(int i = 0; i < 4; i++) {
            int nx = x + dp[i][0];
            int ny = y + dp[i][1];
            // 节点，判断加入
            if(nx >= 0 && nx < width && ny >= 0 && ny < height && !map.isObstacle(nx, ny)) {
                int weight = 1;       // 假设每个相邻节点的权重都为1，实际的需要调用distance函数计算

                // 如果通过 当前节点 到达 邻居节点 的距离比当前已知的距离短，则更新距离数组，并加入优先队列
                if(dist[x][y] + weight < dist[nx][ny]) {
                    dist[nx][ny] = dist[x][y] + weight;
                    pq.push(Status{dist[nx][ny], ny * width + nx, Point{nx, ny}});
                }

            }
        }
    }

    return dist;
}
