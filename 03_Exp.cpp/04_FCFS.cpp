#include<iostream>
using namespace std;

int main()
{
    int n;

    cout<<"Enter number of processes: ";
    cin>>n;

    int pid[n],at[n],bt[n],ct[n],tat[n],wt[n];

    
    for(int i=0;i<n;i++)
    {
        pid[i]=i+1;

        cout<<"Enter Arrival Time and Burst Time for P"<<i+1<<": ";
        cin>>at[i]>>bt[i];
    }

   
    for(int i=0;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(at[i] > at[j])
            {
                swap(at[i],at[j]);
                swap(bt[i],bt[j]);
                swap(pid[i],pid[j]);
            }
        }
    }

    int time=0;

  
    for(int i=0;i<n;i++)
    {
        if(time<at[i])
        {
            time=at[i];
        }

        time=time+bt[i];

        ct[i]=time;

        tat[i]=ct[i]-at[i];

        wt[i]=tat[i]-bt[i];
    }

    
    cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++)
    {
        cout<<pid[i]<<"\t"
            <<at[i]<<"\t"
            <<bt[i]<<"\t"
            <<ct[i]<<"\t"
            <<tat[i]<<"\t"
            <<wt[i]<<endl;
    }

    return 0;
}