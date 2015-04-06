#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int x){
	if(x == 2) return true;
	int ceil = int(sqrt(double(x))+1);
	for(int i = 2; i <= ceil; ++i){
		if(x % i == 0) return false;
	}
	return true;
}

int primeNumber(int N){
	if(N<2) return 0;
	int count  = 0;
	for(int i = 2; i <= N ; ++i){
		if(isPrime(i)) {
			cout << i << ", ";
			count++;
		}
	}
	cout <<  endl;
	return count;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int j = 0;
	int N;
	cout<< "please input a number larger than 2" << endl;
	cin >> N;
	j = primeNumber(N);
	cout << "the total number of primes samller than " << N << " : " ;
	cout << j << endl;
    return 0;
}
