//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

//there are four nodes in example graph 
const int n = 4;

//to avoid overflow:
const int MAX = 1000000;

//this array represents shortest distance to go from i to j
int dist[n + 1][n + 1] = {
	{ 0, 0, 0, 0, 0 }, { 0, 0, 10, 15, 20 },
	{ 0, 10, 0, 25, 25 }, { 0, 15, 25, 0, 30 },
	{ 0, 20, 25, 30, 0 },
};

//memoization for top down recursion:
int memo[n + 1][1 << (n + 1)];

int fun(int i, int mask)
{
	//base case
	if (mask == ((1 << i) | 3))
    {
		return dist[1][i];
    }

	//memoization
	if (memo[i][mask] != 0)
    {
		return memo[i][mask];
    }

    //result of this sub-problem
	int res = MAX; 

	for(int j = 1; j <= n; j++)
    {
		if((mask & (1 << j)) && j != i && j != 1)
        {
			res = std::min(res, fun(j, mask & (~(1 << i))) + dist[j][i]);
        }
    }

	return memo[i][mask] = res;
}


int main()
{
	int ans = MAX;
	for (int i = 1; i <= n; i++)
    {
		ans = std::min(ans, fun(i, (1 << (n + 1)) - 1) + dist[i][1]);
    }

	cout<<"The cost of most efficient tour: "<<ans;

	return 0;
}

