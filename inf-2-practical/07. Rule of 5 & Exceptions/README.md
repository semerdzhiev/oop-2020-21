# Rule of 5 & Изключения

[Запис от упражнението](https://drive.google.com/file/d/1kzcICxG3r4dLUFd5QtBBrJTY7O7vRfWe/view?usp=sharing)

## Lvalues and Rvalues

[Understanding the meaning of lvalues and rvalues in C++](https://www.internalpointers.com/post/understanding-meaning-lvalues-and-rvalues-c)

## Move semantics
[std::move](https://en.cppreference.com/w/cpp/utility/move)

[A move operation should move and leave its source in a valid state](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c64-a-move-operation-should-move-and-leave-its-source-in-a-valid-state)

[Make move assignment safe for self-assignment](https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md#c65-make-move-assignment-safe-for-self-assignment)

## Rule of 5
  Ако класът ви дефинира (или трие) някое от
  - Destructor
  - Copy Constructor
  - Copy Assignment Operator
  - Move Constructor
  - Move Assignment Operator
  
  то *най-вероятно* трябва да дефинира (или трие) и петте. 

## Exception safety 
- No throw - Никога не хвърляме изключения. Стандартната библиотека очаква [noexcept](https://en.cppreference.com/w/cpp/language/exceptions) да са деструкторите, move constructor & assignment operator, swap и всички функции, които се използват в тях. 
- Strong exception guarantee - Ако функцията ни хвърли изключение, то обектите ни се връща обратно в състоянието, в което е била преди началото на изпълнението на функцията. Няма никакви странични ефекти, всички инварианти са запазени. 
- Basic exception guarantee - Ако функцията ни хвърли изключение, то обектите ни все пак остава във валидно състояние. Може да има странични ефекти, но всички инварианти са запазени. 
- No exception guarantee - Нямаме никаква гаранция за състоянието на обектите ни след хвърляне на изключение.


## Copy & swap / Move & swap idiom
Pros:
- просто е, лесно се имплементира
- дава ни Strong exception guarantee
- Избягва се проверката за self-assignment

Cons:
- в някои случаи правенето на допълнително копие може да е твърде скъпо (или ненужно като цяло)

## Exceptions
Изключенията са един от начините за error handling, които можем да ползваме в C++. 

Когато влезем в невалидно състояние и искаме да прекъснем изпълнението на функцията, в която се намираме в момента, можем да "хвърлим" изключение `throw`.
 
Когато хвърлим изключение и не се грижим никъде за прихващането му, програмата ще fail-не по време на изпълнение. Ако не искаме това, а да се грижим за изключенията и спрямо липсата или наличието им да имплементираме някаква логика, можем да използваме:

```c++
try
{
  // call something that possiblly throws an exception
}
catch(exception_type_here& e) 
{
  // do something 
}
catch(another_exception_type_here& e)
{
  // do something else
}
...
```
[try-block](https://en.cppreference.com/w/cpp/language/try_catch)

[Exceptions on cppreference](https://en.cppreference.com/w/cpp/language/exceptions)

## std::exception
[Различни видове изключения, дефинирани в стандарта, може да видите тук](https://en.cppreference.com/w/cpp/error/exception)
