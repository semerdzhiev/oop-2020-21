
# Сериализация и Десереализация.

## [John Conway's Game of life](https://playgameoflife.com/)

Напишете клас `Board`, представляващ дъска от играта на Джон Конуей.
В нашата версия ще представяме жива клетка като `+` и мъртва клетка като `-`
Дъската трябва да се характеризира със следните член данни:
- `size`: ширината и дължината на дъската.
- `field`: същинското поле, което се представя от двумерен масив от символи.
Дъската трябва да поддържа следния интерфейс:
- конструктор с един аргумент - размера на дъската
- конструктор с 2 аргумента - размера на дъската и начално състояние на дъската (нека то се копира дълбоко)
- копиращ конструктор
- конструктор за местене
- оператор равно
- оператор равно за местене
- деструктор
- оператор bool който връща резултат false ако всички клетки на полето са мъртви и true в останалите случаи
- метод `advance` който прави преход от сегашното състояние на дъската към следващото и връща референция към дъската. Дали една клетка ще оцелее в следващото поколение се определя по следните правила:
	- Ако дадена жива клетка има по-малко от 2 живи съседа, то тя умира
	- Ако дадена жива клетка има 2 или 3 живи съседа, то тя продължава да живее в следващото поколение
	- Ако дадена жива клетка има повече от 3 живи съседи, то тя умира
	- Ако дадена мъртва клетка има точно 3 живи съседи, то в следващото поколение и тя става жива
- метод `serialize` който приема поток от тип `ostream` и сериализира дъската в следния формат: на първия ред се изписва `size`: размера на полето, а след това изписва `size` на брой реда със `size` на брой символи представящи състоянието на дадената клетка.
- метод `deserialize` който приема поток от тип `istream` и връща нова дъска, десериализирана от потока по подобен на сериализацията начин.

### Използвайте файла sampleBoard.txt в който се съдържа начално състояние на дъска и генерирайте N файлове със следващите N стъпки на играта.



## Банка

Създайте клас банка, която се състои от име, 10 клона, брой клиенти и уникален номер. 
Всеки клон се характеризира с уникален номер, местонахождение и коефициент за добра работа. 
Реализирайте следните функционалности:
- rule of 3, ако е необходимо
- operator++, който увеличава коефициента на добра работа с 1
- в банката напишете функция, която връща коефициента за добра работа на банката
- реализирайте operator+=, който обединява банка с текущата и избира 10-те най-добри клона
- функция, която връща броя на създадените банки
- напишете приятелска функция, която сравнява две банки, като тази с по-големия коефициент печели нов клиент, а тази с по-малкия - губи. Функцията трябва да върне по-добрата банка.
- банката трябва да има функции за четене и писане в текстови файл, като използват формата по-долу

```
Bank 'id' 'name' 'clients' [
Branch 'id' 'location' 'workCoeff'
...
]
```
