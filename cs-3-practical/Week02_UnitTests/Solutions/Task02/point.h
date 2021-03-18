/**
 * \brief Structure for working with 2D points
 * \author A. Tsonev
 */
#ifndef point
#define point

struct Point
{
    double x; //!< stores X coordinate
    double y; //!< stores Y coordinate

    //! Function for reading point from console
    void read();

    //! Function for printing point data to console
    void print();

    //! Function calculating distance from the center (0,0)
    double distance();

    //! Function calculating distance from specific point
    double distanceFrom(Point other);
};

#endif