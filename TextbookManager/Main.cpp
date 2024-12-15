#include <vector>
#include "Textbook.h"
#include "Distributor.h"
#include "Order.h"
#include "Menu.h"

int main() {
    std::vector<Textbook> textbooks;
    std::vector<Distributor> distributors;

    displayMenu(textbooks, distributors);

    return 0;
}
