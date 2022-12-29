//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <bits/stdc++.h>
using namespace std;

//returning length of lcs
int lcs(char* string_x,char* string_y,int x_len,int y_len,vector<vector<int> >& dp)
{
	if(x_len==0||y_len==0)
    {
		return 0;
    }

	if(string_x[x_len - 1]==string_y[y_len - 1])
    {
		return dp[x_len][y_len] = 1 + lcs(string_x,string_y,x_len - 1,y_len - 1,dp);
    }

	if(dp[x_len][y_len] != -1) 
    {
		return dp[x_len][y_len];
	}

	return dp[x_len][y_len] = max(lcs(string_x,string_y,x_len,y_len - 1,dp),lcs(string_x,string_y,x_len - 1,y_len,dp));
}

int main()
{
	char string_x[] = "JDHDKR";
	char string_y[] = "EISNDKF";

	int x_len = strlen(string_x);
	int y_len = strlen(string_y);
	vector<vector<int> > dp(x_len + 1,vector<int>(y_len + 1,-1));
	cout << "Length of LCS is " << lcs(string_x,string_y,x_len,y_len,dp);

	return 0;
}
