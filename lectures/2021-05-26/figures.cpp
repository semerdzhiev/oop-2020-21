//
// This file is part of the Object-Oriented Programming 2020/21 package
// Author: Atanas Semerdzhiev
// URL: https://github.com/semerdzhiev/oop-2020-21
//

#include <iostream>
#include <string>

class figure {
   std::string m_label;
public:
   figure(std::string label)
      : m_label(label)
   {}

   std::string label() const
   {
      return m_label;
   }

   virtual double area() const = 0;

   virtual ~figure()
   {}
};

class rectangle : public figure {
   unsigned int m_width = 0;
   unsigned int m_height = 0;
public:
   rectangle(std::string label, unsigned int width, unsigned int height)
      : figure(label), m_width(width), m_height(height)
   {}

   virtual double area() const override
   {
      return m_width * m_height;
   }

   void do_rectangle_specific_stuff()
   {
      std::cout << "Hey, I am a rectangle!\n";
   }
};

class circle : public figure {
   double m_radius = 0.0;
public:
   circle(std::string label, double radius)
      : figure(label), m_radius(radius)
   {}

   virtual double area() const override
   {
      return m_radius * m_radius * 3.14;
   }

   void do_circle_specific_stuff()
   {
      std::cout << "Hey, I am a circle!\n";
   }
};

figure* create_figure()
{
   figure* p = nullptr;

   char choice;
   std::cout << "Choose a figure (c-circle, r-rectangle)\n:";
   std::cin >> choice;

   switch (choice)
   {
      case 'R':
      case 'r': {
         unsigned int width, height;
         std::string label;
         std::cout << "\nEnter width, height and label, separated by a space (e.g. 10 20 some_text)\n:";
         std::cin >> width >> height >> label;
         return new rectangle(label, width, height);
      }

      case 'C':
      case 'c': {
         unsigned int radius;
         std::string label;
         std::cout << "\nEnter radius and label, separated by a space (e.g. 10 some_text)\n:";
         std::cin >> radius >> label;
         return new circle(label, radius);
      }

      default: {
         std::cout << "Wrong choice!\n";
         return nullptr;
      }
   }
}

int main()
{
   // better to handle with a smart pointer, but we have not covered that in the course yet
   figure* p = create_figure();

   if (!p) {
      std::cout << "Failed to create a figure!\n";
      return 1;
   }

   std::cout
      << "\nFigure information:"
      << "\n   Label: " << p->label()
      << "\n   Area: " << p->area()
      << "\n   type_info.hash_code: " << typeid(*p).hash_code()
      << "\n   type_info.name: " << typeid(*p).name();

   std::cout
      << "\n\nAbove we passed *the object* to typeid! Here is what happens with the pointer itself:"
      << "\n   type_info.hash_code: " << typeid(p).hash_code()
      << "\n   type_info.name: " << typeid(p).name();


   // dynamic_cast with a pointer
   std::cout << "\n\nTrying to downcast to rectangle*: ";

   rectangle* pr = dynamic_cast<rectangle*>(p);
   
   if (pr) {
      std::cout << "OK\n";
      pr->do_rectangle_specific_stuff();
   }
   else {
      std::cout << "This is not a rectangle!\n";
   }


   // dynaimc_cast with a reference
   std::cout << "\nTrying to downcast to circle&: ";

   try {
      circle& refc = dynamic_cast<circle&>(*p);
      std::cout << "OK\n";
      refc.do_circle_specific_stuff();
   }
   catch (std::bad_cast&) {
      std::cout << "This is not a circle!\n";
   }

   // delete the figure
   delete[] p;
}