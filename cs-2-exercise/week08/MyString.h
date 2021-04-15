#ifndef WEEK08_MYSTRING_H
#define WEEK08_MYSTRING_H


class MyString {
private:
    char *str;
public:
    MyString(char *str);

    ~MyString();

    MyString(const MyString &obj);

    MyString(MyString &&obj);

    friend std::ostream &operator<<(std::ostream &os, const MyString &a);
    bool operator==(MyString& other);
    bool operator==(int num);
    friend bool operator==(int el, const MyString& other);
    friend std::istream& operator>>(std::istream& is, const MyString& a);
};
#endif //WEEK08_MYSTRING_H
