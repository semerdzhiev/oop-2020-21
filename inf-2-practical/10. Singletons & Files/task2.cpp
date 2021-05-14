#include <fstream>
#include <ios>
#include <stdexcept>
#include <string>
#include <vector>
#include <iostream>

class Animal
{
public:
  Animal() = default;
  Animal(const std::string& id, const std::string& species, const std::string& name, unsigned meals_count) : id{id},
                                                                                                             species{species},
                                                                                                             name{name},
                                                                                                             meals_count{meals_count}
  {};
  // selectors & mutators
  std::string get_id() const
  {
    return id;
  }

  void set_meals_count(unsigned _meals_count)
  {
    meals_count = _meals_count;
  }

  friend std::ostream& operator<<(std::ostream& out, const Animal& animal)
  {
    out << animal.id << " " << animal.species << " " << animal.name << " " << animal.meals_count;
    return out;
  }
  friend std::istream& operator>>(std::istream& in, Animal& animal)
  {
    in >> animal.id >> animal.species >> animal.name >> animal.meals_count;
    return in;
  }
private:
  std::string id{};
  std::string species{};
  std::string name{};
  unsigned meals_count{};
};

class AnimalCollection
{
public:
  friend AnimalCollection& operator<<(AnimalCollection& animal_collection, const Animal& animal)
  {
    animal_collection.animals.push_back(animal);
    return animal_collection;
  }
  friend std::ostream& operator<<(std::ostream& out, AnimalCollection& animal_collection)
  {
    for(int i=0; i<animal_collection.animals.size(); i++)
    {
      std::cout << animal_collection.animals[i] << std::endl;
      out << animal_collection.animals[i] << std::endl;
    }
    return out;
  }

  void print_animal_by_id(const std::string& id)
  {
    Animal* animal = get_animal_by_id(id);
    if(!animal)
    {
      return;
    }
    std::cout<<*animal<<std::endl;
  }


  void change_meals_count_by_id(const std::string& id, unsigned meals_count)
  {
    Animal* animal = get_animal_by_id(id);
    if(!animal)
    {
      return;
    }
    animal->set_meals_count(meals_count);
  }
private:
  Animal* get_animal_by_id(const std::string& id)
  {
    for(int i=0; i<animals.size(); i++)
    { 
      if(animals[i].get_id() == id)
      {
        return &animals[i];
      }
    }
    return nullptr;
  }
  std::vector<Animal> animals;
};

int main(int argc, char* argv[])
{
  AnimalCollection animal_collection{};
  std::string file_name = "animals.txt";
  if(argc == 2)
  {
    file_name = argv[1];
  }
  std::ifstream in{file_name};
  if(!in)
  {
    std::cout<<"Error opening file\n";
    return 0;
  }
  while(true)
  {
    Animal animal;
    in >> animal;
    if(in.eof())
    {
      break;
    }
    animal_collection << animal; 
  }
  while(true)
  {
    std::string command;
    std::cin >> command;
    if(command == "exit")
    {
      break;
    }
    if(command == "print")
    {
      std::string animal_id;
      std::cin >> animal_id;
      animal_collection.print_animal_by_id(animal_id);
    }
    if(command == "change")
    {
      unsigned meals_count;
      std::string animal_id;
      std::cin >> meals_count >> animal_id;
      animal_collection.change_meals_count_by_id(animal_id, meals_count);
    }
    if(command == "read")
    {
      Animal animal;
      std::cin >> animal;
      animal_collection << animal;
    }
  }
  in.close();
  std::ofstream out{file_name};
  out << animal_collection;
  out.close();
  return 0;
}