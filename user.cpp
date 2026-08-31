// #include<iostream>
#include"user_account.h"
#include<iomanip>

int User::nextAccountNumber = 0;

User::User(std::string fn, std::string ln, double bal   ): firstName(fn), lastName(ln), balance(bal){
    accountNumber = ++nextAccountNumber;
}
int User::getAccountNumber() const{
    return accountNumber;
}
std::string User::getFirstName() const{
    return firstName;
}
std::string User::getLastName() const{
    return lastName;
}
std::string User::getFullName() const{
    return firstName + " " + lastName;
}
double User::getBalance() const{
    return balance;
}
void User::updateBalance(double bal){
    balance = bal;
}


std::ostream & operator<<(std::ostream& COUT, User& u){
    COUT << "First Name: " << u.getFirstName() << std::endl;
    COUT << "Last Name: " << u.getLastName() << std::endl;
    COUT << "Account Number: " << u.getAccountNumber() << std::endl;
    COUT << "Balance: " << std::fixed << std::setprecision(2) << u.getBalance() << std::endl;
    return COUT;
}

std::ofstream & operator<<(std::ofstream& ofs, User& u){
    ofs << u.getFirstName() << " " << u.getLastName() << " " << u.getAccountNumber() << " " << std::fixed << std::setprecision(2) << u.getBalance() << std::endl;
    return ofs;
}

std::ifstream& operator>>(std::ifstream& ifs, User& u){
    ifs >> u.firstName
    >> u.lastName
    >> u.accountNumber
    >> u.balance;
    return ifs;
}
