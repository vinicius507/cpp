# CPP-00: Introduction to C++

## EX-00: MEGAPHONE

> This exercise introduces the concepts of C++ Streams using the `std::cout` output stream buffer.

The goal of this exercise is to build a tool that behaves like a megaphone, converting all alphabetic characters in the application's arguments to their uppercase form.

Here's an example of how to use the tool:

```sh
$ ./megaphone
* LOUD AND UNBEARABLE FEEDBACK NOISE *

$ ./megaphone "Hey!" "Don't make noise! The kids are asleep!"
HEY! DON'T MAKE NOISE! THE KIDS ARE ASLEEP!
```

## EX-01: PhoneBook

> This exercise introduces C++ classes.

In the PhoneBook exercise, I've created a command-line interface (CLI) tool for storing and displaying contact information.
The PhoneBook can store up to 8 contacts, and has three commands:

- `ADD`: Prompts the user to enter the details of a new contact and adds it to the PhoneBook. The contact details include the first name, last name, nickname, phone number, and darkest secret.
- `SEARCH`: Lists all the contacts in the PhoneBook and prompts the user to choose one. Once the user selects a contact, the tool displays its information.
- `EXIT`: Exits the PhoneBook.

Here's an example of how to use the tool:

```sh
$ ./phonebook
Welcome to the Phonebook CLI tool!
You can use the following commands:
  ADD       Adds a contact to the Phonebook
  SEARCH    Views information about a contact
  EXIT      Exits the application

phonebook# ADD
Add a contact
First name: Vinicius
Last name: Oliveira
Nickname: Myriad
Phone number: +55 83 91010-1010
Darkest secret: The 🍰 is a lie!

phonebook# SEARCH
+----------+----------+----------+----------+
|        Id|First name| Last name|  Nickname|
+----------+----------+----------+----------+
|         1|  Vinicius|  Oliveira|    Myriad|
+----------+----------+----------+----------+
Choose a contact by its index to view its information: 1
First name: Vinicius
Last name: Oliveira
Nickname: Myriad
Phone number: +55 83 91010-1010
Darkest secret: The 🍰 is a lie!

phonebook# EXIT
```
