#ifndef MY_LIBRARY_H
#define MY_LIBRARY_H

#include "AbstractLibrary.h"
#include "BookRepository.h"
#include <vector>
#include <memory>

// MyLibrary is the concrete implementation of AbstractLibrary.
// Composition: owns a BookRepository (lifetime tied to MyLibrary).
// Aggregation: holds non-owning pointers to Member objects (members come and go).
// Association: Members loosely connect to the library to borrow books.
class MyLibrary : public AbstractLibrary {
private:
    std::string library_name_;
    BookRepository book_repository_;              // Composition
    std::vector<Member*> registered_members_;     // Aggregation

    Member* findMember(int member_id) const;

public:
    explicit MyLibrary(const std::string& name);

    void registerMember(Member* member);
    void unregisterMember(int member_id);

    // AbstractLibrary interface
    void addBook(std::unique_ptr<Book> book) override;
    bool borrowBook(int member_id, const std::string& isbn) override;
    bool returnBook(int member_id, const std::string& isbn) override;
    void listBooks() const override;
    void listMembers() const override;
};

#endif // MY_LIBRARY_H
