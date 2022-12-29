//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

//shell sort main code:
void shell_sort(int arr[], int n)
{

    /*
        rearranging elements at each:
            n/2
            n/4
            n/8...
        intervals or gaps
    */

    for(int gap=n/2;gap>0;gap/=2)
    {
        for(int i=gap;i<n;i++)
        {
            int temp=arr[i];
            int j;
            for(j=i;j>=gap && arr[j-gap]>temp; j-=gap)
            {
                arr[j]=arr[j-gap];
            }
            arr[j]=temp;
        }
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

    shell_sort(arr, n);

    
    cout<<endl<<"array after sorting: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

}