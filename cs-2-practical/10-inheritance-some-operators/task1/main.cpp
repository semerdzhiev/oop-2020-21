#include <iostream>
#include"Hero.h"

int main() {
    std::vector<Power> powers;
    Power power(TYPE::AIR,VILIANORHERO::HERO,5);
    powers.push_back(power);
    Hero superman("ime",powers,100,Vilian(),"Moga da letq!");
    std::cout<<superman.getHealth()<<std::endl;
    return 0;
}
