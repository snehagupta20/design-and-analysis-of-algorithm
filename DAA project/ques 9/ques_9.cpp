//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT


#include <algorithm>
#include <iostream>
using namespace std;

//structure to represent a job
struct Job 
{

    //job id
	char id; 

    //deadline of the job
	int deadline; 

    //profit if job is done before or on deadline
	int profit; 
};

//comparator function for sorting jobs
bool comparison(Job a, Job b)
{
	return(a.profit >b.profit);
}

//returning max profit from jobs
void job_scheduling(Job jobs[], int n)
{
	//sorting all jobs according to decreasing order of profit:
	sort(jobs,jobs+n,comparison);

    //to store the result (sequence of jobs)
	int result[n];
    //to keep track of free time slots
	bool slot[n];


	//initializing all slots to be free:
	for(int i=0; i < n; i++)
    {
		slot[i]=false;
    }


	//iterating through all given jobs:
	for(int i=0; i < n; i++) 
    {
		//finding a free slot for this job:
		for(int j=min(n,jobs[i].deadline)-1; j>=0; j--) 
        {
			//free slot found:
			if(slot[j]==false) 
            {
                //adding this job to result
				result[j]=i; 
                //making this slot occupied
				slot[j]=true;
				break;
			}
		}
	}

	//output
	for(int i=0; i < n; i++)
    {
		if(slot[i])
        {
			cout<<jobs[result[i]].id<<" ";
        }
    }
}

int main()
{
	Job jobs[]={{'a',5,202},{'b',2,938},{'c',9,02},{'d',3,13},{'e',6,93}};

	int n=sizeof(jobs) / sizeof(jobs[0]);
	cout<<"Following is maximum profit sequence of jobs "<<endl;

	job_scheduling(jobs,n);
	return 0;
}

