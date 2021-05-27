# Файлове

[Запис](https://drive.google.com/file/d/1kI3bPCGwiXR_4sss8dEV3EZ89RacYa59/view?usp=sharing)

Има бонус задача за домашно <3

## Singleton
``` c++
class Singleton
{
public:
  Singleton(const Singleton&) = delete;
  Singleton& operator=(const Singleton&) = delete;

  static Singleton& get_instance()
  {
    static Singleton instance;
    return instance;
  }
private:
  ~Singleton() = default;
  Singleton() = default;
};
```
## Файлове

В C++ работим с файлове чрез класовете `fstream`, `ifstream`, `ofstream`, които се намират в `fstream` headerfile.

`ofstream`: използва се за писане във файл

`ifstream`: използва се за четене от файл

`fstream`: използва се за писане и четене от файл

Файл отваряме чрез обект от някой от горните класове.

Стъпки, които следваме при работа с файлове:
1. Отваряме файла
2. Проверяваме дали е отворен коректно
3. Работим с файла
4. Когато сме приключили работата си, го затваряме.

Ако искаме да отворим файл само за четене:

```c++
  std::ifstream file;
  file.open("sample.txt");
  // std::ifstream file("sample.txt");
```

Ако искаме да отворим файл само за писане:

```c++
  std::ofstream file;
  file.open("sample.txt", ios::app);
  //std::ofstream file("sample.txt, ios::app);
```

Флагове:

![modes](https://scontent.fsof8-1.fna.fbcdn.net/v/t1.15752-9/186173520_803735573913455_372124460547459352_n.png?_nc_cat=104&ccb=1-3&_nc_sid=ae9488&_nc_ohc=HGbYGz4GFkUAX9COsJG&_nc_ht=scontent.fsof8-1.fna&oh=68915edd5b0b0c96b07d8814fdf78d72&oe=60C1DA75)

*[Credits](https://www.geeksforgeeks.org/file-handling-c-classes/)*


Проверка: Или чрез някой от методите за проверка състоянието на потока, или директно чрез `operator bool()` 
```c++
  if(file.is_open()) 
  {
  //...
  }
  if(file)
  {

  }
```

Когато работим с файлове, използваме два пойнтера, които пазят специфична позиция във файла - `get` и `put`. 

`get` сочи към позицията, от която четем 

`put` сочи позицията, на която пишем

С тези пойнтери са свързани следните методи:

`tellg()` - връща позицията на get пойнтера

`tellp()` - връща позицията на put пойнтера

`seekg(<pos>, [way])` - променя позицията на get пойнтера

`seekp(<pos>, [way])` - променя позицията на put пойнтера, където:

`<pos>` e броя позиции, с които да се измести като започне от
`[way]` което може да е std::ios::beg, std::ios::end, std::ios::cur



Още важни методи:

`eof()` - връща истина, ако е достигат края на файла

`bad()` - връща истина, ако се провали операция за четене или писане

Затваряме файла с метода `close()`. 



## Command Line Arguments in Visual Studio
1. Right-click the default project (the one to be run) in Visual Studio and select "Properties".
2. Click on the "Debug" tab on the left.
3. Enter your command line arguments in the textbox labeled "Command line arguments".
4. Save the updated properties and run the project.
