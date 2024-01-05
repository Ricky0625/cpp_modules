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
    - [LIFO](#lifo)
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

Reverse Polish Notation (RPN), also known as postfix notation, is a mathematical notation in which operators come after their opearands.

Here's a brief explanation of RPN:

1. Operand Placement
   - In RPN, operands are placed before their corresponding operators.
2. Evaluation process
   - To evaluate an RPN expression, you start from the left and move to the right, processing each operand and operator in turn.
   - When you encounter an operator, you perform the operation on the top operands in the stack (the most recent operands encountered).
3. Use of stack
   - RPN expressions are often evaluated using a stack data structure
   - Operands are pushed onto the stack, and when an operator is encountered, the required number of operands are popped from the stack, the operation is performed, and the result is pused back onto the stack.

```text
Prefix Notation: + 3 4
Infix Notation: 3 + 4
Postfix Notation: 3 4 +
```

The use of stack in the context of RPN is closely tied to the LIFO property of stacks. The stack serves as a convenient data structure for processing operands and operators in the correct order during the evaluation of RPN expressions. Here's why a stack is beneficial:

1. Natural LIFO structure
   
   The LIFO property of a stack makes it a natural fit for processing RPN expressions. In RPN, operands are encountered first and operators later. Using a stack ensures that the most recent operands are readily available for operations. The most recent operands will always on top.

2. Operator-Operand Pairing

    When an operator is encountered, it requires a certain number of operands to perform the operation. The stack conveniently holds the necessary operands, and the LIFO order ensures that the most recent operands are used first.

3. Simplifies expression evaluation

    The operands can be pushed onto the stack, and when an operator is encountered, the required number of operands can be easily popped from the stack for the operation.

### LIFO

LIFO stands for Last In, First Out. It is a principle or order in which items are processed or retrieved based on their entry or arrival order. In a Last In, First Out data structure, the last item that was added is the first one to be removed.

Imagine a stack of plates in a cafeteria. When you wash a plate and want to add it to the stack, you place it on the top. When someone neeeds a plate, they take the one from the top of the stack. If you continue adding and removing plates, the last plates you added (the most recent) will be first one to be used.

## ex02: PmergeMe


