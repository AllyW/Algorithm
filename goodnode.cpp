// 
// nodes index from 0
// test case:
// 1 1 1 1 1
// 1 2 3 3 4
// 1 2 3 4 3 
// 0 1 2 3 4
//  
#include <iostream>
#include <vector>
using namespace std;
int mark(int cluster, int i, vector<int> &clusters, vector<int> arr)
{
	if(clusters[i] == -1)
	{
		clusters[i] = cluster;
		if(arr[i] != i)
		{
			return mark(cluster, arr[i], clusters, arr);
		}else
		{
			return i;
		}
	}else
	{
		return clusters[i];
	}
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
	cout << "the nodes inputed: "<<endl;
	for(int i = 0; i < arr.size(); ++i){
		cout << arr[i] << " ";
	}
	cout <<endl;
	vector<int> clusters(N, -1);
	clusters[0] = 0;
	for(int i = 1; i< N; ++i){
		if(arr[i] == 0){
			clusters[i] = 0;
		}
		else
		{
			if(clusters[i] == -1)
			{
				int s = mark(i,i,clusters, arr);
				if(s != i)
				{
					for(int j = 0; j < N; ++j)
					{
						if(clusters[j] == i)
						{
							clusters[j] = s;
						}
					}
				}
			}
		}
	}
	cout << "clusters: " << endl;
    for(int i = 0; i < N; ++i)
	{
		cout << clusters[i] <<" ";
	}
	cout <<endl;
	vector<int> count(N, 0);
	int sum = 0;
	for(int i = 1; i < N; ++i)
	{
		if(count[clusters[i]] == 0)
		{
			count[clusters[i]] = 1;
			sum++;
		}
	}
	cout << "change " <<sum <<" edges to make all the nodes to be good nodes." <<endl;
    return 0;
}
