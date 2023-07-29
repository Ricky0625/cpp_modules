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
    - [User-defined exceptions](#user-defined-exceptions)
  - [Ex00: Mommy, when I grow up, I want to be a bureaucrat!](#ex00-mommy-when-i-grow-up-i-want-to-be-a-bureaucrat)
  - [Ex01: Form up, maggots!](#ex01-form-up-maggots)
  - [Ex02: No, you need form 28B, not 28C](#ex02-no-you-need-form-28b-not-28c)
  - [Ex03: At least this beats coffee-making](#ex03-at-least-this-beats-coffee-making)

## Exceptions

Exceptions allow developers to handle and respond to **exceptional conditions o errors** that may occur during the execution of a program. They provide a way to transfer control to a specific block of code (try-catch block) when an exceptional situation arises, rather than forcing the program to crash.

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

When an exception is thrown is a `try` block, the control flow is immediately transferred to the `catch` block. If no `catch` block exists, the program will terminate.

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

## Ex01: Form up, maggots!

## Ex02: No, you need form 28B, not 28C

## Ex03: At least this beats coffee-making
