# CPP06 notes

CPP06 is about C++ casts, and a bit about static class. Below are the different casts that I would like to know about (ordered from most safest to most dangerous):

1. `const_cast`: Safest
2. `static_cast`: Relatively safe
3. `dynamic_cast`: Relatively safe (but limited to polymorphic classes)
4. `reinterpret_cast`: Unsafe
5. C-style cast: Most dangerous

The documentation below will introduce the most dangerous cast first, and then the safer ones.

## Table of Contents

- [CPP06 notes](#cpp06-notes)
  - [Table of Contents](#table-of-contents)
  - [C-style cast](#c-style-cast)
  - [`reinterpret_cast`](#reinterpret_cast)
  - [`dynamic_cast`](#dynamic_cast)
  - [`static_cast`](#static_cast)
  - [`const_cast`](#const_cast)
  - [Static class](#static-class)

## C-style cast

C-style cast is a way to perform type conversions between different data types using the syntax:

```cpp
(type) value
```

It is the traditional and oldest form of casting available in C++ and is inherited from the C programming language. While it appears to be convenient due to its simplicity, it comes with several risks and is considered less safe compared to the other explicit casts provided by C++.

The `(type)` part specifies the target data type to which the value will be converted, and `value` is the expression or variable to be converted. The C-style cast can be used to perform the following conversions:

1. Conversions between fundamental data types like `int`, `float`, `char`, etc.
2. Custom type conversions between user-defined types
3. Pointer types

However, it lacks the precision and safety checks provided by the explicit casts in C++.

Here are some key aspects and risks of using C-style casts:

1. **Lack of Type Safety**

    C-style casts perform conversions without considering type safety, leading unintended results and potential undefined behavior. It doesn't perfom any runtime checks to ensure that the conversion is valid.

2. **Implicit Conversions**

    C-style casts can perform implicit conversions between types that are not related to each other. For example, it can convert a pointer to an integer type, which is not allowed by the other explicit casts.

3. **Combining Multiple Casts**
   
    C-style casts can combine multiple casts into a single cast. For example, it can perform a `const_cast` and `reinterpret_cast` at the same time, which is not allowed by the other explicit casts. This behaviour can be non-obvious and lead to unintended results.

4. **Harder to Spot**
   
    C-style casts are harder to spot in the code and can be easily missed. This can make it difficult to identify and debug issues caused by the casts.

Due to these risks and the lack of safety checks, C++ standards discourage the use of C-style casts in favor of explicit casts, which provide better type safety and more readable and maintainable.

## `reinterpret_cast`

Syntax:

```cpp
reinterpret_cast<target_type>(value)

int intValue = 42;
char *charPtr = reinterpret_cast<char *>(&intValue);
```

1. **Unsafe Type Conversion**

    Among all the explicit casts provided in C++, `reinterpret_cast` is the most dangerous one. It can perform conversions between unrelated pointer types and between pointers and integral types, which can lead to unexpected results and undefined behavior.

2. **Bit-level conversion**
   
    `reinterpret_cast` performs a bit-level conversion of the pointer value to the target type. It doesn't perform any checks to ensure that the conversion is valid. It simply reinterprets the pointer value as a value of the target type regardless of the actual data stored at that address. It's specifically designed for low-level operations where you need to manipulate the memory representation of objects. When using it, you are telling the compiler to treat the memory address stored in the pointer as an unsigned integer of the same size. This does not change the actual memory contents, it just changes the way the compiler interprets the contents.

3. **No Type Checking**

    `reinterpret_cast` doesn't perform any type checking.

4. **Potential Undefined Behavior**

    `reinterpret_cast` can lead to undefined behavior and crashes since it allows you to bypass the type system and treat objects of one type as if they were objects of another type.

5. **Should use with Extreme Caution**

    `reinterpret_cast` should be used with extreme caution and only when absolutely necessary. It should be avoided as much as possible.

## `dynamic_cast`

1. **Used for Polymorphic Types**
   
   `dynamic_cast` is primarily used for handling conversions within an inheritance hierarchy of polymorphic classes. A class is considered polymorphic if it has at least one virtual function.

2. **Downcasting Safety**

    One of the main use cases of `dynamic_cast` is to safely perform downcasting (converting from a base class pointer/reference to a derived class pointer/reference) within an inheritance hierarchy.

3. **Runtime Type Checking**
   
   Unlike `static_cast`, `dynamic_cast` performs runtime type-checking to ensure the validity of the conversion, If the conversion is not possible, it returns a NULL pointer (for pointers) or throws a `std::bad_cast` exception (for references).

4. **Upcasting**

    Although `dynamic_cast` is often associated with downcasting, it can also be used for upcasting (converting from a derived class pointer/reference to a base class pointer/reference). However, it is not recommended to use `dynamic_cast` for upcasting since it is less efficient than `static_cast`. And it's not necessary since `static_cast` can perform upcasting safely.

5. **Use with Polymorphism**

    `dynamic_cast` relies on the presence of virtual functions in the class hierarchy to work correctly. It uses the virtual table (vtable) to determine the actual type of the object at runtime.

Example:

```cpp
class Base {
public:
    virtual ~Base() {}
}

class Derived : public Base {
public:
    void foo() {}
}

Base *basePtr = new Derived();
Derived *derivedPtr = dynamic_cast<Derived *>(basePtr);
if (derivedPtr) {
    // Downcast succeeded
    derivedPtr->foo();
} else {
    // Downcast failed
}
```

## `static_cast`

Syntax:

```cpp
static_cast<target_type>(value)
```

1. **Numeric Conversions**
   
   `static_cast` is mainly used for numeric conversions between arithmetic types, such as `int`, `float`, `double`, etc. It allows for safe and well-defined conversions, including conversions between interger and floating-point types.

2. **Pointer and Reference Conversion**
   
   `static_cast` can be used for conversions between pointers and references in an inheritance hierarchy (upcasting and downcasting) and conversions between pointers to related types.

3. **No Runtime Checking**
   
   Unlike `dynamic_cast`, `static_cast` does not perform any runtime type-checking. It relies on the programmer's knowledge that the conversion is safe, and the validity of the conversion is checked at compile-time.

4. **Downcasting Limitation**
   
    `static_cast` can only perform downcasting if the object is known to be of the target type. In other words, it should be used when you are sure that the derived class object is indeed of the target type. If you are not sure, you should use `dynamic_cast` instead for polymorphic types.

5. **User-defined Conversion**
   
   `static_cast` can also be used for user-defined conversions when a conversion operator is defined in a class. It allows explicit calls to the conversion operator.

Example:

```cpp
int intValue = 42;
double doubleValue = static_cast<double>(intValue);
```

## `const_cast`

1. **Purpose**
   
   `const_cast` is used to remove or add constness to a variable. It is mainly used to work around situations where you need to modify a variable that was declared as const, or to enforce constness in certain situations where it is required.

2. **Safety Considerations**
   
    `const_cast` is the only cast that can be used to remove the constness of a variable. However, it is not recommended to use `const_cast` to remove constness from a variable and modify it. Doing so can lead to undefined behavior.

3. **Adding Constness**
   
    `const_cast` can also be used to add constness to a variable. This is useful when you want to pass a non-const variable to a function that accepts a const reference or pointer.

4. **Pointer and Reference Types**
   
    `const_cast` can be used with both pointers and references. It can be used to remove or add constness to a pointer/pointed-to data or reference target.

5. **Valid Usage Scenarios**
   
    `const_cast` should only be used in situations where you need to remove or add constness to a variable. It should not be used for any other purpose.

Based on the point above, you can see that why it's the safest cast because it doesn't alter the value of the variable. It just either removes or adds constness to it.

Example:

```cpp
void    modifyValue(const int& value) {
    int& ref = const_cast<int&>(value);
    ref = 42;
}

int main() {
    const int value = 10;
    modifyValue(value);
    std::cout << value << '\n'; // 42
    return 0;
}
```

## Static class

In C++, there is no direct equivalent of a `static class` like in some other programming languages, such as Java. However, you can simulate a static class by utilizing some of the C++ features.

In C++, a static class typically refers to a class that contains only static members and cannot be instantiated to create objects. Essentially, it serves as a container for grouping related static members, providing a namespace-like organization for static elements within the class.

Here are some of the features of a static class:

1. No instantiation
2. Static members only
3. Namespace-like Organization
4. Constructor/Destructor (optional, but place them in private if defined)
