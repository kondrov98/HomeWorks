#include <iostream>
using namespace std;

ostream& endll(ostream& os)
{
    return os <<'\n'<<endl;
}

int main()
{
    int i;
    cout << "Enter int : ";
    while (true)
    {
        if (cin >> i && cin.get() == '\n')
        {
            
            break;      
        }
        else
            cout << i << endl;
            cin.clear();
            while (cin.get() != '\n');
        cerr << "Oops, you got something wrong, enter the number again!" << endl;
    }
    cout << i << endll;
    cout << i ;

    return 0;
}

/*
#include <iostream>
using namespace std;

int main()
{
    int num;
    for (;;) {
        if (cin >> num && cin.get() != '\n')
        {
            break;
        }
        else
        {
            cout << "Incorrect input." << endl;

            while (cin.get() != '\n') cin.clear();
        }
    }
    return 0;
}
*/