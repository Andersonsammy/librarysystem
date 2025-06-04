
#include <iostream>
#include <vector>
#include <string>

class Book {
public:
    int id;
    std::string title;
    std::string author;
    bool isAvailable;

    Book(int id, std::string title, std::string author)
        : id(id), title(title), author(author), isAvailable(true) {}
};

class User {
public:
    int userId;
    std::string name;

    User(int id, std::string name) : userId(id), name(name) {}
};

class Library {
private:
    std::vector<Book> books;

public:
    void addBook(Book book);
    void removeBook(int bookId);
    void searchBook(std::string keyword);
    void borrowBook(int bookId);
    void returnBook(int bookId);
};

void Library::addBook(Book book) {
    books.push_back(book);
    std::cout << "Book added: " << book.title << std::endl;
}

void Library::removeBook(int bookId) {
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->id == bookId) {
            std::cout << "Book removed: " << it->title << std::endl;
            books.erase(it);
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Library::searchBook(std::string keyword) {
    for (auto &book : books) {
        if (book.title.find(keyword) != std::string::npos ||
            book.author.find(keyword) != std::string::npos) {
            std::cout << "Found: " << book.title << " by " << book.author << std::endl;
        }
    }
}

void Library::borrowBook(int bookId) {
    for (auto &book : books) {
        if (book.id == bookId && book.isAvailable) {
            book.isAvailable = false;
            std::cout << "You borrowed: " << book.title << std::endl;
            return;
        }
    }
    std::cout << "Book is not available.\n";
}

void Library::returnBook(int bookId) {
    for (auto &book : books) {
        if (book.id == bookId && !book.isAvailable) {
            book.isAvailable = true;
            std::cout << "You returned: " << book.title << std::endl;
            return;
        }
    }
    std::cout << "Invalid return.\n";
}

int main() {
    Library lib;
    Book b1(1, "C++ Basics", "John Doe");
    Book b2(2, "OOP Concepts", "Jane Smith");

    lib.addBook(b1);
    lib.addBook(b2);

    lib.searchBook("C++");

    lib.borrowBook(1);
    lib.returnBook(1);
    lib.removeBook(2);

    return 0;
}
