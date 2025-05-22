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

    while(!orderEnded) {
        cout << "Please choose a burger option, or select 6 to end order: ";
        cin >> burgerSelection;

        while(burgerSelection < 1 || burgerSelection > 6) {
            cout << "Please choose a valid burger option: ";
            cin >> burgerSelection;
        }

        if(burgerSelection == 6) {
            orderEnded = true;
            break;
        }

        else {
            cout << "How many burgers would you like? : ";
            cin >> userQuantity;
            while(userQuantity < 0) {
                cout << "Please enter a non-negative number of burgers to order: ";
                cin >> userQuantity;
            }
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

    int userCustomerType;
    cout << "Are you a student or staff?" << endl;
    cout << "1. Student\n" << "2. Staff\n";
    cin.ignore();
    cin >> userCustomerType;

    while(userCustomerType != 1 && userCustomerType != 2) {
        cout << "Please enter a correct customer type: ";
        cin >> userCustomerType;
    }




    cout << "\nDe Anza Burger Quantity Ordered: " << quantity1 << endl;
    cout << "Bacon Cheese Burger Quantity Ordered: " << quantity2 << endl;
    cout << "Mushroom Swiss Burger Quantity Ordered: " << quantity3 << endl;
    cout << "Western Burger Quantity Ordered: " << quantity4 << endl;
    cout << "Don Cali Burger Quantity Ordered: " << quantity5 << endl;

    double costQuantity1 = 5.25 * quantity1;
    double costQuantity2 = 5.75 * quantity2;
    double costQuantity3 = 5.95 * quantity3;
    double costQuantity4 = 5.95 * quantity4;
    double costQuantity5 = 5.95 * quantity5;

    cout << fixed << showpoint << setprecision(2);

    cout << "\nCost Per Item: " << endl;
    cout << "De Anza Burger: $5.25 x " << quantity1 << " = " << costQuantity1 << endl;
    cout << "Bacon Cheese Burger: $5.75 x " << quantity2 << " = " << costQuantity2 << endl;
    cout << "Mushroom Swiss Burger: $5.95 x " << quantity3 << " = " << costQuantity3 << endl;
    cout << "Western Burger: $5.95 x " << quantity4 << " = " << costQuantity4 << endl;
    cout << "Don Cali Burger: $5.95 x " << quantity5 << " = " << costQuantity5 << endl;

    cout << "\nTotal Before Tax: " << endl;
    cout << "De Anza Burger: $" << costQuantity1 << endl;
    cout << "Bacon Cheese Burger: $" << costQuantity2 << endl;
    cout << "Mushroom Swiss Burger: $" << costQuantity3 << endl;
    cout << "Western Burger Burger: $" << costQuantity4 << endl;
    cout << "Don Cali Burger: $" << costQuantity5 << endl;

    double subTotal = costQuantity1 + costQuantity2 + costQuantity3 + costQuantity4 + costQuantity5;

    double taxAmount = 0;

    if(userCustomerType == 2) {
        taxAmount = subTotal * .09;
    }


    cout << "\nTax Amount: $" << taxAmount << endl;

    cout << "\nFinal Total: $" << (subTotal + taxAmount) << endl;

    ofstream outputFile;
    outputFile.open("output.txt");

    if(outputFile) {
        outputFile << "Final Bill: $" << (subTotal + taxAmount) << endl;
        outputFile.close();
    }

    else {
        cout << "There was an issue opening the file." << endl;
    }


    return 0;
}
