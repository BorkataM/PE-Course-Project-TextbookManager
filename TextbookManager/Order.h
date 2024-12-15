#ifndef ORDER_H
#define ORDER_H

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include "Distributor.h"
#include "Textbook.h"

class Order {
private:
    Distributor distributor;
    std::vector<Textbook> textbooks;
    std::vector<double> prices;

public:
    void setDistributor(const Distributor& d);
    void addTextbook(const Textbook& t, double price);
    void calculateTotal() const;
    void printOrder() const;
};

#endif