#include <iostream>
using namespace std;

template <class T> class Some{

	public:
		static int stat;
};
template<class T>
int Some<T>::stat = 10;



class base{
	public:
		base(): code('B'){}
		char code;
};

class derived: public base{
	public:
		int code;

};
int main(int argc, const char * argv[]) {
    // insert code here...
    int r = 0;
    int arr[5] = {2,4,6};
    int* p = arr;
    r = *(arr + 2);
	cout <<"r = " << arr[2] << ", " << *(arr + *p) << endl;
    // *p = 2, *(arr + 2) =  *(&arr[0] + 2) = *(&arr[2]) 

	Some<int>::stat = 5;
	cout << Some<int>::stat << " " << Some<char>::stat << " "<< Some<float>::stat << " " << Some<long>::stat << endl;
    derived d;
	d.code = 65;
	cout << d.code <<endl;
	
	return 0;
}
