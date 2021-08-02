#include <iostream>
#include <vector>

template <typename T>
 class Pair1 
{
private:
     T& fir;
     T& sec;
public:
    Pair1(T fir_m, T sec_m) :fir(fir_m), sec(sec_m)
    {

    }

     T first() const
    {
        return fir;
    }

     T second() const
    {
        return sec;
    }
};

 template <typename T, typename F>
 class Pair
 {
 protected:
     T fir;
     F sec;
 public:
     Pair(T fir_m, F sec_m) :fir(fir_m), sec(sec_m)
     {

     }

     T first() const
     {
         return fir;
     }

     F second() const
     {
         return sec;
     }
 };


 
 template <typename F>
 class Pair<std::string, F>
 {
 protected:
     std::string fir;
     F sec;
 public:
     Pair(std::string fir_m, F sec_m) :fir(fir_m), sec(sec_m)
     {

     }

     std::string first() const
     {
         return fir;
     }

     F second() const
     {
         return sec;
     }
 };



 template <typename F>
 class StringValuePair : public Pair<std::string, F>
 {
 private:

 public:
     
     StringValuePair(std::string fir_m, F sec_m) : Pair<std::string, F>(fir_m, sec_m)
     {
        
     }
 };
 


int main()
{
    Pair1<int> p1(6, 9);
    std::cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    std::cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';


    Pair<int, double> p3(6, 7.8);
    std::cout << "Pair: " << p3.first() << ' ' << p3.second() << '\n';

    const Pair<double, int> p4(3.4, 5);
    std::cout << "Pair: " << p4.first() << ' ' << p4.second() << '\n';

    
    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';
    

    return 0;

}

