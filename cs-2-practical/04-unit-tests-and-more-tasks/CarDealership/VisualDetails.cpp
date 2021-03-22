#include "VisualDetails.h"
#include<cstring>
#include <iostream>

VisualDetails::VisualDetails():doorCount(3),hasWing(false) {
   strcpy(color,"undefined");
}

VisualDetails::VisualDetails(const char *_color, unsigned int _doorCount, bool _hasWing):
doorCount(_doorCount),hasWing(_hasWing) {
    strcpy(color,_color);
}

void VisualDetails::setWing(bool _wing) {
    hasWing = _wing;
}

void VisualDetails::setColor(const char* _color) {
    if(strlen(_color)<51) {
        strcpy(color,_color);
    }
}

void VisualDetails::print() const {
    std::cout<<color<<' '<<hasWing<<' '<<doorCount<<'\n';
}

void VisualDetails::readFromConsole() {
    std::cin>>doorCount;
    std::cin>>hasWing;
    std::cin.getline(color,MAX_SIZE);
}
