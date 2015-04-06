//
//

#include <iostream>
#include <vector>
#include <stdlib.h>
using namespace std;

int longestConsecutive(vector<int> &num) {
	// C11 unordered_set<int> s;  
	std::map<int, int> m;
    for (int i=0; i<num.size(); i++){ 
		m[num[i]]=i;
	}
	int max_seq=0;
	for (int i=0; i<num.size(); i++){
		int cnt=1;
		for(int n = num[i]+1;m.find(n)!=m.end();n++){
			m.erase(m.find(n));
			cnt++;
		}
		for(int n = num[i]-1;m.find(n)!=m.end();n--){
			m.erase(m.find(n));
			cnt++;
		}
		if (max_seq < cnt){
			max_seq = cnt;
		}
		if (m.size()==0){
			break;
		}
	}

	return max_seq;
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
    vector<int> a;
	a.push_back(10);

	a.push_back(20);
	a.push_back(0);
	a.push_back(1);
	a.push_back(4);
	a.push_back(5);
	a.push_back(3);
	a.push_back(21);
	a.push_back(22);
	a.push_back(23);
	a.push_back(2);
    int len = longestConsecutive(a);
	cout << "the length of longest consequtive sequence is: " << len << endl;
	printvec(a);
    return 0;
}
