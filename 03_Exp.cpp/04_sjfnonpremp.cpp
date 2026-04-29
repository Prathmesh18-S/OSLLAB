#include<bits/stdc++.h>
using namespace std;
int main(){
    int n=4;
    int at[4]={0,1,2,3};
    int bt[4]={5,3,8,6};

    int ct[4],tat[4],wt[4];
    bool completed[4]={false};

    int time =0;
    int count=0;
    while(count<n){
        int minibt=999;
        int idx=-1;

        for(int i=0;i<n;i++){
            if(at[i]<=time && completed[i]==false){
                  if(bt[i]<minibt){
                    minibt=bt[i];
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
            count++;




        }else{ 
            time++;

        }

    }

    cout<<"\n PT \t AT \t BT \t CT \t TAT \t WT\n";
    for(int i=0;i<n;i++){
        cout<<"p"<<i+1<<"\t"<<at[i]<<"\t"<<bt[i]<<"\t"<<ct[i]<<"\t"<<tat[i]<<"\t"<<wt[i]<<endl;
    }



    return 0;
}