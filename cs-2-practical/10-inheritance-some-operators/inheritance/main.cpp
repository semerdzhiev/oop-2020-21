#include <iostream>
#include<string>
#include <utility>

class Entity {
private:
    float x,y;
protected:
    Entity(float _x,float _y) : x(_x),y(_y) {}
public:
    Entity() = delete;
    float getX() const {
        return x;
    }

    float getY() const {
        return y;
    }

    void setX(float _x) {
        this->x=_x;
    }

    void setY(float _y) {
        this->y=_y;
    }
};

class Player : public Entity {
private:
    std::string name;
public:
    Player(float _x,float _y,std::string  _name) : Entity(_x,_y),name(std::move(_name)) {}
    const std::string& getName() const {
        return name;
    }

    void setName(const std::string& _name) {
        name = _name;
    }
};

class A {
public:
    int x;
protected:
    int y;
private:
    int z;
};

class B : public A {
    void test() {
        x=2;
        y=3;
        //z ne mozhe
    }
};

int main() {
    Player p1(0,1,"Petko");
    p1.setX(3);
    std::cout<<p1.getX()<<std::endl;
    B b;
    b.x;
    //y i z ne mozhe
    return 0;
}
