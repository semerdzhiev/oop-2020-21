# Starcraft

Напишете базов клас `Unit` който има следния интерфейс:

```cpp
class Unit
{
public:
	Unit() = default;
	Unit(int attack, int hitPoints, int armor, const std::string& name);
	Unit(const Unit& other);

	Unit& duel(Unit& other);
	void attack(Unit& other);
	void takeDamage(int damage);
	bool isAlive() const;

	void print(std::ostream& out = std::cout) const;

	int getAttackPower() const;
	int getHitPoints() const;
	int getArmor() const;
	const std::string& getName() const;

	int setAttackPower(int attack);
	int setHitPoints(int hp);
	int setArmor(int armor);
	void setName(const std::string& name);
private:
	int attack;
	int hitPoints;
	int armor;
	std::string name;
};
```
За класа `Unit` както и за всички класове, които го наследяват трябва да е изпълнено следното:
- поле `attack`: точките атака на единицата, както и селектор и мутатор за полето.
- поле `hitPoints`: точките живот на единицата, както и селектор и мутатор за полето.
- поле `armor`: точките защита на единицата, защитата просто намаля получената щета от единицата с точки, равни на стойността на полето, както и селектор и мутатор за полето.
- поле `name`: името на единицата, както и селектор и мутатор за полето.
- Методът `isAlive` връща истина само когато дадената единица има поне 1 точка живот.
- Методът `takeDamage` намаля точките живот на единицата по следната формула: `new_hitpoints = old_hitpoints - (damage_taken - armor)`
- Методът `attack` извиква метода `takeDamage` на единицата която е атакувана(`other`) с аргумент атаката на текущата единица.
- Методът `duel` кара двете единици да се атакуват, като се редуват. Дуелът свършва когато една от двете единици остане без точки живот и методът връща референция към победителя, като на всяка стъпка принтира информация за живота на двете единици както и кой кого атакува.
- Методът `print` принтира информация за единицата на подадения поток, ако нямам такъв принтира на стандартния изход.

Нека съществъват и следните единици:

```
Zerg Units:
Zergling: 10 attack, 30 hitPoints, 1 armor.
Baneling: 15 attack, 30 hitPoints, 1 armor. Специално умение: когато тази единица атакува, тя извършва бонус щета равна на точките и живот. Единицата умира след атака.
Raveger: 20 attack, 100 hitPoints, 3 armor. Специано умение: всяка трета атака прави двойни щети.
Ultralisk: 35 attack, 500 hitPoints, 5 armor. Специално умение: когато тази единица поеме щета, връща щета равна на бронята на ултралиска на атакуващата единица.

Terran Units:
Marine: 10 attack, 25 hitPoints, 2 armor.
Marauder: 15 attack. 30 hitPoints, 2 armor. Специално умение: след като тази единица атакува, тя получава 5 точки живот.
Helion: 35 attack, 300 hitPoints, 7 armor. Специално умение: след всяка атака намаля бронята на противника с 1 (когато бронята се намали до отрицателно число единицата получава бонус щета равна на абсолютната стойност на бронята и).
```
# Starcraft 2

Напишете Клас `Army` представляващ хетерогенен масив от различни единици.

Нека класът има следния интерфейс:

```cpp
class Army
{
public:
	Army();
	Army(std::initializer_list<Unit*>);
	Army(const Army&);
	Army(Army&&);
	Army& operator=(const Army&);
	Army& operator=(Army&&);
	~Army();

	const Unit*& operator[](size_t index) const
	Unit*& operator[](size_t index)

	void pushBack(const Unit*);

	Army& goToWar(Army&);

	const size_t getSize() const;
	const size_t getCapacity() const;
};
```
Методът `goToWar` работи по следния начин:
- дуелират се първите 2 единици от всяка армия.
- когато една от тях загуби победителя се дуелира със следващата жива единица от противниковите единици.
- този процеш продължава докато едната армия не избие другата.
