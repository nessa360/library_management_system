#ifndef BOOK_REPOSITORY_H
#define BOOK_REPOSITORY_H

#include <vector>
#include <memory>
#include <string>
#include "Book.h"

// BookRepository wraps a collection of Book objects (Composition with MyLibrary)
class BookRepository {
private:
    std::vector<std::unique_ptr<Book>> books_;

public:
    void addBook(std::unique_ptr<Book> book);
    Book* findByIsbn(const std::string& isbn);
    bool removeBook(const std::string& isbn);
    void listBooks() const;
    size_t size() const;
};

#endif // BOOK_REPOSITORY_H
