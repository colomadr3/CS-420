#include <iostream>
#include <vector>
using namespace std;

// GLOBAL VARIABLES
string username, password;
string name1 = "Bob Jones";
string name2 = "Sarah Davis"; 
string name3 = "Amy Friendly"; 
string name4 = "Johnny Smith"; 
string name5 = "Carol Spears";
int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;
int choice = 0;
int answer = 0;
int changechoice = 0;
int newservice = 0;
int completed = 0;

/* Function to Change Client servie attributes */
void ChangeCustomerChoice() {

  // Prompt user for Client infomation to change
  cout << "Enter the number of the client that you wish to change\n";
	cin >> changechoice; // Input should be an integer 1-5.
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	cin >> newservice; // Input should only be 1 or 2

  // If statements to compare change choice and the client number. Changes the associated numX variable with the newservice value.
	if (changechoice == 1) {
		num1 = newservice;
	}
	else if (changechoice == 2) {
		num2 = newservice;
	}
	else if (changechoice == 3) {
		num3 = newservice;
	}
	else if (changechoice == 4) {
	  num4 = newservice;
	}
	else if (changechoice == 5) {
	  num5 = newservice;
	}

	return; // returns to main loop

}

/* Function to validate user login */
int CheckUserPermissionAccess() {
  password = "";

  // Promt user for username and password
  cout << "Enter your username:\n";
  cin >> username; // Value has not bearing on the program
  cout << "Enter your password:\n";
  cin >> password;

  // Password is hard coded into program - '123'
  if (password == "123"){
    completed = 1;
  }
  else{
    completed = 2;
  }
  return completed;
}

/* Function to Display client infomation */
void DisplayInfo() {

	cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
	cout << "1. " << name1 << " selected option " << num1  << endl;
	cout << "2. " << name2 << " selected option " << num2 << endl;
	cout << "3. " << name3 << " selected option " << num3 << endl;
	cout << "4. " << name4 << " selected option " << num4 << endl;
	cout << "5. " << name5 << " selected option " << num5 << endl;

  return; // returns to main loop

}

int main() {
  // Added output statement as required by assignment
	cout << "Reverse Engineered by Raphael Coloma" << endl;

	cout << "Hello! Welcome to our Investment Company\n";

  while(answer != 1){
    answer = CheckUserPermissionAccess(); // Call CheckUserPermissionAccess() to validation user. Return 1 for success

    if(answer != 1){
      cout << "Invalid Password. Please try again\n";
    }
  }

  while(choice != 3){
    // Display main menu
		cout << "What would you like to do?\n";
		cout << "DISPLAY the client list (enter 1)\n";
		cout << "CHANGE a client's choice (enter 2)\n"; 
		cout << "Exit the program.. (enter 3)\n";
    
    cin >> choice;  // Input should be an integer 1-3.
    
    cout << "You chose " << choice << endl;

    // Call corresponding function
    if (choice == 1) {
			DisplayInfo();  // Call DisplayInfo function to display client infomation
		}
		else if (choice == 2) {
      ChangeCustomerChoice(); // Call ChangeCustomerChoice function to change attributes in client accounts
		}
  }

  return 0;
}