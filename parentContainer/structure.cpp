#include <bits/stdc++.h>
using namespace std;    


// hugely complex to keep it incomplete as of now

template<typename... Args>
class Structure{
private:
    int * memory;
public:
    Structure(Args ... args) {
        (cout << ... << args) << "\n";
    };
};

int main(){
    Structure s(5, 3,4,'c',2, "sdas", 2.32, 3e14, true, 5);
    return 0;
}

