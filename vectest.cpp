//
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

vector<int> getRow(int Rowindex)
{
    vector<int> v(Rowindex+1,0);
    v[0] = 1;
    for(int i = 0; i < Rowindex; i++){
       for(int j = i+1; j >0; j--){
        v[j] += v[j-1];  
        }
    }
    return v;
}

void printvec(vector<int> p){
     cout << "{";
     for(int i=0; i < p.size(); i++){
        cout << p[i]<< ","; 
     }
     cout << "}" << " ^_^ " << endl;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<int> a(10,1);
    //cout << a << endl;
    cout << "length of a: " << "cannot use"<< endl;
    cout << "size of a is " << a.size()<< endl;
    cout << "a.begin():" << a[0]<<endl;
    int n = 0;
    cout << "input a number:" <<endl;
    cin >> n;
    printvec(getRow(n));
    return 0;
}
