#include <bits/stdc++.h>
using namespace std;

unordered_map <int,unordered_map<int,int> > adjl;
unordered_map <int,int> vc,leaf;
vector <int> deg,cov;

void remove(int x)
{
	for(auto &itr: adjl[x])
	{
		cout << "here" << " " << itr.first << endl;
		if(adjl[itr.first].find(x) != adjl[itr.first].end())
		{
			adjl[itr.first].erase(x);
			deg[itr.first]--;
			cov[itr.first] = 1;
			if(deg[itr.first] == 0 && adjl.find(itr.first) != adjl.end())
			{
				adjl.erase(itr.first);
				leaf.erase(itr.first);
			}
			else if(deg[itr.first] == 1 && cov[itr.first] == 1)
			{
				int leafadj = adjl[itr.first].begin()->first;
				cout << "leafadj" << " " << leafadj << endl;
				adjl[leafadj].erase(itr.first);
				deg[leafadj]--;
				if(deg[leafadj] == 1)
				{
					leaf[leafadj] = 1;
				}
				if(deg[leafadj] == 0)
				{	
					adjl.erase(leafadj);
					leaf.erase(leafadj);
					deg[leafadj] = 0;
					vc[leafadj] = 1;
				}
				adjl.erase(itr.first);
			}
			else if(deg[itr.first] == 1)
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
	cov.resize(n,0);

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
		for(auto &itr: leaf)
		{
			cout << itr.first << endl;
		}
		cout << endl;
		if(leaf.size() == 0)
			break;
		int select = leaf.begin()->first;
		leaf.erase(select);
		cout << "select = " << select << endl;
		int p = adjl[select].begin()->first;
		remove(p);
		vc[p] = 1;
		for(auto &itr: leaf)
		{
			cout << itr.first << endl;
		}
		cout << endl;
	}

	cout << "One of the Dominating Sets is " << endl;
	for(auto &itr: vc)
	{
		cout << itr.first << " ";
	}
	cout << endl;
}