#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cout<<"enter the number of processes:";
    cin>>n;

    int pid[n],at[n],tat[n],bt[n],wt[n],pr[n],ct[n];
    bool completed[n];
    for(int i=0;i<n;i++){
        cout<<"enter the at and bt and pt for p"<<i+1;
        cin>>at[i]>>bt[i]>>pr[i];
        completed[i]=false;

        
    }

    int cnt=0;
    int time=0;

    while(cnt<n){
        int highpr=999;
        int idx=-1;

        for(int i=0;i<n;i++){
            if(at[i]<=time && completed[i]==false){
                if(pr[i]<highpr){
                    highpr=pr[i];
                    idx=i;
                }
            }
        }
        if(idx!=-1){
            time=time+bt[idx];
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];
            completed[idx]=true;
            cnt++;


        }else{
            time++;
        }








    }
    cout<<"\nP\tAT\tBT\tPR\tCT\tTAT\tWT\n";

    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<"\t"
            <<at[i]<<"\t"
            <<bt[i]<<"\t"
            <<pr[i]<<"\t"
            <<ct[i]<<"\t"
            <<tat[i]<<"\t"
            <<wt[i]<<endl;
    }

    return 0;
}






