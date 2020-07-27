//  main.cpp
//  ThreeStrikes
//  This program was created by Abdalla Atalla and finished on 11/22/19. This program is a game where the user has to pick a chip from a bag and the chip will be either a digit or strike. There are three strikes allowed until you lose the game. If its a digit then guess which position it belongs to in the car's price. Have fun!
//  Created by Abdalla Atalla on 11/17/19.
//  Copyright © 2019 Abdalla Atalla. All rights reserved.

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void threeStrikes()
{

    cout << "~~~~~~~~~~Welcome to the Three Strikes Game~~~~~~~~~~" << endl
         << "Please pick a chip from a bag, the chip will" << endl
         << "be either a digit or strike. If it's a digit then guess" << endl
         << "which position it belongs to the car's price." << endl;
    cout << endl
         << "PANEL    :  _ _ _ _ _ < this is the (0) position " << endl;
    cout << "Position    4 3 2 1 0 " << endl;
    cout << "Accumulation of three strikes will result in losing the game!" << endl;

    int originalPrice[5];
    int price[5];
    int guessed = 0;
    int strikes = 0;
    char input;
    int bag[8];
    int digit;
    int digitPlaced = 0;

    srand(time(0));
    string panel[2][5] = {{"_", "_", "_", "_", "_"}, {"4", "3", "2", "1", "0"}};

    // generating car price
    price[0] = rand() % 10;

    bag[0] = price[0];

    for (int i = 1; i < 5; ++i)
    {
        int number = rand() % 10;
        for (int n : price)
        {
            while (n == number)
            {
                number = rand() % 10;
            }
        }

        price[i] = number;
        bag[i] = number;
    }

    for (int i = 5; i < 8; i++)
    {
        bag[i] = -1;
    }

    // showing car price
    cout << "The price must be hidden, but for you it's ok... : " << endl;
    cout << "$";
    for (int i = 0; i < 5; ++i)
    {
        cout << price[i];
    }
    cout << endl;

    for (int i = 0; i < 5; i++)
    {
        originalPrice[i] = price[i];
    }

    do
    {
        cout << "Enter 'p' to pick a chip, or any other key to quit the game : " << endl;
        cin >> input;

        if (input == 'p')
        {
            cout << "Strikes hit : " << strikes << endl;
            cout << "Digits placed : " << digitPlaced << endl;
            cout << "Panel : $ ";
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 5; j++)
                {
                    cout << panel[i][j] << " ";
                }
                cout << std::setw(11) << endl;
            }
            for (int i = 0; i < 8; i++)
            {
                // Testing to see whats in the bag     cout << bag[i];
            }
            int picked = bag[(rand() % 8)];
            // Testing to see number picked if -1 then strike
            cout << "\nYou picked the digit: " << picked << endl;
            bool digitFound = false;

            for (int i = 0; i < 5; i++)
            {
                if (picked == price[i])
                {
                    cout << "Which position do you think this digit belongs? " << endl;
                    cin >> digit;

                    if (digit == 4 - i)
                    {
                        cout << "Correct, you got the right position!!" << endl;
                        panel[0][4 - digit] = std::to_string(picked);
                        digitPlaced++;
                        digitFound = true;
                        price[i] = -2;
                        // since -2 need to redraw b/c that value has been used
                    }
                    else
                    {
                        cout << "Sorry you guess the wrong position!!" << endl;
                    }
                    break;
                }
            }

            if (picked == -1)
            {
                strikes++;
                cout << "You picked a strike!!" << endl;
            }
        }
        else
        {
            // picked wrong key not 'p' exit
            break;
        }

        if (strikes == 3)
        {
            cout << "Sorry you lost the game!" << endl;
            ;
            cout << "The price of the car was: ";
            for (int i = 0; i < 5; i++)
            {
                cout << originalPrice[i];
            }
            cout << endl;
            break;
        }

        if (digitPlaced == 5)
        {
            cout << "Congratulations !!! You won the car!! " << endl;
            for (int i = 0; i < 5; i++)
            {
                cout << originalPrice[i];
            }
            cout << endl;
            break;
        }
    } while (/*strikes != 3 || */ digitPlaced != 5);
}

int main()
{
    char input;
    do
    {
        threeStrikes();
        cout << "Do you want to play again? (y/n)" << endl;
        cin >> input;
    } while (input == 'y' || input == 'Y');
    cout << "Thank you, goodbye!" << endl
         << "Programmer~~Abdalla Atalla C++" << endl;
    cout << "CISC 192" << endl;
    return 0;
}

/* cout << "~~~~Welcome to the Three Strikes Game~~~~~~" << endl << "Pick a chip from a bag, the chip will be either a digit or strike." << endl << " If it's a digit then guess which position it belongs to the car's price"
 cout << "PANEL    : $ _ _ _ _ _ < this is the (0) position " << endl;
 cout << "            4 3 2 1 0 " << endl;
cout << "Accumulation of three strikes will result in losing the game!" << endl;
cout << "The price must be hidden, but for you it's ok... : " << << endl;
cout << " Enter 'c' to pick a chip, or any other key to quit the game : " << endl;
cout << "Strikes hit :" << endl;
cout << "Digits placed : " << endl;
cout << " You picked the digit:" << endl;
cout "Panel : " << endl;
cout << "Which position do you think this digit belongs? " << endl;
cout << "Correct, you got the right position!!" << endl;
cout << "Sorry you guees the wrong position!!" << endl;
cout << "You picked a strike!!" << endl;
cout << "Sorry you lost the game!" << endl;
cout << "Congratulations !!! You won the car !! " << endl;
cout << "The price of the car was: " << << endl;
cout << "Do you want to play again? (y/n)" << << endl;
cout << "Goodbye!" << endl << "Programmer~~Abdalla Atalla C++" << endl;
cout << "CISC 192" << endl;
 
 */
