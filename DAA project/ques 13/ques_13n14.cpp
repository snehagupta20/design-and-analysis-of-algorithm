//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <bits/stdc++.h>
using namespace std;
int dp[100][100];


int matrix_chain_multi(int* p, int i, int j)
{
	if(i==j)
	{
		return 0;
	}
	if(dp[i][j] != -1)
	{
		return dp[i][j];
	}
	dp[i][j]=INT_MAX;
    

	for(int k=i; k < j; k++)
	{
		dp[i][j]=min( dp[i][j], matrix_chain_multi(p, i, k) + matrix_chain_multi(p, k + 1, j) + p[i - 1] * p[k] * p[j]);
	}
	return dp[i][j];
}
int matrix_order(int* p, int N)
{
	int i=1, j=N - 1;
	return matrix_chain_multi(p, i, j);
}

int main()
{
    int N;
    cout<<"enter N:"<<endl;
    cin>>N;
    int* arr= new int[N];
    cout<<"enter the elements of the matrix: "<<endl;
    for(int i=0; i < N; i++)
    {
        cin>>arr[i];
    }

	memset(dp, -1, sizeof dp);

	cout<<"Minimum number of multiplications is "<<matrix_order(arr, N);
}

