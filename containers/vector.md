# vector.cpp

defines a class vector which tries to support all the inbuild functions of original c++ vector

aimed to maintain similar time and space usage

complete support of data structures of elements

eg: $vector<int>, vector<string>, vector<vector<int>>, ...$

overloaded operators: <<, [] for easy debugging, and quick access to array.

keeps track of size and capacity of vector, and automatically increases the capacity when needed.

The More Pain:

-> vector<bool> will have to keep things more sturctured to know exact bit of a item, whereas, vector<int> doesn't consider remembering bit, it just remembers byte address.

```
    vector<bool> a(8);
    vector<int> b(8);
    cout << a.memoryUsed() << " " << (b.memoryUsed()) << "\n";
```
current output -> 8 32

expected output -> 1 32

-> not limiting it to boolean searching ways to make it general for any datatype with having a umber of bits which dont require a complete byte.
eg: a dice class could have a data member value{1,2,3,4,5,6} can be denoted be 3 bits.
if you store them in int a million die will take a million bytes but in bit packed formate 375000 bytes ie. 37% of original.

-> assume building on top of them like a $vector<vector<int>>$ would be a good optimization without considering how is memory moving touching memory.