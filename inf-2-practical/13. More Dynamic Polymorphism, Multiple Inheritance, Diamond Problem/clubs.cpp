#include <iostream>
#include <string>
#include <vector>

enum musicType
{
  POPFOLK,
  HOUSE,
  ROCK,
  ALL,
};

class Person
{
private:
  std::string name;
  unsigned age;
  double money;
  unsigned whiskey_number;
  unsigned vodka_number;
  musicType type;

public:
  Person(const std::string name, unsigned age, double money, unsigned whiskey_number, unsigned vodka_number, musicType type) : name(name),
                                                                                                                               age(age),
                                                                                                                               money(money),
                                                                                                                               whiskey_number(whiskey_number),
                                                                                                                               vodka_number(vodka_number),
                                                                                                                               type(type) {}

  musicType getMusicType() const
  {
    return type;
  }

  bool isAdult() const
  {
    return age >= 18;
  }

  bool hasEnoughMoney(double vodka_price, double whiskey_price, double additional_cost)
  {
    return (vodka_price * vodka_number + whiskey_price * whiskey_number + additional_cost <= money);
  }
};

class Club
{
protected:
  std::string name;
  double whiskey_price;
  double vodka_price;
  std::vector<Person *> clients;

  std::size_t find(Person *client)
  {
    for (std::size_t i = 0; i < clients.size(); i++)
      if (clients[i] == client)
        return i;
    return -1;
  }

public:
  Club(const std::string &name, double whiskey_price, double vodka_price) : name(name),
                                                                            whiskey_price(whiskey_price),
                                                                            vodka_price(vodka_price)
  {
  }

  virtual bool addClient(Person *newClient) = 0;

  bool removeClient(Person *client)
  {
    size_t position = find(client);
    if (position != -1)
    {
      clients.erase(clients.begin() + position);
      return true;
    }
    return false;
  }
};

class DiscoClub : public Club
{
private:
  std::string star_name;

public:
  static const unsigned capacity;

  DiscoClub(const std::string &name, double whiskey_price, double vodka_price, const std::string &_star_name) : Club(name, whiskey_price, vodka_price),
                                                                                                            star_name(star_name)
  {
    if (vodka_price < 20 || whiskey_price < 35)
      throw std::invalid_argument("Invalid prices!");
  }

  bool addClient(Person *newClient) override
  {
    double additional_cost = 0;
    if (!newClient->isAdult())
      additional_cost = 20;

    if (newClient->getMusicType() != musicType::ROCK && clients.size() < capacity && newClient->hasEnoughMoney(vodka_price, whiskey_price, additional_cost))
    {
      clients.push_back(newClient);
      return true;
    }
    return false;
  }
};

const unsigned DiscoClub::capacity = 70;

class HouseClub : public Club
{
private:
  unsigned dj_number;

public:
  HouseClub(const std::string &name, double whiskey_price, double vodka_price, unsigned dj_number) : Club(name, whiskey_price, vodka_price),
                                                                                                 dj_number(dj_number)
  {
    if (vodka_price < 30 || whiskey_price < 40)
      throw std::invalid_argument("Invalid prices!");
  }

  bool addClient(Person *newClient) override
  {
    if (newClient->getMusicType() != musicType::POPFOLK && newClient->isAdult() && newClient->hasEnoughMoney(vodka_price, whiskey_price, 0))
    {
      clients.push_back(newClient);
      return true;
    }
    return false;
  }
};

class RockClub : public Club
{
private:
  static const unsigned capacity;

public:
  RockClub(const std::string &name, double whiskey_price, double vodka_price) : Club(name, whiskey_price, vodka_price)
  {
    if (vodka_price < 40 || whiskey_price < 30)
      throw std::invalid_argument("Invalid prices!");
  }

  bool addClient(Person *newClient) override
  {
    if (newClient->getMusicType() != musicType::HOUSE && newClient->isAdult() && newClient->hasEnoughMoney(vodka_price, whiskey_price, 0) && clients.size() < capacity)
    {
      clients.push_back(newClient);
      return true;
    }
    return false;
  }
};

const unsigned RockClub::capacity = 30;

class City
{
private:
  std::vector<Person *> people;
  std::vector<Club *> clubs;

public:
  Person *addPerson(Person *person)
  {
    people.push_back(person);
    return person;
  }

  Club *addClub(Club *club)
  {
    clubs.push_back(club);
    return club;
  }

  bool addPersonToClub(Person *client, Club *club)
  {
    return club->addClient(client);
  }

  bool removeClientFromClub(Person *client, Club *club)
  {
    return club->removeClient(client);
  }
};

int main()
{

  City myCity;
  Person person1("Mimi", 15, 50, 0, 2, musicType::ALL);
  Person person2("Alex", 25, 150, 3, 1, musicType::HOUSE);
  Person person3("Vanio", 20, 100, 3, 0, musicType::ROCK);

  Club *club = new DiscoClub("Planeta", 40, 30, "Galin");
 
  myCity.addClub(club);

  myCity.addPerson(&person1);
  myCity.addPerson(&person2);
  myCity.addPerson(&person3);

  myCity.addPersonToClub(&person1, club);
  myCity.addPersonToClub(&person2, club);
  myCity.addPersonToClub(&person3, club);

  myCity.removeClientFromClub(&person2, club);

  delete club;

  return 0;
}