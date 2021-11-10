#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Timer.h"


template <typename T>
T Swap(int* u, int* j)
{
    std::cout << "&u = " << u << "; " << "u = " << *u << '\n';
    std::cout << "&j = " << j << "; " << "j = " << *j << '\n';

    std::cout << '\n';

     
    int* l(std::move(u));
    std::cout << "l = " << l << "; " << "*l = " << *l << '\n';
    u = std::move(j);
    std::cout <<"u = "<< u << "; " <<"*u = "<< *u << '\n';
    j = std::move(l);
    std::cout << "j = " << j << "; " << "*j = " << *j << '\n';

    std::cout << '\n';

    std::cout << "&u = " << u << "; " << "u = " << *u << '\n';
    std::cout << "&j = " << j << "; " << "j = " << *j << '\n';

}



void j(int a, int b)
{
    a++;
    b++;
}


template <typename T>
T SortPointer(std::vector<int*>& point)
{
    std::sort(point.begin(), point.end(), [](int *lhs,int *rhs) 
    {
        return *lhs < *rhs;
    });
    std::cout << '\n';
}



int main()
{
    setlocale(LC_ALL, "Russian");

    int u, j;
    u = 5;
    j = 6;
    int* a = &u;
    int* b = &j;
    Swap<void>(&u, &j);
    std::cout << '\n';
    


    int meaning[6] = { 5,4,2,7,8,1 };
    std::vector<int*> point;
    for (short i = 0; i < 6; i++)
    {
        point.push_back(&meaning[i]);
        std::cout << point[i]<<' '<< *point[i] << '\n';
    }
    std::cout << '\n';
    SortPointer<void>(point);
    for (short i = 0; i < point.size(); i++)
    {
        std::cout << point[i] << ' ' << *point[i] << '\n';
    }
    std::cout << '\n';
    std::cout << '\n';
    std::ifstream War_And_Piece("C:\\Users\\kondr\\Desktop\\Programming\\C++\\Hard Moment\\Hard_Moment_2\\Hard_Moment_2\\Hard_Moment_2\\War and piece.txt");
    std::vector<std::string> String1;
    std::string STR;
    std::string STR_1;
    
    while (!War_And_Piece.eof())
    {
        std::getline(War_And_Piece, STR, '\n');
        STR_1 += STR;
        String1.push_back(STR);
        
    }

    std::getline(War_And_Piece, STR_1);
    //1
    Timer timer1("\ncount_if and find");
    unsigned int symbol1 = 0;
    symbol1 = count_if(STR_1.begin(), STR_1.end(), [](char &c)
    {
        char a[] = { 'a','A','e','E','y','Y','u','U','i','I','o','O' };
        return std::find(a, a + 12, c) != a+12;
    });

    std::cout << "vowel letters 1 = " << symbol1 << "\n";
    timer1.print();
    std::cout << '\n';
    std::cout << '\n';
    //2
    Timer timer2("\ncount_if and for");
    unsigned int symbol2=0;
    for (int i = 0; i < String1.size(); i++)
    {
        STR = String1[i];
        symbol2 += std::count_if(STR.begin(), STR.end(), [](char &c)
        {
            return c == 'a' || c == 'e' || c == 'y' || c == 'u' || c == 'i' || c == 'o'|| c == 'A' || c == 'E' || c == 'Y' || c == 'U' || c == 'I' || c == 'O';
        });

    }

    std::cout << "vowel letters 2 = "<< symbol2 << "\n";
    timer2.print();
    std::cout << '\n';
    std::cout << '\n';
    //3
    Timer timer3("\nfor and find");
    unsigned int symbol3 = 0;
    for (int i = 0; i < STR_1.size(); i++)
    {
        char a[] = { 'a','A','e','E','y','Y','u','U','i','I','o','O' };
        if (std::find(a, a + 12, STR_1[i]) != a + 12)
        {
            symbol3++;
        }

    }

    std::cout << "vowel letters 3 = " << symbol3 << "\n";
    timer3.print();
    std::cout << '\n';
    std::cout << '\n';
    //4
    Timer timer4("\nfor and for");
    unsigned int symbol4 = 0;
    for (int i = 0; i < String1.size(); i++)
    {
        for (int j = 0; j < String1[i].size(); j++)
        {
            if (String1[i][j] == 'a' || String1[i][j] == 'e' || String1[i][j] == 'y' || String1[i][j] == 'u' || String1[i][j] == 'i' || String1[i][j] == 'o' ||
                String1[i][j] == 'A' || String1[i][j] == 'E' || String1[i][j] == 'Y' || String1[i][j] == 'U' || String1[i][j] == 'I' || String1[i][j] == 'O')
            {
                symbol4++;
            }
        }
    }

    std::cout << "vowel letters 4 = " << symbol4 << "\n";
    timer4.print();

    return 0;
}