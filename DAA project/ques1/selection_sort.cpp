//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>
using namespace std;

//function to swap the the position of two elements
void swap(int *a, int *b) 
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void selection_sort(int blood_pressure[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int min = i;
        for (int j = i + 1; j < n; j++) 
        {
            //selecting the minimum element in each loop.
            if (blood_pressure[j] < blood_pressure[min])
            {
                min = j;
            }
        }
        //putting min at the correct position
        swap(&blood_pressure[min], &blood_pressure[i]);
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

    selection_sort(blood_pressure, n);


    //output
    cout<<"sorted blood pressure rates: ";
    for (int i = 0; i < n; i++)  
    {
        cout<<blood_pressure[i]<<" ";  
    }
    cout<<endl<<"maximum blood pressure: " << blood_pressure[n-1]<<endl<<"minimum blood pressure: " << blood_pressure[0];

    return 0;


}