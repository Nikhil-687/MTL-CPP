#include<iostream>
#include<string>
using namespace std;

template <typename T>
class vector{
private:
    T * tempMemory, * memory = new T[1];
    size_t length = 0;
    size_t capacity = 1;
    
public:
    vector(){

    }
    vector(int t){
        length = t;
        capacity = t;
        memory = new T[capacity];
    }
    vector(int t, T a){
        length = t;
        capacity = t;
        memory = new T[capacity];
        for(int i = 0;i < length;i++){
            memory[i] = a;
        }
    }
    void push_back(T a){
        if(length < capacity){
            memory[length] = a;
            length++;
        }
        else{
            tempMemory = new T[2 * capacity];
            capacity *= 2;
            for(int i = 0;i < length;i++){
                tempMemory[i] = memory[i];
            }
            delete[] memory;
            memory = tempMemory;
            memory[length] = a;
            length++;
        }
    }
    void display(){
        for(int i = 0;i < length;i++){
            cout << memory[i] << " ";
        }
        cout << "\n";
    }
    int size(){
        return length;
    }
    T operator[](size_t a){
        try
        {
            if(a >= length){
                cerr << "accessing vector[" << a << "] when length is " << length << "\n";
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
    friend ostream& operator<<(ostream& os, vector<T> a){
        for(int i = 0;i < a.size();i++){
            os << a[i] << " ";
        }
        os << "\n";
        return os;
    }
    T pop_back(){
        try
        {
            if(length == 0){
                cerr << "poping from an empty vector\n";
                throw overflow_error("Vector is empty");
            }
        }
        catch(const std::exception& e)
        {
            std::cerr << e.what() << '\n';
            std::exit(EXIT_FAILURE);
        }

        T x = memory[length - 1];
        length--;
        return x;        
    }
    T * begin(){
        return memory;
    }
    T * end(){
        return memory + length;
    }
};


int main(){
    vector<int> a;
    vector<vector<int>> b;
    a.push_back(5);
    a.push_back(4);
    a.push_back(2);
    b.push_back(a);
    for(int j = 0;j < b.size();j++){
        for(int i = 0;i < b[j].size();i++){
            cout << b[j][i] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    cout << b;
    cout << *b.begin() << "\n";
    cout << *(a.end() - 1) << "\n";
}