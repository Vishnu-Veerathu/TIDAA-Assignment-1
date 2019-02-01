#include <bits/stdc++.h>
using namespace std;

int n;
vector < vector <int > > adjl;
vector <int> vis;


pair<int,int> farthest_awayh(int v,int p)
{
	vis[v] = p;
	pair<int,int> leaf = make_pair(0,v);
	for(int i = 0;i < adjl[v].size();i++)
	{
		if(vis[adjl[v][i]] == -1)
		{
			pair<int,int> temp = farthest_awayh(adjl[v][i],v);
			temp.first++;
			if(temp.first >= leaf.first)
			{
				leaf = temp;
			}
		}
	}
	return leaf;
}

int farthest_away(int v)
{
	for(int i = 0;i < n;i++)
	{
		vis[i] = -1;
	}
	return farthest_awayh(v,n).second;
}



int main()
{
	cin >> n;
	adjl.resize(n);
	vis.resize(n);
	for(int i = 0;i < n-1;i++)
	{
		int a,b;
		cin >> a >> b;
		adjl[a].push_back(b);
		adjl[b].push_back(a);
	}

	int d1 = farthest_away(1);
	int d2 = farthest_away(d1);

	int pl = 0;

	int trav = d2;
	cout << "One of the longest paths is: ";
	while(trav != d1)
	{
		pl++;
		cout << trav << " ";
		trav = vis[trav];
	}
	cout << d1 << endl;
	cout << "Longest Path Length is " << pl << endl;
}