#include<bits/stdc++.h>
using namespace std;

void nextfit(int blocksize[], int m, int processsize[], int n)
{
    int allocation[n];

    for(int i=0;i<n;i++)
        allocation[i]=-1;

    int last=0;

    for(int i=0;i<n;i++)
    {
        int count=0;

        while(count<m)
        {
            if(blocksize[last] >= processsize[i])
            {
                allocation[i]=last;
                blocksize[last]-=processsize[i];
                last=(last+1)%m;
                break;
            }

            last=(last+1)%m;
            count++;
        }
    }

    cout<<"\nNext Fit Allocation:\n";

    for(int i=0;i<n;i++)
    {
        if(allocation[i]!=-1)
            cout<<"Process "<<i+1<<" -> Block "<<allocation[i]+1<<endl;
        else
            cout<<"Process "<<i+1<<" -> Not Allocated"<<endl;
    }
}

int main()
{
    int blocksize[]={100,500,200,300,600};
    int processsize[]={212,117,112,426};

    int m=5,n=4;

    nextfit(blocksize,m,processsize,n);

    return 0;
}