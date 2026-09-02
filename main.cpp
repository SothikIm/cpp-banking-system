#include "user_account.h"
#include <cstdlib>
#include <map>
#include <conio.h>
#include<limits>
using namespace std;

class Bank{
    private:
        map<int, User> users;
    public:
        Bank();
        User OpenAccount(string fn, string ln, double bal);
        User BalanceEnquiry(int accountNumber);
        User Deposit(int accountNumber,float amount);
        User Withdraw(int accountNumber,float amount);
        void CloseAccount(int accountNumber);
        void ShowAllAccounts();
        bool HasThisAccount(int accountNumber);
        ~Bank();
};

void clearScreen()
{
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

void printMenu(){
    cout << "***Banking System***" << endl;
    cout << "\tSelect one option below: " << endl;
    cout << "\t1. Open an Account" << endl;
    cout << "\t2. Balance Enquiry" << endl;
    cout << "\t3. Deposit" << endl;
    cout << "\t4. Withdrawal" << endl;
    cout << "\t5. Close an Account" << endl;
    cout << "\t6. Show All Accounts" << endl;
    cout << "\t7. Clear Screen" << endl;
    cout << "\t8. Quit the system" << endl;
}

void getKeyToContinue(){
    cout << "Press space to continue: ";
    while(true){
        if(_kbhit()){ // check whether key is press or not
            char key = _getch(); // get the key without input
            if(key == ' '){
                break;
            }
        }
    }
}

template <typename T>  
T inputVariable(const string messages){
    T var;
    while(true)
    {
        try{
            cout << messages;
            if(!(cin >> var)){
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                throw runtime_error("Invalid Input");
            }
            break;
        }
        catch (runtime_error& e){
            cerr << e.what() << endl;
        }
    }
    return var;
}

void requireAccount(Bank& b, int accountNumber){
    if(!b.HasThisAccount(accountNumber))
        throw runtime_error("Account not found");
}

int main(){
    Bank b;
    User u;
    
    int choice;
    int accountNumber;
    float amount;

    string fn;
    string ln;
    double bal;
    do
    {
        /* code */
        printMenu();
        choice = inputVariable<int>("Enter your choice: ");
        switch (choice)
        {
        case 1:
            /* code */
            cout << "Enter your fist name: ";
            cin >> fn;
            cout << "Enter your last name: ";
            cin >> ln;
            bal = inputVariable<double>("Enter your balance: ");
            u = b.OpenAccount(fn, ln, bal);
            cout << "Congradulation Account is Created" <<endl;
            cout << u;
            break;
        case 2:
            /* code */
            try{
                accountNumber = inputVariable<int>("Enter your account number: ");
                requireAccount(b, accountNumber);
                u = b.BalanceEnquiry(accountNumber);
                cout << endl << "Your detial account: " << endl;
                cout << u;
            }
            catch(exception& e){
                cerr << e.what() << endl;
            }
            getKeyToContinue();
            break;
        case 3:
            /* code */
            try{
                accountNumber = inputVariable<int>("Enter your account number: ");
                requireAccount(b, accountNumber);
                amount = inputVariable<double>("Enter your amount: ");
                u = b.Deposit(accountNumber, amount);
                cout << endl << "Account is Deposited" << endl;
                cout << u;
            }
            catch (exception& e){
                cerr << e.what() << endl;
            }
            getKeyToContinue();
            break;
        case 4:
            /* code */
            try{
                accountNumber = inputVariable<int>("Enter your account number: ");
                requireAccount(b, accountNumber);
                amount = inputVariable<double>("Enter your amount: ");
                u = b.Withdraw(accountNumber, amount);
                cout << endl << "Account is Withdrawed" << endl;
                cout << u;
            }
            catch (exception& e){
                cerr << e.what() << endl;
            }
            getKeyToContinue();
            break;
        case 5:
            try{
                accountNumber = inputVariable<int>("Enter your account number: ");
                map<int, User>::iterator itr;
                if (!b.HasThisAccount(accountNumber)){
                    throw runtime_error("Account not found");
                }
                b.CloseAccount(accountNumber);
                cout << "Account close successfully" << endl;
            }
            catch (exception& e){
                cerr << e.what() << endl;
            }
            break;
        case 6:
            /* code */
            clearScreen();
            b.ShowAllAccounts();
            getKeyToContinue();
            break;
        case 7:
            clearScreen();
            break;
        case 8:
            /* code */
            cout << "Quit The System" << endl;
            break;
        
        default:
            cout << "Please input a valid number" << endl;
            getKeyToContinue();
            break;
        }
    }while (choice != 8);

    return 0;
}

Bank::Bank(){
    User user;
    int maxAcc;
    ifstream ifs("user_account.txt");
    if(!ifs){
        return;
    }
    while(ifs >> user){
        users.insert(pair<int, User>(user.getAccNo(), user));
        maxAcc = max(maxAcc, user.getAccNo());
    }
    User::setNextAccountNumber(maxAcc);
    ifs.close();
}

User Bank::OpenAccount(string fn, string ln, double bal){
    User u(fn, ln, bal);
    users.insert(pair<int, User>(u.getAccNo(), u));
    ofstream ofs("user_account.txt", ios::trunc);
    map<int, User>::iterator itr;
    for(itr = users.begin(); itr != users.end(); itr++){
        ofs << itr->second;
    }
    ofs.close();
    return u;
}

void Bank::ShowAllAccounts(){
    User u;
    map<int, User>::iterator itr;
    for(itr = users.begin(); itr != users.end(); itr++){
        cout << itr->second;
    }
}

User Bank::BalanceEnquiry(int accountNumber){
    map<int, User>::iterator itr = users.find(accountNumber);
    return itr->second;
}

User Bank::Deposit(int accountNumber,float amount){
    map<int, User>::iterator itr = users.find(accountNumber);
    itr->second.deposit(amount);
    return itr->second;
}

User Bank::Withdraw(int accountNumber,float amount){
    map<int, User>::iterator itr = users.find(accountNumber);
    itr->second.withdraw(amount);
    return itr->second;
}

void Bank::CloseAccount(int accountNumber){
    map<int, User>::iterator itr = users.find(accountNumber);
    cout << "Account delete: " << itr->second;
    users.erase(accountNumber);
}

Bank::~Bank(){
    map<int, User>::iterator itr;
    ofstream ofs("user_account.txt");
    for(itr = users.begin(); itr != users.end(); itr++){
        ofs << itr->second;
    }
    ofs.close();
}

bool Bank::HasThisAccount(int accountNumber){
    map<int, User>::iterator itr = users.find(accountNumber);
    if(itr == users.end()){
        return false;
    }
    return true;
}