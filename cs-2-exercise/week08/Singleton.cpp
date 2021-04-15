#include <iostream>
#include "Singleton.h"
Singleton* Singleton::instance = nullptr;

Singleton* Singleton::getInstance()
{
    if (instance == nullptr)
    {
        std::cout<<"Create new object..."<<std::endl;
        instance = new Singleton();
    } else {
        std::cout<<"Object already exist..."<<std::endl;
    }

    return instance;
}

Singleton::Singleton()
{}
