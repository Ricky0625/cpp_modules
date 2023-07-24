# CPP03 Notes

CPP03 is about getting familiar with one of the pillar of OOP: **Inheritance**. This notes will be about the main concepts of inheritance and how to use it in C++. As well as discussing the pros and cons of inheritance.

## Table of Contents

- [CPP03 Notes](#cpp03-notes)
  - [Table of Contents](#table-of-contents)
  - [Inheritance](#inheritance)
    - [Inheritance in C++](#inheritance-in-c)
    - [Key Points of Inheritance in C++98](#key-points-of-inheritance-in-c98)
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

There are some cases where you have a function in base class that you want to let the derived class to have their own implementation (override). In these cases, you need to declare that function as `virtual`.

```cpp
class Base {
  public:
    virtual void print() {
      cout << "Base class" << endl;
    }
}

class DerivedClass : public Base {
  public:
    void print() {
      cout << "Derived class" << endl;
    }
}
```

In C++, if a class has at least one virtual function, it is considered to be a polymorphic class. Polymorphic classes should have a virtual destructor. The reason is that when you delete an object through a pointer to its base class, without a virtual destructor, the destructor of the base class will be called, but the derived class destructor will not be called. This can lead to memory leaks.

```cpp
class Base {
  public:
    virtual void print() {
      cout << "Base class" << endl;
    }
    virtual ~Base() {
      cout << "Base class destructor" << endl;
    }
}

class DerivedClass : public Base {
  public:
    void print() {
      cout << "Derived class" << endl;
    }
    ~DerivedClass() {
      cout << "Derived class destructor" << endl;
    }
}

int main() {
  Base *b = new DerivedClass();
  b->print();
  delete b;
}
```

By having the destructor of the base class as virtual, you are informing the compiler to call the most derived class destructor first when deleting objects through a pointer to the base class. This ensures that all the destructors are called and no memory leaks occur.

Keep in mind that a virtual destructor is only necessary in the base class. You don't need to mark the destructors of derived classes as virtual unless they are further subclassed and you want to ensure proper cleanup in those cases as well.

### Key Points of Inheritance in C++98

1. **Constructors and Destructors**: There's no support for inheriting constructors or destructors. This means that if you want to initialiize the base class members in the derived class, you have to call the base class constructor explicitly in the initialization list of the derived class constructor.
2. **Virtual Functions**: Virtual functions are used to achieve runtime polymorphism. They are declared in the base class and can be overridden by the derived class. The function call is resolved at runtime.
3. **Abstract Classes**: You can create abstract classes by defining pure virtual functions. An abstract class is a class that contains at least one pure virtual function, and it cannot be instantiated. It can be used as a base class to create derived classes.
4. **Static Members**: Static members are not inherited by the derived class. Each class, whether base or derived, has its own copy of the static members.
5. **Multiple Inheritance**: C++98 does support multiple inheritance. This means that a class can inherit from more than one class. This can lead to the diamond problem, which can be resolved by using virtual inheritance.

## Exercises

### ex00: Aaaaand... OPEN!

This exercise is just a refresher on how to create a class. We need to follow the Orthodox Canonical Form when creating the class. The subject also mentioned that there are a few public member functions that need to be implemented.

### ex01: Serena, my love!

This exercise want us to create a class that inherits from the class we created in ex00. The derived class will have attributes with different value. Also, the derived class's constructor, destructor and member functions will have different implementation.

By comparing two classes, they both have one same function but the implementation is different. To do so, I need to change that function to `virtual` in the base class. Then, I can override that function in the derived class. When there's at least one virtual function it turns the class into a polymorphic class. Therefore, we need to add a virtual destructor to the base class to avoid memory leaks. This is extremely important if we want to do cleanup in the derived class. Virtual destructor ensures that the most derived class destructor is called first when deleting objects through a pointer to the base class.

### ex02: Repetitive work

This exercise is exactly the same as ex01. So, there's no much to discuss here.

### ex03: Now it's weird!

This exercise introduce the problem that comes with multiple inheritance. The problem is called the *Diamond Problem*. The problem occurs when a class inherits from two classes that have the same superclass. This leads to ambiguity when accessing members inherited through both paths.

Besides that, this exercise also introduce us the concept of member hiding or name hiding. This happens when a derived class defines a member with the same name as one of the members in the base class. The derived class member hides/shadows the base class member. Both of them are separate and distinct member. The derived class member can only be accessed directly and the base class member can only be accessed through the scope resolution operator.
