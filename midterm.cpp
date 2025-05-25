/*
 * Names: Ryan Tran
 * Team Name: Boolean Bunch
 *
 */

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

int main() {
    //Display numbered list of menu items.
    int quantity1 = 0, quantity2 = 0, quantity3 = 0, quantity4 = 0, quantity5 = 0;
    int userQuantity;
    int burgerSelection;
    bool orderEnded = false;
    cout << "1. De Anza Burger - $5.25 \n"
         << "2. Bacon Cheese Burger - $5.75\n"
         << "3. Mushroom Swiss Burger - $5.95\n"
         << "4. Western Burger - $5.95\n"
         << "5. Don Cali Burger - $5.95\n"
         << "6. End Order" << endl;

    // User input loop for burger selection.
    while(!orderEnded) {
        cout << "Please choose a burger option, or select 6 to end order: ";
        cin >> burgerSelection;

        // Input validation for the option selection.
        while(burgerSelection < 1 || burgerSelection > 6) {
            cout << "Please choose a valid burger option: ";
            cin >> burgerSelection;
        }

        // break out of the while loop if the order is supposed to end
        if(burgerSelection == 6) {
            orderEnded = true;
            break;
        }

        // Trailing-else if a burger is selected.
        else {

            // User input selection for the number of burgers selected
            cout << "How many burgers would you like? : ";
            cin >> userQuantity;

            // Input validation, only allows non-negative input for # of burgers
            while(userQuantity < 0) {
                cout << "Please enter a non-negative number of burgers to order: ";
                cin >> userQuantity;
            }

            // Switch cases for the burger selection, adds inputted quantity to selected burger
            switch(burgerSelection) {
                case 1:
                    quantity1 += userQuantity;
                    break;
                case 2:
                    quantity2 += userQuantity;
                    break;
                case 3:
                    quantity3 += userQuantity;
                    break;
                case 4:
                    quantity4 += userQuantity;
                    break;
                case 5:
                    quantity5 += userQuantity;
                    break;
            }
        }

    }

    // Customer type input selection
    int userCustomerType;
    cout << "Are you a student or staff?" << endl;
    cout << "1. Student\n" << "2. Staff\n";
    cin.ignore();
    cin >> userCustomerType;

    // Input validation for customer type (student or staff)
    while(userCustomerType != 1 && userCustomerType != 2) {
        cout << "Please enter a correct customer type: ";
        cin >> userCustomerType;
    }



    // Displaying the quantity of each burger that is ordered.
    cout << "\nDe Anza Burger Quantity Ordered: " << quantity1 << endl;
    cout << "Bacon Cheese Burger Quantity Ordered: " << quantity2 << endl;
    cout << "Mushroom Swiss Burger Quantity Ordered: " << quantity3 << endl;
    cout << "Western Burger Quantity Ordered: " << quantity4 << endl;
    cout << "Don Cali Burger Quantity Ordered: " << quantity5 << endl;

    // Calculations for the cost of each type of burger separately.
    double costQuantity1 = 5.25 * quantity1;
    double costQuantity2 = 5.75 * quantity2;
    double costQuantity3 = 5.95 * quantity3;
    double costQuantity4 = 5.95 * quantity4;
    double costQuantity5 = 5.95 * quantity5;

    // Output formatting, in fixed point notation, always show point and two decimal points
    cout << fixed << showpoint << setprecision(2);

    // Displaying the cost of each burger individually
    cout << "\nCost Per Item: " << endl;
    cout << "De Anza Burger: $5.25 x " << quantity1 << " = $" << costQuantity1 << endl;
    cout << "Bacon Cheese Burger: $5.75 x " << quantity2 << " = $" << costQuantity2 << endl;
    cout << "Mushroom Swiss Burger: $5.95 x " << quantity3 << " = $" << costQuantity3 << endl;
    cout << "Western Burger: $5.95 x " << quantity4 << " = $" << costQuantity4 << endl;
    cout << "Don Cali Burger: $5.95 x " << quantity5 << " = $" << costQuantity5 << endl;

    // Displaying the subtotal of each burger (cost of all items before tax)
    cout << "\nTotal Before Tax: " << endl;
    cout << "De Anza Burger: $" << costQuantity1 << endl;
    cout << "Bacon Cheese Burger: $" << costQuantity2 << endl;
    cout << "Mushroom Swiss Burger: $" << costQuantity3 << endl;
    cout << "Western Burger Burger: $" << costQuantity4 << endl;
    cout << "Don Cali Burger: $" << costQuantity5 << endl;

    // Calculation for the subTotal (cost of all burgers ordered)
    double subTotal = costQuantity1 + costQuantity2 + costQuantity3 + costQuantity4 + costQuantity5;

    // Displaying the sub total
    cout << "\nSub Total: $" << subTotal << endl;

    // Declaring and initializing a varialbe to represent tax
    double taxAmount = 0;

    // If the customer is a staff member, calculate tax amount.
    if(userCustomerType == 2) {
        taxAmount = subTotal * .09;
    }

    // Display the amount of tax
    cout << "\nTax Amount: $" << taxAmount << endl;

    // Display the final total
    cout << "\nFinal Bill: $" << (subTotal + taxAmount) << endl;

    // Make an ofstream object and open a new output.txt file
    ofstream outputFile;
    outputFile.open("output.txt");

    // If file successfully opened, write the monetary value of the final bill
    if(outputFile) {

        outputFile << fixed << showpoint << setprecision(2);
        // Writing the cost per item
        outputFile << "\nCost Per Item: " << endl;
        outputFile << "De Anza Burger: $5.25 x " << quantity1 << " = $" << costQuantity1 << endl;
        outputFile << "Bacon Cheese Burger: $5.75 x " << quantity2 << " = $" << costQuantity2 << endl;
        outputFile << "Mushroom Swiss Burger: $5.95 x " << quantity3 << " = $" << costQuantity3 << endl;
        outputFile << "Western Burger: $5.95 x " << quantity4 << " = $" << costQuantity4 << endl;
        outputFile << "Don Cali Burger: $5.95 x " << quantity5 << " = $" << costQuantity5 << endl;

        // Writing the sub total
        outputFile << "\nTotal Before Tax: " << endl;
        outputFile << "De Anza Burger: $" << costQuantity1 << endl;
        outputFile << "Bacon Cheese Burger: $" << costQuantity2 << endl;
        outputFile << "Mushroom Swiss Burger: $" << costQuantity3 << endl;
        outputFile << "Western Burger Burger: $" << costQuantity4 << endl;
        outputFile << "Don Cali Burger: $" << costQuantity5 << endl;

        outputFile << "\nSub Total: $" << subTotal << endl;

        // Displaying the tax amount
        outputFile << "\nTax Amount: $" << taxAmount << endl;

        // Displaying the final bill
        outputFile << "\nFinal Bill: $" << (subTotal + taxAmount) << endl;
        outputFile.close();
    }

    // Trailing-else displays an error message if file did not open properly.
    else {
        cout << "There was an issue opening the file." << endl;
    }

    return 0;
}
