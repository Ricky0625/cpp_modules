# CPP05 notes

CPP05 introduces the following concepts:

1. Repetition (i think it means loops? i guess i will skip this)
2. Exceptions

## Table of Contents

- [CPP05 notes](#cpp05-notes)
  - [Table of Contents](#table-of-contents)
  - [Exceptions](#exceptions)
    - [Syntax \& Keywords](#syntax--keywords)
    - [Throwing exceptions](#throwing-exceptions)
    - [Catching exceptions](#catching-exceptions)
    - [Stack unwinding in C++](#stack-unwinding-in-c)
      - [Call stack recap](#call-stack-recap)
    - [User-defined exceptions](#user-defined-exceptions)
  - [Ex00: Mommy, when I grow up, I want to be a bureaucrat!](#ex00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)
  - [Ex01: Form up, maggots!](#ex01-form-up-maggots)
  - [Ex02: No, you need form 28B, not 28C](#ex02-no-you-need-form-28b-not-28c)
  - [Ex03: At least this beats coffee-making](#ex03-at-least-this-beats-coffee-making)

## Exceptions

Exceptions allow developers to handle and respond to **exceptional conditions or errors** that may occur during the execution of a program. They provide a way to transfer control to a specific block of code (try-catch block) when an exceptional situation arises, rather than forcing the program to crash.

### Syntax & Keywords

- `try` block: contains code that may throw an exception
- `catch` block: catches and handles exceptions thrown by the `try` block
- `throw` keyword: used to throw an exception

```cpp
try {
  // code that may throw an exception
  if (/* some condition */) {
    throw exception_type;
  }
} catch (exception_type e) {
  // code to handle exception
}
```

### Throwing exceptions

Exceptions can be thrown using the `throw` statement, followed by an expression representing the exception to be thrown. It can be of any type, but commonly it is a string literal, a class or an object.

When an exception is thrown in a `try` block, the control flow is immediately transferred to the `catch` block. If no `catch` block exists, the program will terminate.

```cpp
#include <iostream>

int main() {
  try {
    throw "Exception thrown";
  } catch (const char* e) {
    std::cout << "Exception caught: " << e << std::endl;
  }
  return 0;
}
```

### Catching exceptions

When an exception is throw, the program will search for a `catch` block that can handle the exception. The `catch` block that matches the type of the thrown exception will be executed. You can have multiple `catch` blocks for different types of exceptions.

If there's an exception that doesn't match any of the `catch` blocks, the program will terminate. To handle this, you can have a `catch` block that catches all exceptions using `...` as the exception type.

```cpp
#include <iostream>

int main() {
  try {
    throw 20;
  } catch (int e) {
    std::cout << "Exception caught: " << e << std::endl;
  }
  catch (...) {
    std::cout << "Default exception caught" << std::endl;
  }
  return 0;
}
```

### Stack unwinding in C++

**Stack unwinding** is the process of removing function entries from the call stack *during the handling of exceptions*. In C++, when an exception is thrown, the program looks for an appropriate exception handler to handle the exception. If the exception is nout caught within the current function, the stack starts to unwind.

During stack unwinding, the destructors of local objects in each stack frame are caleld as the stack is unwound.

If an appropriate exception handler is found, the stack unwinding stops, and the control is transferred to the handler. If no handler is found, the program may terminate, and an error message will be displayed.

#### Call stack recap

When a function is called, a new frame is added to the call stack. This frame contains information about the function call, including local variables, return addresses (where the execution continues from), and other relevant data. The call stack is a data structure that manages the flow of control in a program, keeping track of the currently active function calls.

If the called function itself calls another function, another stack frame is pushed onto the stack.

When a function completes its execution or encounters a return statement, its stack frame is popped from the stack.

```cpp
// CPP Program to demonstrate Stack Unwinding 
#include <iostream> 
using namespace std;
  
// A sample function f1() that throws an int exception 
void f1() throw(int)
{
  cout << "\n f1() Start ";
  throw 100;
  cout << "\n f1() End ";
}

// Another sample function f2() that calls f1() 
void f2() throw(int)
{
  cout << "\n f2() Start ";
  f1();
  cout << "\n f2() End ";
}

// Another sample function f3() that calls f2() and handles 
// exception thrown by f1() 
void f3()
{
  cout << "\n f3() Start ";
  try {
      f2();
  }
  catch (int i) {
      cout << "\n Caught Exception: " << i;
  }
  cout << "\n f3() End";
}

// Driver Code
int main()
{
  f3();

  getchar();
  return 0;
}
```

### User-defined exceptions

In C++, exceptions are objects, and they are typically represented as classes. When we create a user-defined exception, it is indeed implemented as a class that inherits from a base exception class.

All exceptions thrown are instances of classes derived from `std::exception`. This class has a virtual member function called `what()` that returns a null-terminated character sequence (of type `const char*`) that describes the exception.

```cpp
#include <iostream>
#include <exception>
#include <string>

class MyException : public std::exception {
  public:
    MyException(const std::string& msg) : msg_(msg) {}
    virtual const char* what() const throw() {
      return msg_.c_str();
    }
  private:
    std::string msg_;
};
```

## Ex00: Mommy, when I grow up, I want to be a bureaucrat!

For this exercise, we were asked to create a class called `Bureaucrat`. This class should have a constant name and a grade that ranges from 1 (highest grade) to 150 (lowest grade). Any attempt to instantiate a Bureaucrat using an invalid grade must throw an exception: either a `Bureaucrat::GradeTooHighException` or a `Bureaucrat::GradeTooLowException`. Both are user-defined exceptions.

For my test cases, I'm just testing these:

1. Initialize a bureaucrat with grade that is too low or high. (should throw an exception)
2. Update grade. Check if the class will throw exception if the grade accidentally exceed the range.

## Ex01: Form up, maggots!

For this exercise, we need to create another class `Form`. This class should have:

- a constant name
- a boolean indicating whether it is signed
- a constant grade required to execute it

> all these attributes should be private

The Form should follow the same rules that apply to the Bureaucrat.

## Ex02: No, you need form 28B, not 28C

For Ex02, we were asked to create three concrete classes that inherit from the Form class. Each of them will have a different output when being executed.

## Ex03: At least this beats coffee-making
