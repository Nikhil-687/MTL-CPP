#include<iostream>
#include<string>
#include<algorithm>
#include "vector.cpp"
using namespace std;

template <typename T, size_t Bits>
class bitVector{
private:
    
public:
    bitVector(){
        cout << Bits << " bits alloted for bitVector\n";
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
    cout << (a.back()) << " " << (a.front()) << "\n";
    sort(a.begin(), a.end());
    a.display();
    bitVector<int, 2> x;
}