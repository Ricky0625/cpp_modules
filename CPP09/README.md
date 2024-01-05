# CPP09 notes

CPP09 aims to let us explore STL and try to use different standard containers to perform each exercise in this module. Once a container is used, we cannot use it for the rest of the module.

## Table of Contents

- [CPP09 notes](#cpp09-notes)
  - [Table of Contents](#table-of-contents)
  - [Standard Template Library (STL) revision](#standard-template-library-stl-revision)
    - [Summary of key components within the STL](#summary-of-key-components-within-the-stl)
  - [ex00: Bitcoin Exchange](#ex00-bitcoin-exchange)
    - [My thought process](#my-thought-process)
  - [ex01: Reverse Polish Notation](#ex01-reverse-polish-notation)
  - [ex02: PmergeMe](#ex02-pmergeme)

## Standard Template Library (STL) revision

The Standard Template Library (STL) is a powerful set of C++ template classes to provide general-purpose classes and functions with templates that implement many popular and commonly used algorithms and data structures like vectors, lists, queues, and stacks.

### Summary of key components within the STL

| Category | Examples |
| :---: | :--- |
| Containers | **Vector** (Dynamic array), **List** (Doubly linked list), **Deque** (Double ended queue), **Stack** (LIFO), **Map** (Key value pairs), etc. |
| Iterators | **Input** (read), **Output** (Write), **Forward** (Read & Write, moves forward), **Bidirectional** (like Forward but in both directions), **Random access** (Read & Write, allows random access) |
| Algorithms | sort, find, copy, transform, remove, etc |
| Function objects (Functors) | **Arithmetic** (plus, minus, multiplies, etc), **Comparision** (less, greater, equal_to, etc.), **Logical** (logical_and, logical_or, logical_not, etc.) |
| Utilities | Pair, Smart pointers, String and Numeric functions (to_string, stoi, stod, etc) |

Obviously there are more, these are just a short summary.

## ex00: Bitcoin Exchange

For this exercise, we were asked to create a program which outputs the value of a certain amount of bitcoin on a certain date. This program must use a database in csv format which will represent bitcoin price over time. The program will take as input a second database, storing the different prices/dates to evaluate. The program should display on the standard output the result of the value multiplied by the exchange rate according to the data indicated in your database (first database, the csv file).

Below are the rules that the program must respect:

- Program name should be `btc`
- Should take a file as argument
- Each line in the file (second database, the argument) should use the followin format: `date | value`
- A valid date will always be in the following format: `Year-Month-Day`
- A valid value must either a float or a positive integer, between 0 and 1000.

> If the date used in the input does not exist in your DB then you must use the closest date contained in your DB. Be careful to use the lower date and not the upper one.

### My thought process

After understanding the subject, I examined the CSV file that was provided by the subject first. Each line of the csv file represents the bitcoin price over time with a specific format: `date,exchange rate`. So, the records seem like they're in key-value pair fashion. Knowing this, I know that I need to use one of the associative containers, which leave me with these options (in C++98):

1. Set: stores unique, sorted elements.
2. Multiset: similar to set, but allows duplicate elements. Store elements in sorted order.
3. Map: Stores key-value pairs, where each key is unique. Store elements in sorted order.
4. Multimap: Similar to map, but allows multiple elements with the same key.
5. Unordered-multiset: basically multiset, but stores elements in an unordered manner.
6. Unordered-multimap: Basically multimap, but stores elements in an unordered manner.

I can safely exclude `Set`, `Multiset`, and `Unordered-Multiset` out of the choices as they are not storing elements in a key-value pair fashion. What's left is to check whether there's a need to allow duplicate keys. After I read through all the records again, I found out that the dates for each of the records are unique. That means I don't have the need to use `Multimap` or 'Unordered Multimap'. And that leaves me with one choice, which is `Map`.

Now, onto the high level overview of what the program does.

```text
1. Check if the two database can be openened and read. (CSV & the given file)
2. Process the CSV file first. Store data into a map.
    - Extract key & value from each line.
    - Check if the key & value follows the format specified by the subject.
    - Store the key & value as a pair into the map.
        -> Key is stored as epoch time (time_t)
        -> Value is stored as a float.
3. Process the given file. Output the updated exchange rate.
    - Extract key & value from each line.
    - Check if the key & value follows the format specified by the subject.
    - Check if the value is within range. (0 - 1000)
    - Search of for the record in the map (using lower_bound)
    - Output the updated exchange rate.
```

## ex01: Reverse Polish Notation

## ex02: PmergeMe


