#include<bits/stdc++.h>
using namespace std;

void bestfit(int blocksize[], int m, int processsize[], int n)
{
    int allocation[n];

  
    for(int i=0; i<n; i++)
    {
        allocation[i] = -1;
    }


    for(int i=0; i<n; i++)
    {
        int bestidx = -1;

        for(int j=0; j<m; j++)
        {
           
            if(blocksize[j] >= processsize[i])
            {
                
                if(bestidx == -1 || blocksize[j] < blocksize[bestidx])
                {
                    bestidx = j;
                }
            }
        }

       
        if(bestidx != -1)
        {
            allocation[i] = bestidx;

            blocksize[bestidx] =
                blocksize[bestidx] - processsize[i];
        }
    }

    cout<<"\nBest Fit Allocation:\n";

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

    int m = 5;
    int n = 4;

    bestfit(blocksize,m,processsize,n);

    return 0;
}