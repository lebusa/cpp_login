#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool login(string username, string password)
{
  string uname, pw;
  ifstream r("./users/" + username + ".dat");
  getline(r, uname);
  getline(r, pw);
  if (uname == username && pw == password)
  {
    return true;
  }
  else
  {
    return false;
  }
};

void sign_up(string username, string password)
{
  ofstream f;
  f.open("./users/" + username + ".dat");
  f << username + "\n";
  f << password + "\n";
  f.close();
  cout << username << " registration successful" << endl;
};

enum choices
{
  c_login = 1,
  c_register = 2,
  c_exit = 3
};

void showInstructions()
{
  cout << "Select a task\n"
       << "1: to login\n"
       << "2: to register\n"
       << "3: to quit\n"
       << "------------\n";
}

int main()
{
  showInstructions();
  string username, password;
  int choice = 0;

  while (choice != choices::c_exit)
  {
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
    else if (choice == choices::c_register)
    {
      cout << "Enter new username: ";
      cin >> username;
      cout << "Set a password: ";
      cin >> password;
      cout << endl;
      sign_up(username, password);
      cout << endl;
    }
    showInstructions();
    cin >> choice;
  }
  cout << "Bye!" << endl;
  return 0;
}
