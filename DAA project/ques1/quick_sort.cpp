#include <iostream>
using namespace std;

//function to swap elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


//function to rearrange array (finding the partition point)
int partition(int array[], int low, int high) {
    
    //selecting the rightmost element as pivot
    int pivot = array[high];
    
    //pointer for greater element
    int i = (low-1);

    //traversing each element of the array
    //comparing them with the pivot
    for (int j = low; j < high; j++)
    {
        if (array[j] <= pivot) {
            
        i++;
        
        //swaping element at i with element at j
        swap(&array[i], &array[j]);
        }
    }
    
    //swap pivot with the greater element at i
    swap(&array[i + 1], &array[high]);
    
    //return the partition point
    return (i + 1);
}

/*
    low: starting index
    high: ending index
*/
void quick_sort(int array[], int low, int high)
{
    //base case:
    if (low < high) {
        
        //finding the pivot element such that
        //elements smaller than pivot are on left of pivot
        //elements greater than pivot are on righ of pivot
        int p = partition(array, low, high);

        //recursive call on the left of pivot
        quick_sort(array, low, p - 1);

        //recursive call on the right of pivot
        quick_sort(array, p + 1, high);
    }
}


int main() 
{
    //number of entries to be made in an array
    int  n;
    //inputting n from user
	cout << "Enter the number of entries:";
	cin >>n;

    //allocating an array named "blood_pressure" of size n
	int *blood_pressure = new int(n);
	cout << "Enter " << n << " blood pressure rates = " << endl;

    //inputting rate from the user
	for (int x = 0; x < n; x++) 
    {
		cin >> blood_pressure[x];
	}
    
    // perform quick_sort on blood_pressure
    quick_sort(blood_pressure, 0, n - 1);

    //output
    cout<<"sorted blood pressure rates: ";
    for (int i = 0; i < n; i++)  
    {
        cout<<blood_pressure[i]<<" ";  
    }
    cout<<endl<<"maximum blood pressure: " << blood_pressure[n-1]<<endl<<"minimum blood pressure: " << blood_pressure[0];

    return 0;

}