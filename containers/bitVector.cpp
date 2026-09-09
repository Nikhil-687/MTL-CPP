#include<iostream>
#include<string>
#include<algorithm>
#include<bitset>
#include "vector.cpp"
using namespace std;



class Cordinates{
    // char x, y; // considering a case for 100 x 100 grid. we dont require a complete 4 byte in;
    // but that too require 16 bits we can converge it to 14, because 10000 < 2 ^ 14
    // idea is to take 7 bit variable.
    bitset<7> x = 0, y = 0;

    // to denote 3,5
    // x = 3 -> x = 0000011
    // y = 5 -> y = 0000101

public:
    Cordinates(int a, int b){
        int cnt = 0;
        while(a){
            if(a%2){
                x.set(cnt);
            }
            cnt++;
            a/=2;
        }
        cnt = 0;
        while(b){
            if(b%2){
                y.set(cnt);
            }
            cnt++;
            b/=2;
        }
    }

};

template<class T>
struct bit_width
{
    static constexpr size_t Bits = 8 * sizeof(T);
};

template<> struct bit_width<Cordinates>
{
    static constexpr size_t Bits = 14;
};

template <typename T, size_t Bits = 0>
class bitVector{
private:
    int reqBits = Bits;
    int reqBytes = (reqBits + 7) /8;
    void basicAllocator(){   
        if constexpr (Bits == 0){
            cout << bit_width<T>::Bits <<  " bits per item will be allocated\n";
        }
        else{
            static_assert(Bits >= bit_width<T>::Bits, "Bits too small for this type's declared range");
            cout << Bits <<  " bits per item will be allocated\n";
        } 
    }
public:
    bitVector(){
        basicAllocator();
    }
    bitVector(int t){
        basicAllocator();
    }
    bitVector(int t, T a){
        basicAllocator();
    }
};




int main(){
    bitVector<int, 35> x;
    bitVector<int> y;
    bitVector<Cordinates, 14> z(2);
    int a = 3, b = 5;
    Cordinates c1(a, b);
    bitset<2> n;
    cout << n << " " << sizeof(n) << "\n";
}
