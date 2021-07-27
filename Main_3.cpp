#include <iostream>
#include <math.h>
#include<utility>
using namespace std;


//Task1
class Figure
{
protected:
    int a, h, R;
    const float pi = 3.1415;
public:
    Figure(int a, int b):a(a),h(b)
    {

    }



    Figure(int R ) :R(R)
    {

    }

    virtual int area()
    {
        return 0;
    }
};

class Parallelogram : public Figure
{
private:
   
public:
    Parallelogram(int a, int h) :  Figure(a,h)
    {

    }

    int area()
    {
        return a * h;
    }
};


class Circle : public Figure
{
private:
    
public:
    Circle(int R) : Figure(R)
    {

    }

    int area()
    {
        return pi * R * R;
    }
};

class Rectangl : public Parallelogram
{
private:
    
public:
    Rectangl(int a, int b) : Parallelogram(a, b)
    {

    }

    int area()
    {
        return a * h;
    }
};

class Square : public Parallelogram
{
private:

public:
    Square(int a) : Parallelogram(a, a)
    {

    }

    int area()
    {
        return a * a;
    }
};

class Rhombus : public Parallelogram
{
private:

public:
    Rhombus(int a, int h) : Parallelogram(a, h)
    {


    }

    int area()
    {
        return a * h;
    }
};
//Task1


   

//Task2
class Car
{
protected:
public:

    Car(const char company[], const char model[])
    {
        cout << "Company: " << company << "\nModel: " << model << "\n";
    }
};

class PassengerCar : virtual public Car
{
private:

public:
    PassengerCar(const char Pcc[], const char Pcm[]) :Car(Pcc,Pcm)
    {
        cout << "Company: " << Pcc << "\nModel: " << Pcm << "\n";
    }
};

class Bus : virtual public Car
{
private:

public:
    Bus(const char Bc[], const char Bm[]) :Car(Bc, Bm)
    {
        cout << "Company: " << Bc << "\nModel: " << Bm << "\n";
    }
};

class Minivan :  public Bus, public PassengerCar
{
private:

public:
    Minivan(const char C[], const char Mm[], const char Bm[], const char Pcm[]) :
        Bus(C, Bm), PassengerCar(C,Pcm), Car(C,Mm)
    {

    }
};

//Task2




//Task3
class Fraction
{
private:
    short numerator;
    short denumenator;
public:
    Fraction(short f_numerator, short f_denumenator) : numerator(f_numerator), denumenator(f_denumenator)
    {
        if (!denumenator)
        {
            cout << "ERROR !!!! DENUMENATOR CANNOT BE EQUAL TO 0 !!!!\n The denominator is assigned a default value of 1.\n\n";
            denumenator = 1;
        }
        short i = 2;
        short j = 0;
        short k = 0;
        short sum = 1;
        while (!(numerator % i) || !(denumenator % i) || (numerator > i) || (denumenator > i))
        {
            if (!(numerator % i))
            {
                j++;
                numerator /= i;
            }
            if (!(denumenator % i))
            {
                k++;
                denumenator /= i;
            }
            if ((numerator % i) && (denumenator % i))
            {
                if (k == 0 || j == 0)
                {
                }
                else
                {
                    if (k < j)
                        sum *= i * k;
                    else
                        sum *= i * j;
                }
                numerator *= pow(i , j);
                denumenator *= pow(i , k);
                j = 0;
                k = 0;
                i++;
                for (int l = 2; l < i; l++)
                {
                    if (!(i % l))
                    {
                        i++;
                        l = 2;
                    }
                }
            }
        }    
        numerator /= sum;
        denumenator /= sum;   
    }


    
    
    friend Fraction operator+(const Fraction& f1, const Fraction& f2);
    friend Fraction operator-(const Fraction& f1, const Fraction& f2);
    friend Fraction operator*(const Fraction& f1, const Fraction& f2);
    friend Fraction operator/(const Fraction& f1, const Fraction& f2);
    friend bool operator< (const Fraction& f1, const Fraction& f2);
    friend bool operator>=(const Fraction& f1, const Fraction& f2);
    friend bool operator> (const Fraction& f1, const Fraction& f2);
    friend bool operator<= (const Fraction& f1, const Fraction& f2);
    Fraction operator-() const
    {
        return Fraction(-numerator, denumenator);
    }

   


    void printFraction()
    {
        cout << numerator << "/" << denumenator;
    }
};

Fraction operator+(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.numerator * f2.denumenator+ f2.numerator * f1.denumenator, f1.denumenator * f2.denumenator);
}

Fraction operator-(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.numerator * f2.denumenator - f2.numerator * f1.denumenator, f1.denumenator * f2.denumenator);
}

Fraction operator*(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.numerator * f2.numerator , f1.denumenator * f2.denumenator);
}

Fraction operator/(const Fraction& f1, const Fraction& f2)
{
    return Fraction(f1.numerator * f2.denumenator, f1.denumenator * f2.numerator);
}





bool operator< (const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denumenator < f2.numerator* f1.denumenator;
}

bool operator>=(const Fraction& f1, const Fraction& f2)
{
    return !(f1.numerator * f2.denumenator < f2.numerator* f1.denumenator);
}

bool operator> (const Fraction& f1, const Fraction& f2)
{
    return f1.numerator * f2.denumenator > f2.numerator* f1.denumenator;
}

bool operator<=(const Fraction& f1, const Fraction& f2)
{
    return !(f1.numerator * f2.denumenator > f2.numerator* f1.denumenator);
}

//Task3




//Task4


//Task4





    int main()
    {
    //Task1

    //Task1
    cout << "\n\n\n";
    //Task2
    Minivan car("Mercedes","RRR","Big","Small");

    cout << "\n\n\n";

    Bus car2("Mercedes", "Big");

    cout << "\n\n\n";

    PassengerCar car3("Mercedes", "Small");

    cout << "\n\n\n";

    Car car4("Mercedes", "RRR1");
    //Task2
    cout << "\n\n\n";
    //Task3
    Fraction frac1(6,8);
    Fraction frac2(1,8);
    Fraction fracSum = frac1 + frac2;
    fracSum.printFraction();
    cout << "\n\n";
    Fraction fracNoSum = frac1 - frac2;
    fracNoSum.printFraction();
    cout << "\n\n";
    Fraction fracProduct = frac1 * frac2;
    fracProduct.printFraction();
    cout << "\n\n";
    Fraction fracDivision = frac1 / frac2;
    fracDivision.printFraction();
    cout << "\n\n";
    Fraction fracMinus = -frac1;
    fracMinus.printFraction();
    cout << "\n\n";

    if (frac1 < frac2)
    {
        frac1.printFraction();
        cout <<" < ";
        frac2.printFraction();
        cout << ": True.\n\n";
    }
    else
    {
        frac1.printFraction();
        cout << " < ";
        frac2.printFraction();
        cout << ": False.\n\n";
    }

    if (frac1 >= frac2)
    {
        frac1.printFraction();
        cout << " >= ";
        frac2.printFraction();
        cout << ": True.\n\n";
    }
    else
    {
        frac1.printFraction();
        cout << " >= ";
        frac2.printFraction();
        cout << ": False.\n\n";
    }

    if (frac1 > frac2)
    {
        frac1.printFraction();
        cout << " > ";
        frac2.printFraction();
        cout << ": True.\n\n";
    }
    else
    {
        frac1.printFraction();
        cout << " > ";
        frac2.printFraction();
        cout << ": False.\n\n";
    }

    if (frac1 <= frac2)
    {
        frac1.printFraction();
        cout << " <= ";
        frac2.printFraction();
        cout << ": True.\n\n";
    }
    else
    {
        frac1.printFraction();
        cout << " <= ";
        frac2.printFraction();
        cout << ": False.\n\n";
    }

    //Task3
    cout << "\n\n\n";
    //Task4
       
    //Task4    
        return 0;
    }

 




/*
class Animal
{
public:
    Animal(const char a[]) {
        cout << a << endl;
    }
};

class Cat : virtual public Animal
{
public:
    Cat(const char a[], const char c[]) : Animal(a)
    {
        cout << c << endl;
    }
};

class Mouse : virtual public Animal
{
public:
    Mouse(const char a[], const char m[]) : Animal(a)
    {
        cout << m << endl;
    }
};

class Cartoon : public Cat, public Mouse
{
public:
    Cartoon(const char a[], const char c[], const char m[]) :
        Cat(a, c), Mouse(a, m), Animal(a)
    { }
};

int main() {
    Cartoon animal("animal", "cat", "mouse");
}
*/