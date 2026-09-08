#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> a = {2,4,2,21,2,1,2,12};
    vector<int> b = {2,4,2,21,2,1,2,12, 2};
    a.push_back(2);
    a.pop_back();
    cout << a.back() << " " << a.front() << "\n";
    cout << a.capacity() * sizeof(int) << " " << b.capacity() * sizeof(int) << "\n";
}