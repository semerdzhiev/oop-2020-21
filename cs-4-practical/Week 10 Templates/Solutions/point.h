#pragma once

using std::ostream;
using std::istream;

class Point {
  int x, y;

public:
  Point(int x = 0, int y = 0);
  Point(Point const &);

  Point &operator=(Point const &);
  bool operator>(Point const) const;
  bool operator==(Point const);
  friend ostream &operator<<(ostream &, Point const &);
  friend istream &operator>>(istream &, Point &);

  void setX(int _x) { x = _x; };
  void setY(int _y) { x = _y; };
  int getX() const { return x; };
  int getY() const { return y; };
};
