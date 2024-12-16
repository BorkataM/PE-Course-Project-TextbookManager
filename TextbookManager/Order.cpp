#include "Order.h"

using namespace std;

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
    cout << "Total Order Price: " << fixed << setprecision(2) << total << "\n";
}

void Order::printOrder() const {
    cout << "Distributor Information:\n" << distributor << "\n";
    cout << "Ordered Textbooks:\n";
    for (size_t i = 0; i < textbooks.size(); ++i) {
        cout << textbooks[i] << "Price: " << prices[i] << "\n\n";
    }
    calculateTotal();
}