
#ifndef WEEK08_SINGLETON_H
#define WEEK08_SINGLETON_H


class Singleton
{
private:
    static Singleton* instance;

    Singleton();

public:
    static Singleton* getInstance();
};



#endif //WEEK08_SINGLETON_H
