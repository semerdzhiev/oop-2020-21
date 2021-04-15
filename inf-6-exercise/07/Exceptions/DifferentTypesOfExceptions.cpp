#include <iostream>

#include <cstring>
#include <cassert>
#include <vector>

class Test
{
    public:
        Test(const char* str)
        {
            std::cout << "Entering Test(" << str << ")\n";

            strcpy_s(text, strlen(str) + 1, str);
        }

        ~Test()
        {
            std::cout << "Entering ~Test(" << text << ")\n";
        }

    private:
        char text[100]{};
};

void throwException()
{
    Test t("Constructed by throwException()");

    int choice;
    std::cout
        << "What do you want to throw today?\n"
        << "  [1] char\n"
        << "  [2] int\n"
        << "  [3] double\n"
        << "  [4] std::exception object\n"
        << "  [5] std::out_of_range object\n"
        << "Your choice: ";

    std::cin >> choice;

    switch (choice)
    {
        case 1: throw '!';

        case 2: throw 5;

        case 3: throw (double)5.5;

        case 4: throw std::exception("Something happened!");

        case 5: throw std::out_of_range("Something is out of range!");

        default:
            throw std::exception("Really? You failed to enter a number between 1 and 5?!");
    }

    std::cout << "Will this line ever be executed?\n";
}

// външна функция, която обработва само два вида изключения
void caller()
{
    Test t("Constructed by caller()");

    try
    {
        // дори и функцията да хвърли изключение от тип char,
        // няма да бъде направено преобразувано до int

        // не се осъществява неявно преобразуване за примитивните типове данни
        // единствено, ако имаме йерархия от изключения, 
        // изключение от производен тип може да бъде прихванато от catch блок,
        // в който е указан базовия тип
        // ако в catch блока трябва да бъдат изброени и производните типове и базовия тип, 
        // базовия тип трябва да бъде накрая
        throwException();
    }
    catch (int ex)
    {
        std::cout << "Caught an int: " << ex << std::endl;
    }
    catch (double ex)
    {
        std::cout << "Caught a double: " << ex << std::endl;
    }
}

// прости примери за прихващане на изключение
int main()
{
    Test t("Constructed by main()");

    try
    {
        // кои от изключенията са обработени в caller?
        caller();
    }
    // ако изключението е обект, то трябва да бъде прихванато по псевдоним, 
    // за да се избегне излишното му копиране
    catch (const std::out_of_range& ex)
    {
        // what() е виртуална функция, която се извиква през псевдоним
        // динамично свързване
        std::cout << "Caught a std::out_of_range: " << ex.what() << std::endl;
    }
    // std::out_of_range преди std::exception, защото е производен клас
    // в противен случай изключение от тип std::out_of_range ще бъде прихването 
    // в catch блока на std::exception
    catch (const std::exception& ex)
    {
        std::cout << "Caught a std::exception: " << ex.what() << std::endl;
    }
    // специален тип catch блок, който се използва за прихващане на всякакъв вид изключения,
    // ако се използва трябва да стои най-отдолу, като последен блок
    catch (...)
    {
        std::cout << "Caught something that the rest have failed to catch... but what is it?\n";
    }

	return 0;
}




