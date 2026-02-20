#ifndef MEMBER_H
#define MEMBER_H

#include <string>
#include <vector>
#include "Book.h"

class Member {
protected:
    std::string name_;
    int member_id_;
    std::vector<Book*> borrowed_books_;
    int max_books_;

public:
    Member(const std::string& name, int member_id, int max_books);
    virtual ~Member() = default;

    std::string getName() const;
    int getMemberId() const;
    int getMaxBooks() const;
    const std::vector<Book*>& getBorrowedBooks() const;

    virtual bool borrowBook(Book* book);
    virtual bool returnBook(const std::string& isbn);

    virtual std::string getMemberType() const = 0;
    std::string toString() const;
};

class RegularMember : public Member {
public:
    explicit RegularMember(const std::string& name, int member_id);
    std::string getMemberType() const override;
};

class PremiumMember : public Member {
public:
    explicit PremiumMember(const std::string& name, int member_id);
    std::string getMemberType() const override;
};

#endif // MEMBER_H
