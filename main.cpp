#include<iostream>
#include<fstream>
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
    cout << "\tSelect one option below: " << endl;
    cout << "\t1. Open an Account" << endl;
    cout << "\t2. Balance Enquiry" << endl;
    cout << "\t3. Deposit" << endl;
    cout << "\t4. Withdrawal" << endl;
    cout << "\t5. Close an Account" << endl;
    cout << "\t6. Show All Accounts" << endl;
    cout << "\t7. Quit" << endl;
}

int main(){
    
    cout << "***Banking System***" << endl;
    printMenu();
    int choice;
    do
    {
        /* code */
        cout << "Enter you choice: "; cin >> choice;
        switch (choice)
        {
        case 1:
            /* code */
            cout << "Do One " << endl;
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
            /* code */
            cout << "Quit The System" << endl;
            break;
        
        default:
            cout << "Please input a valid number" << endl;
            break;
        }
    }while (choice != 7);

    return 0;
}