# Упражнение 12 - 17/05/2021
## План за упражнението
	- Ще си поговирм за виртуални функции
	- Множествено наследяване
	- Ще решим една/две задачки/(а)

## Задача 1
Да се напишат следните класове:
- Person - съдържа име. егн. Нека това е абстрактен клас.
- Student - наследява Person и добавя полето faculty number.
- Lecturer - наследява Person и добавя полето salary.
- FacultyMember - наследява Student и Lecurer.
Да се демонстрира така създадената йерархия като се създаде обект от FacultyMember и се попълнят всички полета. 
Да се извикат методите getName(), getNumber(), getSalary() и да се принтират в конзолата.

## Задача 2
Използвайте вече създадената от задача 1 класова йерархия и имплементирайте следните функционалности:
- Въвеждане на FacultyMember от клавиатурата
- Съхранение на FacultyMember във файл
- Четене на FacultyMember от файл
- Принтиране на FacultyMember
