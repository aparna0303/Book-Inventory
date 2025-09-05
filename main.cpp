#include<iostream>
#include <vector>
#include <string>
#include<limits>
using namespace std;

class Book {
    string title, author, publisher;
    float price;
    int stock;

public:
    Book() : price(0.0), stock(0) {}

    void input() {
        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);
        cout << "Enter Publisher Name: ";
        getline(cin, publisher);
        cout << "Enter Price: ";
        cin >> price;
        cout << "Enter Stock: ";
        cin >> stock;
        cin.ignore(); // clear input buffer
    }

    void display() const {
        cout << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nPublisher: " << publisher
             << "\nPrice: " << price
             << "\nStock: " << stock << "\n";
    }

    bool matches(string t, string a) const {
        return (title == t && author == a);
    }

    void buy(int qty) {
        if (qty <= stock) {
            cout << "Total Cost: Rs. " << price * qty << "\n";
            stock -= qty;
        } else {
            cout << "Only " << stock << " copies available!\n";
        }
    }
};

int main() {
    vector<Book> books;
    int choice;

    do {
        cout << "\n--- Book Inventory Menu ---\n";
        cout << "1. Add Book\n";
        cout << "2. Search Book\n";
        cout << "3. Buy Book\n";
        cout << "4. Display All Books\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        if (choice == 1) {
            Book b;
            b.input();
            books.push_back(b);
        }
        else if (choice == 2) {
            string t, a;
            cout << "Enter Title: ";
            getline(cin, t);
            cout << "Enter Author: ";
            getline(cin, a);
            bool found = false;
            for (const auto& b : books) {
                if (b.matches(t, a)) {
                    cout << "Book Found:\n";
                    b.display();
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 3) {
            string t, a;
            int qty;
            cout << "Enter Title: ";
            getline(cin, t);
            cout << "Enter Author: ";
            getline(cin, a);
            bool found = false;
            for (auto& b : books) {
                if (b.matches(t, a)) {
                    cout << "Enter Quantity to Buy: ";
                    cin >> qty;
                    cin.ignore();
                    b.buy(qty);
                    found = true;
                    break;
                }
            }
            if (!found) cout << "Book not found.\n";
        }
        else if (choice == 4) {
            if (books.empty()) cout << "No books in inventory.\n";
            else {
                for (const auto& b : books)
                    b.display();
            }
        }
        else if (choice != 5) {
            cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    cout << "Exiting the program.\n";
    return 0;
}
// g++ main.cpp -o main.exe
// .\main.exe