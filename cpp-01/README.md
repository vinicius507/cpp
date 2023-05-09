# CPP-01

## EX-00: Zombies!

The goal of this exercise is to create a `Zombie` class and compare the process of instantiating a class on the stack and on the heap.

To instantiate a class on the stack, we can use the following syntax:

```cpp
  Foo obj = Foo(bar);

  // Alternatively, if `Zombie` has a default constructor implementation, you can simply do:
  Foo obj;
```

Heap allocation, on the other hand, requires the use of the new keyword:

```cpp
  Foo *obj = new Foo();
```

To deallocate a class instantiated with the new keyword, we use the delete operator:

```cpp
  Foo *obj = new Foo();
  delete obj; // Free!
```

## EX-01: A horde!

The goal of this exercise is to create a function `zombieHorde` that generates a horde of zombies. The function should use a single allocation for all zombies. We can do this by allocating an array of Zombie objects:

```cpp
  Foo *objs = new Foo[n];
```

> **Note**
>
> This method requires the presence of a default constructor implementation for `Zombie`.

To deallocate the array, we use the `delete[]` operator:

```cpp
  Foo *objs = new Foo[n];
  delete[] objs;
```

## EX-02: Shadow clone Jutsu!!

The goal of this exercise is to get acquainted with C++ references!
References, like pointers, are used to indirectly access objects.

The differences between pointers and references are:

- **Syntax**: Pointers are declared using an `*` before the variable name, while references use a `&`;

```cpp
  std::string name;     // Object.
  std::string *namePtr; // Pointer.
  std::string &namePtr; // Reference.
```

- **Nullability**: pointers can be set to null, while references must always be initialized to refer to an object and cannot be null.
- **Assignment**: pointers can be reassigned to point to a different object, while references cannot.
- **Memory management**: pointers are ideally used for dynamic memory allocation, while references provide an alias for an existing object.

> **Note**
>
> Unlike pointers, references cannot be null. Attempting to declare a reference without initializing it will result in a compiler error.
