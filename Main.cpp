#include<iostream>
#include<windows.h>
#include<conio.h>
using namespace std;

void local_time_formate(int hr, int mint, int sec, int x)
{
    while (true)
    {
        int y = x;
        while (hr <= 12)
        {
            while (mint < 60)
            {
                while (sec < 60)
                {
                    Sleep(1000);
                    system("cls");
                    cout << endl << endl << endl;
                    cout << "                       " << "HOUR" << " : " << "MINUTES" << "  : " << "SECONDS" << "     : AM/PM" << endl;
                    cout << "                         " << hr << "  :   " << mint << "      :   " << sec;
                    if (y == 1)
                    {
                        cout << "        :: " << "AM" << endl;
                    }
                    else if (y == 2)
                    {
                        cout << "        :: " << "PM" << endl;
                    }
                    cout << "        Press 0 or SPACE to stop the clock." << endl;

                    sec++;

                    if (_kbhit())
                    {
                        int key = _getch();
                        if (key == 48 || key == 32)
                        {
                            return;
                        }
                    }
                }
                sec = 0;
                mint++;
            }
            mint = 0;
            hr++;
            if (y == 2 && hr == 12)
            {
                y = 1;
            }
            else if (y == 1 && hr == 12)
            {
                y = 2;
            }
            else if (hr > 12)
            {
                hr = 1;
            }
        }
        hr = 1;
    }
}

void international_time_formate(int hr, int mint, int sec, int x)
{
    while (true)
    {
        while (hr <= 24)
        {
            while (mint < 60)
            {
                while (sec < 60)
                {
                    Sleep(1000);
                    system("cls");
                    cout << endl << endl << endl;
                    cout << "                       " << "HOUR" << " : " << "MINUTES" << "  : " << "SECONDS" << "     : AM/PM" << endl;
                    cout << "                         " << hr << "  :   " << mint << "      :   " << sec;
                    if (x == 1)
                    {
                        cout << "        :: " << "AM" << endl;
                    }
                    else if (x == 2)
                    {
                        cout << "        :: " << "PM" << endl;
                    }
                    cout << "        Press 0 or SPACE to stop the clock." << endl;

                    sec++;

                    if (_kbhit())
                    {
                        int key = _getch();
                        if (key == 48 || key == 32)
                        {
                            return;
                        }
                    }
                }
                sec = 0;
                mint++;
            }
            mint = 0;
            hr++;
            if (x == 1 && hr >= 12)
            {
                x = 2;
            }
            if (hr > 24)
            {
                hr = 1;
                x = 1;
            }
        }
        hr = 1;
    }
}

int main()
{
    int hr, mint, sec;

    while (1)
    {
        int choice;

        cout << "Which time formate do you want ?" << endl;
        cout << "1. International 24 Hours formate." << endl;
        cout << "2. Local 12 Hours formate." << endl;
        cout << "3. End the program."<<endl;
        cout << "Choice : ";
        cin >> choice;

        if (choice == 1)
        {
            cout << "Give me current time (HH MM SS): ";
            cin >> hr >> mint >> sec;
            int x;

            if (!(hr >= 12))
            {
                cout << "1. AM ." << endl;
                cout << "2. PM ." << endl;
                cout << "Choice : ";
                cin >> x;

                if (x == 2 && hr > 12)
                {
                    international_time_formate(hr, mint, sec, x);
                }
                else if (x == 2 && hr <= 12)
                {
                    hr = hr + 12;
                    international_time_formate(hr, mint, sec, x);
                }
                else if (x == 1)
                {
                    international_time_formate(hr, mint, sec, x);
                }
                else
                {
                    cout << "Enter correct formate of your data." << endl;
                }
            }

            if (hr >= 12)
            {
                x = 2;
                international_time_formate(hr, mint, sec, x);
            }
            else
            {
                cout << "Enter correct formate of your data." << endl;
            }
        }
        else if (choice == 2)
        {
            cout << "Give me current time (HH MM SS): ";
            cin >> hr >> mint >> sec;
            int x;
            cout << "1. AM ." << endl;
            cout << "2. PM ." << endl;
            cout << "Choice : ";
            cin >> x;

            if (hr > 12)
            {
                hr -= 12;
                local_time_formate(hr, mint, sec, x);
            }
            else if (hr <= 12)
            {
                local_time_formate(hr, mint, sec, x);
            }
            else
            {
                cout << "Enter correct formate data." << endl;
            }
        }
        else if (choice == 3)
        {
            break;
        }
    }

    return 0;
}
