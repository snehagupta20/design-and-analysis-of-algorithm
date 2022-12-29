//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT


#include<iostream>
using namespace std;

//to return two values from min max function
struct Pair
{
	int min;
	int max;
};

struct Pair min_max(int array[], int n)
{
	struct Pair minmax;	
	int i;
	
	//initializing the first two elements as minimum and maximum for when array has even number of elements:
	if(n%2==0)
	{
		if(array[0]>array[1])	
		{
			minmax.max=array[0];
			minmax.min=array[1];
		}
		else
		{
			minmax.min=array[0];
			minmax.max=array[1];
		}
		
		//setting the starting index for loop
		i=2;
	}
	
	//initializing the first element as minimum and maximum for when array has odd number of elements:
	else
	{
		minmax.min=array[0];
		minmax.max=array[0];
		
		//setting the starting index for loop
		i=1;
	}
	
	//picking elements in pair and comparing the pair with max and min
	while(i< n-1)
	{		
		if(array[i]>array[i+1])		
		{
			if(array[i]>minmax.max)	
            {
				minmax.max=array[i];
            }
				
			if(array[i+1]<minmax.min)		
            {
				minmax.min=array[i+1];	
            }   
		}
		else	
		{
			if(array[i+1]>minmax.max)	
            {
				minmax.max=array[i+1];
            }
				
			if(array[i]<minmax.min)
            {		
				minmax.min=array[i];	
            }
		}
		
		//incrementing the index by 2
		i += 2;
	}		
	return minmax;
}

int main()
{

	int array[]={183,837,837,482,928,394};
    //n: array size
	int n=6;
	
	Pair minmax=min_max(array,n);
	
	cout<<"Minimum element is "<<minmax.min<<endl;
	cout<<"Maximum element is "<<minmax.max;
		
	return 0;
}

