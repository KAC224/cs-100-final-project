#include <iostream>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <ctime>
#include <string>
// #include <windows.h>

using namespace std;

int const ROWS = 5;
int const COLUMNS = 5;
int milliseconds = 1000;
int milliseconds2 = 500;

string Begin()
{
    cout << endl;
    cout << endl;
    cout << "Welcome to Apni Gaari, a program designed to find you a sports car suited to your racing needs.";
    cout << endl;
    cout << endl;

    cout << "Would you like to begin? (yes/no) ";
    cout << endl;
    cout << endl;

    string y_n;
    cin >> y_n;
    cout << endl;

    // this works!
    while (y_n != "Yes" && y_n != "yes" && y_n != "no" && y_n != "No")
    {
        cout << "Invalid input. Retry: ";
        cin >> y_n;
        cout << endl;
    }

    return y_n;
}

void showOptions()
{
    // Sleep(milliseconds);
    cout << "Here are your car options: ";
    cout << endl;
    cout << endl;

    cout << "Mercedes" << endl;
    cout << "Ferrari" << endl;
    cout << "Aston Martin" << endl;
    cout << "Porsche" << endl;
    cout << "Lamborgini" << endl;
    cout << endl;
}

void selectPricing(int *p_price, int *p_filter)
{
// Sleep(milliseconds);
    cout << "Select your price range of daily rate (PKR): "; // ranges can be changed
    cout << endl;
    cout << endl;

    cout << "Choice 1: <=10000" << endl;
    cout << "Choice 2: 10000-20000" << endl;
    cout << "Choice 3: 20000-30000" << endl;
    cout << "Choice 4: 30000-40000" << endl;
    cout << "Choice 5: >=40000" << endl;
    cout << endl;

    int choice_1;
    cout << "Choice: ";
    cin >> choice_1; // kinda like a do loop
    cout << endl;

    // ITS DONE ?!?!??!?! shukar
    // this considers invalid inputs and inputs out of range
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> choice_1;
        }

        if ((!cin.fail() && choice_1 < 1) || (!cin.fail() && choice_1 > 5))
        {
            cout << "Invalid input. Please try again: ";
            cin >> choice_1;
        }

        if (!cin.fail() && !(choice_1 < 1 || choice_1 > 5))
        {
            cout << endl;
            break;
        }
    }

    switch (choice_1)
    {
    case 1:

        // this is range <10000
        {

            for (int i = 0; i < 25; i++)
            {

                if (*(p_price + i) < 10000)
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }

            break;
        }
    case 2:
        // this is range 10000-20000
        {

            for (int i = 0; i < 25; i++)
            {
                if ((*(p_price + i) >= 10000) && (*(p_price + i) < 20000))
                {

                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }
            break;
        }
    case 3:
    {
        // 20000-30000
        for (int i = 0; i < 25; i++)
        {
            if ((*(p_price + i) >= 20000) && (*(p_price + i) < 30000))
            {

                *(p_filter + i) = i; // this will fill in the filter array
            }
        }
        break;
    }
    case 4:
    {
        // 30000-40000
        for (int i = 0; i < 25; i++)
        {
            if ((*(p_price + i) >= 30000) && (*(p_price + i) < 40000))
            {

                *(p_filter + i) = i; // this will fill in the filter array
            }
        }
        break;
    }
    case 5:
    {
        //>50000
        for (int i = 0; i < 25; i++)
        {
            if (*(p_price + i) >= 40000)
            {

                *(p_filter + i) = i; // this will fill in the filter array
            }
        }
        break;
    }
    }
}

void selectColour(char *p_colour, int *p_filter)
{
    // Sleep(milliseconds);
    cout << "Select your colour: "; // colours can be changed
    cout << endl;
    cout << endl;
    cout << "Choice 1: Red" << endl;
    cout << "Choice 2: Blue" << endl;
    cout << "Choice 3: Black" << endl;
    cout << "Choice 4: White" << endl;
    cout << "Choice 5: Silver" << endl;
    cout << endl;

    int choice_2;
    cout << "Choice: ";
    cin >> choice_2;
    cout << endl;

    // // input validation:
    // while (!(cin >> choice_2) || (choice_2 < 1) || (choice_2 > 5))
    // {
    //     cout << "This choice not valid. please enter one of the choices given: " << endl;
    //     cout << endl;
    //     cout << "Select your colour: ";
    //     cout << endl;
    //     cout << endl;
    //     cout << "Choice 1: Red" << endl;
    //     cout << "Choice 2: Blue" << endl;
    //     cout << "Choice 3: Black" << endl;
    //     cout << "Choice 4: White" << endl;
    //     cout << "Choice 5: Silver" <<endl;
    //     cout << endl;

    //     cout << "Choice: ";

    //     cin.clear();
    //     cin.ignore(123, '\n');
    //     cout << endl;
    // }

    // input validation. invalid inputs and out of range
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> choice_2;
        }

        if ((!cin.fail() && choice_2 < 1) || (!cin.fail() && choice_2 > 5))
        {
            cout << "Invalid input. Please try again: ";
            cin >> choice_2;
        }

        if (!cin.fail() && !(choice_2 < 1 || choice_2 > 5))
        {
            cout << endl;
            break;
        }
    }

    switch (choice_2)
    {
    case 1: // red case
    {
        for (int i = 0; i < 25; i++)
        {
            if (*(p_colour + i) == 'r')
            {
                if (i == *(p_filter + i))
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }

            else
            {
                *(p_filter + i) = -1;
            }
        }
        break;
    }
    case 2: // blue case
    {
        for (int i = 0; i < 25; i++)
        {
            if (*(p_colour + i) == 'b')
            {
                if (i == *(p_filter + i))
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }
            else
            {
                *(p_filter + i) = -1;
            }
        }
        break;
    }
    case 3: // black case
    {
        for (int i = 0; i < 25; i++)
        {
            if (*(p_colour + i) == 'k')
            {
                if (i == *(p_filter + i))
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }
            else
            {
                *(p_filter + i) = -1;
            }
        }
        break;
    }

    case 4: // white case
    {
        for (int i = 0; i < 25; i++)
        {
            if (*(p_colour + i) == 'w')
            {
                if (i == *(p_filter + i))
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }
            else
            {
                *(p_filter + i) = -1;
            }
        }
        break;
    }
    case 5: // silver case
    {
        for (int i = 0; i < 25; i++)
        {
            if (*(p_colour + i) == 's')
            {
                if (i == *(p_filter + i))
                {
                    *(p_filter + i) = i; // this will fill in the filter array
                }
            }
            else
            {
                *(p_filter + i) = -1;
            }
        }
        break;
    }
    }
}

void selectMileage(int *p_mileage, int *p_filter)
{
    // Sleep(milliseconds);
    cout << "Select your mileage specifications(MPG): "; // ranges can be changed
    cout << endl;
    cout << endl;
    cout << "Choice 1: 20-25" << endl;
    cout << "Choice 2: 25-30" << endl;
    cout << endl;

    int choice_3;
    cout << "Choice: ";
    cin >> choice_3;
    cout << endl;

    // invalid inputs and out of range
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> choice_3;
        }

        if ((!cin.fail() && choice_3 < 1) || (!cin.fail() && choice_3 > 2))
        {
            cout << "Invalid input. Please try again: ";
            cin >> choice_3;
        }

        if (!cin.fail() && !(choice_3 < 1 || choice_3 > 2))
        {
            cout << endl;
            break;
        }
    }

    switch (choice_3)
    {
    case 1:
        // mileage is 20-25
        {
            for (int i = 0; i < 25; i++)
            {
                if ((*(p_mileage + i) >= 20) && (*(p_mileage + i) < 25))
                {
                    if (i == *(p_filter + i))
                    {
                        *(p_filter + i) = i; // this will fill in the filter array
                    }
                }
                else
                {
                    *(p_filter + i) = -1;
                }
            }
            break;
        }
    case 2:
        // mileage is 25-30
        {
            for (int i = 0; i < 25; i++)
            {
                if ((*(p_mileage + i) >= 25) && (*(p_mileage + i) < 30))
                {
                    if (i == *(p_filter + i))
                    {
                        *(p_filter + i) = i; // this will fill in the filter array
                    }
                }
                else
                {
                    *(p_filter + i) = -1;
                }
            }
            break;
        }
    }
}

void printFinalOptions(int *p_filter, char *p_car, int *p_price, char *p_colour, int *p_mileage, int &c)
{
    // Sleep(milliseconds);
    cout << "Your final options are: " << endl;
    cout << endl;

    for (int i = 0; i < 25; i++)
    {
        if (*(p_filter + i) != -1)
        {
            // print car code
            cout << "Car Code: " << *(p_filter + i) << endl;
            // print car brand
            if (*(p_car + i) == 'M')
                cout << "Car Brand: "
                     << "Mercedes" << endl;
            else if (*(p_car + i) == 'F')
                cout << "Car Brand : "
                     << "Ferrari" << endl;
            else if (*(p_car + i) == 'A')
                cout << "Car Brand: "
                     << "Aston Martin" << endl;
            else if (*(p_car + i) == 'P')
                cout << "Car Brand : "
                     << "Porsche" << endl;
            else if (*(p_car + i) == 'L')
                cout << "Car Brand: "
                     << "Lamborgini" << endl;

            //  print details : price, colour, mileage
            cout << "Daily Rate: " << *(p_price + i) << " PKR" << endl;

            if (*(p_colour + i) == 'r')
                cout << "Colour: "
                     << "Red" << endl;
            else if (*(p_colour + i) == 'b')
                cout << "Colour: "
                     << "Blue" << endl;
            else if (*(p_colour + i) == 'k')
                cout << "Colour: "
                     << "Black" << endl;
            else if (*(p_colour + i) == 'w')
                cout << "Colour: "
                     << "White" << endl;
            else if (*(p_colour + i) == 's')
                cout << "Colour: "
                     << "Silver" << endl;

            cout << "Mileage: " << *(p_mileage + i) << " MPG" << endl;
            cout << endl;
        }
    }
    // make sure if there arent any options
    for (int i = 0; i < 25; i++)
    {
        if (*(p_filter + i) != -1)
        {
            c++;
        }
    }
    if (c == 0)
    {
        cout << "There are no cars with these specifications available. " << endl;
        cout << endl;
    }
}

void selectFinalOption(int *p_filter)
{
    cout << "Select your car by entering its car code: "; // ranges can be changed
    cout << endl;
    cout << endl;

    int choice_4;
    cout << "Car Code: ";
    cin >> choice_4;
    cout << endl;

    // input validation
    // invalid inputs and out of range
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> choice_4;
        }

        if ((!cin.fail() && *(p_filter + choice_4) == -1) || (!cin.fail() && choice_4 < 0) || (!cin.fail() && choice_4 >= 25))
        {
            cout << "Invalid input. Please try again: ";
            cin >> choice_4;
        }

        if (!cin.fail() && !(choice_4 < 0 || choice_4 >= 25) && *(p_filter + choice_4) != -1)
        {
            cout << endl;
            break;
        }
    }

    for (int i = 0; i < 25; i++)
    {
        if (choice_4 == *(p_filter + i))
        {
            *(p_filter + i) = i;
        }
        else
        {
            *(p_filter + i) = -1;
        }
    }
}

int findAndStoreDailyRate(int *p_filter, int *p_price)
{
    int daily_rate;
    for (int i = 0; i < 25; i++)
    {
        if (*(p_filter + i) != -1)
        {

            daily_rate = *(p_price + i);
        }
    }
    return daily_rate;
    // after this, we'll stop relying on filter array
}

double calculateTotal(int daily_rate, int &days)
{

    double price = 0;
    double initial_deposit = 10000;
     double tax_rate = 0.16;
    double tax = 0;
    double daily_rate_sum = 0;

    cout << "Initial deposit is 10000 RS. Tax is added and charged at 16% of total price." << endl;
    cout << endl;

    cout << "Enter number of days for renting sportscar: ";

    cin >> days;
    cout << endl;

    // input validation
    // invalid inputs and out of range inputs

    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> days;
        }

        if (!cin.fail() && days <= 0)
        {
            cout << "Invalid input. Please try again: ";
            cin >> days;
        }

        if (!cin.fail() && !(days <= 0))
        {
            cout << endl;
            break;
        }
    }

    // calculate total price:
    cout << "Calculating final price: " << endl;
    cout << "Initial Deposit:         " << initial_deposit << " +" << endl;
    // daily rate:

    daily_rate_sum = daily_rate_sum + (days * daily_rate);
    price = price + daily_rate_sum;
    cout << "Daily Rate Sum:          " << price << " +" << endl;
    // + initial deposit
    price = price + initial_deposit;

    tax = tax + (price * tax_rate);
    cout << "Tax:                     " << tax << " +" << endl;
    // + tax
    price = price + tax;
    cout << "Final Price:           = " << price << endl;
    cout << endl;

    cout << "Your total for " << days << " days is " << price << " PKR" << endl;
    cout << endl;
    return price;
}

void cardDetails(double price)
{
    string cardtype;
    string cardno;
    int exp_date;
    char a;

    cout << "Please enter type of card (Types supported: Mastercard/Visa): ";
    cin >> cardtype;
    cout << endl;

    // input validation
    // this considers anything not a mastercard or a visa card
    while (cardtype != "Mastercard" && cardtype != "mastercard" && cardtype != "Visa" && cardtype != "visa")
    {
        cout << "Invalid input. Retry: ";
        cin >> cardtype;
        cout << endl;
    }

    a = toupper(cardtype[0]);
    cout << "Enter card number for your " << a << cardtype.substr(1) << " card: ";
    cin >> cardno;
    cout << endl;

    // og input validation
    while (cardno.length() != 16)
    {
        cout << "Invalid input. Length should be 16 digits. Please try again: ";
        cin >> cardno;
    }

    cout << "Enter expiration date of card (yymmdd): ";
    cin >> exp_date;
    cout << endl;

    // og input validation
    while (exp_date / 10000 < 23)
    {
        cout << "Credit card is expired. Transaction terminated. " << endl;
        cout << "Enter card number again: " << endl;
        cin >> exp_date;
    }

    //     // input validation (further complexities on card details)
    //     while (exp_date / 10000 < 23 || !(cin>>exp_date)|| exp_date % 100 > 31 || (exp_date/100)%100 >31 || exp_date<0 || (exp_date %1000000 != exp_date))
    //     {
    //         if (exp_date / 10000 < 23 )
    //         {
    //         cout << "Credit card is expired. Transaction terminated. " << endl;
    //         cout << "Enter card number again: " << endl;
    //         cin >> exp_date;
    //         }
    //         else if ( !(cin>>exp_date) || exp_date<0 || (exp_date %1000000 != exp_date))
    //         {
    //             cout << "Invalid input. Please try again: ";
    //             cin.clear();
    //         cin.ignore(123, '\n');
    //         cout << endl;

    //         }
    //         else if (exp_date % 100 > 31 || (exp_date/100)%100 >31 )
    //         {
    // cout << "Invalid input. Please try again: ";
    //             cin.clear();
    //         cin.ignore(123, '\n');
    //         cout << endl;
    //         }
    //     }

    string y_n;
    double discount = 0;
    double discount_rate = 0.15;

    if (price > 10000)
    {
        cout << "Your card is eligible for a 15% discount. Apply? (yes/no): ";
        cin >> y_n;
        cout << endl;
        cout << endl;

        // input validation. reject anything other than a yes or a no
        while (y_n != "yes" && y_n != "Yes" && y_n != "no" && y_n != "No")
        {
            cout << "Invalid input. Please try again: ";
            cin >> y_n;
            cout << endl;
        }

        if (y_n == "Yes" || y_n == "yes")
        {
            discount = discount + (discount_rate * price);
            price = price - discount;

            cout << "Discount: " << discount << " PKR " << endl;
            cout << "Your new total is " << price << " PKR" << endl;
            cout << endl;
            cout << endl;
        }
    }
    cout << "Loading . . ." << endl;
// Sleep(milliseconds);
    cout << "Payment has been made.\nA total of " << price << " PKR "
         << "has been deducated from account number " << cardno.substr(0, 4) << "**********" << cardno.substr(14, 2) << endl;
    cout << endl;
}

void transfer(double price)
{
    string app;
    string cardtype;
    char a;
    char b;

    cout << "E-transfer supported by: ";
    cout << endl;

    cout << " 1.Jazzcash,\n 2.EasyPaisa, \n 3.Sadapay. \n ";
    cout << endl;

    cout << "Enter the name of your desired app: ";
    cin >> app;
    a = app[0];
    cout << endl;
    cout << endl;

    // input validation. reject anything thats not the name of app
    while (a != 'j' && a != 'J' && a != 's' && a != 'S' && a != 'E' && a != 'e')
    {
        cout << "Invalid input. Please try again: ";
        cin >> app;
        a = app[0];
        cout << endl;
    }

    if (a == 'j' || a == 'J')
    {
        cout << "Log into Jazzcash: " << endl;
        cout << endl;

        string cred_1, cred_2;
        cout << "Username: ";
        cin >> cred_1;

        cout << "Password: ";
        cin >> cred_2;
        cout << endl;

        while (cred_2.length() < 8)
        {
            cout << "Password length cannot be less than 8. Please re-enter: ";
            cin >> cred_2;
        }

        string y_n;
        double discount = 0;
        double discount_rate = 0.15;

        if (price > 10000)
        {
            cout << "Your bill is eligible for a 10% discount. Apply? (yes/no): ";
            cin >> y_n;
            cout << endl;

            // //input validation. reject anything thats not a yes or a no
            while (y_n != "yes" && y_n != "Yes" && y_n != "no" && y_n != "No")
            {
                cout << "Invalid input. Please try again: ";
                cin >> y_n;
                cout << endl;
            }

            if (y_n == "yes" || y_n == "Yes")
            {
                discount = discount + (discount_rate * price);
                price = price - discount;

                cout << "Discount: " << discount << " PKR " << endl;
                cout << "Your new total is " << price << " PKR" << endl;
                cout << endl;
            }
           
            cout << "Verifying payment. Please wait..." << endl;
            // Sleep(milliseconds);
            cout << " " << endl;
            cout << "Transaction successful!" << endl;
            cout << endl;
            cout << "Your name has been entered in a Jazzcash Exclusive Lucky Draw to win tickets to the Grand Prix Bahrain 2024 and get a chance to meet one of the drivers!" << endl;
            cout << endl;
        }
    }
    if (a == 'E' || a == 'e')
    {
        cout << "Log into EasyPaisa: " << endl;
        cout << endl;
        string cred_1, cred_2;

        cout << "Username: ";
        cin >> cred_1;

        cout << "Password: ";
        cin >> cred_2;
        cout << endl;

        while (cred_2.length() < 8)
        {
            cout << "Password length cannot be less than 8. Please re-enter: ";
            cin >> cred_2;
        }

        cout << "Verifying payment. Please wait..." << endl;
        // Sleep(milliseconds);
        cout << " " << endl;
        cout << "Transaction successful!" << endl;
        cout << endl;
    }

    if (a == 'S' || a == 's')
    {
        cout << "Log into Sadapay: ";
        string cred_1, cred_2;

        cout << "Username: ";
        cin >> cred_1;

        cout << "Password: ";
        cin >> cred_2;
        cout << endl;

        while (cred_2.length() < 8)
        {
            cout << "Password length cannot be less than 8. Please re-enter: ";
            cin >> cred_2;
        }

        cout << "Verifying payment. Please wait..." << endl;
        // Sleep(milliseconds);
        cout << " " << endl;
        cout << "Transaction successful!" << endl;
        cout << endl;
    }
}

void fullPayment(double price, int &mode)
{

    cout << "Pick number of preferred payment mode:";
    cout << endl;

    cout << " 1. Cash,\n 2. Card, \n 3. E-transfer: " << endl;
    cout << endl;

    cout << "Mode: ";
    cin >> mode;
    cout << endl;

    // input validation
    // valid inputs and out of range inputs
    while (1)
    {
        if (cin.fail()) // returns true when input fails
        {
            cin.clear(); // use to clear error state of buffer

            // ignores rest of the line
            // after first error occurs
            // skips to the next line
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please try again: ";
            cin >> mode;
        }

        if ((!cin.fail() && mode < 1) || (!cin.fail() && mode > 3))
        {
            cout << "Invalid input. Please try again: ";
            cin >> mode;
        }

        if (!cin.fail() && !(mode < 1 || mode > 3))
        {
            cout << endl;
            break;
        }
    }

    switch (mode)
    {
    case 1:
    {
        cout << "Please head to the nearest Apni Gaari branch for payment. ";
        cout << endl;
        cout << endl;
    }
    break;
    case 2:
    {
        cardDetails(price);
    }
    break;
    case 3:
    {
        transfer(price);
    }
    break;
    }
}

void printBill(double price, int days, int mode, int *p_filter, char *p_car, char *p_colour, int *p_mileage)
{
    cout << endl;
    string name;
    cout << "Enter name: ";
    //getline(cin, name);
    cin>> name;
    cout << "Generating receipt..." << endl;
    cout << endl;
    // Sleep(milliseconds);
    cout << "    _____________________________________________________ " << endl;
    cout << "    *****************************************************" << endl;
    cout << "    **********************APNIGAARI**********************" << endl;
    cout << "    The one stop shop for all your racing needs!    " << endl;
    cout << "    Customer name: " << name << endl;
    cout << "    Purchase ID " << rand() << endl;
    time_t current_time = time(0);
    char *ptr_time = ctime(&current_time);

    cout << "      Date and time of purchase: " << ptr_time << endl;
    for (int i = 0; i < 25; i++)
    {
        if (*(p_filter + i) != -1)
        {
            // print car code
            cout << "    Car Code: " << *(p_filter + i) << endl;
            // print car brand
            if (*(p_car + i) == 'M')
                cout << "    Car Brand: "
                     << "Mercedes" << endl;
            else if (*(p_car + i) == 'F')
                cout << "    Car Brand : "
                     << "Ferrari" << endl;
            else if (*(p_car + i) == 'A')
                cout << "    Car Brand: "
                     << "Aston Martin" << endl;
            else if (*(p_car + i) == 'P')
                cout << "    Car Brand : "
                     << "Porsche" << endl;
            else if (*(p_car + i) == 'L')
                cout << "    Car Brand: "
                     << "Lamborgini" << endl;

            //  print details : price, colour, mileage

            if (*(p_colour + i) == 'r')
                cout << "    Colour: "
                     << "Red" << endl;
            else if (*(p_colour + i) == 'b')
                cout << "    Colour: "
                     << "Blue" << endl;
            else if (*(p_colour + i) == 'k')
                cout << "    Colour: "
                     << "Black" << endl;
            else if (*(p_colour + i) == 'w')
                cout << "    Colour: "
                     << "White" << endl;
            else if (*(p_colour + i) == 's')
                cout << "    Colour: "
                     << "Silver" << endl;

            cout << "    Mileage: " << *(p_mileage + i) << " MPG" << endl;
            cout << endl;
        }
    }
    cout << "      The total bill is " << price << " PKR." << endl;
    cout << "      Days rented: " << days << endl;

    string format;
    if (mode == 1)
    {
        format = "Cash";
    }
    else if (mode == 2)
    {
        format = "Card";
    }
    else if (mode == 3)
    {
        format = "E-Transfer";
    }

    cout << "      Mode of payment: " << format << endl;
    cout << "    _____________________________________________________ " << endl;
    cout << endl;
    cout << "This is a computer generated receipt. Please keep with you when picking up vehicle. " << endl;
}

void End()
{
    cout << "Thank you for shopping at Apni Gaari!" << endl;
    cout << endl;

    cout << "Have a nice day!" << endl;
    cout << endl;
}

int main()
{
    // make arrays, these need to be used throughout
    char car[ROWS][COLUMNS] = {'M', 'F', 'A', 'P', 'L',
                               'M', 'F', 'A', 'P', 'L',
                               'M', 'F', 'A', 'P', 'L',
                               'M', 'F', 'A', 'P', 'L',
                               'M', 'F', 'A', 'P', 'L'}; // car type array
    // car[0][COLUMNS] = '\0';
    // car[1][COLUMNS] = '\0';
    // car[2][COLUMNS] = '\0';
    // car[3][COLUMNS] = '\0';
    // car[4][COLUMNS] = '\0';
    char *p_car;
    p_car = &car[0][0];

    //   <10,000 | >=10,000 and <20,000 | >=20,000 and <30,000 | >=30,000 and <40,000 | >= 40,000
    int price[ROWS][COLUMNS] = {5000, 6000, 7000, 8000, 9000,
                                15000, 16000, 17000, 18000, 19000,
                                25000, 26000, 27000, 28000, 29000,
                                35000, 36000, 37000, 38000, 39000,
                                45000, 46000, 47000, 48000, 49000}; // prices can be changed
    int *p_price;
    p_price = &price[0][0];

    char colour[ROWS][COLUMNS] = {'r', 'b', 'r', 'r', 'w',
                                  'b', 'w', 'w', 'k', 'r',
                                  'w', 's', 'k', 's', 'b',
                                  'b', 'w', 'r', 'k', 's',
                                  's', 'k', 's', 'w', 'r'}; // colours can be changed
    // colour[0][COLUMNS] = '\0';
    // colour[1][COLUMNS] = '\0';
    // colour[2][COLUMNS] = '\0';
    // colour[3][COLUMNS] = '\0';
    // colour[4][COLUMNS] = '\0';
    char *p_colour;
    p_colour = &colour[0][0];

    int mileage[ROWS][COLUMNS] = {22, 24, 28, 29, 28,
                                  27, 29, 27, 22, 25,
                                  23, 25, 21, 27, 20,
                                  25, 20, 24, 24, 27,
                                  21, 26, 28, 23, 21}; // 20-30 MPG // mileage can be changed
    int *p_mileage;
    p_mileage = &mileage[0][0];

    int filter[ROWS][COLUMNS] = {-1, -1, -1, -1, -1,
                                 -1, -1, -1, -1, -1,
                                 -1, -1, -1, -1, -1,
                                 -1, -1, -1, -1, -1,
                                 -1, -1, -1, -1, -1}; // this is the array that will narrow down options
    int *p_filter;
    p_filter = &filter[0][0];

    string answer;
    answer = Begin();

    if (answer == "yes" || answer == "Yes")
    {
        // function to show options
        showOptions();

        // function to go through price category
        selectPricing(p_price, p_filter);
        // category 1 filtered!

        // function to go through colour category
        selectColour(p_colour, p_filter);
        // category 2 filtered!

        // function to go through mileage
        selectMileage(p_mileage, p_filter);
        // category 3 filtered!

        int c = 0;
        // function to print final options
        printFinalOptions(p_filter, p_car, p_price, p_colour, p_mileage, c);

        if (c != 0)
        {
            // function to select final option
            selectFinalOption(p_filter);

            // function to find daily rate and store value
            int daily_rate = findAndStoreDailyRate(p_filter, p_price);

            // function to calculate total and show it to user
            //commented out
            int days;
            double price = calculateTotal(daily_rate, days);

            // function that carrys out all the payment modes
            // put this above calculate total
            //send daily rate instead of price
            int mode;
            fullPayment(price, mode);

            // function to print out ticket
            printBill(price, days, mode, p_filter, p_car, p_colour, p_mileage);

            // ending messages
            End();
        }
        else
            End();
    }
    else
        End();

    return 0;
}

// get line masla
// i swear, this coding project isnt funny anymore :((
