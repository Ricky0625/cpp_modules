# CPP00

CPP00 is the first project of the C++ branch at 42. We will first be introduced to the basics of C++ and the standard library. Below are the topics that the module want us to explore more one:

1. Namespaces
2. Classes
3. Member functions
4. `stdio` streams
5. Initialization lists
6. `static`
7. `const`
8. ... and some other basic stuff

## Table of Contents

- [CPP00](#cpp00)
  - [Table of Contents](#table-of-contents)
  - [Mandatory topics](#mandatory-topics)
    - [Namespaces](#namespaces)
    - [Classes](#classes)
    - [Member functions](#member-functions)
    - [`stdio` streams](#stdio-streams)
    - [Initialization lists](#initialization-lists)
    - [`static`](#static)
    - [`const`](#const)
    - [Constructors](#constructors)
    - [Destructors](#destructors)
  - [ex00: Megaphone](#ex00-megaphone)
  - [ex01: My Awesome Phonebook](#ex01-my-awesome-phonebook)
    - [Usage](#usage)

## Mandatory topics

### Namespaces

In C++, namespaces are used to organize code into logical groups and prevent naming conflicts. A namespace defines a scope in which identifiers, such as variables, functions, and classes, can be declared without colliding with the names defined in other namespaces or the global namespace.

```cpp
namespace foo {
    int value() { return 5; }
}

namespace bar {
    const double pi = 3.1416;
    double value() { return 2 * pi; }
}

int main() {
    std::cout << foo::value() << '\n';
    std::cout << bar::value() << '\n';
    std::cout << bar::pi << '\n';
    return 0;
}
```

In the above example, we have two namespaces: `foo` and `bar`. Each namespace contains a function called `value` that returns a different value. We can access the function `value` of each namespace by using the scope resolution operator `::`.

In some of the C++ codebase, it's normal to see the `using namespace` directive. The most commonly use case is to use the `std` namespace. However, this is often discouraged in C++ programming. Why is that?

1. It can cause name collisions. `std` contains a vast number of identifiers, including common names like `size`, `count`, `first`, and `last`. If you use `using namespace std`, you can no longer use those names for your own variables, functions, classes, or any other identifier. Hence, `using namespace std` could potentially increases the likelihood of naming conflicts with other libraries or your own code.
2. Explicity qualifying names with namespace (`std::`) helps improve code readability and makes it clear where each identifier is defined. It also makes the code more maintainable, because it's easier to identify which namespace each identifier is defined in.

That being said, there are cases where `using namespace std` is acceptable, such as in small and isolated code snippets or quick prototyping. However, it's generally recommended to prefer explicit qualification (`std::`) to avoid potential naming conflicts.

Instead of using `using namespace std`, you can selectively import only the specific elements you need from the `std` namespace using individual `using` directives.

```cpp
#include <iostream>

using std::cout;
using std::endl;

int main() {
    cout << "Hello, world!" << endl;
    return 0;
}
```

In this way, you import only the necessary names into the current scope, reducing the risks of conflicts and making it clear which names are being used from the `std` namespace.

### Classes

A class is like a blueprint that defines the structure for objects, which are instances of the class. It defines a set of attributes/states (data members) and behaviors (member functions) that an object of that class can have. Classes are the foundation of object-oriented programming (OOP).

Let's say you have a Cat class. We know that every cat has a lot of standard attributes: name, sex, age, weight, color, favourite food, etc. These are the attributes of the class. All cats also behave similarly, they breathe, eat, run, sleep and meow. These are the class's behaviours. The attributes and the behaviours of a class are called members of the class.

With this class, you can create instances to represent different cats. Each instance has its own values for the attributes, completely independent from the other instances.

### Member functions

As mentioned, member functions are the "behaviours" of a class. It also referred to as methods. Member functions can be categorized into two types:

1. **Instance Member Functions**: Functions that operate on individual objects of a class. They have access to the data members and can modify them. Instance member functions are typically used to perform operations that depend on the state of an object.
2. **Static Member Functions**: These functions are associated with the class itself rather than with individual objects of the class. They can be called without creating an object of the class. Static member functions can only access static data members and other static member functions.

Let's use the Cat class as example again, so let's say the Cat class is defined as below:

```cpp
class Cat
{
    private:
        std::string name;
        int age;
    
    public:
        void setName(const std::string& catName);
        void setAge(int catAge);
        void introduce();
        // Makes all the cat play together!
        static void play();
}

int main() {
    Cat cat1;
    cat1.setName("Garfield"); // Instance member function call for cat1
    cat1.setAge(5); // Instance member function call for cat1

    Cat cat2;
    cat2.setName("Tom"); // Instance member function call for cat2
    cat2.setAge(3); // Instance member function call for cat2

    cat1.introduce(); // Instance member function call for cat1
    cat2.introduce(); // Instance member function call for cat2

    Cat::play(); // Static member function call
}
```

To summarize:

- Instance member functions (`setName`, `setAge`, `introduce`) are called on specific cat objects and operate on their individual data members.
- Static member function (`play`) is called on the class itself and performs an action that is not specific to any particular cat object.


Using instance member functions and static member functions together allows us to define behavior and actions that are unique to individual cats as well as behaviours that apply to all cats.

### `stdio` streams

In C++, the Standard Input/Output (stdio) streams are a set of predefined streams that allow for input and output operations. They are part of the C++ Standard Library and provide a standardized way to interact with various input and output devices.

There are mainly three stdio streams:

1. `std::cin`: Standard input stream, which is used for reading input from the user. You can use it to read different types of data, such as integers, floating-point numbers, characters, and strings.
2. `std:cout`: Standard output stream, which is used for printing output to the screen. You can use `std::cout` to display text, numbers, and other data types on the console.
3. `std::cerr`: Standard error stream, which is used for printing error messages and diagnostics. Unlike `std::cout`, `std::cerr` is not buffered, which means that its output is always displayed immediately on the screen.

### Initialization lists

Initialization lists, also known as initializer lists, are used to initialize the member variables of a class within the constructor's initialization section. When an object of a class is created, its data members need to be properly initialized. The initialization list provides a way to initialize these member variables before the body of the constructor executes. It has the following syntax:

```cpp
class MyClass
{
    private:
        int member1;
        std::string member2;
        double member3;
    
    public:
        MyClass();
        MyClass(int value1, std::string value2, double value3);
}

MyClass::MyClass() : member1(value1), member2(value2), member3(value3) {
    // Constructor body
}

MyClass::MyClass(int value1, std::string value2, double value3) : member1(value1), member2(value2), member3(value3) {
    // Overloadded Constructor body
}
```

Using an initializer list in C++ provides several benefits:

1. **Efficiency**: Initialization lists allow you to initialize class member variables directly, avoiding unnecessary default constructions and subsequent assignments. This can be more efficient in terms of memory and performance, especially for complex objects or types that are expensive to construct.

2. **Initialization of Constants and References**: Initialization lists are necessary for initializing const member variables and references since they cannot be assigned values after they are initialized. With an initializer list, you can directly initialize these variables during object construction.

3. **Initialization of Complex Objects**: If a class contains member objects that require specific initialization logic or have their own constructors, the initialization list allows you to invoke the appropriate constructors directly with the desired arguments.

4. **Order of Initialization**: The initialization list ensures that class members are initialized in the specified order, which may be different from the order they are declared in the class. This is particularly important when one member variable depends on the state of another member variable for its initialization.

5. **Base Class Initialization**: When a derived class inherits from a base class, the initialization list is used to specify the constructor of the base class that should be invoked during object creation. This allows you to initialize both the derived class and its base class members correctly.

6. **Consistency and Clarity**: By using an initialization list, you clearly separate the initialization of member variables from the constructor body. This improves code readability, reduces the chances of mistakenly reassigning variables, and ensures a consistent initialization approach throughout the class.

### `static`

The static keyword in C and C++ has similar uses, but there are some differences in their specific behaviors and contexts. Let's discuss the differences when it comes to their usage:

- **Global variables**: In C, the static keyword used with a global variable limits its scope to the file where it is declared. This means the variable is only accessible within the same source file. In C++, when used with a global variable, static gives the variable internal linkage, meaning it is only accessible within the translation unit where it is declared (similar to C). However, in C++, it is recommended to use an unnamed namespace instead of static to achieve internal linkage for global variables.

- **Function scope**: In C, the static keyword used with a function makes the function have internal linkage, meaning it is only visible within the same source file. In C++, static used with a function has a different meaning. It makes the function a static member function of a class, which can be called without an object and can only access other static members of the class.

- **Local variables**: In both C and C++, the static keyword used with a local variable inside a function gives it static storage duration. This means the variable retains its value between function calls. However, the scope of the variable remains within the function.

- **Class members**: In C++, the static keyword used with a class member (data member or member function) makes it belong to the class itself rather than individual objects of the class. It is shared among all objects of the class. Static data members have a single instance for the entire class, while static member functions can be called without an object.

It's important to note that these are some of the common uses of the static keyword in C and C++. The usage and behavior can vary depending on the specific context, such as in different scopes, class definitions, or global variables. Understanding the specific rules and implications of static in the relevant programming language is crucial for correct usage.

### `const`

Here are the main uses of the `const` keyword in C++:

1. **Const Variables**: Declaring a variable as `const` indicates that its value cannot be changed once it's initialized. It makes the variable *READ-ONLY*.

    ```cpp
    const int MAX_VALUE = 100;
    ```

2. **Const Function Parameters**: Using `const` with function parameters allows you to specify that the function does not modify the parameter's value. This is useful when you want to ensure that a function does not accidentatlly modify its input.

    ```cpp
    void print(const std::string& text) {
        std::cout << text << std::endl;
    }
    ```

> `const std::string& text` & `std::string const& text` are the same thing. The `const` keyword can be placed either before or after the type.

3. **Const Member Functions**: Member functions can also be declared as `const`, indicating that they do not modify the state of the object on which they are called. Declaring a member function as `const` allows it to be called on both `const` and `non-const` objects of `MyClass`.

    ```cpp
    class MyClass {
        public:
            int getValue() const {
                return value;
            }
        
        private:
            int value;
    }
    ```
### Constructors

Constructors are special member functions in C++ that are associated with the creation of objects of a class.

Characteristics of constructors:

- Initialize the objects of a class. They have the same name as the class and are declared within the class definition.
- Automatically called when an object is created. Ensure that the object is initialized before it is used.
- Can have parameters, allowing you to pass arguments during object creation to set the initial values of member variables.
- Can be overloaded, meaning can have multiple constructors with different parameters in a class.
- If no constructor is defined in a class, the compiler provides a default constructor that initializes the member variables to their default values (zero for numeric types, empty for string, and null for pointers).

```cpp
class MyClass {
    public:
        MyClass() {
            // Constructor body
        }

        MyClass(int value) {
            // Overloaded constructor body
        }
    
    private:
        int value;
}
```

### Destructors

Destructors are also special member functions in C++. They are called when an object is destroyed or deleted. They have the same name as the class, preceded by a tilde (~). They are declared within the class definition and cannot have parameters or return types.

Characteristics of destructors:

- Clean up resources and perform any necessart finalization when an object is destroyed or goes out of scope.
- Automatically called when an object is destroyed or by using the `delete` keyword to delete an dynamically allocated object.
- Cannot have parameters or return types.
- If no destructor is defined in a class, the compiler provides a default destructor that does nothing.

## ex00: Megaphone

There's no much to say about this exercise. It's just me trying to get used to the syntax of C++. Also, trying to create solutions that are more CPP-like (lol). Learned about the standard library `string` class and the `toupper` function.

## ex01: My Awesome Phonebook

Through this exercise, I created my first class in C++. After this exercise, I learned:

1. How to create a class
2. How to define & declare constructor and destructor
3. How to initialize class member variables using initialization lists
4. Using `this` keyword is optional in C++
5. Common practices when it comes to naming class member variables
6. Common practices to define & declare getters and setters
7. How to use `std::string` and `std::getline` to read input from the user

### Usage

Compile the program by using `make`. Then, run the program by using `./PhoneBook`. The program will prompt you to enter a command. The available commands are:

- `ADD`: Add a new contact to the phonebook
- `SEARCH`: Search for a contact in the phonebook
- `EXIT`: Exit the program