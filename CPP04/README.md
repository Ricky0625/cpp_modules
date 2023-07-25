# CPP04 notes

CPP04 is about:

1. Subtype polymorphism
2. Abstract classes
3. Interfaces

## Table of Contents

- [CPP04 notes](#cpp04-notes)
  - [Table of Contents](#table-of-contents)
  - [Subtype polymorphism](#subtype-polymorphism)
  - [Abstract classes](#abstract-classes)
  - [Interfaces](#interfaces)
  - [Exercises](#exercises)
    - [ex00: Polymorphism](#ex00-polymorphism)
    - [ex01: I don't want to set the world on fire](#ex01-i-dont-want-to-set-the-world-on-fire)
    - [ex02: Abstract class](#ex02-abstract-class)
    - [ex03: Interface \& recap](#ex03-interface--recap)

## Subtype polymorphism

Before we deep dive into what is subtype polymorphism, let's first talk about what is **polymorphism**.

Polymorphism is the ability of a program to detect the real class of an object and call its implementation even when its real type is unknown in the current context. We can also think of polymorphism as the ability of an object to "pretend" to be something else, usually a class it extends or an interface it implements.

Ok. It seems very abstract. Let's look at some animal examples.

Most animal *can make sounds*. We can anticipate that all subclasses will need to override the base `makeSound` method so each subclass can implement its own sound. Hence, we can say that the animal class can be declared as an abstract class.

```cpp
// abstract class: class with at least one pure virtual method
class Animal {
public:
    virtual void makeSound() const = 0;
};
```

An abstract class let us omit any default implementation of the method in the superclass, but *force* all subclasses to come up with their own implementation.

Imagine that we've put several cats and dogs (~~not animal abuse~~) into a bag. Then, with closed eyes, we take the animals one-by-one out of the bag. After taking an animal from the bag, we don't know for sure what it is. However, if we cuddle it hard enough, the animal will make a sound, depending on its concrete class/type. This is polymorphism.

> Concrete class: A class that can be instantiated. A class that is not abstract. A class that implements the interface/abstact class is considered a concrete class.

After understanding what is polymorphism, we can now talk about subtype polymorphism. *Subtype polymorphism*, also known as runtime polymorphism or dynamic polymorphism, is a concept in OOP where a subclass(derived class) can be treated as an instance of its superclass(base class). This allows us to use a derived class object wherever a base class object is expected. In other words, a derived class object can be assigned to a base class reference or pointer.

The major difference between subtype polymorphism and other forms of polymorphism lies in the *timing* of the method resolution. In subtype polymorphism, the method resolution is done at runtime. In other forms of polymorphism, the method resolution is done at compile time.

In the context of C++, subtype polymorphism is achieved through the use of virtual functions. When a base class declares a function as virtual, it allows its subclasses to override that function with their own implementation. When calling a virtual function on a base class pointer or reference that is pointing to a derived class object, the appropriate function to be executed is determined at runtime.

```cpp
class Shape {
  public:
    virtual void draw() const {
        std::cout << "Drawing a shape" << std::endl;
    }
}

class Circle : public Shape {
  public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }
}

int main() {
    Shape *shapeptr = new Circle();
    shapeptr->draw(); // "Drawing a circle"
    delete shapeptr;
    return 0;
}
```

In this example, we have base class `Shape` with a virtual funciton `draw()`. We also have a derived class `Circle` that override the `draw()` function. When we create a `Circle` object and use a `Shape` pointer to call the `draw()` function, it dynamically dispatches the call to the `Circle` class `draw()` function at runtime, demonstrating subtype polymorphism.

## Abstract classes

An abstract class is a class that cannot be instantiated. It serves as a blueprint for other classes and is meant to be subclassed or derived from by other classes. An abstract class typically contains one or more pure virtual functions, which are simply virtual functions with the `= 0` syntax appended to them. They don't have a definition. These pure virtual functions are merely placeholders, indicating its subclasses to implement the function (a must).

Key features of an abstract class:

1. Cannot be instantiated directly. Cannot create objects of an abstract class type.
2. It may contain concrete (non-virtual) member functions with implementations.
3. It may contain pure virtual functions (functions with no implementation).
4. It may contain data members and other member functions like a regular class.

```cpp
class Shape {
  public:
    // pure virtual function
    virtual void draw() const = 0;

    // concrete function
    void displayArea() cont {
        std::cout << "Area: " << area << std::endl;
    }
  
  protected:
    virtual double calculateArea() const = 0;

  private:
    double area;
}

class Circle : public Shape {
  public:
    void draw() const override {
        std::cout << "Drawing a circle" << std::endl;
    }

  protected:
    double calculateArea() const override {
        return 3.14 * radius * radius;
    }

  private:
    double radius;
}

int main() {
  // Shape shape; // error: cannot instantiate abstract class
  Circle circle;
  circle.draw(); // "Drawing a circle"
  circle.displayArea(); // "Area: 3.14"
}
```

## Interfaces

Interface is actually not supported in C++. In C++, interface and abstract class are quite similar. They are both used to define a common set of methods that must be implemented by derived classes. However, there are some differences:

1. **Implementation**: An interface can only contain pure virtual functions, while an abstract class can contain both pure virtual and concrete functions.
2. **Object creation**: Abstract classes cannot be instantiated directly. They serve as blueprints for other classes, and you cannot create objects of the abstract class. On the other hand, interfaces cannot be instantiated directly either, but they can be implemented by classes.
3. **Purpose**: Abstract classes are used to provide a common base class with some default behavior and require derived classes to provide specific implementations for certain methods. Interfaces, on the other hand, define a contract or a set of methods that must be implemented by any class that wants to adhere to that interface. They are used to enforce a certain behavior in classes that implement them.

```cpp
// Abstract class acting as an interface
class Printable {
  public:
    virtual void print() const = 0; // pure virtual function, no implementation
    virtual ~Printable() {}; // virtual destructor
}

// Concrete class implementing the Printable interface
class Book : public Printable {
  public:
    Book(std::string title) : title(title) {}

    // Implementing the pure virtual function from the Printable interface
    void print() const override {
      std::cout << "Book: " << title << std::endl;
    }
  
  private:
    std::string title;
}

// Concrete class implementing the Printable interface
class Magazine : public Printable {
  public:
    Magazine(std::string name) : name(name) {}

    // Implementing the pure virtual function from the Printable interface
    void print() const override {
      std::cout << "Magazine: " << name << std::endl;
    }
  
  private:
    std::string name;
}

int main() {
  Printable* printable1 = new Book("The Lord of the Rings");
  Printable* printable2 = new Magazine("National Geographic");

  printable1->print(); // "Book: The Lord of the Rings"
  printable2->print(); // "Magazine: National Geographic"

  delete printable1;
  delete printable2;

  return 0;
}
```

The example above demonstrate an abstract that acts as an interface. It contains one pure virtual function `print()`. Then, we have two concrete classes `Book` and `Magazine` that inherit from `Printable` and provide implementations for the `print` function. The `main` function demonstrates how we can use `Printable` interface to handle objects of derived classes polymorphically.

## Exercises

### ex00: Polymorphism

This exercise demonstrates what is subtype polymorphism as well as the importance of virtual destructor in polymorphic classes. The task is simple. Create an Animal class and it will have a member function `makeSound` which is marked as `virtual`. Meaning its derived class can override it to have its own implementation. Then, create a Dog class and a Cat class that inherit from the Animal class. The `makeSound` function in the derived classes will override the base class `makeSound` function. After this, we need to write some test cases to test if the polymorphism works as expected.

To really ensure that we know how this works, we were asked to create another class, WrongAnimal. Then have a derived class called WrongCat to inherit it. The subject didn't specify much about the implementation of these two classes but I decided to have two feature for this class to demonstrate how polymorphism works:

1. The `makeSound` function is not marked as `virtual`.
2. No virtual destructor.

Based on these two feature, it will make the classes not polymorphic. Then, we can see the difference between polymorphic and non-polymorphic classes. Test cases were created to demonstrate the difference. Based on the test cases, I also learned that in a non-polymorphic class, if you call its method through a pointer of its concrete class type, it will call its implementation. But, if you try to call the method (which is supposed to be overwritten) through a pointer of its base class type, it will call the base class implementation. Interesting.

### ex01: I don't want to set the world on fire

### ex02: Abstract class

### ex03: Interface & recap
