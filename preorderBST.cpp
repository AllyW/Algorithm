// 
//  Created by Ally Wang 04/26/2015 
//  
//  Given a list of numbers, determine whether it can represent the pre-order traversal list of a binary search tree (BST)
// 
//  test case:
//  3 
//  1 2 3
//  YES
//
//  3
//  2 1 3
//  YES
//
//  6
//  3 2 1 5 4 6
//  YES
//
//  4
//  1 3 4 2
//  NO
//
//  5
//  3 4 5 1 2
//  NO
//
#include <iostream>
#include <vector>
using namespace std;

bool ispreBST(vector<int> arr, int start, int stop)
{
	if(stop - start <= 2) return true;
	int root = arr[start];
	int lstop, rstart;
	int i = start+1;
	while(i < stop && arr[i] < root ) ++i;
	lstop = i;
	rstart = i;
	for(i = rstart; i < stop; ++i)
	{
		if(arr[i] <= root) return false;  // test if all the nodes in the right part is larger than root
	}
	return ispreBST(arr, start+1, lstop) && ispreBST(arr, rstart, stop);
}
int main() {
	int N;
	cout << "please input the number of nodes: ";
	cin >> N;
	vector<int> arr;
	int tmp=0, i = 0;
	cout <<"please input the nodes consequence: " << endl;
	while(cin >> tmp){
		arr.push_back(tmp);
		i++;
		if(i==N)
			break;
	}
	cout << "the nodes used: "<<endl;
	for(int i = 0; i < arr.size(); ++i){
		cout << arr[i] << " ";
	}
	cout << endl;
	if(ispreBST(arr, 0, N))
	{
		cout << "YES" << endl;
	}else
	{
		cout << "NO" <<endl;
	}
    return 0;
}
