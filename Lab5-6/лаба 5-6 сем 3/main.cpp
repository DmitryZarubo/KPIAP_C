#include <iostream>
#include "file_class.h"
#include"classes.h"
using namespace std;
int main() {
    using namespace MYFILECLASS;
    myFileClass<Tank> file1;
    myFileClass<int> file2;
    file2 << 435 << 234 << 145 << 65;
    cout << file2<<endl;
    Tank tirg;
    cin >> tirg;
    Tank copy;
    file1 << tirg;
    file1 >> &copy;
    cout <<endl<< copy;
    return 0;
}