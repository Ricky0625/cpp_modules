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
      - [Overloading comparison operators](#overloading-comparison-operators)
      - [Overloading arithmetic operators](#overloading-arithmetic-operators)
      - [Overloading pre- \& post- increment \& decrement](#overloading-pre---post--increment--decrement)
      - [Overloading built-in functions](#overloading-built-in-functions)
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

No much to say about this exercise. It is just to pratice the Orthodox Canonical Class Form. Learned about some common practices when comes to implementing the copy constructor and copy assignment operator.

### ex01: Towards a more useful fixed-point number class

This exercise is about ad-hoc polymorphism. We need to learn how to overload operators and functions. It require us to further extend the Fixed class to be able to handle integer, and float. We also need to overload the `<<` operator to be able to print the value of the Fixed class.

### ex02: Now we're talking

This exercise want us to overload even more operators and functions! BRUHHH.

In this exercise, we are required to overload the following operators:

1. Comparision operators: `==`, `!=`, `>`, `<`, `>=`, `<=`
2. Arithmetic operators: `+`, `-`, `*`, `/`
3. Post- and pre-increment and decrement operators: `++`, `--`

We also need to overload the following functions:

1. `min`: Takes two `Fixed` references and returns the smallest one.
2. `min`: Takes two `Fixed` const references and returns the smallest one.
3. `max`: Takes two `Fixed` references and returns the biggest one.
4. `max`: Takes two `Fixed` const references and returns the biggest one.

#### Overloading comparison operators

When overloading comparison operators, we need to consider the following:

1. **Return type**. The return type should be `bool`.
2. **Const correctness**. The overloaded operators should be `const` member functions to indicate that they do not modify the object.
3. **Provide all relevant comparisons**. If you overload any of the comparison operators, it is generally a good practice to overload all of them to ensure that the behavior is consistent.
4. **Avoid modifying operands**. The operands should be passed by `const` reference to avoid modifying them. This also avoids unnecessary copying of the operands.

#### Overloading arithmetic operators

When overloading arithmetic operators, we need to consider the following:

1. **Return type**. The return type should be something that makes sense in your context. It should also return a new object instead of modifying the operands.
2. **Const correctness**. The overloaded operators should be `const` member functions to indicate that they do not modify the object.
3. **Error handling**. The overloaded operators should handle any errors that may occur. For example, if you are overloading the division operator, you should check for division by zero.

#### Overloading pre- & post- increment & decrement

When overloading pre- increment/decrement:

1. **Behavior**: The pre-increment/decrement operator should increment/decrement the value of the object and return the updated value.
2. **Return type**: The return type should be a reference to the object to allow chaining of operations.
3. **Overloads as member function**: The pre-increment/decrement operator should be overloaded as a member function to allow the object to be modified.
4. **Const correctness**: The pre-increment/decrement operator should be a `const` member function to indicate that it does not modify the object.

When overloading post- increment/decrement:

1. **Behavior**: The post-increment/decrement operator should increment/decrement the value of the object and return the previous value.
2. **Return type**: The return type should be a copy of the object to avoid returning a reference to a local variable.
3. **Overloads as member function**: The post-increment/decrement operator should be overloaded as a member function to allow the object to be modified.
4. **Const correctness**: The post-increment/decrement operator should be a `const` member function to indicate that it does not modify the object.

#### Overloading built-in functions

In general, when overloading built-in functions, the function signature should match the built-in function as closely as possible.

### ex03: BSP
