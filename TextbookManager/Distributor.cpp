#include "Distributor.h"

using namespace std;


Distributor::Distributor() {}

Distributor::Distributor(const string& n, const string& a, const string& p) : name(n), address(a), phone(p) {}

string Distributor::getName() const { return name; }
void Distributor::setName(const string& n) { name = n; }

string Distributor::getAddress() const { return address; }
void Distributor::setAddress(const string& a) { address = a; }

string Distributor::getPhone() const { return phone; }
void Distributor::setPhone(const string& p) { phone = p; }

ostream& operator<<(ostream& os, const Distributor& d) {
    os << "Name: " << d.name << "\n"
        << "Address: " << d.address << "\n"
        << "Phone: " << d.phone << "\n";
    return os;
}