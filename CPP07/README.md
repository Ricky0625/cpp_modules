# CPP07 Notes

CPP07 is about **Templates**.

## Table of Contents

- [CPP07 Notes](#cpp07-notes)
  - [Table of Contents](#table-of-contents)
  - [Templates](#templates)
    - [Function Templates](#function-templates)
    - [Class Templates](#class-templates)
    - [Template Arguments](#template-arguments)
    - [Function Templates vs Function Overloading](#function-templates-vs-function-overloading)
    - [Class Templates vs Inheritance](#class-templates-vs-inheritance)
  - [Exercise 00: Start with a few functions](#exercise-00-start-with-a-few-functions)
  - [Exercise 01: Iter](#exercise-01-iter)
  - [Exercise 02: Array](#exercise-02-array)

## Templates

Templates are a powerful feature that allows developers to write generic code that can work with different types without having to duplicate the code for each specific type. Templates enable you to create functions and classes that can be parameterized with one or more types or values, making the code more flexible, reusable, and efficient.

### Function Templates

A function template is a blueprint for creating a family of functions. The keyword **template** is used to define a function template. It is defined using the `template` keyword followed by the template parameter list and the function signature. The template parameter list must be enclosed in angle brackets and separated by commas. The template parameter list can consist of one or more template parameters.

```cpp
template <typename T>
T add(T a, T b)
{
    return a + b;
}
```

### Class Templates

A class template is similar to a function template but applies to classes. The keyword **template** is used to define a class template. It is defined using the `template` keyword followed by the template parameter list and the class definition. The template parameter list must be enclosed in angle brackets and separated by commas. The template parameter list can consist of one or more template parameters.

```cpp
template <typename T>
class Container {
    private:
        T data;
    public:
        // member functions and etc
}
```

### Template Arguments

When using a function or class template, you provide template arguments inside angle brackets (`<>`). For function templates, template arguments are usually deduced from the function arguments, but they can also eb explicitly specified.

```cpp
int result = add<int>(5, 10); // Explicitly specifying T as int
Container<double> container; // Creating a Container<double> object
```

### Function Templates vs Function Overloading

Function templates can be more flexible and efficient than function overlaoding when working with multiple types. Function templates allow you to write generic algorithms without explicitly defining multiple versions of the function for different types.

### Class Templates vs Inheritance

Class templates are more flexible and efficient than inheritance when working with multiple types. Template-based generic programming can something be a better alternative to using inheritance for code reuse.

## Exercise 00: Start with a few functions

This exercise is just a warm-up to get familiar with templates. Created three generic functions that can be used with any type (`swap`, `min`, `max`). Tested with `int`, `float`, `double`, `char`, `string`, and `bool`.

## Exercise 01: Iter

Another exercise to get familiar with templates. Created a function `iter` that takes in an array of any type, the length of the array and a function pointer. The function iterates through the array and calls the function pointer on each element of the array.

Also created some generic function that can be passed into the `iter` function.

## Exercise 02: Array

Created a class template `Array` that works like a normal array and can accept any type. During the process, I learned about that you can actually create an empty array. But if you want to access this empty array, it will be undefined behaviour. Also, if you use a pointer to create an empty array, it doesn't mean it's NULL. It's just an empty array, not NULL. NULL means it's pointing to nothing. But an empty array is still pointing to something, just that it's empty. It will have a memory address and you need to free it otherwise it's a memory leak. Empty array cause leaks LMAO. Other than these, this exercise is basically repeating what we did in the previous exercise and all the modules before this.
