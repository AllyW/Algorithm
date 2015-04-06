//
//

#include <iostream>
#include <string>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    string a1("Jack");
    string a2("Rose");
    cout << "assign a1 to rs and ps:" << endl;
    cout << "a1 = "<< a1 << ", &a1 = " << &a1 << endl;
    cout << "a2 = " << a2 << ", &a2 = "<< &a2 << endl;
    string &rs = a1;
    string *ps = &a1;
    cout << "rs = " << rs << ", &rs = " << &rs << endl;
    cout << "ps = " << ps<< ", &ps = " << &ps << ", *ps = " << *ps << endl;
    cout << "assign a2 to rs and ps:" << endl;
    rs = a2;
    ps = &a2;
    cout << "a1 = "<< a1 << ", &a1 = " << &a1 << endl;
    cout << "a2 = " << a2 << ", &a2 = "<< &a2 << endl;
    cout << "rs = " << rs << ", &rs = " << &rs << endl;
    cout << "ps = " << ps<< ", &ps = " << &ps << ", *ps = " << *ps <<endl;
    return 0;
}

     
