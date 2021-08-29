#include <iostream>
#include "args_loader.hpp"

#define FILE_NAME "params.txt"

int main(int argc, char** argv)
{ 
    ArgsLoader loader(FILE_NAME);
    vector<uint64_t> uints = loader.LoadUints();    
     
    cout << "args: ";
    for (auto it = uints.begin(); it < uints.end(); it++)
        cout << *it << " ";
    cout << endl;

    cout << "arg: " << loader.LoadUintAt(0) << endl;
    cout << "arg: " << loader.LoadUintAt(4) << endl;
    cout << "arg: " << loader.LoadUintAt(1) << endl;

    return 0;
}