# Operator overloading. Exceptions

## Operator overloading

### Overloading operators using friend functions:
```
class <Class_name> {
public:
	friend <return_type> operator<operator_symbol>(<parameters>);
};
 
<return_type> operator<operator_symbol>(<parameters>) {
	// body
}
```

### Friend functions can be defined inside the class

### Overloading operators for operands of different types

### Overloading operators using normal functions

### Overloading the I/O operators

```
std::ostream& operator<< (std::ostream &out, const <Class_name> &class) {
    out << class.param;
    return out;
}
```

```
std::istream& operator>> (std::istream &in, <Class_name> &class) {
    // note that parameters must be non-const so we can modify the class members with the input values
    in >> class.param; 
    return in;
}
```

### Overloading operators using member functions

--  <b>The following rules of thumb can help you determine which form is best for a given situation:</b>

- If you’re overloading assignment (=), subscript ([]), function call (()), or member selection (->), do so as a member function.
- If you’re overloading a unary operator, do so as a member function.
- If you’re overloading a binary operator that does not modify its left operand (e.g. operator+), do so as a normal function (preferred) or friend function.
- If you’re overloading a binary operator that modifies its left operand, but you can’t modify the definition of the left operand (e.g. operator<<, which has a left operand of type ostream), do so as a normal function (preferred) or friend function.
- If you’re overloading a binary operator that modifies its left operand (e.g. operator+=), and you can modify the definition of the left operand, do so as a member function.

## Exceptions (throw, try, catch)

### Throwing exceptions:
-- the <b> throw </b> statement is used to signal that an exception or error case has occurred.

-- Examples:

- throw -1; // throw a literal integer value
- throw ENUM_INVALID_INDEX; // throw an enum value
- throw "Can not take square root of negative number"; // throw a literal C-style (const char*) string
- throw dX; // throw a double variable that was previously defined
- throw MyException("Fatal Error"); // Throw an object of class MyException

### Looking for exceptions:
-- the <b> try </b> keyword to define a block of statements (called a try block) that acts as an observer, looking for any exceptions that are thrown by any of the statements within the try block.

### Handling exceptions:
-- the <b> catch </b> keyword is used to define a block of code (called a catch block) that handles exceptions for a single data type.

### Exceptions are handled immediately

### Throwing exceptions outside of a try block

### Examples:
```
int main() {
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;
 
    try {
        if (x < 0.0) {
        	throw "Can not take sqrt of negative number"; // throw exception of type const char*
        }

        std::cout << "The sqrt of " << x << " is " << sqrt(x) << '\n';
    } catch (const char* exception) { 
        std::cerr << "Error: " << exception << '\n';
    }
}
```

```
double mySqrt(double x) {
    if (x < 0.0)
        throw "Can not take sqrt of negative number"; // throw exception of type const char*
 
    return sqrt(x);
}
 
int main() {
    std::cout << "Enter a number: ";
    double x;
    std::cin >> x;
 
    try {
        double d = mySqrt(x);
        std::cout << "The sqrt of " << x << " is " << d << '\n';
    } catch (const char* exception) {
        std::cerr << "Error: " << exception << std::endl;
    }
 
    return 0;
}
```

# Задачи:

### Задача 1:
Направете клас Student, който има следните данни: име, факултетен номер и булева променлива, индикираща дали студента е записал някаква дисциплина. Да се напишат:
```
- метод, който принтира името и номера на студента;
```
### Задача 2:
Направете клас University, който има следните данни: масив от Student. Да се напишат:
```
- метод за добавяне на Student;
- operator+, който връща нов University с конкатинитанирани масивите от Student на двата класа;
- operator[], който връща i-я елемент от масива;
```

### Задача 3:
Напишете unit тестове.

