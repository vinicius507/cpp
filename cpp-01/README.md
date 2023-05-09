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
