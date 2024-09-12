#include <iostream>
#include <iomanip>
#include <iomanip>  //use to manipulate output
#include <fstream>
#include <string>
#include <math.h>
@@ -38,6 +38,7 @@ class Movie
    void ticket_calculation(string movCode, int &total_seat_select);
    void ticket_print(string movCode, char seat[4][15], int &total_seat_select);
    void finish_seat(int &y, int &x, char seat[4][15]);
    void sale_report(string movCode, int &y, int &x, char seat[4][15]);
};


@@ -475,6 +476,7 @@ void Movie::book()
                        }
                        else
                        {
                        	sale_report(movCode, y, x, seat);
                            mainMenu();
                        }

@@ -831,6 +833,71 @@ void Movie::finish_seat(int &y, int &x, char seat[4][15])
    total_seat_select = 0;
}

void Movie:: sale_report(string movCode, int &y, int &x, char seat[4][15]) 
{
    int total_seat=0;
    int empty_seat=0;
    int total_seat_sold = 0;
    system("cls");
    for (y = 0; y < 4; y++)
    {
        for (x = 0; x <= 14; x++)
        {
            ++total_seat;
            if (seat[y][x] == 'X')
            {
                ++total_seat_sold;
            }
            else if(seat[y][x] != 'X')
            {
                ++empty_seat;
            }
        }
    }

    fstream data;
    data.open("movieDatabase.txt", ios::in);

    string movName, movGenre, movRating;
    int movYear;
    double movPrice;

    string myString, price;
    string line;

    while (getline(data, line))
    {
        stringstream ss(line);
        string record;
        while (getline(ss, record, ','))
        {
            if (record == movieCode)
            {
                stringstream ss(line);
                getline(ss, movCode, ',');
                getline(ss, movName, ',');
                getline(ss, movGenre, ',');
                getline(ss, myString, ',');
                movYear = stoi(myString);
                getline(ss, movRating, ',');
                getline(ss, price, ',');
                movPrice = stod(price);
            }
        }
    }
    data.close();

    cout << "\n\t\t\t    *** SALES REPORT ***             " << endl << endl;
    cout << "\t\t         Movie Name : " << movName << endl;
    cout << "\t\t        Total Seats : " << total_seat << endl;
    cout << "\t\t         Sold Seats : " << total_seat_sold << endl; 
    cout << "\t\t        Empty Seats : " << empty_seat << endl;
    cout << "\t\t       Ticket Price : " << movPrice << endl;
    cout << "\t\tTotal Amount Earned : " << total_seat_sold * movPrice << endl;

    cout << "\n\n";
	system("pause");
}

void Movie:: login()
{
