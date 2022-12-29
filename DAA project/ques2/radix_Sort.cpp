//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

//function to get the largest element from an arr
int get_max(int arr[], int n) 
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

//using counting sort to sort the elements 
void count_sort(int arr[], int n, int place) 
{
    const int max = 10;
    int final[n];
    int count[max];

    for (int i = 0; i < max; ++i)
    {
        count[i] = 0;
    }

    //calculating the count of elements
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / place) % 10]++;
    }

    //calculating the cumulative count
    for (int i = 1; i < max; i++)
    {
        count[i] += count[i - 1];
    }

    //placing the elements in sorted order
    for (int i = n - 1; i >= 0; i--) 
    {
        final[count[(arr[i] / place) % 10] - 1] = arr[i];
        count[(arr[i] / place) % 10]--;
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = final[i];
    }

}

//main function to implement radix sort
void radix_Sort(int arr[], int n) 
{
    //getting maximum element
    int max = get_max(arr, n);

    //apply counting sort to sort elements based on place value.
    for (int place = 1; max / place > 0; place *= 10)
    {
        count_sort(arr, n, place);
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

    radix_Sort(arr, n);

    
    cout<<endl<<"array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}