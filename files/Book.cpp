#include "Book.h"
#include <sstream>

Book::Book(const std::string& title, const std::string& author, const std::string& isbn)
    : title_(title), author_(author), isbn_(isbn), is_borrowed_(false) {}

std::string Book::getTitle() const { return title_; }
std::string Book::getAuthor() const { return author_; }
std::string Book::getIsbn() const { return isbn_; }
bool Book::isBorrowed() const { return is_borrowed_; }

void Book::setTitle(const std::string& title) { title_ = title; }
void Book::setAuthor(const std::string& author) { author_ = author; }
void Book::setIsbn(const std::string& isbn) { isbn_ = isbn; }
void Book::setBorrowed(bool borrowed) { is_borrowed_ = borrowed; }

std::string Book::toString() const {
    std::ostringstream oss;
    oss << "\"" << title_ << "\" by " << author_ << " (ISBN: " << isbn_ << ")"
        << (is_borrowed_ ? " [BORROWED]" : " [AVAILABLE]");
    return oss.str();
}
