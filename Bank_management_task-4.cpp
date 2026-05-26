#include <iostream>
#include <vector>
#include <string>

using namespace std;

 
// Transaction Class
 
class Transaction {
public:
    string type;
    double amount;

    Transaction(string t, double a) {
        type = t;
        amount = a;
    }

    void showTransaction() {
        cout << type << " : " << amount << endl;
    }
};

 
// Account Class
 
class Account {
private:
    string accountNumber;
    string accountType;
    double balance;

public:
    vector<Transaction> transactions;

    Account(string accNo, string accType, double bal) {
        accountNumber = accNo;
        accountType = accType;
        balance = bal;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount) {

        if (amount > 0) {

            balance = balance + amount;

            transactions.push_back(Transaction("Deposit", amount));

            cout << "Money Deposited Successfully\n";
        }
        else {
            cout << "Invalid Amount\n";
        }
    }

    void withdraw(double amount) {

        if (amount > balance) {
            cout << "Insufficient Balance\n";
        }
        else {

            balance = balance - amount;

            transactions.push_back(Transaction("Withdraw", amount));

            cout << "Money Withdrawn Successfully\n";
        }
    }

    void showAccount() {

        cout << "\nAccount Number : " << accountNumber;
        cout << "\nAccount Type   : " << accountType;
        cout << "\nBalance        : " << balance << endl;

        cout << "\nTransactions:\n";

        if (transactions.size() == 0) {
            cout << "No Transactions\n";
        }

        for (int i = 0; i < transactions.size(); i++) {
            transactions[i].showTransaction();
        }
    }
};

 
// Customer Class
 
class Customer {
private:
    int customerId;
    string name;

public:
    vector<Account> accounts;

    Customer(int id, string n) {
        customerId = id;
        name = n;
    }

    int getCustomerId() {
        return customerId;
    }

    string getName() {
        return name;
    }

    void addAccount(Account acc) {
        accounts.push_back(acc);
    }

    void showCustomer() {

        cout << "\nCustomer ID : " << customerId;
        cout << "\nCustomer Name : " << name << endl;

        if (accounts.size() == 0) {
            cout << "No Accounts\n";
        }

        for (int i = 0; i < accounts.size(); i++) {

            cout << "\n----- Account " << i + 1 << " -----\n";

            accounts[i].showAccount();
        }
    }
};

 
// Main Function
 
int main() {

    vector<Customer> customers;

    int customerCount = 0;
    int accountCount = 1000;

    int mainChoice;

    do {

        cout << "\n";
        cout << "========================================\n";
        cout << "         BANK MANAGEMENT SYSTEM         \n";
        cout << "========================================\n";

        cout << "\nMAIN MENU\n";
        cout << "----------------------------------------\n";
        cout << "1. Customer Management\n";
        cout << "2. Account Management\n";
        cout << "3. Transactions\n";
        cout << "4. Reports & Views\n";
        cout << "0. Exit\n";

        cout << "\nEnter Choice : ";
        cin >> mainChoice;

        
        // CUSTOMER MANAGEMENT
  
        if (mainChoice == 1) {

            int choice;

            do {

                cout << "\nCUSTOMER MANAGEMENT\n";
                cout << "----------------------------------------\n";

                cout << "1. Create Customer\n";
                cout << "2. View Customer\n";
                cout << "3. Show All Customers\n";
                cout << "0. Back\n";

                cout << "\nEnter Choice : ";
                cin >> choice;

                // Create Customer
                if (choice == 1) {

                    string name;

                    cout << "Enter Customer Name : ";
                    cin >> name;

                    customerCount++;

                    customers.push_back(Customer(customerCount, name));

                    cout << "Customer Created Successfully\n";
                    cout << "Customer ID : " << customerCount << endl;
                }

                // View Customer
                else if (choice == 2) {

                    int id;
                    bool found = false;

                    cout << "Enter Customer ID : ";
                    cin >> id;

                    for (int i = 0; i < customers.size(); i++) {

                        if (customers[i].getCustomerId() == id) {

                            customers[i].showCustomer();

                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "Customer Not Found\n";
                    }
                }

                // Show All Customers
                else if (choice == 3) {

                    if (customers.size() == 0) {
                        cout << "No Customers Available\n";
                    }

                    for (int i = 0; i < customers.size(); i++) {

                        cout << "\n====================\n";

                        customers[i].showCustomer();
                    }
                }

            } while (choice != 0);
        }

       
        // ACCOUNT MANAGEMENT
        
        else if (mainChoice == 2) {

            int choice;

            do {

                cout << "\nACCOUNT MANAGEMENT\n";
                cout << "----------------------------------------\n";

                cout << "1. Open Account\n";
                cout << "0. Back\n";

                cout << "\nEnter Choice : ";
                cin >> choice;

                if (choice == 1) {

                    int id;
                    bool found = false;

                    cout << "Enter Customer ID : ";
                    cin >> id;

                    for (int i = 0; i < customers.size(); i++) {

                        if (customers[i].getCustomerId() == id) {

                            string type;
                            double balance;

                            cout << "Enter Account Type : ";
                            cin >> type;

                            cout << "Enter Initial Balance : ";
                            cin >> balance;

                            string accNo = "ACC" + to_string(accountCount);

                            accountCount++;

                            Account acc(accNo, type, balance);

                            customers[i].addAccount(acc);

                            cout << "Account Opened Successfully\n";
                            cout << "Account Number : " << accNo << endl;

                            found = true;
                        }
                    }

                    if (!found) {
                        cout << "Customer Not Found\n";
                    }
                }

            } while (choice != 0);
        }

        
        // TRANSACTIONS
 
        else if (mainChoice == 3) {

            int choice;

            do {

                cout << "\nTRANSACTIONS\n";
                cout << "----------------------------------------\n";

                cout << "1. Deposit\n";
                cout << "2. Withdraw\n";
                cout << "0. Back\n";

                cout << "\nEnter Choice : ";
                cin >> choice;

                // Deposit
                if (choice == 1) {

                    string accNo;
                    double amount;
                    bool found = false;

                    cout << "Enter Account Number : ";
                    cin >> accNo;

                    for (int i = 0; i < customers.size(); i++) {

                        for (int j = 0; j < customers[i].accounts.size(); j++) {

                            if (customers[i].accounts[j].getAccountNumber() == accNo) {

                                cout << "Enter Amount : ";
                                cin >> amount;

                                customers[i].accounts[j].deposit(amount);

                                found = true;
                            }
                        }
                    }

                    if (!found) {
                        cout << "Account Not Found\n";
                    }
                }

                // Withdraw
                else if (choice == 2) {

                    string accNo;
                    double amount;
                    bool found = false;

                    cout << "Enter Account Number : ";
                    cin >> accNo;

                    for (int i = 0; i < customers.size(); i++) {

                        for (int j = 0; j < customers[i].accounts.size(); j++) {

                            if (customers[i].accounts[j].getAccountNumber() == accNo) {

                                cout << "Enter Amount : ";
                                cin >> amount;

                                customers[i].accounts[j].withdraw(amount);

                                found = true;
                            }
                        }
                    }

                    if (!found) {
                        cout << "Account Not Found\n";
                    }
                }

            } while (choice != 0);
        }

       
        // REPORTS & VIEWS
     
        else if (mainChoice == 4) {
 

    int choice;

    do {

        cout << "\nREPORTS & VIEWS\n";
        cout << "----------------------------------------\n";

        cout << "1. Transaction History\n";
        cout << "2. Balance Enquiry\n";
        cout << "3. List All Customers\n";
        cout << "0. Back\n";

        cout << "\nEnter Choice : ";
        cin >> choice;

       
        // Transaction History
  
        if (choice == 1) {

            string accNo;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> accNo;

            for (int i = 0; i < customers.size(); i++) {

                for (int j = 0; j < customers[i].accounts.size(); j++) {

                    if (customers[i].accounts[j].getAccountNumber() == accNo) {

                        cout << "\nTransaction History\n";

                        for (int k = 0; k < customers[i].accounts[j].transactions.size(); k++) {

                            customers[i].accounts[j]
                            .transactions[k]
                            .showTransaction();
                        }

                        found = true;
                    }
                }
            }

            if (!found) {
                cout << "Account Not Found\n";
            }
        }
 
        // Balance Enquiry
   
        else if (choice == 2) {

            string accNo;
            bool found = false;

            cout << "Enter Account Number : ";
            cin >> accNo;

            for (int i = 0; i < customers.size(); i++) {

                for (int j = 0; j < customers[i].accounts.size(); j++) {

                    if (customers[i].accounts[j].getAccountNumber() == accNo) {

                        cout << "\nCurrent Balance : "
                             << customers[i].accounts[j].getBalance()
                             << endl;

                        found = true;
                    }
                }
            }

            if (!found) {
                cout << "Account Not Found\n";
            }
        }

  
        // List All Customers
  
        else if (choice == 3) {

            if (customers.size() == 0) {

                cout << "No Customers Available\n";
            }

            for (int i = 0; i < customers.size(); i++) {

                cout << "\n====================\n";

                customers[i].showCustomer();
            }
        }

    } while (choice != 0);
}
        

    
        // EXIT
 
        else if (mainChoice == 0) {

            cout << "\nThank You\n";
        }

        else {

            cout << "Invalid Choice\n";
        }

    } while (mainChoice != 0);

    return 0;
}
