//
//  eoftest.cpp
//  HF
//
//  Created by Ally Wang on 12/10/14.
//  Copyright (c) 2014 Ally Wang. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    cout << "Enter some numbers:" << endl;
    int sum = 0, value = 0;
    while(cin >> value){
        sum += value;
}
    cout << "The sum is "<< sum << endl;
    return 0;
}
