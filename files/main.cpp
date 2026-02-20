#include <iostream>
#include <memory>
#include "MyLibrary.h"
#include "Member.h"
#include "Book.h"

int main() {
    std::cout << "===== Library Management System Demo =====\n\n";

    // Create the library (owns its BookRepository via composition)
    MyLibrary library("City Central Library");

    // --- Add Books ---
    std::cout << "--- Adding Books ---\n";
    library.addBook(std::make_unique<Book>("The Pragmatic Programmer", "Hunt & Thomas", "978-0135957059"));
    library.addBook(std::make_unique<Book>("Clean Code",              "Robert C. Martin", "978-0132350884"));
    library.addBook(std::make_unique<Book>("Design Patterns",         "Gang of Four",     "978-0201633610"));
    library.addBook(std::make_unique<Book>("The C++ Programming Language", "Bjarne Stroustrup", "978-0321563842"));
    library.addBook(std::make_unique<Book>("Effective Modern C++",    "Scott Meyers",     "978-1491903995"));

    library.listBooks();

    // --- Register Members ---
    std::cout << "\n--- Registering Members ---\n";
    RegularMember alice("Alice",   101);
    PremiumMember bob("Bob",       201);
    RegularMember carol("Carol",   102);

    library.registerMember(&alice);
    library.registerMember(&bob);
    library.registerMember(&carol);

    library.listMembers();

    // --- Borrow Books ---
    std::cout << "\n--- Borrowing Books ---\n";
    library.borrowBook(101, "978-0135957059");  // Alice borrows Pragmatic Programmer
    library.borrowBook(101, "978-0132350884");  // Alice borrows Clean Code
    library.borrowBook(101, "978-0201633610");  // Alice borrows Design Patterns (hits limit)
    library.borrowBook(201, "978-0321563842");  // Bob borrows C++ Programming Language
    library.borrowBook(201, "978-1491903995");  // Bob borrows Effective Modern C++
    library.borrowBook(201, "978-0201633610");  // Bob borrows Design Patterns
    library.borrowBook(102, "978-0132350884");  // Carol tries already-borrowed book

    library.listBooks();
    library.listMembers();

    // --- Return Books ---
    std::cout << "\n--- Returning Books ---\n";
    library.returnBook(101, "978-0132350884");  // Alice returns Clean Code
    library.returnBook(102, "978-0132350884");  // Carol borrows now-available Clean Code
    library.borrowBook(102, "978-0132350884");

    library.listBooks();
    library.listMembers();

    // --- Unregister a Member ---
    std::cout << "\n--- Unregistering Carol ---\n";
    library.unregisterMember(102);
    library.listMembers();

    std::cout << "\n===== Demo Complete =====\n";
    return 0;
}
