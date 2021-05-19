# Inheritance

## "Has-a" relationship and "Is-a" relationship

## Inheritance chains

## Order of construction of derived classes

## Constructors and initialization of derived classes

-- only non-inherited variables can be initialized in the initialization list;

-- add a call to the base class Constructor in the initialization list of the derived class;

-- Inheritance chains - constructors can only call constructors from their immediate parent/base class;

-- Destructors - when a derived class is destroyed, each destructor is called in the reverse order of construction;


## Inheritance and access specifiers

### The protected access specifier

### Different kinds of inheritance

- If you do not choose an inheritance type, C++ defaults to private inheritance;

-- A class can always access its own (non-inherited) members.

-- The public accesses the members of a class based on the access specifiers of the class it is accessing.

-- A derived class accesses inherited members based on the access specifier inherited from the parent class. This varies depending on the access specifier and type of inheritance used.

### Public inheritance

| Access specifier in base class | Access specifier when inherited publicly |
|--|--|
| Public | Public |
| Protected | Protected |
| Private | Inaccessible |

-- <b> Use public inheritance unless you have a specific reason to do otherwise. </b>

### Protected inheritance

| Access specifier in base class | Access specifier when inherited publicly |
|--|--|
| Public | Protected |
| Protected | Protected |
| Private | Inaccessible |

### Private  inheritance

| Access specifier in base class | Access specifier when inherited publicly |
|--|--|
| Public | Private |
| Protected | Private |
| Private | Inaccessible |


## Adding new functionality to a derived class

## Calling inherited functions and overriding behavior

### Calling a base class function

-- if the behavior provided by a base class is sufficient, we can simply use the base class behavior;

### Redefining behaviors

### Adding to existing functionality


## Hiding inherited functionality

### Changing an inherited member’s access level

```
    // <func_name> is protected in Base
    // changing it to public in Derived class via a using declaration

public:
    using Base::<func_name>; // note: no parenthesis here
```

### Hiding functionality

```
    // <member_name> is public member in Base
    // changing it to private in Derived class via a using declaration

private:
    using Base::<member_name>; 
```

```
    // <func_name> is protected in Base
    // mark this function as inaccessible in Derived class

    <return_type> <func_name>() = delete; 
```


## Multiple inheritance

### Problems with multiple inheritance

-- derived class has same functions;

-- work around : explicitly specify which version you meant to call:

```
    Derived d;
    d.Base1::<func_name>();
```

### Diamond problem

-- <b> Avoid multiple inheritance unless alternatives lead to more complexity. </b>


# Задачи:

## Задача 1:
Направете клас Food, който да съдържа следните данни:
```
- тегло;
- части, на които е възможно да се дели;
- тегло на единица част;
- цена;
```

Напишете методите:
```
- consume, който да реализира намаляването на продукта с една част;
- print, който принтира обекта на конзолата;
```

## Задача 2:
Направете клас Pizza, който да наследява класа Food, но и да съдържа още данни за:
```
- типът на пицата;
```

## Задача 3:
Направете клас Salad, който да наследява класа Food, но и да съдържа още данни за:
```
- брой продукти, които съдържа;
- дали има подправки(true/false);
```

## Задача 4:
Направете клас Menu, който да съдържа списък от тип Food\*. Да се реализират методи за:
```
- добавяне и премахване на продукти от менюто;
- принтиране на информацията на продуктите;
- извеждане на най-евтиния продукт;
```