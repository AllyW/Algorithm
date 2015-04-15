//
//  Created by Ally Wang on 15/04/15.
//

#include <iostream>
using namespace std;

int find_root(int arr[], int i){
	if(arr[i] == i)
		return i;
	return find_root(arr,arr[i]);
}

int main(int argc, const char * argv[]) {
	int N;
	cout << "please input the number of nodes: ";
	cin >> N;
	int arr[N];
	int tmp, i = 0;
	cout << endl;
	while(cin >> tmp && i < N){
		arr[i++] = tmp;
		cout << i << endl;
	}
   	
    if(i < N){
		cout << "not enough " << N << "Nodes input" << endl;
		return -1;
	}
    int temp = 0, root = 0;
	for(int i = 0; i != N; ++i){
		root = find_root(arr,i);
		if(root != 0)
			temp++;
	}
    cout << temp;
    return 0;
}
