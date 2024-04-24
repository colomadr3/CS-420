#include <iostream>
#include <vector>
#include <limits>

using namespace std;

// GLOBAL VARIABLES
/*
* Global variables can be potential security issues due to the access control they are given.
* They also make it difficult to keep track of the flow of data. Since they are global, any function
* can change the data they hold and thus make it harder to track when/where the data is changed.
* Variables should be limited to the scope of where they are used/needed and if another function
* requires that data, it should be passed to the function to maintain oop abstraction.
*/
// ***FIXED*** Moved the unnecessary global variables to local scopes.
int num1 = 1;
int num2 = 2;
int num3 = 1;
int num4 = 1;
int num5 = 2;

/* Function to Change Client servie attributes */
void ChangeCustomerChoice() {
	// ***FIXED*** Moved the variable 'changechoice' and 'newservice' from global to local.
	int changechoice = 0;
	int newservice = 0;

  // Prompt user for Client infomation to change
  cout << "Enter the number of the client that you wish to change\n";

	/*
	* Input validation should be done to ensure only integers 1-5 can be entered
	*/
	cin >> changechoice; // Input should be an integer 1-5.
	cout << "Please enter the client's new service choice (1 = Brokerage, 2 = Retirement)\n";
	
	/*
	* Input validation should be done to ensure only integers 1 & 2 can be entered
	*/
	cin >> newservice; // Input should only be 1 or 2

  // If statements to compare change choice and the client number. Changes the associated numX variable with the newservice value.
	/*
	* A series of 'if' statements were used. A switch statement would have been cleaner and use less memory
	* Best practices - a final 'else' should be include for error checking and data validation.
	*/
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
	// ***FIXED*** Moved the variable 'completed' from global to local.
	int completed = 0;
	string username = ""; 			// Usernames and passwords should not be hardcoded into a program
  string password = "";

  // Promt user for username and password
  cout << "Enter your username:\n";

	/*
	* Usernames and passwords should not be hard coded in a program.
	* They should instead be kept in an encrypted database and reference to when neccessary.
	* Input restrictions/requirements to prevent injection attacks
	* Limiting login attempts should also be used to prevent bruteforce hacking
	*/
  cin >> username; // Value has not bearing on the program
  cout << "Enter your password:\n";
  cin >> password;

  // Password is hard coded into program - '123'
	/*
	* Password should not be hard coded in a program
	* Program does not check for username
	*/
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
	// ***FIXED*** Moved the name variables from global to local.
	string name1 = "Bob Jones";
	string name2 = "Sarah Davis"; 
	string name3 = "Amy Friendly"; 
	string name4 = "Johnny Smith"; 
	string name5 = "Carol Spears";

  /*
	* Information should be stored in a database and referenced as needed.
	*/
	cout << "  Client's Name    Service Selected (1 = Brokerage, 2 = Retirement)" << endl;
	cout << "1. " << name1 << " selected option " << num1  << endl;
	cout << "2. " << name2 << " selected option " << num2 << endl;
	cout << "3. " << name3 << " selected option " << num3 << endl;
	cout << "4. " << name4 << " selected option " << num4 << endl;
	cout << "5. " << name5 << " selected option " << num5 << endl;

  return; // returns to main loop

}

int main() {
	// ***FIXED*** Moved the variable 'answer' and 'choice' from global to local.
	int answer = 0;
	int choice = 0;

  // Added output statement as required by assignment
	cout << "Reverse Engineered by Raphael Coloma" << endl;

	cout << "Hello! Welcome to our Investment Company\n";

	/*
	* The variable 'answer' should be local
	*/
  while(answer != 1){
    answer = CheckUserPermissionAccess(); // Call CheckUserPermissionAccess() to validation user. Return 1 for success

    if(answer != 1){
      cout << "Invalid Password. Please try again\n";
    }
  }

  while(choice != 3){
    // Display main menu
		cout << "What would you like to do?" << endl;
		cout << "DISPLAY the client list (enter 1)" << endl;
		cout << "CHANGE a client's choice (enter 2)" << endl; 
		cout << "Exit the program... (enter 3)" << endl;
    
		/*
		* Input validation should be done to ensure only integers 1-3 can be entered
		*/
    cin >> choice;  // Input should be an integer 1-3.
    
		// if statement to not display the "You chose x" when input is invalid
		if(choice && choice > 0 && choice < 4){
    	cout << "You chose " << choice << endl;
		}

    // Call corresponding function
		/*
		* A series of 'if' statements were used. A switch statement would have been cleaner and use less memory
		* No hard code exit written for option 3.
		* Best practices - a final 'else' should be include for error checking and data validation.
		if (choice == 1) {
			DisplayInfo();  // Call DisplayInfo function to display client infomation
		}
		else if (choice == 2) {
      ChangeCustomerChoice(); // Call ChangeCustomerChoice function to change attributes in client accounts
		}
		*/
		// ***FIXED*** Switch statement implemented with input validation to ensure only integers 1-3 are entered.
		switch(choice){
			case 1:
				DisplayInfo();
				break;
			case 2:
				ChangeCustomerChoice();
				break;
			case 3:
				cout << "Goodbye! " << endl;
				break;
			default:
				cout << "Invalid Value. Input should be an interger 1-3" << endl;
				cin.clear();
  			cin.ignore(numeric_limits<streamsize>::max(), '\n');
				break;
		}


  }

  return 0;
}