#ifndef runner
#define runner

const int MAX_STRING = 128;
const int NUMBER_OF_MARATHONS = 12;

/**
 * \brief Structures for working with runners
 * \author D. Zhekov
 */
struct Runner
{
    char* name; //!< stores runner name
    char* family; //!< stores runner family name
    double times[NUMBER_OF_MARATHONS]; //!< stores marathon times

    //! Function for reading from console
    void read();
    //! Function for getting pace
    double getPace();
    //! Function tfor counting number of times other runner is beated
    int beatNtimes(Runner *other);
    //! Function for cleaning
    void clean();
};

#endif