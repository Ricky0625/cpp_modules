# CPP02 Learning Notes

Below are the mandatory topics for this module:

1. Ad-hoc polymorphism
2. Operator overloading
3. Orthodox canonical class form

## Table of Contents

- [CPP02 Learning Notes](#cpp02-learning-notes)
  - [Table of Contents](#table-of-contents)
  - [Ad-hoc PolyMorphism](#ad-hoc-polymorphism)
  - [Orthodox Canonical Class Form](#orthodox-canonical-class-form)
    - [An ideal implementation of a copy constructor](#an-ideal-implementation-of-a-copy-constructor)
    - [An ideal implementation of a copy assignment operator](#an-ideal-implementation-of-a-copy-assignment-operator)
  - [Exercises](#exercises)
    - [ex00: My First Class in Orthodox Canonical Form](#ex00-my-first-class-in-orthodox-canonical-form)
    - [ex01: Towards a more useful fixed-point number class](#ex01-towards-a-more-useful-fixed-point-number-class)
    - [ex02: Now we're talking](#ex02-now-were-talking)
    - [ex03: BSP](#ex03-bsp)

## Ad-hoc PolyMorphism

Ad-hoc polymorphism,, is a feature of programming languages that allows multiple functions or operators to have the same name but different parameter lists. There are two concepts that fall under the umbrella of ad-hoc polymorphism:

1. Function overloading
2. Operator overloading

It enables different implementations of the same function or operator to be called based on the types or numebr of arguments provided.

```cpp
// function overloading
int add(int a, int b) { return a + b; }
double add(double a, double b) { return a + b; }

// operator overloading
class Foo {
  public:
    // overload the + operator
    Foo operator+(const Foo& rhs) const;
};
```

In this case, the function `add` is overloaded to work with both `int` and `double` data types.

## Orthodox Canonical Class Form

In C++98, the Orthodox Canonical Class Form, aka Rule of Three, is a guideline in C++ for defining the necessary member functions and operators when implementing a class that manage resources or has complex behavior. The rule states that if a class defines one of the following it should probably explicitly define all three:

1. Destructor
2. Copy constructor: Creates a new instance by making a copy of an existing instance. It is necessary when you want to perform a **deep copy** of the object's data members.
3. Copy assignment operator: Assigns the value of one instance to another instance. It is necessary when you want to support assignment operations between objects of the same class.

### An ideal implementation of a copy constructor

```cpp
class MyClass {
    private:
        int* data; // Example dynamic resource
        int size;
    public:
        // copy constructor
        MyClass(const MyClass& other) : data(nullptr), size(other.size) {
            // perform deep copy
            if (other.data != nullptr) {
                data = new int[size];
                for (int i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            }
        }
}
```

The implementation above follows these guidelines:

1. **Deep copy**. It performs a deep copy of the resource. It creates a new array (`data`) with the same size as the source object's array. Then it copies the values from the source object's array to the new array.
2. **Resource Management**. It properly manages the resource by allocating new memory using `new` so that the source object's array is not modified and the new object's array has its own copy of the data.
3. **Initialization list**. It uses an initialization list to initialize the `size` member variable. This is more efficient than assigning the value in the body of the constructor.

The aim for copy constructor is to create a new object with its own independent copy of the resource, ensuring that modifications to one object do not affect the other.

### An ideal implementation of a copy assignment operator

An ideal implementation of a copy assignment operator also follows similar principle as the copy constructor but with more added common practices.

```cpp
class MyClass {
    private:
        int *data; // Example dynamic resource
        int size;
    
    public:
        // copy assignment operator
        MyClass& operator=(const MyClass& other) {
            // check for self-assignment
            if (this == &other) {
                return *this;
            }

            // free the existing resource
            delete[] data;

            // perform deep copy
            size = other.size;
            if (other.data != nullptr) {
                data = new int[size];
                for (int i = 0; i < size; ++i) {
                    data[i] = other.data[i];
                }
            } else {
                data = nullptr;
            }
            return *this;
        }
}
```

The implementation above follow these guidelines:

1. **Deep Copy**
2. **Resource Management**. Delete the existing resource before allocating new memory to avoid memory leak.
3. **Self-assignment check**. It checks for self-assignment. If the source object is the same as the destination object, it returns the current object by reference.

Why delete the existing resource before allocating new memory? Consider the following example:

```cpp
MyClass obj1;
MyClass obj2;
obj1 = obj2;
```

In this object, `obj1` has its own dynamic resource. When `obj2` is assigned to `obj1`, the existing resource of `obj1` is deleted before allocating new memory. If the existing resource is not deleted, the memory allocated to `obj1` will be lost and cannot be freed.

## Exercises

### ex00: My First Class in Orthodox Canonical Form

### ex01: Towards a more useful fixed-point number class

### ex02: Now we're talking

### ex03: BSP