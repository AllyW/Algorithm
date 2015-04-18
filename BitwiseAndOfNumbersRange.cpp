//
//  Created by Ally Wang on 18/04/15.
//  Copyright (c) 2015 Ally Wang. All rights reserved.
//

#include <iostream>
using namespace std;

int rangeBitwiseAnd(int m, int n) 
{
	int res=0;
	if(m == n) return m;
	int diff = n-m; // determine the highest bit that can be common on 1 in the numbers between m and n
	for(int i = 30; i > 0; --i)
	{
		int a = 1<<i;
		if(n >= a && a >= diff)
		{
			n = n -a;
			if(m >= a)
			{
				m = m -a;
				res +=a;
			}
		}
    }
    return res;
 }

string convertToBinary(int x)
{
	string s;
	for(int i=0; i < 32; ++i)
	{
		int tmp = x>>i & 1;
		s.push_back(tmp+'0');
	}
	reverse(s.begin(), s.end());
	return s;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    int m, n;
	cout << "please input two positive number as range: " << endl;
    cin >> m >> n;
    if(m >n) swap(m,n);
	cout << "binary in order: " << endl;
	for(int i = m; i <= n; ++i)
	{
		string s = convertToBinary(i);
		cout << s << endl;
	}

    int res = rangeBitwiseAnd(m,n);
	cout << "Bitwise AND between " << m << " and " << n << " is: " << res << endl;

	return 0;
}
