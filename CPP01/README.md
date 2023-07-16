# CPP01 Learning Notes

According to the subject, these are the topics that CPP01 want us to explore:

1. Memory allocation
2. Pointers to members
3. References
4. Switch statement

Same as CPP00, I will use the same structure to organize my notes.

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

### Switch statement

## Exercises

### ex00

### ex01

### ex02

### ex03

### ex04

### ex05

### ex06
