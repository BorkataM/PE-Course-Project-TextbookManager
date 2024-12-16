#include <vector>
#include "Textbook.h"
#include "Distributor.h"
#include "Order.h"
#include "Menu.h"

using namespace std;

int main() {
    vector<Textbook> textbooks;
    vector<Distributor> distributors;

    displayMenu(textbooks, distributors);

    return 0;
}
