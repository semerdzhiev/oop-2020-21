# Static member variables and functions

## Static member variables

-- static variables keep their values and are not destroyed even after they go out of scope

-- Unlike normal member variables, static member variables are shared by all objects of the class

-- Static members are not associated with class objects

-- Inline initialization of static member variables

## Static member functions

-- Like static member variables, static member functions are not attached to any particular object

-- Static member functions have no * this pointer


# Задачи:

## Задача 1:
Задайте автоматично генериране на факултетни номера (поредни) на класа Student от предишното упражнение.

## Задача 2:
Направете клас Subject, който има следните данни: статичен указател към University(от предното упражнение), масив от факултетни номера на студенти. Да се напишат:
```
- статичен метод за добавяне на указателя към University;
- метод за добавяне на факултетен номер на студент;
- статичен метод който принтира факултетните номера и имената на всички студенти които нямат записана дисциплина;
- оperator[], който връща студента отговарящ на i-я добавен факултетен номер;
```