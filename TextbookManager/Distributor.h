#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <string>
#include <iostream>

using namespace std;

class Distributor {
private:
    std::string name;
    std::string address;
    std::string phone;

public:
    Distributor();
    Distributor(const string& n, const string& a, const string& p);

    std::string getName() const;
    void setName(const string& n);

    std::string getAddress() const;
    void setAddress(const string& a);

    std::string getPhone() const;
    void setPhone(const string& p);

    friend ostream& operator<<(ostream& os, const Distributor& d);
};

#endif