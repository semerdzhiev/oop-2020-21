#include <cmath>
#include <iostream>

struct Point
{
  unsigned x;
  unsigned y;
};

bool is_ortogonal(const Point& a, const Point& b, const Point& c)
{
  return (b.x - a.x) * (b.x - c.x) + (b.y - a.y) * (b.y-c.y) == 0;
}

bool is_rectangle(const Point& a, const Point& b, const Point& c, const Point& d)
{
  return is_ortogonal(a, b, c) && is_ortogonal(b, c, d) && is_ortogonal(c, d, a);
}

double get_distance(const Point& a, const Point& b)
{
  return std::sqrt((a.x-b.x) * (a.x - b.x) + (a.y-b.y)*(a.y-b.y));
}

double get_area(const Point& a, const Point& b, const Point& c, const Point& d)
{
  if(!is_rectangle(a, b, c, d))
  {
    //what can we do here?
    return -1;
  }
  auto sideA = get_distance(a, b);
  auto sideB = get_distance(b, c);
  return sideA*sideB;
}

int main()
{
  Point A{0, 0};
  Point B{2, 0};
  Point C{2, 3};
  Point D{0, 3};
  std::cout<<get_area(A, B, C, D)<<std::endl;
  return 0;
}