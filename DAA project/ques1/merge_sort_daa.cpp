//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <iostream>  
using namespace std;  
  
//function to merge the subarrays(L and R) of blood_pressure[] 
void merge(int blood_pressure[], int start, int mid, int end)    
{    
    /*
        n1: length of L (left subarray)
        n2: length of R (right subarray)
    */
    int n1 = mid - start + 1, n2 = end - mid;    
    int L[n1], R[n2]; 
      
    /* copy data to temp arrays */  
    for (int i = 0; i < n1; i++)  
    {  
        L[i] = blood_pressure[start + i]; 
    }   
    for (int j = 0; j < n2; j++)    
    {
        R[j] = blood_pressure[mid + 1 + j];    
    }
      
    /*
        i: initiial index of L
        j: initial index of R
        k: initial index of merged subarray
    */
    int i=0,j=0,k=start;
      
    //until we reach the end of either L or R, we pick larger among elements L and R and place them in the correct position in the final array
    while (i < n1 && j < n2)    
    {    
        if(L[i] <= R[j])    
        {    
            blood_pressure[k] = L[i];    
            i++;    
        }    
        else    
        {    
            blood_pressure[k] = R[j];    
            j++;    
        }    
        k++;    
    }    

    //for extra elements 
    while (i<n1)    
    {    
        blood_pressure[k] = L[i];    
        i++;    
        k++;    
    }    
      
    while (j<n2)    
    {    
        blood_pressure[k] = R[j];    
        j++;    
        k++;    
    }    
}    
  
/*
    main function for merge sort
    start: beginning of the array
    mid: mid of the array
    end: end of the array
*/
void merge_sort(int blood_pressure[], int start, int end)  
{  
    //base case
    if (start < end)   
    {  
        //formula to calculate the mid of the array
        int mid = (start + end) / 2;  

        //calling merge sort for blood_pressure(0....mid)
        merge_sort(blood_pressure, start, mid);  

        //calling merge sort for blood_pressure(mid+1....end)
        merge_sort(blood_pressure, mid + 1, end);  

        //merging the arrays together
        merge(blood_pressure, start, mid, end);  
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

    merge_sort(blood_pressure, 0, n - 1);  


    //output
    cout<<"sorted blood pressure rates: ";
    for (int i = 0; i < n; i++)  
    {
        cout<<blood_pressure[i]<<" ";  
    }
    cout<<endl<<"maximum blood pressure: " << blood_pressure[n-1]<<endl<<"minimum blood pressure: " << blood_pressure[0];
    return 0;  
}  
