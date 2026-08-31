#include<iostream>
#include<fstream>
#include "user_account.h"
#include <cstdlib>
using namespace std;

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

int main(){
    
    
    int choice;
    do
    {
        /* code */
        printMenu();
        cout << "Enter you choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            cout << "Do One " << endl;
            // clearScreen();
            break;
        case 2:
            /* code */
            cout << "Do Two " << endl;
            break;
        case 3:
            /* code */
            cout << "Do Three " << endl;
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
            cout << "Do Six " << endl;
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

    User u1;
    ifstream ifs("user_account.txt");
    if (!ifs.is_open())
        return 1;
    else{
        ifs >> u1;
        cout << u1;
        ifs.close();
    }

    return 0;
}