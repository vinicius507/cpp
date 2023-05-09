# CPP-00: Introduction to C++

## EX-00: MEGAPHONE

The goal of this exercise is to build a tool that behaves like a megaphone, converting all alphabetic characters in the application's arguments to their uppercase form.

It uses the [`std::toupper`](https://en.cppreference.com/w/cpp/string/byte/toupper) function from the standard library to convert the characters.

Here's an example of how to use the tool:

```
$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *

$ ./megaphone "Hey!" "Don't make noise! The kids are asleep!"
HEY! DON'T MAKE NOISE! THE KIDS ARE ASLEEP!
```
