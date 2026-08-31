#pragma once

#include <iostream>
#include <string>
#include <fstream>

class User {
private:
    std::string firstName;
    std::string lastName;
    double balance;

    static int nextAccountNumber;
    int accountNumber;

public:
    User(std::string fn = "", std::string ln = "", double bal = 0);

    int getAccountNumber() const;
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    double getBalance() const;

    void updateBalance(double bal);

    friend std::ostream& operator<<(std::ostream& ofs, User& u);
    friend std::istream& operator>>(std::istream& ifs, User& u);
    friend std::ofstream & operator<<(std::ofstream& COUT, User& u);
    friend std::ifstream& operator>>(std::ifstream& CIN, User& u);
};