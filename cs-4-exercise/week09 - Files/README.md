## Input/Output with files

### 1. Stream classes

 - **fstream** - read/write operations
 - **ifstream** - reading from a file
 - **ofstream** - writing to a file
 
 ```c
 #include <iostream>
#include <fstream>
using namespace std;

int main()
{
    //ofstream file("asd2.txt");
    ofstream file;
    file.open("asd.txt");
    if (file.is_open())
    {
        file << "Asd" << endl;
        file.close();
    }
    system("PAUSE");
    return 0;
}
```

### 2. Open a file
```c
open (filename, mode /*optional - default value depends on the stream class*/);
```
Modes:
- **ios::in** - Open for read
- **ios::out** - Open for write.
- **ios::binary** - Open in binary mode.
- **ios::ate** - Open a file for output and move the read/write control to the end of the file
- **ios::app** - Append mode. All output to that file to be appended to the end
- **ios::trunc** - If the file exists, delete its content

Flags can be combined with the bitwise OR operator: ios::out | ios::app | ios::binary

Default modes:
 - **fstream** - ios::in | ios::out. If you specify mode, the default mode is overridden, not combined 
 - **ifstream** - ios::in. Even when you specify mode that doesn't include it, it will be combined with ios::in flag
 - **ofstream** - ios::out. Even when you specify mode that doesn't include it, it will be combined with ios::out flag

Invalid combinations: 

 - ios::trunc | ios::app
 - ios::trunc without ios::out
 
### 3. Reading and writing from/to a text file demo
```
operator <<
operator >>
getline(istream, str)
```

### 4. File position pointers
```c
streampos tellg(); - current get position
streampos tellp(); - current put position
```

Set the get/put positions:
```c
seekg ( offset, direction );  
seekp ( offset, direction );
```

direction can be:

 - ios::beg - offset counted from the beginning of the stream
- ios::cur - offset counted from the current position
- ios::end - offset counted from the end of the stream

### 5. Binary files
```c
istream& read (char* s, streamsize n);
ostream& write (const char* s, streamsize n);
```

### 6. Задачи

Създайте файл test.txt в работната директория със следното съдържание:
```
Lorem ipsum dolor sit amet, consectetur adipiscing elit. 
Vestibulum ac massa tempor, egestas lacus vitae, tristique leo. 
Donec non mollis tortor. Class aptent taciti sociosqu ad litora torquent per conubia nostra, per inceptos himenaeos.
```

1. Отпечатайте на стандартния изход съдържанието на файла, броя на редовете му и размера в байтове
2. Напишете клас Jedi, който има член данна char** m_skills, която представлява динамичен масив от динамични числови низове. Имплементирайте методите void read(const char* filename) и void write(const char* filename), които прочитат / записват обект от класа Jedi във файл с името filename. Класът Jedi да има статична променлива m_version, която да се има предвид при сериализацията.
3. Добавете член данна за възрастта на Jedi към класа и се уверете, че обекти от тип Jedi могат да се четат дори със старата версия на класа (преди да има член данната m_age)