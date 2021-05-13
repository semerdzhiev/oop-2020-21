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
1. Отваряме файл
2. Проверяваме дали е отворен коректно
3. Работим с файла
4. Когато сме приключили работата си го затваряме.

Ако искаме да отворим файл само за четене:

```c++
  ifstream file;
  file.open("sample.txt");
  // ifstream file("sample.txt");
```

Ако искаме да отворим файл само за писане:

```c++
  ofstream file;
  file.open("sample.txt", ios::app);
  //ofstream file("sample.txt, ios::app);
```

Флагове:

*modes.png*


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

Когато работим с файлове използваме два пойнтера, които пазят специфичва позиция във файла - `get` и `put`. 
`get` сочи към позицията от която четем 
`put` сочи позицията на която пишем

С тези пойнтери са свързани следните методи:
`tellg()` - връща позицията на get пойнтера
`tellp()` - връща позицията на put пойнтера
`seekg(<pos>, [way])` - променя позицията на get пойнтера
`seekp(<pos>, [way])` - променя позицията на put пойнтера, където:
`<pos>` e броя позиции с който да се измести като започне от
`[way]` което може да е ios_base::beg, ios_base::end, ios_base::cur

## Command Line Arguments in Visual Studio
1. Right-click the default project (the one to be run) in Visual Studio and select "Properties".
2. Click on the "Debug" tab on the left.
3. Enter your command line arguments in the textbox labeled "Command line arguments".
4. Save the updated properties and run the project.
