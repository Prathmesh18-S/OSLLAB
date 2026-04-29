#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cout<<"enter the no of process:";
cin>>n;

int pid[n],at[n],bt[n],tat[n],wt[n],ct[n],pr[n],rt[n];
for(int i=0;i<n;i++){
    cout<<"enter the at and bt and pt for P"<<i+1;
    cin>>at[i]>>bt[i]>>pr[i];
   rt[i]=bt[i];
}
int time=0;
int cnt=0;
while(cnt<n){
    int hightp=999;
    int idx=-1;

    for(int i=0;i<n;i++){
   if(at[i]<=time && rt[i]>0){
     if(pr[i]<hightp){
        hightp=pr[i];
        idx=i;
     }
   }

    }

    if(idx!=-1){
        rt[idx]--;
        time++;
        if(rt[idx]==0){
            cnt++;
            ct[idx]=time;
            tat[idx]=ct[idx]-at[idx];
            wt[idx]=tat[idx]-bt[idx];


        }
    }
        else{
            time++;
        }
    
}

cout<<"\n PID \t At \t bt  \t  pr \t tat \t wt \n";
for(int i=0;i<n;i++){
    cout<<"p"<<i+1<<"\t"<<at[i]<<"\t "<<bt[i]<<"\t"<<pr[i]<<" \t"<< tat[i]<<"\t"<<wt[i]<<endl;
}


    return 0;
}