#ifndef ABSTRACT_LIBRARY_H
#define ABSTRACT_LIBRARY_H

#include <string>
#include <memory>
#include "Book.h"
#include "Member.h"

// Abstract base class representing the general concept of a Library
class AbstractLibrary {
public:
    virtual ~AbstractLibrary() = default;

    virtual void addBook(std::unique_ptr<Book> book) = 0;
    virtual bool borrowBook(int member_id, const std::string& isbn) = 0;
    virtual bool returnBook(int member_id, const std::string& isbn) = 0;
    virtual void listBooks() const = 0;
    virtual void listMembers() const = 0;
};

#endif // ABSTRACT_LIBRARY_H
