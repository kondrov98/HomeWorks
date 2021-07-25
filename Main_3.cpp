#include <iostream>
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

};

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