#include <iostream>
using namespace std;

void reverseNM(int nums[], int left, int right){
        while(left < right){
            swap(nums[left], nums[right]);
            ++left;
            --right;
        }
        return;
}

void rotate(int nums[], int n, int k) {
        if(k <= 0 || n <= 0) return;
        if(k > n) k = k%n;
        reverseNM(nums, 0, n-1);  // must be decleared before rotate
        reverseNM(nums, 0, k-1);
        reverseNM(nums, k, n-1);
        return;
}
int main() {
    // insert code here...
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int tmp;
	cout <<" input the rotate k : " << endl;
	cin >> tmp; // no >> endl
	rotate(a, 10, tmp);
	int *e = &a[10]; // the element pass of the array end
    for(int *b = a; b != e; b++)
		cout << *b << ", ";
	cout << endl;
    return 0;
}
