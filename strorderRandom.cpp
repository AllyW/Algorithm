//
// created by Ally Wang 04/25/2015
// 
// random the order of inner chars (except the first and last char) within each word in one sentence
//

#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;


void randomWord(string &s, int first, int last)
{
	int wlength = last - first + 1;
	for(int i = 1; i < wlength-2; ++i)
	{
		int r = rand() % (wlength-2-i);
		//cout << r << endl;
		swap(s[first+1+r], s[first + wlength-1-i]);
	}
}
void strRandom(string &s){
	for(int i = 0; i < s.size(); )
	{
		while(i < s.size() && s[i] == ' ') ++i;
		int first = i;
		while(i < s.size() && s[i] != ' ') ++i;
		int last = i;
		//cout << s.substr(first, last-first)<<endl;
		//cout <<first << " " << last << endl;
		if(last - first <= 3) continue;
		randomWord(s, first, last-1);
	}
	return;
}
int main(int argc, const char * argv[]) {
    string pstr;
	cout <<"Please input a sentence: " << endl;
	getline(cin, pstr);
    strRandom(pstr);
	cout << endl;
	cout << "sentence after randomnalization: " << endl;
	cout << pstr << endl;
    return 0;
}
