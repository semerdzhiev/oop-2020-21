#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

class Date
{
    public:
        Date();
        Date(size_t day, size_t month, size_t year);

        // copy constructor, defined only to show some trailing information
		Date(const Date&);

        // destructor, defined only to show some trailing information
        ~Date();

        // set- methods
        size_t getDay() const;
        size_t getMonth() const;
        size_t getYear() const;

        // get- methods
        void setDay(size_t day);
        void setMonth(size_t month);
        void setYear(size_t year);

        void print() const;

    private:
        size_t day{ 1 };
        size_t month{ 1 };
        size_t year{ 1900 };

        // checks if the three input arguments form a valid date
        bool isValidDate(size_t day, size_t month, size_t year);
};

#endif // DATE_H_INCLUDED
