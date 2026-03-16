#include <iostream>
#include <vector>
using namespace std;

struct Book {
    string title;
    string author;
    string isbn;
    bool available;
    string borrower;
    int dueDays;
};

vector<Book> library;

// Add book to database
void addBook() {
    Book b;
    cout << "Enter Title: ";
    cin.ignore();
    getline(cin, b.title);

    cout << "Enter Author: ";
    getline(cin, b.author);

    cout << "Enter ISBN: ";
    getline(cin, b.isbn);

    b.available = true;
    library.push_back(b);

    cout << "Book added successfully!\n";
}

// View all books
void viewBooks() {
    if (library.empty()) {
        cout << "No books available.\n";
        return;
    }

    for (int i = 0; i < library.size(); i++) {
        cout << "\nBook " << i + 1 << endl;
        cout << "Title: " << library[i].title << endl;
        cout << "Author: " << library[i].author << endl;
        cout << "ISBN: " << library[i].isbn << endl;
        cout << "Status: " << (library[i].available ? "Available" : "Checked Out") << endl;
    }
}

// Search books
void searchBook() {
    string keyword;
    cout << "Enter Title/Author/ISBN to search: ";
    cin.ignore();
    getline(cin, keyword);

    bool found = false;

    for (auto &b : library) {
        if (b.title == keyword || b.author == keyword || b.isbn == keyword) {
            cout << "\nBook Found\n";
            cout << "Title: " << b.title << endl;
            cout << "Author: " << b.author << endl;
            cout << "ISBN: " << b.isbn << endl;
            cout << "Status: " << (b.available ? "Available" : "Checked Out") << endl;
            found = true;
        }
    }

    if (!found)
        cout << "Book not found.\n";
}

// Checkout book
void checkoutBook() {
    string isbn, name;
    int days;

    cout << "Enter ISBN of book: ";
    cin >> isbn;

    for (auto &b : library) {
        if (b.isbn == isbn && b.available) {
            cout << "Enter borrower name: ";
            cin >> name;

            cout << "Enter due days: ";
            cin >> days;

            b.available = false;
            b.borrower = name;
            b.dueDays = days;

            cout << "Book checked out successfully.\n";
            return;
        }
    }

    cout << "Book not available.\n";
}

// Return book
void returnBook() {
    string isbn;
    int lateDays;

    cout << "Enter ISBN of returning book: ";
    cin >> isbn;

    for (auto &b : library) {
        if (b.isbn == isbn && !b.available) {

            cout << "Enter number of late days: ";
            cin >> lateDays;

            int fine = lateDays * 5; // ₹5 per day

            b.available = true;
            b.borrower = "";

            cout << "Book returned successfully.\n";
            cout << "Fine: ₹" << fine << endl;

            return;
        }
    }

    cout << "Book record not found.\n";
}

int main() {

    int choice;

    do {
        cout << "\n===== LIBRARY MANAGEMENT SYSTEM =====\n";
        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Checkout Book\n";
        cout << "5. Return Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {

            case 1: addBook(); break;
            case 2: viewBooks(); break;
            case 3: searchBook(); break;
            case 4: checkoutBook(); break;
            case 5: returnBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice\n";

        }

    } while(choice != 6);

    return 0;
}