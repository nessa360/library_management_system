#include "MyLibrary.h"
#include <iostream>
#include <algorithm>

MyLibrary::MyLibrary(const std::string& name) : library_name_(name) {}

Member* MyLibrary::findMember(int member_id) const {
    auto it = std::find_if(registered_members_.begin(), registered_members_.end(),
        [member_id](Member* m) { return m->getMemberId() == member_id; });
    return (it != registered_members_.end()) ? *it : nullptr;
}

void MyLibrary::registerMember(Member* member) {
    if (!member) return;
    if (findMember(member->getMemberId())) {
        std::cout << "Member " << member->getName() << " is already registered.\n";
        return;
    }
    registered_members_.push_back(member);
    std::cout << member->getMemberType() << " member \"" << member->getName()
              << "\" registered at " << library_name_ << ".\n";
}

void MyLibrary::unregisterMember(int member_id) {
    auto it = std::find_if(registered_members_.begin(), registered_members_.end(),
        [member_id](Member* m) { return m->getMemberId() == member_id; });
    if (it == registered_members_.end()) {
        std::cout << "Member ID " << member_id << " not found.\n";
        return;
    }
    std::cout << "Member \"" << (*it)->getName() << "\" unregistered.\n";
    registered_members_.erase(it);
}

void MyLibrary::addBook(std::unique_ptr<Book> book) {
    std::cout << "Added book: " << book->toString() << "\n";
    book_repository_.addBook(std::move(book));
}

bool MyLibrary::borrowBook(int member_id, const std::string& isbn) {
    Member* member = findMember(member_id);
    if (!member) {
        std::cout << "Member ID " << member_id << " is not registered.\n";
        return false;
    }
    Book* book = book_repository_.findByIsbn(isbn);
    if (!book) {
        std::cout << "Book with ISBN " << isbn << " not found.\n";
        return false;
    }
    return member->borrowBook(book);
}

bool MyLibrary::returnBook(int member_id, const std::string& isbn) {
    Member* member = findMember(member_id);
    if (!member) {
        std::cout << "Member ID " << member_id << " is not registered.\n";
        return false;
    }
    return member->returnBook(isbn);
}

void MyLibrary::listBooks() const {
    std::cout << "\n=== Books in " << library_name_ << " ===\n";
    book_repository_.listBooks();
}

void MyLibrary::listMembers() const {
    std::cout << "\n=== Registered Members at " << library_name_ << " ===\n";
    if (registered_members_.empty()) {
        std::cout << "  (no members registered)\n";
        return;
    }
    for (const auto& member : registered_members_) {
        std::cout << "  " << member->toString() << "\n";
        for (const auto& book : member->getBorrowedBooks()) {
            std::cout << "    -> " << book->toString() << "\n";
        }
    }
}
