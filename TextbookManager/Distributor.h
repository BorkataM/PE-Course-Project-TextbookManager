#ifndef DISTRIBUTOR_H
#define DISTRIBUTOR_H

#include <string>
#include <iostream>

class Distributor {
private:
    std::string name;
    std::string address;
    std::string phone;

public:
    Distributor();
    Distributor(const std::string& n, const std::string& a, const std::string& p);

    std::string getName() const;
    void setName(const std::string& n);

    std::string getAddress() const;
    void setAddress(const std::string& a);

    std::string getPhone() const;
    void setPhone(const std::string& p);

    friend std::ostream& operator<<(std::ostream& os, const Distributor& d);
};

#endif