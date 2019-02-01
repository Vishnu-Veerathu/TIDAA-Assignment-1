#include <bits/stdc++.h>
using namespace std;

unordered_map <int,unordered_map<int,int> > adjl;
unordered_map <int,int> vc,leaf;
vector <int> deg;

void remove(int x)
{
	for(auto &itr: adjl[x])
	{
		if(adjl[itr.first].find(x) != adjl[itr.first].end())
		{
			adjl[itr.first].erase(x);
			deg[itr.first]--;

			if(deg[itr.first] == 0 && adjl.find(itr.first) != adjl.end())
			{
				adjl.erase(itr.first);
				leaf.erase(itr.first);
			}
			if(deg[itr.first] == 1)
			{
				leaf[itr.first] = 1;
			}
		}
	}
	adjl.erase(x);
	leaf.erase(x);
	deg[x] = 0;
}

int main()
{
	int n;
	cin >> n;
	deg.resize(n);

	for(int i =0;i < n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		adjl[a][b] = 1;
		adjl[b][a] = 1;
		deg[a]++;
		deg[b]++;
	}
	
	cout << "Input done" << endl;

	for(int i = 0;i < n;i++)
	{
		if(deg[i] == 1)
			leaf[i] = 1;
	}



	while(1)
	{
		if(leaf.size() == 0)
			break;
		int select = leaf.begin()->first;
		leaf.erase(select);
		int p = adjl[select].begin()->first;
		remove(p);
		vc[p] = 1;
	}

	cout << "One of the Vertex Covers is " << endl;
	for(auto &itr: vc)
	{
		cout << itr.first << " ";
	}
	cout << endl;
}