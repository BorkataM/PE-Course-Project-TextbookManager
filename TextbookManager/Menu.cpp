#include "Menu.h"
#include <iostream>
#include <fstream>

void displayMenu(std::vector<Textbook>& textbooks, std::vector<Distributor>& distributors) {
    int choice;
    do {
        std::cout << "1. Add Textbook\n";
        std::cout << "2. Add Distributor\n";
        std::cout << "3. Make Order\n";
        std::cout << "4. Save Textbooks to File\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
        case 1: {
            std::string title, author, isbn, releaseDate, approvalDate;
            int edition, copies;
            bool approved;

            std::cout << "Enter title: ";
            std::getline(std::cin, title);
            std::cout << "Enter author: ";
            std::getline(std::cin, author);
            std::cout << "Enter edition: ";
            std::cin >> edition;
            std::cin.ignore();
            std::cout << "Enter ISBN: ";
            std::getline(std::cin, isbn);
            std::cout << "Enter release date: ";
            std::getline(std::cin, releaseDate);
            std::cout << "Enter copies: ";
            std::cin >> copies;
            std::cin.ignore();
            std::cout << "Is it approved (1 for yes, 0 for no): ";
            std::cin >> approved;
            std::cin.ignore();

            if (approved) {
                std::cout << "Enter approval date: ";
                std::getline(std::cin, approvalDate);
            }

            textbooks.emplace_back(title, author, edition, isbn, releaseDate, copies, approved, approvalDate);
            break;
        }
        case 2: {
            std::string name, address, phone;
            std::cout << "Enter distributor name: ";
            std::getline(std::cin, name);
            std::cout << "Enter address: ";
            std::getline(std::cin, address);
            std::cout << "Enter phone: ";
            std::getline(std::cin, phone);

            distributors.emplace_back(name, address, phone);
            break;
        }
        case 3: {
            if (distributors.empty()) {
                std::cout << "No distributors available. Add a distributor first.\n";
                break;
            }

            int distributorIndex;
            std::cout << "Select a distributor:\n";
            for (size_t i = 0; i < distributors.size(); ++i) {
                std::cout << i + 1 << ". " << distributors[i].getName() << "\n";
            }
            std::cin >> distributorIndex;
            std::cin.ignore();

            if (distributorIndex < 1 || distributorIndex > distributors.size()) {
                std::cout << "Invalid choice.\n";
                break;
            }

            Order order;
            order.setDistributor(distributors[distributorIndex - 1]);

            while (true) {
                int bookIndex;
                double price;
                std::cout << "Select a textbook to add to the order (0 to finish):\n";
                for (size_t i = 0; i < textbooks.size(); ++i) {
                    std::cout << i + 1 << ". " << textbooks[i].getTitle() << "\n";
                }
                std::cin >> bookIndex;

                if (bookIndex == 0) {
                    break;
                }

                if (bookIndex < 1 || bookIndex > textbooks.size()) {
                    std::cout << "Invalid choice.\n";
                    continue;
                }

                std::cout << "Enter price: ";
                std::cin >> price;
                std::cin.ignore();

                order.addTextbook(textbooks[bookIndex - 1], price);
            }

            order.printOrder();
            break;
        }
        case 4: {
            std::ofstream outFile("textbooks.txt");
            if (!outFile) {
                std::cout << "Error opening file for writing.\n";
                break;
            }

            for (const auto& textbook : textbooks) {
                outFile << textbook << "\n";
            }

            outFile.close();
            std::cout << "Textbooks saved to file successfully.\n";
            break;
        }
        case 5: {
            std::cout << "Exiting...\n";
            break;
        }
        default: {
            std::cout << "Invalid choice. Try again.\n";
        }
        }
    } while (choice != 5);
}
