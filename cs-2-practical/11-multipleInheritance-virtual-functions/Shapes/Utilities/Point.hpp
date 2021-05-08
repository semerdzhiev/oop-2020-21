#pragma once

struct Point2D
{
	double x;
	double y;

	Point2D(double _x = 0, double _y = 0) : x(_x), y(_y) {}

	friend std::ostream& operator<<(std::ostream& out, const Point2D& point);
	friend std::istream& operator>>(std::istream& in, Point2D& point);
};

inline std::ostream& operator<<(std::ostream& out, const Point2D& point)
{
	out << point.x << " " << point.y;

	return out;
}

inline std::istream& operator>>(std::istream& in, Point2D& point)
{
	in >> point.x >> point.y;

	return in;
}
