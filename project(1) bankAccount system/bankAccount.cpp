#include <iostream>
#include <string>
using namespace std;
class bankAccount
{
private:
  string accountNumber;
  double balance;

public:
  bankAccount(string aN, double bal)
  {
    accountNumber = aN;
    balance = bal;

    if (balance <= 0)
    {
      balance = 0;
    }
  }

  // getter method

  string getAccountNumber()
  {
    return accountNumber;
  }

  double getBalance()
  {
    return balance;
  }

  void deposit(int amount)
  {
    if (amount > 0)
    {
      balance = balance + amount;
    }
  }

  void withdraw(int amount)
  {
    if (amount > 0 && amount <= balance)
    {
      balance -= amount;
    }
  }
};
int main()
{
  bankAccount bA("ali12345", 8900.87);
  bA.deposit(1000);
  bA.withdraw(100);

  bankAccount bA2("haiderali123", 8900);
  bA2.deposit(200);
  bA2.withdraw(50);

  cout << "information of first person..." << endl;
  cout << "your remaining balance:" << endl;

  cout << bA.getBalance() << endl;

  cout << endl;

  cout << "information of second person..." << endl;

  cout << bA2.getBalance() << endl;
  return 0;
}