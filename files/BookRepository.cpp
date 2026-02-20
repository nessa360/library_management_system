#include "BookRepository.h"
#include <algorithm>
#include <iostream>

void BookRepository::addBook(std::unique_ptr<Book> book) {
    books_.push_back(std::move(book));
}

Book* BookRepository::findByIsbn(const std::string& isbn) {
    auto it = std::find_if(books_.begin(), books_.end(),
        [&isbn](const std::unique_ptr<Book>& b) { return b->getIsbn() == isbn; });
    return (it != books_.end()) ? it->get() : nullptr;
}

bool BookRepository::removeBook(const std::string& isbn) {
    auto it = std::find_if(books_.begin(), books_.end(),
        [&isbn](const std::unique_ptr<Book>& b) { return b->getIsbn() == isbn; });
    if (it == books_.end()) return false;
    books_.erase(it);
    return true;
}

void BookRepository::listBooks() const {
    if (books_.empty()) {
        std::cout << "  (no books in repository)\n";
        return;
    }
    for (const auto& book : books_) {
        std::cout << "  " << book->toString() << "\n";
    }
}

size_t BookRepository::size() const {
    return books_.size();
}
