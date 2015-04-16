//
//  Created by Ally Wang on 15/04/15.
//

#include <iostream>
#include <vector>
using namespace std;
// test the one line int input and multiple line int input to see the order of cout<<i
int main() {
	int N;
	cout << "please input the number of nodes: ";
	cin >> N;
	vector<int> arr;
	int tmp=0, i = 0;
	cout <<"please input the nodes consequence: " << endl;
	while(cin >> tmp){
		arr.push_back(tmp);
		cout << i++ <<endl;  // newline to get one single int input, string input seperate with space... 
		//if int seperate with space, it first read the whole line
		//anyway input one var followed by a newline....
	}
	cout << "input finished!"<<endl;
	for(int i = 0; i < arr.size(); ++i){
		cout << arr[i] << ", ";
	}
	cout <<endl;
    return 0;
}
