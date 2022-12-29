//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT


#include <bits/stdc++.h>
using namespace std;
int knapsack01(int capacity, int weight[], int value[], int n)
{
	//making and initializing dp array
	int dp[capacity + 1];
	memset(dp, 0, sizeof(dp));

	for(int i=1; i < n + 1; i++) 
    {
		for(int w=capacity; w>=0; w--)
        {

			if(weight[i-1] <=w)
            {
				//finding the maximum value
				dp[w]= max( dp[w], dp[w-weight[i-1]]+value[i - 1] );
            }
		}
	}

    //returning the maximum value of knapsack
	return dp[capacity]; 
}
int main()
{
	int value[]={39, 293, 102};
	int weight[]={90, 10, 10};
	int capacity=100;
	int n=sizeof(value)/sizeof(value[0]);
	cout<<knapsack01(capacity, weight, value, n);
	return 0;
}
