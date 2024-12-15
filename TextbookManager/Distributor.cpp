#include "Distributor.h"

Distributor::Distributor() {}

Distributor::Distributor(const std::string& n, const std::string& a, const std::string& p) : name(n), address(a), phone(p) {}

std::string Distributor::getName() const { return name; }
void Distributor::setName(const std::string& n) { name = n; }

std::string Distributor::getAddress() const { return address; }
void Distributor::setAddress(const std::string& a) { address = a; }

std::string Distributor::getPhone() const { return phone; }
void Distributor::setPhone(const std::string& p) { phone = p; }

std::ostream& operator<<(std::ostream& os, const Distributor& d) {
    os << "Name: " << d.name << "\n"
        << "Address: " << d.address << "\n"
        << "Phone: " << d.phone << "\n";
    return os;
}