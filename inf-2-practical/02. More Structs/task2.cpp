#include <iostream>

const unsigned SPEED_OF_LIGHT = 299792; 

struct Planet
{
  char* name;
  double distance;
  double diameter;
  double mass;
};

Planet read_planet()
{
  Planet p;
  p.name = new char[50];
  std::cin>>p.name>>p.distance>>p.diameter>>p.mass;
  return p;
}

void print_planet(const Planet& p)
{
  std::cout<<p.name<<" "<<p.distance<<" "<<p.diameter<<" "<<p.mass<<std::endl;
}

unsigned get_time(const Planet& p)
{
  return p.distance / SPEED_OF_LIGHT;
}

int main()
{
  auto planet = read_planet();
  print_planet(planet);
  return 0;
}