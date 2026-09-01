#include "user_account.h"
#include <cstdlib>
#include <map>
#include <conio.h>
using namespace std;

class Bank{
    private:
        map<int, User> users;
    public:
        Bank();
        User OpenAccount();
        User BalanceEnquiry(int accountNumber);
        User Deposit(int accountNumber,float amount);
        User Withdraw(int accountNumber,float amount);
        void CloseAccount(int accountNumber);
        void ShowAllAccounts();
        // ~Bank();
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
        if(_kbhit()){
            char key = _getch();
            if(key == ' '){
                break;
            }
        }
    }
}

int main(){
    Bank b;
    User u;
    
    int choice;
    int accountNumber;
    float amount;
    do
    {
        /* code */
        printMenu();
        cout << "Enter you choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            u = b.OpenAccount();
            cout << "Congradulation Account is Created" <<endl;
            cout << u;
            break;
        case 2:
            /* code */
            cout << "Enter account number: ";
            cin >> accountNumber;
            u = b.BalanceEnquiry(accountNumber);
            cout << "Your detial account: " << endl;
            cout << u;
            cout << "Press space to continue: ";
            while(true){
                if(-kbhit()){
                    char key = _getch();
                    if (key == ' ')
                        break;
                }
            }
            break;
        case 3:
            /* code */
            cout << "Enter account number: ";
            cin >> accountNumber;
            cout << "Enter the amount: ";
            cin >> amount;
            u = b.Deposit(accountNumber, amount);
            cout << endl << "Account is Deposited" << endl;
            cout << u;
            getKeyToContinue();
            break;
        case 4:
            /* code */
            cout << "Do Four " << endl;
            break;
        case 5:
            /* code */
            cout << "Do Five " << endl;
            break;
        case 6:
            /* code */
            clearScreen();
            b.ShowAllAccounts();
            {
                while(true){
                    if(_kbhit()){ // Checks whether a key has been pressed.
                        char key;
                        cout << "Press Space to continue: ";
                        key = _getch(); // Get char without press enter
                        if(key == ' ')
                            break;
                    }
                }
            }
            
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
            break;
        }
    }while (choice != 8);

    

    return 0;
}

Bank::Bank(){
    User user;
    ifstream ifs("user_account.txt");
    if(!ifs){
        return;
    }
    while(ifs >> user){
        users.insert(pair<int, User>(user.getAccNo(), user));
    }
    User::setNextAccountNumber(user.getAccNo());
    ifs.close();
}

User Bank::OpenAccount(){
    User u;
    cin >> u;
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
    if(itr == users.end()){
        throw runtime_error("Account not found");
    }
    return itr->second;
}

User Bank::Deposit(int accountNumber,float amount){
    map<int, User>::iterator itr = users.find(accountNumber);
    if(itr == users.end()){
        throw runtime_error("Account not found");
    }
    itr->second.deposit(amount);
    return itr->second;
}