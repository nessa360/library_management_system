#include "Member.h"
#include <algorithm>
#include <sstream>
#include <iostream>

Member::Member(const std::string& name, int member_id, int max_books)
    : name_(name), member_id_(member_id), max_books_(max_books) {}

std::string Member::getName() const { return name_; }
int Member::getMemberId() const { return member_id_; }
int Member::getMaxBooks() const { return max_books_; }
const std::vector<Book*>& Member::getBorrowedBooks() const { return borrowed_books_; }

bool Member::borrowBook(Book* book) {
    if (!book) {
        std::cout << "Error: null book pointer.\n";
        return false;
    }
    if (book->isBorrowed()) {
        std::cout << "Book \"" << book->getTitle() << "\" is already borrowed.\n";
        return false;
    }
    if (static_cast<int>(borrowed_books_.size()) >= max_books_) {
        std::cout << name_ << " has reached the borrow limit (" << max_books_ << " books).\n";
        return false;
    }
    borrowed_books_.push_back(book);
    book->setBorrowed(true);
    std::cout << name_ << " borrowed \"" << book->getTitle() << "\".\n";
    return true;
}

bool Member::returnBook(const std::string& isbn) {
    auto it = std::find_if(borrowed_books_.begin(), borrowed_books_.end(),
        [&isbn](Book* b) { return b->getIsbn() == isbn; });

    if (it == borrowed_books_.end()) {
        std::cout << name_ << " does not have a book with ISBN " << isbn << ".\n";
        return false;
    }
    (*it)->setBorrowed(false);
    std::cout << name_ << " returned \"" << (*it)->getTitle() << "\".\n";
    borrowed_books_.erase(it);
    return true;
}

std::string Member::toString() const {
    std::ostringstream oss;
    oss << "[" << getMemberType() << "] " << name_ << " (ID: " << member_id_ << ")"
        << " | Borrowed: " << borrowed_books_.size() << "/" << max_books_;
    return oss.str();
}

// RegularMember
RegularMember::RegularMember(const std::string& name, int member_id)
    : Member(name, member_id, 3) {}

std::string RegularMember::getMemberType() const { return "Regular"; }

// PremiumMember
PremiumMember::PremiumMember(const std::string& name, int member_id)
    : Member(name, member_id, 5) {}

std::string PremiumMember::getMemberType() const { return "Premium"; }
