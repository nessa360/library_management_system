# Library Management System (C++)

A simplified Library Management System implemented in C++ demonstrating core Object-Oriented Programming concepts: encapsulation, inheritance, abstraction, composition, aggregation, and association.

---

## Project Structure

```
library_system/
├── Book.h / Book.cpp               # Book class with encapsulation
├── Member.h / Member.cpp           # Member base class + RegularMember & PremiumMember
├── BookRepository.h / BookRepository.cpp  # Manages the collection of books
├── AbstractLibrary.h               # Abstract base class for library operations
├── MyLibrary.h / MyLibrary.cpp     # Concrete library implementation
└── main.cpp                        # Demo / entry point
```

---

## OOP Concepts Used

**Encapsulation** — `Book` stores title, author, and ISBN as private attributes, accessed only through getters and setters.

**Inheritance** — `Member` is the abstract base class. `RegularMember` (borrow limit: 3) and `PremiumMember` (borrow limit: 5) inherit from it.

**Abstraction** — `AbstractLibrary` defines the interface (`addBook`, `borrowBook`, `returnBook`) as pure virtual methods. `MyLibrary` provides the concrete implementation.

**Composition** — `MyLibrary` owns a `BookRepository` by value. The repository's lifetime is tied to the library.

**Aggregation** — `MyLibrary` holds non-owning pointers to `Member` objects. Members exist independently and can register or unregister.

**Association** — When a book is borrowed, both the `Member` and the `Book` object reflect the relationship at runtime.

---

## How to Compile and Run

Requires a C++17 compatible compiler (g++ or clang++).

```bash
g++ -std=c++17 -Wall -Wextra -o library_demo \
    Book.cpp BookRepository.cpp Member.cpp MyLibrary.cpp main.cpp

./library_demo
```

---

## Example Output

```
===== Library Management System Demo =====

--- Adding Books ---
Added book: "The Pragmatic Programmer" by Hunt & Thomas (ISBN: 978-0135957059) [AVAILABLE]
Added book: "Clean Code" by Robert C. Martin (ISBN: 978-0132350884) [AVAILABLE]

--- Registering Members ---
Regular member "Alice" registered at City Central Library.
Premium member "Bob" registered at City Central Library.

--- Borrowing Books ---
Alice borrowed "The Pragmatic Programmer".
Alice borrowed "Clean Code".
Alice borrowed "Design Patterns".
Bob borrowed "The C++ Programming Language".

--- Returning Books ---
Alice returned "Clean Code".
Carol borrowed "Clean Code".
```