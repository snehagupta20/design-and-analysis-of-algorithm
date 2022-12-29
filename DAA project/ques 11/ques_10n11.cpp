//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT


#include <bits/stdc++.h>
using namespace std;

//structure for an item which stores weight and corresponding value of item:
struct items 
{
	int value, weight;

	//constructor
	items(int value, int weight)
	{
		this->value=value;
		this->weight=weight;
	}
};

//comparison function to sort items according to val/weight ratio:
bool cmp(struct items a, struct items b)
{
	double r1=(double)a.value/(double)a.weight;
	double r2=(double)b.value/(double)b.weight;
	return r1 > r2;
}

//main function:
double frac_knapsack(int weight, struct items arr[], int n)
{
	//Sorting items on basis of ratio:
	sort(arr,arr+n,cmp);

	double finalvalue=0.0;

	//looping through all items
	for(int i=0; i < n; i++) 
    {	
		//adding items completely
		if(arr[i].weight <= weight) 
        {
			weight-=arr[i].weight;
			finalvalue+=arr[i].value;
		}

		else 
        {
			finalvalue+=arr[i].value * ((double)weight/(double)arr[i].weight);
			break;
		}
	}

	//returning final value:
	return finalvalue;
}

int main()
{
    //weight: capacity of knapsack
	int weight=100;
	items arr[]={{92,20},{128,11},{292,90}};

	int n=sizeof(arr)/sizeof(arr[0]);

	cout<<frac_knapsack(weight,arr,n);
	return 0;
}
