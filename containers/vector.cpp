#include<iostream>
using namespace std;

template <typename T>
class vector{
private:
    T * tempMemory, * memory = new T[1];
    size_t size = 0;
    size_t capacity = 1;

public:
    void push_back(T a){
        if(size < capacity){
            memory[size] = a;
            size++;
        }
        else{
            tempMemory = new T[2 * capacity];
            capacity *= 2;
            for(int i = 0;i < size;i++){
                tempMemory[i] = memory[i];
            }
            delete[] memory;
            memory = tempMemory;
            memory[size] = a;
            size++;
        }
    }
    void display(){
        for(int i = 0;i < size;i++){
            cout << memory[i] << " ";
        }
        cout << "\n";
    }
    T operator[](size_t a){
        try
        {
            if(a >= size){
                cerr << "accessing vector[" << a << "] when size is " << size << "\n";
                throw overflow_error("Index out of bounds");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::exit(EXIT_FAILURE);
        }
        
        return memory[a];
    }
};


int main(){
    vector<long long> a;
    a.push_back(3);
    a.push_back(5);
    a.push_back(7);
    a.push_back(2);
    cout << a[4] << "\n";
    a.display();
}