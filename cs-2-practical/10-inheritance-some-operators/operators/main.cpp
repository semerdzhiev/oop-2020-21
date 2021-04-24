#include <iostream>
#include<cassert>
#include<cmath>

class Time {
private:
    unsigned seconds{};
    unsigned minutes{};
    unsigned hours{};
public:
    explicit operator bool() const {
        return seconds != 0 && minutes != 0 && seconds != 0;
    }

    // prefix ( ++time)
    Time &operator++() {
        seconds++;
        return *this;
    }

//    postfix time ++
    Time operator++(int) {
        Time copy(*this);
        seconds++;
        return copy;
    }

    Time() = default;

    explicit Time(unsigned _seconds, unsigned _minutes = 0, unsigned _hours = 0) {
        assert(_seconds < 60 && _minutes < 60 && _hours < 24);
        seconds = _seconds;
        minutes = _minutes;
        hours = _hours;
    }

    bool operator()(unsigned x) const {
        return hours >= x;
    }

    bool operator()() const {
        return hours != 0;
    }
};

class Point2D {
private:
    int x = 0;
    int y = 0;
public:
    Point2D(int x, int y) : x(x), y(y) {}

    int X() const { return x; }

    int Y() const { return y; }

    double distance(int x1, int y1) const {
        return sqrt(((x - x1) * (x - x1)) + ((y - y1) * (y - y1)));
    }
};

class PointWrapper {
private:
    Point2D *ptr;
public:
    PointWrapper(int x, int y) {
        ptr = new Point2D(x, y);
    }

    PointWrapper() : ptr() {}

    PointWrapper(const PointWrapper &) = delete;

    PointWrapper &operator=(const PointWrapper &) = delete;

    ~PointWrapper() {
        delete ptr;
    }

    Point2D *operator->() {
        return ptr;
    }

    Point2D &operator*() {
        return *ptr;
    }
};

int main() {
    Time t(25, 30, 10);
    if (t) {
        std::cout << "True\n";
    }

    PointWrapper p(1, 1);
    std::cout << p->distance(0, 0) << std::endl<<(*p).X()<<' '<<(*p).Y()<<std::endl;
    std::cout << t(20);
    return 0;
}
