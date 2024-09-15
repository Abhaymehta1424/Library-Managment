#include <iostream>
#include <string>

using namespace std;

const int MAX_BOOKS = 100;

struct Book {
    int id;
    string title;
    string author;
    bool isIssued;
    string issuedTo;
};

class LibraryManagementSystem {
private:
    Book books[MAX_BOOKS];
    int bookCount;

public:
    LibraryManagementSystem() : bookCount(0) {}

    void addBook() {
        if (bookCount >= MAX_BOOKS) {
            cout << "Library is full. Cannot add more books.\n";
            cout << "---------------------------\n";
            return;
        }

        Book newBook;
        cout << "Enter Book ID: ";
        cin >> newBook.id;
        cin.ignore(); // Clear newline character from the input buffer
        cout << "Enter Book Title: ";
        getline(cin, newBook.title);
        cout << "Enter Book Author: ";
        getline(cin, newBook.author);
        newBook.isIssued = false;
        newBook.issuedTo = "";

        books[bookCount++] = newBook;
        cout << "Book added successfully.\n";
        cout << "---------------------------\n";
    }

    void searchBook() {
        int id;
        cout << "Enter Book ID to search: ";
        cin >> id;

        for (int i = 0; i < bookCount; ++i) {
            if (books[i].id == id) {
                cout << "Book Found:\n";
                cout << "ID: " << books[i].id
                     << "\nTitle: " << books[i].title
                     << "\nAuthor: " << books[i].author
                     << "\nStatus: " << (books[i].isIssued ? "Issued" : "Available")
                     << "\nIssued To: " << (books[i].isIssued ? books[i].issuedTo : "N/A") << endl;
                return;
            }
        }
        cout << "Book not found.\n";
        cout << "---------------------------\n";
    }

    void issueBook() {
        int id;
        cout << "Enter Book ID to issue: ";
        cin >> id;
        cin.ignore(); // Clear newline character from the input buffer

        string studentName;
        cout << "Enter Student Name: ";
        getline(cin, studentName);

        for (int i = 0; i < bookCount; ++i) {
            if (books[i].id == id) {
                if (books[i].isIssued) {
                    cout << "Book is already issued.\n";
                    cout << "---------------------------\n";
                } else {
                    books[i].isIssued = true;
                    books[i].issuedTo = studentName;
                    cout << "Book issued to " << studentName << ".\n";
                    cout << "---------------------------\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
        cout << "---------------------------\n";
    }

    void returnBook() {
        int id;
        cout << "Enter Book ID to return: ";
        
        cin >> id;

        for (int i = 0; i < bookCount; ++i) {
            if (books[i].id == id) {
                if (!books[i].isIssued) {
                    cout << "Book was not issued.\n";
                    cout << "---------------------------\n";
                } else {
                    books[i].isIssued = false;
                    books[i].issuedTo = "";
                    cout << "Book returned successfully.\n";
                    cout << "---------------------------\n";
                }
                return;
            }
        }
        cout << "Book not found.\n";
        cout << "---------------------------\n";
    }

    void listAllBooks() {
        if (bookCount == 0) {
            cout << "No books available.\n";
            cout << "---------------------------\n";
            return;
        }

        // Sorting books by ID using a simple bubble sort
        for (int i = 0; i < bookCount - 1; ++i) {
            for (int j = 0; j < bookCount - i - 1; ++j) {
                if (books[j].id > books[j + 1].id) {
                    Book temp = books[j];
                    books[j] = books[j + 1];
                    books[j + 1] = temp;
                }
            }
        }

        cout << "List of all books:\n";
        for (int i = 0; i < bookCount; ++i) {
            cout << "ID: " << books[i].id
                 << "\nTitle: " << books[i].title
                 << "\nAuthor: " << books[i].author
                 << "\nStatus: " << (books[i].isIssued ? "Issued" : "Available")
                 << "\nIssued To: " << (books[i].isIssued ? books[i].issuedTo : "N/A") << endl
                 << "---------------------------\n";
        }
    }

    void deleteBook() {
        int id;
        cout << "Enter Book ID to delete: ";
        cin >> id;

        int i;
        for (i = 0; i < bookCount; ++i) {
            if (books[i].id == id) {
                break;
            }
        }

        if (i == bookCount) {
            cout << "Book not found.\n";
            cout << "---------------------------\n";
            return;
        }

        // Shift books to remove the deleted book
        for (int j = i; j < bookCount - 1; ++j) {
            books[j] = books[j + 1];
        }
        --bookCount;
        cout << "Book deleted successfully.\n";
        cout << "---------------------------\n";
    }
};

int main() {
    LibraryManagementSystem library;
    int choice;

    while (true) {
    	cout << "";
        cout << "Library Management System Menu:\n";
        cout << "1. Add New Book\n";
        cout << "2. Search for a Book\n";
        cout << "3. Issue a Book\n";
        cout << "4. Return a Book\n";
        cout << "5. List All Books\n";
        cout << "6. Delete a Book\n";
        cout << "7. Exit\n";
        cout << "";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 7) break;

        switch (choice) {
            case 1:
                library.addBook();
                break;
            case 2:
                library.searchBook();
                break;
            case 3:
                library.issueBook();
                break;
            case 4:
                library.returnBook();
                break;
            case 5:
                library.listAllBooks();
                break;
            case 6:
                library.deleteBook();
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
                break;
        }
    }

    return 0;
}

