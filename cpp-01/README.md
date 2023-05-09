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
