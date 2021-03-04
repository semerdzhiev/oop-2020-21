#include <iostream>

const int NUMBER_OF_PIXELS = 16;

struct Pixel
{
    unsigned red{};
    unsigned green{};
    unsigned blue{}; 
};

struct Screen
{
    Pixel pixels[NUMBER_OF_PIXELS]{};
    unsigned size{};
    unsigned brightness{};
};

//Red 255 0 0 
//Green 0 255 0
//Blue 0 0 255

enum Colors 
{ 
    ERed, EGreen, EBlue
};


void paint_all(Screen& screen, const Pixel& new_pixel)
{
    for(int i=0; i<NUMBER_OF_PIXELS; i++)
    {
        screen.pixels[i]=new_pixel;
    }
}

void paint(Colors color, Screen& screen)
{
    switch(color) {
        case Colors::ERed: 
             paint_all(screen, Pixel{255,0,0});
             break;
         case Colors::EGreen: 
             paint_all(screen, Pixel{0, 255, 0});
             break;
         case Colors::EBlue: 
             paint_all(screen, Pixel{0,0,255});
             break;
    }
}

bool is_smaller(const Screen& screen1, const Screen& screen2) 
{
    return screen1.size < screen2.size;
}

void lower_brightness(Screen& screen, unsigned reduce_with) 
{
    if (reduce_with >= screen.brightness)
        screen.brightness = 0;
    else 
        screen.brightness-=reduce_with;
}


int main()
{
    Screen screen; 
    paint(EBlue, screen);
    
    return 0;
}   