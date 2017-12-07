#include <iostream>
#include <string>
#include "Account.hpp"

using namespace std;

int main(void)
{
#ifdef PRINT_DEBUG_INFO
#endif
    Account account1{"Jane Green", 50};
    Account account2{"John Blue", -7};
    int depositAmount;

    // Display initial balance of each object.
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance() << "\n";
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance();

    cout << "\n\nEnter deposit amount for account1: ";
    cin >> depositAmount;
    cout << "Adding $" << depositAmount << " to account1's balance\n\n";
    account1.deposit(depositAmount);

    // Display balances.
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance() << "\n";
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance();

    cout << "\n\nEnter deposit amount for account2: ";
    cin >> depositAmount;
    cout << "Adding $" << depositAmount << " to account2's balance\n\n";
    account2.deposit(depositAmount);

    // Display balances.
    cout << "account1: " << account1.getName() << " balance is $"
        << account1.getBalance() << "\n";
    cout << "account2: " << account2.getName() << " balance is $"
        << account2.getBalance() << endl;
    return 0;
}
