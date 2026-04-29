#include<bits/stdc++.h>
using namespace std;

void worstfit(int blocksize[], int m, int processsize[], int n)
{
    int allocation[n];

    for(int i=0; i<n; i++)
    {
        allocation[i] = -1;
    }

    
    for(int i=0; i<n; i++)
    {
        int worstidx = -1;

        // Check all blocks
        for(int j=0; j<m; j++)
        {
            // Block should be enough
            if(blocksize[j] >= processsize[i])
            {
                // First suitable OR larger suitable block
                if(worstidx == -1 ||
                   blocksize[j] > blocksize[worstidx])
                {
                    worstidx = j;
                }
            }
        }

      
        if(worstidx != -1)
        {
            allocation[i] = worstidx;

            blocksize[worstidx] =
                blocksize[worstidx] - processsize[i];
        }
    }

   
    cout<<"\nWorst Fit Allocation:\n";

    for(int i=0; i<n; i++)
    {
        if(allocation[i] != -1)
        {
            cout<<"Process "<<i+1
                <<" -> Block "
                <<allocation[i]+1<<endl;
        }
        else
        {
            cout<<"Process "<<i+1
                <<" -> Not Allocated"<<endl;
        }
    }
}

int main()
{
    int blocksize[] = {100,500,200,300,600};
    int processsize[] = {212,117,112,426};

    int m=5;
    int n=4;

    worstfit(blocksize,m,processsize,n);

    return 0;
}