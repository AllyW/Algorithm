// add 50 to 100

#include <iostream>
using namespace std;
int main(int argc, const char * argv[]) {
    int sum = 0, value = 50;
    while(value <= 100){
        sum += value;
        value++;
}
    cout << "The sum from 50 to 100 is "<< sum << endl;
    return 0;
}
