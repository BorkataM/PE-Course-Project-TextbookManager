#include "Menu.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int getValidInt(const string& prompt, int min = INT_MIN, int max = INT_MAX) {
    int value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= min && value <= max) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Please try again.\n";
        clearInput();
    }
}

double getValidDouble(const string& prompt, double min = 0.0) {
    double value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (!cin.fail() && value >= min) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
        cout << "Invalid input. Please try again.\n";
        clearInput();
    }
}

string getNonEmptyString(const string& prompt) {
    string input;
    while (true) {
        cout << prompt;
        getline(cin, input);
        if (!input.empty()) return input;
        cout << "Input cannot be empty. Please try again.\n";
    }
}

void displayMenu(vector<Textbook>& textbooks, vector<Distributor>& distributors) {
    int choice;
    do {
        cout << "1. Add Textbook\n";
        cout << "2. Add Distributor\n";
        cout << "3. Make Order\n";
        cout << "4. Save Textbooks to File\n";
        cout << "5. Exit\n\n";
        cout << "Enter your choice: ";
        choice = getValidInt("", 1, 5);

        switch (choice) {
        case 1: {
            string title = getNonEmptyString("Enter title: ");
            string author = getNonEmptyString("Enter author: ");
            int edition = getValidInt("Enter edition (positive integer): ", 1);
            string isbn = getNonEmptyString("Enter ISBN: ");
            string releaseDate = getNonEmptyString("Enter release date: ");
            int copies = getValidInt("Enter copies (positive integer): ", 1);
            bool approved = getValidInt("Is it approved (1 for yes, 0 for no): ", 0, 1);

            string approvalDate;
            if (approved) {
                approvalDate = getNonEmptyString("Enter approval date: ");
            }

            textbooks.emplace_back(title, author, edition, isbn, releaseDate, copies, approved, approvalDate);
            break;
        }
        case 2: {
            string name = getNonEmptyString("Enter distributor name: ");
            string address = getNonEmptyString("Enter address: ");
            string phone = getNonEmptyString("Enter phone: ");
            distributors.emplace_back(name, address, phone);
            break;
        }
        case 3: {
            if (distributors.empty()) {
                cout << "No distributors available. Add a distributor first.\n";
                break;
            }

            cout << "Select a distributor:\n";
            for (size_t i = 0; i < distributors.size(); ++i) {
                cout << i + 1 << ". " << distributors[i].getName() << "\n";
            }
            int distributorIndex = getValidInt("Enter the distributor number: ", 1, distributors.size());

            Order order;
            order.setDistributor(distributors[distributorIndex - 1]);

            while (true) {
                cout << "Select a textbook to add to the order (0 to finish):\n";
                for (size_t i = 0; i < textbooks.size(); ++i) {
                    cout << i + 1 << ". " << textbooks[i].getTitle() << "\n";
                }

                int bookIndex = getValidInt("", 0, textbooks.size());
                if (bookIndex == 0) break;

                double price = getValidDouble("Enter price (positive number): ");
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
        case 5:
            cout << "Exiting...\n";
            break;
        }
    } while (choice != 5);
}
