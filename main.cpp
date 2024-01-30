#include <iostream>
#include <vector>
#include <algorithm>  
#include <string>


class Book {
private:
    std::string title;
    std::string author;
    std::string isbn;

public:

    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : title(title), author(author), isbn(isbn) {}


    std::string getTitle() const {
        return title;
    }

    std::string getAuthor() const {
        return author;
    }

    std::string getISBN() const {
        return isbn;
    }


    void display() const {
        std::cout << "Title: " << title << "\nAuthor: " << author << "\nISBN: " << isbn << "\n\n";
    }
};


class Library {
private:
    std::vector<Book> books;

public:
   
    void addBook(const Book& book) {
        books.push_back(book);
    }

 
    void removeBook(const std::string& isbn) {
        auto it = std::remove_if(books.begin(), books.end(),
            [isbn](const Book& book) { return book.getISBN() == isbn; });

        if (it != books.end()) {
            books.erase(it, books.end());
            std::cout << "Book with ISBN " << isbn << " removed from the library.\n";
        } else {
            std::cout << "Book with ISBN " << isbn << " not found in the library.\n";
        }
    }


    void displayBooks() const {
        if (books.empty()) {
            std::cout << "No books in the library.\n";
        } else {
            std::cout << "Books in the library:\n";
            for (const Book& book : books) {
                book.display();
            }
        }
    }
};

int main() {
    Library library;


    std::cout << "Enter books for the library. Enter 'done' to finish.\n";
    std::string title, author, isbn;

    while (true) {
        std::cout << "Enter title (or 'done' to finish): ";
        std::getline(std::cin, title);

        if (title == "done") {
            break;
        }

        std::cout << "Enter author: ";
        std::getline(std::cin, author);

        std::cout << "Enter ISBN: ";
        std::getline(std::cin, isbn);

        Book newBook(title, author, isbn);
        library.addBook(newBook);
    }


    library.displayBooks();

   
    std::cout << "Enter ISBN to remove a book: ";
    std::getline(std::cin, isbn);
    library.removeBook(isbn);


    library.displayBooks();

    return 0;
}