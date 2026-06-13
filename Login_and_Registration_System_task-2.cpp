 #include <iostream>
#include <fstream>
#include <string>
#include <cstdio>

using namespace std;

// Check if username already exists
bool usernameExists(string username)
{
    ifstream file("users.txt");

    if (!file)
    {
        return false;
    }

    string user, pass;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            file.close();
            return true;
        }
    }

    file.close();
    return false;
}

// Register User
void registerUser()
{
    string username, password;

    cout << "\n====================";
    cout << "\n     REGISTER";
    cout << "\n====================\n";

    cout << "Enter Username : ";
    cin >> username;

    if (usernameExists(username))
    {
        cout << "\nUsername already exists!\n";
        return;
    }

    cout << "Enter Password : ";
    cin >> password;

    ofstream file("users.txt", ios::app);

    if (!file)
    {
        cout << "\nError opening file!\n";
        return;
    }

    file << username << " " << password << endl;

    file.close();

    cout << "\nRegistration Successful!\n";
}

// Login User
void loginUser()
{
    string username, password;
    string user, pass;

    cout << "\n====================";
    cout << "\n       LOGIN";
    cout << "\n====================\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    ifstream file("users.txt");

    bool found = false;

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            found = true;
            break;
        }
    }

    file.close();

    if (found)
    {
        cout << "\nLogin Successful!";
        cout << "\nWelcome " << username << "!\n";
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

// Forgot Password
void forgotPassword()
{
    string username;
    string user, pass;

    cout << "\n====================";
    cout << "\n  FORGOT PASSWORD";
    cout << "\n====================\n";

    cout << "Enter Username : ";
    cin >> username;

    ifstream file("users.txt");

    bool found = false;

    while (file >> user >> pass)
    {
        if (user == username)
        {
            found = true;
            cout << "\nYour Password is : " << pass << endl;
            break;
        }
    }

    file.close();

    if (!found)
    {
        cout << "\nUsername Not Found!\n";
    }
}

// Delete Account
void deleteAccount()
{
    string username, password;
    string user, pass;

    cout << "\n====================";
    cout << "\n  DELETE ACCOUNT";
    cout << "\n====================\n";

    cout << "Enter Username : ";
    cin >> username;

    cout << "Enter Password : ";
    cin >> password;

    ifstream file("users.txt");
    ofstream temp("temp.txt");

    bool deleted = false;

    while (file >> user >> pass)
    {
        if (user == username && pass == password)
        {
            deleted = true;
        }
        else
        {
            temp << user << " " << pass << endl;
        }
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (deleted)
    {
        cout << "\nAccount Deleted Successfully!\n";
    }
    else
    {
        cout << "\nInvalid Username or Password!\n";
    }
}

// Main Function
int main()
{
    int choice;

    do
    {
        cout << "\n====================================";
        cout << "\n   USER AUTHENTICATION SYSTEM";
        cout << "\n====================================";
        cout << "\n[1] Register";
        cout << "\n[2] Login";
        cout << "\n[3] Forgot Password";
        cout << "\n[4] Delete Account";
        cout << "\n[5] Exit";
        cout << "\n\nEnter Choice : ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                registerUser();
                break;

            case 2:
                loginUser();
                break;

            case 3:
                forgotPassword();
                break;

            case 4:
                deleteAccount();
                break;

            case 5:
                cout << "\nThank You!\n";
                break;

            default:
                cout << "\nInvalid Choice! Please Try Again.\n";
        }

    } while (choice != 5);

    return 0;
}