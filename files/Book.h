#ifndef BOOK_H
#define BOOK_H

#include <string>

class Book {
private:
    std::string title_;
    std::string author_;
    std::string isbn_;
    bool is_borrowed_;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn);

    // Getters
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getIsbn() const;
    bool isBorrowed() const;

    // Setters
    void setTitle(const std::string& title);
    void setAuthor(const std::string& author);
    void setIsbn(const std::string& isbn);
    void setBorrowed(bool borrowed);

    std::string toString() const;
};

#endif // BOOK_H
