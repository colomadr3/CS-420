#include <iostream>
#include <limits>

using namespace std;

/* Code with Vulnerabilities
////////////////////////

// This function is created but not used.
void DisplayMenu(){
    cout << "----------------" << endl;
    cout << "- 1)Add -" << endl;
    cout << "- 2)Subtract -" << endl;
    cout << "- 3)Multiply -" << endl;
    cout << "- 4)Exit -" << endl;
    cout << "----------------" << endl;
    return;
}
    
int main(){

// Variables not initialized.
int userInput, firstVal, secondVal, result;
    
    // While loop exit condition does not match menu displayed to the user.
    while(userInput != 5){

        // This code is redundant. Function DisplayMenu() should be used instead.
        cout << "----------------" << endl;
        cout << "- 1)Add -" << endl;
        cout << "- 2)Subtract -" << endl;
        cout << "- 3)Multiply -" << endl;
        cout << "- 4)Exit -" << endl;
        cout << "----------------" << endl;
    
        cin >> userInput;

        if(userInput == 1){
            // redundant code - can be called before the if statements to save memory.
            // no prompt is provided to the user. Can be confusing and introduce errors.
            // no input validations to ensure values are integers.
            cin >> firstVal;
            cin >> secondVal;

            // output buffer not flushed before calculations are computed.
            // incorrect signs is being displayed 
            cout << firstVal << " - " << secondVal << " = ";

            // calculation is done in the middle of a cout statement.
            // incorrect calculation is being made
            result = firstVal - secondVal;
            cout << result << endl;
        }
        else if(userInput == 2){
            // redundant code - can be called before the if statements to save memory.
            // no prompt is provided to the user. Can be confusing and introduce errors.
            // no input validations to ensure values are integers.
            cin >> firstVal;
            cin >> secondVal;

            // output buffer not flushed before calculations are computed.
            cout << firstVal << " - " << secondVal << " = ";

            // calculation is done in the middle of a cout statement.
            // incorrect calculation is being made
            result = firstVal + secondVal;
            cout << result << endl;
        }
        else if(userInput == 3){
            // redundant code - can be called before the if statements to save memory.
            // no prompt is provided to the user. Can be confusing and introduce errors.
            // no input validations to ensure values are integers.
            cin >> firstVal;
            cin >> secondVal;

            // output buffer not flushed before calculations are computed.
            // incorrect signs is being displayed 
            cout << firstVal << " - " << secondVal << " = ";

            // calculation is done in the middle of a cout statement.
            // incorrect calculation is being made
            result = firstVal / secondVal;
            cout << result << endl;
        }

    }
return 0;

}
*/

/* Code Corrected
/////////////////////////////
*/

// DisplayMenu Function outputs the menu to the screen to prompt the user on the selections they can make.
void DisplayMenu(){
    cout << "----------------" << endl;
    cout << "- 1)Add -" << endl;
    cout << "- 2)Subtract -" << endl;
    cout << "- 3)Multiply -" << endl;
    cout << "- 4)Exit -" << endl;
    cout << "----------------" << endl;
    return;
}

// InputValidation function to alert the user that their input is invalid.
void InputValidation(){
  cout << "Input invalid. Please try again" << endl;
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
  return;
}
    
int main(){

// Declared Variable
int userInput, firstVal, secondVal, result;
    
    // userInput variable initialized to 0 to prevent unexpected calculations
    userInput = 0;
    
    // While loop exit condition set to correct number based on the information prompted by the DisplayMenu function
    while(userInput != 4){

      // Variables are initialized to 0 to prevent unexpected calculations
      firstVal = 0;
      secondVal = 0;
      result = 0;

        // DisplayMenu function called to reduce redundant code.
        DisplayMenu();

        cin >> userInput;
        // Input validation to ensure only menu options listed are entered
        // prevent possible overflow errors and injection attacks
        while(!userInput || userInput > 4){
            InputValidation();
            cin >> userInput;
        }
        if(userInput == 4){
            break;
        }
        
        // Prompt for user's first value to keep process clear
        cout << "Please enter your first Value (integers only)" << endl;

        // cin statement for first value done outside of if statements to reduce redundancy and optimize memory
        cin >> firstVal;
        // Input validation to ensure only integers are entered
        // prevent possible overflow errors and injection attacks
        while(!firstVal){
            InputValidation();
            cin >> firstVal;
        }
        
        // Prompt for user's second value to keep process clear
        cout << "Please enter your second Value (integers only)" << endl;

        // cin statement for second value done outside of if statements to reduce redundancy and optimize memory
        cin >> secondVal;
        // Input validation to ensure only integers are entered
        // prevent possible overflow errors and injection attacks
        while(!secondVal){
            InputValidation();
            cin >> secondVal;
        }

        if(userInput == 1){ // Addition
            // correct calculation is done before the cout statement.
            result = firstVal + secondVal;
            
            // Output is not being interupted by calculations and buffer is being flushed to prevent unexpected behavior.
            cout << firstVal << " + " << secondVal << " = " << result << endl;
        }
        else if(userInput == 2){ // Subtraction
            // correct calculation is done before the cout statement.
            result = firstVal - secondVal;

            // Output is not being interupted by calculations and buffer is being flushed to prevent unexpected behavior.
            cout << firstVal << " - " << secondVal << " = " << result << endl;
        }
        else if(userInput == 3){ // Multiplication
            // correct calculation is done before the cout statement.
            result = firstVal * secondVal;

            // Output is not being interupted by calculations and buffer is being flushed to prevent unexpected behavior.
            cout << firstVal << " x " << secondVal << " = " << result << endl;
        }

    }
return 0;
}