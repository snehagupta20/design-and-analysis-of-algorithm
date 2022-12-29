//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;
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

    int x;
    cout<<"enter the element you want to know the index of: ";
    cin>>x; 

    //linear search (going through array sequentially)
    for(int i=0;i<n;i++)
    {
        if(arr[i]==x)
        {
            //output
            cout<<"element "<<x<<" found at index "<<i<<" :)"<<endl;
        }
    }

}