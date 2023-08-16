# CPP08 notes

CPP08 aims to let us explore template containers, iterators, and algorithms.

## Table of Contents

- [CPP08 notes](#cpp08-notes)
  - [Table of Contents](#table-of-contents)
  - [Standard Template containers (STL)](#standard-template-containers-stl)
    - [Sequence containers](#sequence-containers)
    - [Container adaptors](#container-adaptors)
    - [Associative containers](#associative-containers)
    - [Unordered associative containers](#unordered-associative-containers)
  - [Iterators](#iterators)
  - [Algorithms](#algorithms)
  - [ex00: Easy find](#ex00-easy-find)
  - [ex01: Span](#ex01-span)
  - [ex02: Mutated abomination](#ex02-mutated-abomination)

## Standard Template containers (STL)

A container is a data structure that holds a collection of data. There are implemented as class templates, which allows a great flexibility in the types supported as elements. It manages the storage space for its elements and provides member functions to access them, either directly or through [iterators](#iterators).

Containers replicate common data structures used in programming: dynamic arrays (vector), linked lists (list), stacks (stack), queues (queue), heaps (priority_queue), trees (set), associative arrays (map)...

Many containers have several member functions in common, and share functionalities.

Something that's worth noting is that `stack`, `queue`, and `priority_queue` are container adaptors, which means that they are implemented on top of other container classes with a specific interface. They are not full container classes with iterators and such. The underlying container is encapsulated in such a way that its elements are accessed by the members of the of the container adaptor independently of the underlying container class used.

### Sequence containers

- `array` - Static array (C++ 11)
- `vector` - Vector (dynamic array)
- `deque` - Double ended queue
- `forward_list` - Singly linked list (C++ 11)
- `list` - Doubly linked list

### Container adaptors

- `stack` - LIFO stack
- `queue` - FIFO queue
- `priority_queue` - Priority queue

### Associative containers

- `set` - Set
- `multiset` - Multiple-key set
- `map` - Map (associative array)
- `multimap` - Multiple-key map

### Unordered associative containers

- `unordered_set` - Unordered set (C++ 11)
- `unordered_multiset` - Unordered multiset
- `unordered_map` - Unordered map (C++ 11)
- `unordered_multimap` - Unordered multimap

## Iterators

Iterators are a powerful concept used to traverse and manipulate elements of various containers in a generic and uniform way. Iterators provide an abstraction that allows you to navigate through the elements of a container without needing to know the underlying details of the container's implementation.

**Travesal**: Iterators allow you to move through the elements of a container sequentially, providing methods to move forward, backward, and jump to specific positions.

**Operations**: Iterators support various operations like dereferencing, assignment, comparison, and arithmetic operations for offsets.

C++ provides different types of iterators to cater to different needs:

1. **Input iterators**: Used for reading elements from a container
2. **Output iterators**: Used for writing elements to a container
3. **Forward iterators**: Allow forward travesal, supporting read and write operations
4. **Bidirectional iterators**: Allow both forward and backward traversal.
5. **Random access iterators**: Support random access to elements, enabling efficient indexing and arithmetic operations.

Input & output iterators are the most limited types of iterators.

Forward iterators have all the functionality of input iterators and if they are not constant iterators, they also have the functionality of output iterators.

INPUT/OUTPUT <- FORWARD <- BIDIRECTIONAL <- RANDOM ACCESS

In short, you can think of an iterator as a concept similar to a pointer. But it provide a way to traverse and access elements within a container. However, iterators are more generic than pointers and designed to work with different types of containers and data structure.

## Algorithms

`<algorithm>` header in C++ is part of the C++ STL and provides a collection of functions that operate on sequences of elements. These functions are algorithmic operations that perform common tasks such as searching, sorting, and manipulating elements within containers. The algorithms provided by the `<algorithm>` header are generic, meaning that they can be used on different kinds of containers and can be used in combination with iterators. So instead of having set of functions like sorting or searching in each container type, STL provides a consistent interface through the `<algorithm>` header. This makes it easier to work with different container types using a unified set of algorithms.

## ex00: Easy find

In this exercise, we need to write a function template `easyfind` that accepts a type `T`. It takes two parameters. The first one has type `T` and the second one is an integer. It's basically repeating what we've done in CPP07.

Throughout the process, I learned a concept called **dependent type name**, which is a type that depeneds on a template parameter. So something like this:

```cpp
template <typename Container>
void test (Container cont)
{
  typename Container::iterator it;
  // logic
}
```

Here, the variable `it` inside the function is dependent on the template parameter `Container`. `typename` is use to inform the compiler that to treat the variable data type as a type. The `typename` keyword is necessary here because if we didn't explicitly tell the compiler that `Container::iterator` is a type, it would assume that it's a variable. Or a static member function.

Besides that, I learned about how to interact with `vector`, `deque` & `list`. This includes how to create, add, remove, and iterate through them using iterators.

## ex01: Span

## ex02: Mutated abomination
