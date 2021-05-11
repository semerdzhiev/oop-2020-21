
#include<iostream>
#include<string>
using namespace std;


class Heroe {
public:
    int heal;
    int speed;
    int attack;
    string name;
    Heroe():  heal(0), speed(0), attack(0),
              name(std::move("")) {}
    Heroe(int heal, int speed, int attack, string name) : heal(heal), speed(speed), attack(attack),
                                     name(std::move(name)){
        cout<<"Heroe..."<<endl;
    }
};

class Wizard : virtual public Heroe {
public:
    Wizard() = default;
    void attack1() {} // First special ability
};

class Paladin : virtual public Heroe{
public:
    Paladin() = default;
};

class Healer : virtual public Heroe {
private:
    int healPoints;
public:
    Healer(int healPoints) {
        this->healPoints = healPoints;
    };
    void regenerate() {};//
};

class Ranger : virtual public Heroe{
public:
    Ranger() = default;
};

class Heroe1: public Wizard, public Healer {
public:
    Heroe1(int healPoints, int heal, string name): Healer(healPoints), Wizard(), Heroe(heal, 5, 10, name)  {}

};


class Heroe2 : public Paladin, public Ranger {
public:
    Heroe2(int healPoints, int heal, string name): Paladin(), Ranger(), Heroe(heal, 5, 15, name) {}

};


int main() {
    Heroe1* h = new Heroe1(5, 20, "Merilin");
    delete h;
}