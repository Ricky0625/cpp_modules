# CPP01 Learning Notes

According to the subject, these are the topics that CPP01 want us to explore:

1. Memory allocation
2. Pointers to members
3. References
4. Switch statement

Same as CPP00, I will use the same structure to organize my notes.

## Table of Contents

- [CPP01 Learning Notes](#cpp01-learning-notes)
  - [Table of Contents](#table-of-contents)
  - [Mandatory Topics](#mandatory-topics)
    - [Memory allocation](#memory-allocation)
    - [Pointers to members](#pointers-to-members)
    - [References](#references)
    - [Switch statement](#switch-statement)
  - [Exercises](#exercises)
    - [ex00: BraiiiiiiinnnzzzZ](#ex00-braiiiiiiinnnzzzz)
    - [ex01: Moar brainz!](#ex01-moar-brainz)
    - [ex02: HI THIS IS BRAIN](#ex02-hi-this-is-brain)
    - [ex03: Unnecessary violence](#ex03-unnecessary-violence)
    - [ex04: Sed is for losers](#ex04-sed-is-for-losers)
      - [Usage](#usage)
    - [ex05: Harl 2.0](#ex05-harl-20)
    - [ex06: Harl filter](#ex06-harl-filter)

## Mandatory Topics

### Memory allocation

There's no much difference between C and C++ in memory allocation. There's also stack and heap memory in C++. The only difference is that C++ introduce `new` and `delete` operators to allocate and free memory in heap.

The `new` operator is used to allocate memory in heap. It will returns a pointer to the allocated memory, which can be assigned to a pointer variable. To deallocate or to free a memory allocated by `new`, we use `delete` operator.

C++ also introduces alternative memory management operators, `new[]` and `delete[]`, to allocate and free memory for arrays. These operators handle the allocation and deallocation of memory blocks for array objects and ensure proper initialization and cleanup of each element.

Since C++ supports OOP. It introduces constructors and destructors as special member functions for initializing and cleaning up objects. Constructors are called automatically when an object is create, while destructors are called when an object goes out of scope or is explicitly deleted.

Syntax of constructor and destructor:

```cpp
class MyClass {
    public:
        MyClass(); // constructor
        ~MyClass(); // destructor
};

MyClass::MyClass() {
    // constructor body
}

MyClass::~MyClass() {
    // destructor body
}
```

Besides that, C++ also has an interesting variant of `new` operator, called **Placement new**. It allows the programmer to specify the address of the storage area where the object will be created. This will be useful in scenarios where you need precise control over object construction and want to specify the exact memory location where the object will be created.

The syntax of placement new is as follows:

```cpp
new (address) type (arguments);
```

Lastly, C++ also introduces **Smart Pointers** as part of the standard library. Smart pointers automate memory management by providing automatic deallocation of objects and ownership semantics. They help prevent memory leaks, provides a safer and more efficient alternative to raw pointers. Do your own research on this if you are interested.

### Pointers to members

Pointers to members in C++ are a mechanism that allows you to store and manipulate member functions are member variables of a class as pointers. They provide a way to refer to specific members of a class without needing an instance of the class.

There are two types of pointers to members:

1. Pointers to Member Functions

    These are used to refer to member functions (behaviors, methods) of a class. They store the address of a specific member function and can be called later using an object or pointer to the class. Pointers to member functions have a special syntax, denoted by the class type, followed by the scope resolution operator `::`, followed by the function name.

    ```cpp
    class MyClass {
        public:
            void memberFunction(int param) {
                // function body
            }
    };

    int main() {
        // declare a pointer to member function
        void (MyClass::*ptr)(int) = &MyClass::memberFunction;

        MyClass obj;
        // call member function using pointer to member function
        (obj.*ptr)(10);
        return 0;
    }
    ```

2. Pointers to Data Members

    I guess the idea of this is kinda like using pointers in C. (Actually, Pointers to Member functions is like using function pointers as well, but with a sprinkle of syntax sugar).

    ```cpp
    class MyClass {
        public:
            int memberVariable;
    };

    int main() {
        // declare a pointer to member variable
        int MyClass::*ptr = &MyClass::memberVariable;

        MyClass obj;
        // accessing and modifying member variable using pointer to member variable
        obj.*ptr = 10;
        return 0;
    }
    ```

Pointers to members are useful in scenarios such as callback functions and event handling.

Example of using pointers to members as callback functions:

```cpp
class MyClass {
    public:
        void memberFunction(int param) {
            // function body
        }
};

void callback(void (MyClass::*ptr)(int), MyClass& obj) {
    // call member function using pointer to member function
    (obj.*ptr)(10);
}

int main() {
    MyClass obj;
    // declare a pointer to member function
    void (MyClass::*ptr)(int) = &MyClass::memberFunction;

    // pass pointer to member function as callback function
    callback(ptr, obj);
    return 0;
}
```

Please note that there's some differences when using pointers to members on members that are declared as `private` or `protected`.

1. Private

    Pointers to private members can only be obtained and used within the class there the member is declared. They cannot be accessed or called directly from outside the class and its derived classes.

    ```cpp
    class MyClass {
        private:
            int privateMember;

            void privateMethod() {
                std::cout << "Private method called\n";
            }

        public:
            void accessPrivateMember() {
                int MyClass::*ptrToPrivateMember = &MyClass::privateMember;
                this->*ptrToPrivateMember = 42;
                std::cout << "Private member value: " << privateMember << "\n";
            }

            void accessPrivateMethod() {
                void (MyClass::*ptrToPrivateMethod)() = &MyClass::privateMethod;
                (this->*ptrToPrivateMethod)();
            }
    };

    int main() {
        MyClass obj;
        obj.accessPrivateMember();  // Output: Private member value: 42
        obj.accessPrivateMethod();  // Output: Private method called
        return 0;
    }
    ```

2. Protected

    Pointers to protected members can be accessed and used within the class and its derived classes. They cannot be accessed or called directly from outside the class. Pointers to protected members allow derived classes to access and modify protected members of the base class as they needed.

    ```cpp
    class BaseClass {
        protected:
            int protectedMember;

            void protectedMethod() {
                std::cout << "Protected method called\n";
            }
    };

    class DerivedClass : public BaseClass {
        public:
            void accessProtectedMember() {
                int BaseClass::*ptrToProtectedMember = &BaseClass::protectedMember;
                this->*ptrToProtectedMember = 42;
                std::cout << "Protected member value: " << protectedMember << "\n";
            }

            void accessProtectedMethod() {
                void (BaseClass::*ptrToProtectedMethod)() = &BaseClass::protectedMethod;
                (this->*ptrToProtectedMethod)();
            }
    };

    int main() {
        DerivedClass obj;
        obj.accessProtectedMember();  // Output: Protected member value: 42
        obj.accessProtectedMethod();  // Output: Protected method called

        return 0;
    }
    ```

### References

In C++, a reference is a way to create an **alternative name or alias** for an existing object. It allows you to refer to the same object using a different name, providing a convenient and efficient way to work with variables.

Hmmm... sounds like pointers in C... right? Well, there's some differences between pointers and references. Let's take a look at the differences by understanding this analogy:

A pointer in C is like a house address written on a piece of paper. It holds the information about the location of a house (memory address), and you can follow the address to access of modify the house (memory location) it points to. You can also change the address on the paper to point to a different house (reassign the pointer). You can also have a piece of paper with no address written on it (NULL pointer).

In C++, a reference is like a nickname or an alias for a house. It's like an alternative name that refers directly to the house itself, not just its address. **Once you assign a nickname to a house, it always refers to that specific house and cannot be changed to refer to a different house.** You cannot have a nickname without a house, it must always refer to a house.

Here are some notable points about reference:

1. References are declared using `&` symbol. They must be initialized when they are declared. For example, `int &ref = var;`
2. Alias for an Object. A reference acts as an alias for the object it is referencing. It refers to the same memory location as the object it is initialized with. Any changes made to the reference will affect the original object, and vice versa.
3. No memory allocation. A reference does not allocate any memory. It only provides an alternative name for an existing object.
4. References are commonly used as function parameters to pass arguments by reference. This allows the function to modify the original object that was passed to it.
5. Cannot be Null. Unlike pointers, references must always refer to a valid object. They cannot be uninitialized or set to null.
6. Immutable reference. Once a reference is initialized to refer to an object, it cannot be changed to refer to a different object. The reference remains bound to the original object throughout its lifetime.
7. No pointer arithmetic. Unlike pointers, references do not support pointer arithmetic. You cannot increment or decrement a reference.

### Switch statement

Switch statement is a control flow statement used for multi-way branching based on the value of an expression. It allows you to execute different blocks of code based on different possible values of a variable.

The syntax of switch statement is as follows:

```cpp
switch (expression) {
    case value1:
        // code to be executed if expression == value1
        break;
    case value2:
        // code to be executed if expression == value2
        break;
    case value3:
        // code to be executed if expression == value3
        break;
    default:
        // code to be executed if expression doesn't match any of the above cases
}
```

There's a concept called **fall-through** in switch statement. It means that if there's no `break` statement in a case, the execution will continue to the next case. This is useful in scenarios where you want to execute the same code for multiple cases.

```cpp
switch (expression) {
    case value1:
    case value2:
    case value3:
        // code to be executed if expression == value1 or value2 or value3
        break;
    default:
        // code to be executed if expression doesn't match any of the above cases
}
```

The `default` case is optional and is executed when none of the case labels match the expression's value. It is similar to the `else` clause in an `if-else` statement. It is usually placed at the end of the switch block, but it can be placed anywhere in the block.

The case labels must be constants or constant expressions. They are compared with the value of the expression using the `==` operator. The expression is usually an integral type like `int` or `char`.

## Exercises

### ex00: BraiiiiiiinnnzzzZ

This exercise is about learning the difference between allocating an object on the stack and on the heap. I also learned about how destructors are called when an object goes out of scope. Besides that, I also understand that the benefits of using stack-allocated objects in C++, which one of them is that the object will be automatically destroyed when it goes out of scope. So it eliminates the need to manually free the memory allocated for the object.

### ex01: Moar brainz!

This exercise aims to let us familiar with how to allocate an array of objects on the heap. I also learned about how to use `new[]` and `delete[]` operators to allocate and free memory for arrays. There's nothing much to say about this exercise.

### ex02: HI THIS IS BRAIN

This exercise aims to let us familiar with references and pointers.

### ex03: Unnecessary violence

This exercise aims to let us think when should we use a pointer to an object and when should we use a reference to an object. Based on the case described in the exercise, HumanA will always be armed while HumanB may not always have a Weapon, meaning that it's nullable.

Based on the comparison between references and pointers, we can see that reference must always refer to a valid object. So it actually make sense to let the weapon object in HumanA class to be a reference so that we can just reference the created weapon object to it. However, for HumanB class, it's better to use a pointer to Weapon object because it's nullable. Another reason is that we can't set null to a reference so using a pointer here seems ideal.

### ex04: Sed is for losers

This exercise is about string manipulation, files object, and recreate the `sed` command in C++.

Through this exercise, I learned about how to use `std::fstream`. It's a class that represents a file stream. It provides member functions for creating, opening, closing, reading from, writing to, and manipulating files. It also provides member functions for working with the file's internal position pointer, which is used to identify the current read/write position within the file.

#### Usage

```bash
./sed <filename> <s1> <s2>
```

> s1 and s2 are strings. s1 is the string to be replaced and s2 is the string to replace s1.

### ex05: Harl 2.0

### ex06: Harl filter
