# Classes

## Struct vs Class:

- <b> Use the struct keyword for data-only structures. Use the class keyword for objects that have both data and functions.</b>

## Classes:

### Member Functions (Methods)

### Class Members

### Public vs private access:

- <b> Make member variables private, and member functions public, unless you have a good reason not to. </b>

## Access functions and encapsulation

### Encapsulation (information hiding) - the process of keeping the details about how an object is implemented hidden away from users of the object. Instead, users of the object access the object through a public interface. In this way, users are able to use the object without having to understand how it is implemented.

- <b> Encapsulated  classes are easier to use and reduce the complexity of your programs </b>

- <b> Encapsulated classes help protect your data and prevent misuse </b>

- <b> Encapsulated classes are easier to change </b>

- <b> Encapsulated classes are easier to debug </b>

### Access functions

- Getters (accessors)

- Setters (mutators) 

## Constructors

- <b> Constructor </b> is a special kind of class member function that is automatically called when an object of that class is instantiated. Constructors are typically used to initialize member variables of the class to appropriate default or user-provided values, or to do any setup steps necessary for the class to be used.

### Default constructors

### Constructors with parameters

### Reducing your constructors

### Implicit constructor

## Destructors

# Задача:
Направете клас Person, който има следните данни: име, години, дали има свидетелство за управление на МПС. Да се напишат:
```
- конструктор по подразбиране;
- конструктор с параметри;
- деструктор;
- get-ъри и set-ъри;
- функция, която принтира информацията за човека.
```