//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;


void insertion_sort(int blood_pressure[], int n) 
{
    for (int step = 1; step < n; step++)
    {
        int key = blood_pressure[step];
        int j = step - 1;

        //comparing key with each element on the left of it until an element smaller than it is found.
        while (key < blood_pressure[j] && j >= 0)
        {
            blood_pressure[j + 1] = blood_pressure[j];
            --j;
        }
        blood_pressure[j + 1] = key;
    }
}

int main()
{
    //number of entries to be made in an array
    int  n;
    //inputting n from user
	cout << "Enter the number of entries:";
	cin >>n;

    //allocating an array named "blood_pressure" of n size
	int *blood_pressure = new int(n);
	cout << "Enter " << n << " blood pressure rates = " << endl;

    //inputting rate from the user
	for (int x = 0; x < n; x++) 
    {
		cin >> blood_pressure[x];
	}

    insertion_sort(blood_pressure, n);

    //output
    cout<<"sorted blood pressure rates: ";
    for (int i = 0; i < n; i++)  
    {
        cout<<blood_pressure[i]<<" ";  
    }
    cout<<endl<<"maximum blood pressure: " << blood_pressure[n-1]<<endl<<"minimum blood pressure: " << blood_pressure[0];
    return 0;


}