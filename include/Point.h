#ifndef POINT_H
#define POINT_H

#include <cstddef>
#include <functional>
#include <iostream>

class Point {
private:
    int x;
    int y;

public:
    // Constructors
    Point(): x(0), y(0) {}
    Point(int x, int y): x(x), y(y) {}

    // Destructor
    ~Point() {}

    // get
    int getX() const {
        return x;
    }
    int getY() const {
        return y;
    }

    // set
    void setX(int x) {
        this -> x = x;
    }
    void setY(int y) {
        this -> y = y;
    }

    // == operator for unordered_set
    bool operator==(const Point& other) const {
        return x == other.x && y == other.y;
    }

    // hash for unordered_set
    friend struct std::hash<Point>;
};

// 哈希函数的特化
namespace std {
    template<> struct hash<Point> {
        std::size_t operator()(const Point& p) const {
            // 使用经典的哈希组合技术
            std::size_t h1 = std::hash<int>()(p.getX());
            std::size_t h2 = std::hash<int>()(p.getY());
            return h1 ^ (h2 << 1);
        }
    };
}

// struct PointHash {
//     std::size_t operator()(const Point& p) const {
//         // 使用经典的哈希组合技术
//         std::size_t h1 = std::hash<int>()(p.getX());
//         std::size_t h2 = std::hash<int>()(p.getY());
//         return h1 ^ (h2 << 1);
//     }
// };


#endif // POINT_H
