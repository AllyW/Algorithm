//
//  main.cpp
//  HF
//
//  Created by Ally Wang on 12/10/14.
//  Copyright (c) 2014 Ally Wang. All rights reserved.
//

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    int val1, val2;
	for(int i = 0; i < 5; i++){
		cout << i << " ";
	}
	cout << endl;
	cout << "please input two numbers : " <<endl; 
    cin >> val1 >> val2;
    cout << val1 + val2 << endl;
    cout << "Hello, World!\n";
    return 0;
}
