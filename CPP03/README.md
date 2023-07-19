# CPP03 Notes

CPP03 is about getting familiar with one of the pillar of OOP: **Inheritance**. This notes will be about the main concepts of inheritance and how to use it in C++. As well as discussing the pros and cons of inheritance.

## Table of Contents

- [CPP03 Notes](#cpp03-notes)
  - [Table of Contents](#table-of-contents)
  - [Inheritance](#inheritance)
    - [Inheritance in C++](#inheritance-in-c)
  - [Exercises](#exercises)
    - [ex00: Aaaaand... OPEN!](#ex00-aaaaand-open)
    - [ex01: Serena, my love!](#ex01-serena-my-love)
    - [ex02: Repetitive work](#ex02-repetitive-work)
    - [ex03: Now it's weird!](#ex03-now-its-weird)

## Inheritance

*Inheritance* is the ability to build new classes on top of existing classes. The main benifits of inheritance is code reuse. If you want a create a class that's slightly different from an existing one, there's no need to duplicate code. Instead, you extend the existing class and put extra functionality into a resulting subclass, which inherits fields and methods of the superclass (based class / parent class).

The consequence of using inheritance is that subclasses have the same interface as their parent class. You can't hide a method in a subclass if it was declared in the superclass. You must also implement all the interface methods in the subclass, even if you don't need them or don't make sense for you subclass.

> Base class / Parent class / Superclass: The class whose members are inherited is called the base class.
> Derived class / Child class / Subclass: The class that inherits the members of another class is called the derived class.

### Inheritance in C++

Some of the programming languages that supports OOP allow a class to inherit multiple classes. C++ is one of them. There are three types of inheritance in C++:

1. **Public Inheritance**: The public members of the base class become public members of the derived class. Protected members become protected, and private members are not accessible in the derived class.
2. **Protected Inheritance**: The public and protected members of the base class become protected members of the derived class. Private members are not accessible in the derived class.
3. **Private Inheritance**: The public and protected members of the base class become private members of the derived class. Private members are not accessible in the derived class.

When creating objects of the derived class, the constructors of both the base and derived classes are called, starting from the most derived class. When destroying objects, the destructors of the most derived class will be called first.

The derived class can implement/redefine their own version of methods (virtual functions) that are inherited from the base class.

Since C++ supports multiple inheritance, this leads to a situation called the *diamond problem*. This problem occurs when a class inherits from two classes that have the same superclass. This leads to ambiguity when accessing members inherited through both paths.

To address the diamond problem, you can use *virtual inheritance*, which ensures that only one instance of the common base class is shared among the derived classes.

```cpp
class Base {
  // Base class definition
}

class DerivedClass : public Base {
  // Derived class definition
}

class DerivedClass : protected Base {
  // Derived class definition
}

class DerivedClass : private Base {
  // Derived class definition
}

class DerivedClass : public Base1, public Base2 {
  // Derived class definition
}

class DerivedClass : public Base1, protected Base2 {
  // Derived class definition
}

class DerivedClass : public Base1, private Base2 {
  // Derived class definition
}

class DerivedClass : public virtual Base1, public virtual Base2 {
  // Derived class definition
}
```

## Exercises

### ex00: Aaaaand... OPEN!

### ex01: Serena, my love!

### ex02: Repetitive work

### ex03: Now it's weird!
