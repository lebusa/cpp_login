#include <iostream>
#include <string>
#include <fstream>

using namespace std;

// user login
bool login(string username, string password)
{
  string uname, pw;
  ifstream r("./users/" + username + ".dat"); // read a file corresponding to username
  getline(r, uname);
  getline(r, pw);
  if (uname == username && pw == password) // check if read and supplied credentials match
  {
    return true;
  }
  else
  {
    return false;
  }
};

// register a user
void sign_up(string username, string password)
{
  ofstream f;
  f.open("./users/" + username + ".dat"); // store user credentials in file with username
  f << username + "\n";
  f << password + "\n";
  f.close();
  cout << "\n" << username << " registration successful\n" << endl;
};

// choices for user selection
enum choices
{
  c_login = 1,
  c_register = 2,
  c_exit = 3
};

void showInstructions()
{
  cout << "Select a task\n"
       << "  1: to login\n"
       << "  2: to register\n"
       << "  3: to quit\n"
       << "------------\n";
}

int main()
{
  showInstructions();
  string username, password;
  int choice;
  cin >> choice;
  // loop until user quits
  while (choice != choices::c_exit)
  {
    // handle sign in selection
    if (choice == choices::c_login)
    {
      cout << "Enter your username: ";
      cin >> username;
      cout << "Type your password: ";
      cin >> password;
      bool loggedIn = login(username, password);
      if (loggedIn)
      {
        cout << "\nWelcome " << username << "!" << endl
             << endl;
      }
      else
      {
        cout << "\nUsername/password is incorrect" << endl
             << endl;
      }
    }
    // handle sign up selection
    else if (choice == choices::c_register)
    {
      cout << "Enter new username: ";
      cin >> username;
      cout << "Set a password: ";
      cin >> password;
      sign_up(username, password);
    }
    showInstructions();
    cin >> choice;
  }
  cout << "Bye!" << endl;
  return 0;
}
