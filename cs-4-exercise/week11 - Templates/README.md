# Templates

## Function templates

### Template parameter declaration:
```
template <typename T> 
<return_type> <function_name>(T param)
{
	
}
```

### Function template instances - function with actual types

- Operators, function calls, and function templates

### Template classes
```
template <class T>
class <Class_name> 
{

};
```

## Задачи:

### Задача 1:
Дефинирайте шаблонен клас Set, който поддържа следните операции:
```
- bool add(T element) - добавя елемент. Връща true, ако елементът не е съществувал в множеството
- bool contains(T element) - проверява дали елемент принадлежи на множеството
- bool isEmpty()
- bool remove(T element) - премахва елемент от множеството. Връща true, ако множеството е съдържало този елемент
- int getSize() - връща броя елементи в множеството
- operator==
- operator+ - обединение на 2 множества (връща ново множество, без да променя текущото)
- operator* - сечение на 2 множества (връща ново множество, без да променя текущото)
- operator- - разлика на 2 множества (връща ново множество, без да променя текущото)
- operator<<, с който да се принтират в конзолата всички редове от файла
```

### Задача 2:
Към класа Set, добавете методите за записване (write) във файл и четене (read) от файл на елементите в класа.

### Задача 3:
Към класа Set, добавете методите:
```
- Set map(MapFn<T>); - променя всеки елемент от множеството
- Set filter(Predicate<T>); - връща ново множество от елементите, които удовлетворяват условието
- K reduce(ReduceFn<T>, K initialValue) - обединяване на елементите в един резултат
```
