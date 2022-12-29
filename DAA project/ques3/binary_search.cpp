//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include<iostream>
using namespace std;

int binarysearch(int arr[],int x,int start,int end)
{
    //base case:
    if(end>=start)
    {
        //finding mid point of the array
        int mid=start+(end-start)/2;

        //if midpoint=x, return midpoint
        if(arr[mid]==x)
        {
            return mid;
        }

        //searching the left half
        if(arr[mid]>x)
        {
            //calling binarysearch function on first half of the array
            return binarysearch(arr,x,start,mid-1);
        }

        //searching the right half
        if(arr[mid]<x)
        {
            //calling binarysearch function on second half of the array
            return binarysearch(arr,x,mid+1,end);
        }
    }

    return -1;
}

int main()
{
    //number of entries to be made in an array
    int  n;
    //inputting n from user
	cout << "Enter the number of entries:";
	cin >>n;

    //allocating an array of n size
	int *arr = new int(n);  
	cout << "Enter " << n << " numbers in sorted manner (either descending or ascending)= " << endl;

    //inputting from the user
	for (int x = 0; x < n; x++) 
    {
		cin >> arr[x];
	}

    int x;
    cout<<"enter the element you want to know the index of: ";
    cin>>x;

    //performing binary search recursively
    int index= binarysearch(arr,x,0,n-1);

    if(index==-1)
    {
        cout<<"element not found in the array! :(";
    }
    else{
        cout<<"element is found at the index "<<index<<" :)";
    }

}