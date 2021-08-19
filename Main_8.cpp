#include <iostream>
using namespace std;
struct Coordinates 
{
    short x, y;
};

class DivisionByZero
{
private:

public:
    DivisionByZero() {}
};

class Ex
{
private:
    
    public:
        int x;
        Ex(int m_x) : x(m_x)
        {

        }
};

class Bar
{
private:
    int y;
public:
    Bar()
    {
        y = 0;
    }

    int set(int& a)
    {
        if (y + a > 100)
        {
            throw Ex(a * y);
        }
        else
        {
            y = a;
            return y;
        }
    }
};


template <typename T>
T _div(T a, T b)
{
    if (b == NULL)
        throw DivisionByZero();
    else
        return a / b;
}

class OffTheField
{
private:

public:
    OffTheField()
    {

    }
};

class IllegalCommand
{
private:

public:
    IllegalCommand()
    {

    }
};




class Robot
{
private:
    Coordinates coord;
    short field[10][10];
public:

    Robot()
    {
        Start();
    }
    void Start()
    {       
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                field[i][j] = 0;
            }
        }
        field[0][0] = 1;
        coord.x = 0;
        coord.y = 0;
    }
    Coordinates findRobot()
    {

        for (int i = 0; i < 10; i++)
        {
            bool k=0;
            for (int j = 0; j < 10; j++)
            {
                if (field[i][j] == 1)
                {
                    coord.x = j;
                    coord.y = i;
                    k = 1;
                    break;
                }
            }
            if(k==1)
                break;

        }

        return coord;
    }

    void Moving_north()
    {
        if (findRobot().y == 0)
        {
            throw OffTheField();
        }
        else
        {
            field[findRobot().y][findRobot().x] = 0;
            field[findRobot().y - 1][findRobot().x] = 1;

            cout << "\n\nMovement in the direction to the north!\n\n";
        }
    }

    void Moving_south()
    {
        if (findRobot().y == 9)
        {
            throw OffTheField();
        }
        else
        {
            field[findRobot().y][findRobot().x] = 0;
            field[findRobot().y + 1][findRobot().x] = 1;
            cout << "\n\nMovement in the direction to the south!\n\n";
        }
    }

    void Moving_west()
    {
        if (findRobot().x == 0)
        {
            throw OffTheField();
        }
        else
        {
            field[findRobot().y][findRobot().x] = 0;
            field[findRobot().y][findRobot().x - 1] = 1;
            cout << "\n\nMovement in the direction to the west!\n\n";
        }
    }

    void Moving_east()
    {
        if (findRobot().x == 9)
        {
            throw OffTheField();
        }
        else
        {
            field[findRobot().y][findRobot().x] = 0;
            field[findRobot().y][findRobot().x + 1] = 1;
            cout << "\n\nMovement in the direction to the east!\n\n";
        }
    }

    void Drawing_a_field()
    {
        cout << "+-+-+-+-+-+-+-+-+-+-+\n";
            for (int i = 0; i < 10; i++)
            {
                for (int j = 0; j < 10; j++)
                {
                    cout <<"|"<<field[i][j];
                }
                cout << "|\n+-+-+-+-+-+-+-+-+-+-+\n";
            }     
    }

};








int main()
{
    try
    {
        cout << _div(6, 2) << '\n';
        cout << _div<double>(6, 4) << '\n';
        cout << _div(6, 0) << '\n';
    }
    catch (DivisionByZero)
    {
        cerr << "b == 0: Fatal ERROR!!!\n";
    }
    
    Bar bar;
    int n;
    while (cin >> n && n != 0)
    {
     try
     {        
             
            bar.set(n);
     }
     catch (Ex a)
     {
         cerr << "Error: y = " << a.x << '\n';
     }
    }


    cout << "Enter the direction using the keys \"w s a d\"\n";

    cout << "Enter 0 if you want to finish.\n";

    char r;
    Robot robot;
    while(cin >> r&&r!='0')
    {
        try {
            if (r == 'w')
            {
                robot.Moving_north();
                robot.Drawing_a_field();
            }
            else
            {
                if (r == 's')
                {
                    robot.Moving_south();
                    robot.Drawing_a_field();
                }
                else
                {
                    if (r == 'a')
                    {
                        robot.Moving_west();
                        robot.Drawing_a_field();
                    }
                    else
                    {
                        if (r == 'd')
                        {
                            robot.Moving_east();
                            robot.Drawing_a_field();
                        }
                        else
                        {
                            throw IllegalCommand();
                        }
                    }
                }
            }
        }
        catch (OffTheField)
        {
            cerr << "Going off the grid!!! Choose a different direction.\n ";
        }
        catch (IllegalCommand)
        {
            cerr << "Incorrect direction.\n ";
        }
    }

    
    return 0;
}

