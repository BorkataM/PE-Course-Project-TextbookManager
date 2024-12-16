#include "Menu.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void displayMenu(vector<Textbook>& textbooks, vector<Distributor>& distributors) {
    int choice;
    do {
        cout << "1. Add Textbook\n";
        cout << "2. Add Distributor\n";
        cout << "3. Make Order\n";
        cout << "4. Save Textbooks to File\n";
        cout << "5. Exit\n\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1: {
            string title, author, isbn, releaseDate, approvalDate;
            int edition, copies;
            bool approved;

            cout << "Enter title: ";
            getline(cin, title);
            cout << "Enter author: ";
            getline(cin, author);
            cout << "Enter edition: ";
            cin >> edition;
            cin.ignore();
            cout << "Enter ISBN: ";
            getline(cin, isbn);
            cout << "Enter release date: ";
            getline(cin, releaseDate);
            cout << "Enter copies: ";
            cin >> copies;
            cin.ignore();
            cout << "Is it approved (1 for yes, 0 for no): ";
            cin >> approved;
            cin.ignore();

            if (approved) {
                cout << "Enter approval date: ";
                getline(cin, approvalDate);
            }

            textbooks.emplace_back(title, author, edition, isbn, releaseDate, copies, approved, approvalDate);
            break;
        }
        case 2: {
            string name, address, phone;
            cout << "Enter distributor name: ";
            getline(cin, name);
            cout << "Enter address: ";
            getline(cin, address);
            cout << "Enter phone: ";
            getline(cin, phone);

            distributors.emplace_back(name, address, phone);
            break;
        }
        case 3: {
            if (distributors.empty()) {
                cout << "No distributors available. Add a distributor first.\n";
                break;
            }

            int distributorIndex;
            cout << "Select a distributor:\n";
            for (size_t i = 0; i < distributors.size(); ++i) {
                cout << i + 1 << ". " << distributors[i].getName() << "\n";
            }
            cin >> distributorIndex;
            cin.ignore();

            if (distributorIndex < 1 || distributorIndex > distributors.size()) {
                cout << "Invalid choice.\n";
                break;
            }

            Order order;
            order.setDistributor(distributors[distributorIndex - 1]);

            while (true) {
                int bookIndex;
                double price;
                cout << "Select a textbook to add to the order (0 to finish):\n";
                for (size_t i = 0; i < textbooks.size(); ++i) {
                    cout << i + 1 << ". " << textbooks[i].getTitle() << "\n";
                }
                cin >> bookIndex;

                if (bookIndex == 0) {
                    break;
                }

                if (bookIndex < 1 || bookIndex > textbooks.size()) {
                    cout << "Invalid choice.\n";
                    continue;
                }

                cout << "Enter price: ";
                cin >> price;
                cin.ignore();

                order.addTextbook(textbooks[bookIndex - 1], price);
            }

            order.printOrder();
            break;
        }
        case 4: {
            ofstream outFile("textbooks.txt");
            if (!outFile) {
                cout << "Error opening file for writing.\n";
                break;
            }

            for (const auto& textbook : textbooks) {
                outFile << textbook << "\n";
            }

            outFile.close();
            cout << "Textbooks saved to file successfully.\n";
            break;
        }
        case 5: {
            cout << "Exiting...\n";
            break;
        }
        default: {
            cout << "Invalid choice. Try again.\n";
        }
        }
    } while (choice != 5);
}
