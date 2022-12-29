//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

void count_sort(int arr[], int n) 
{

    int final[10];
    int count[10];
    int max = arr[0];

    //finding the largest element of the arr
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    //initializing count arr with all zeros.
    for (int i = 0; i <= max; ++i) 
    {
        count[i] = 0;
    }

    //storing the count of each element 
    for (int i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }

    //storing the cummulative count of each arr
    for (int i = 1; i <= max; i++) 
    {
        count[i] += count[i - 1];
    }

    //finding the index of each element of the original arr in count arr, and placing the elements in final arr
    for (int i = n - 1; i >= 0; i--) 
    {
        final[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    //copying the sorted elements into original arr
    for (int i = 0; i < n; i++) 
    {
        arr[i] = final[i];
    }
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
	cout << "Enter " << n << " numbers= " << endl;

    //inputting from the user
	for (int x = 0; x < n; x++) 
    {
		cin >> arr[x];
	}

    cout<<"array before sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    count_sort(arr, n);

    
    cout<<endl<<"array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}