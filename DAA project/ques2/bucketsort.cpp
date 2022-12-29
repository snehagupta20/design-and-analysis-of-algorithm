//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;


int main()
{

    //number of entries to be made in an array
    int  n;
    //inputting n from user
	cout<<"Enter the number of entries:";
	cin >>n;


    float arr[n];
	cout<<"Enter "<<n<<" numbers= "<<endl;

    //inputting from the user
	for (int x=0; x<n; x++) 
    {
		cin >> arr[x];
	}

    cout<<"array before sorting: ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }


    //creating n empty buckets
	vector<float> b[n];


	//putting array elements in different buckets
	for (int i=0; i<n; i++) 
    {
        //index in bucket
		int bi=n * arr[i]; 
		b[bi].push_back(arr[i]);
	}


	//sorting individual buckets
	for (int i=0; i<n; i++)
    {
		sort(b[i].begin(), b[i].end());
    }


	//concatenating all buckets into array
	int index=0;
	for (int i=0; i<n; i++)
    {
		for (int j=0; j<b[i].size(); j++)
        {
			arr[index++]=b[i][j];
        }
    }

    
    cout<<endl<<"array after sorting: ";
    for (int i=0; i<n; i++)
    {
        cout<<arr[i]<<" ";
    }

	return 0;
}
