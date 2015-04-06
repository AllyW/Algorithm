//
//  inttest.cpp
//  HF
//
//  Created by Ally Wang on 12/10/14.
//  Copyright (c) 2014 Ally Wang. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int i =0;
    int j = 0;
    i = 4/2;
    cout << "4/2=" << i << endl;
    i = 5/2;
    cout << "5/2= "<< i << endl;
    i = INT_MAX;
    j = INT_MIN;
    cout << "INT_MAX = " << i << endl;
    cout << "INT_MIN = " << j << endl;
    cout << "INT_MAX + 1 = " << i+1 <<endl;
    cout << "INT_MIN - 1 = " << j-1 <<endl;
    long long m = INT_MAX +1;
    long long n = INT_MIN -1;
    cout << "Even long long: "<<  m << ", " << n << endl;
    cout <<"Long long : max() = "<< numeric_limits<long long>::max() << endl;
    cout << "long max()= " << numeric_limits<long >::max() <<endl;
    i = 9 & 0x1;
    cout <<"9 & 0x1 = " << i << endl;
    j = 8 & 0x1;
    cout << "8 & 0x1 = " << j << endl;
    return 0;
}
