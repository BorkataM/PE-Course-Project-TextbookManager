#include "Order.h"

void Order::setDistributor(const Distributor& d) { distributor = d; }

void Order::addTextbook(const Textbook& t, double price) {
    textbooks.push_back(t);
    prices.push_back(price);
}

void Order::calculateTotal() const {
    double total = 0;
    for (double price : prices) {
        total += price;
    }
    std::cout << "Total Order Price: " << std::fixed << std::setprecision(2) << total << "\n";
}

void Order::printOrder() const {
    std::cout << "Distributor Information:\n" << distributor << "\n";
    std::cout << "Ordered Textbooks:\n";
    for (size_t i = 0; i < textbooks.size(); ++i) {
        std::cout << textbooks[i] << "Price: " << prices[i] << "\n\n";
    }
    calculateTotal();
}