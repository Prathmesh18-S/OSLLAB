#include<bits/stdc++.h>
using namespace std;

void firstfit(int blocksize[],int m,int processsize[],int n){
    int allocation[n];
    for(int i=0;i<n;i++){
        allocation[i]=-1;
    }
   for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(blocksize[j]>=processsize[i]){
            allocation[i]=j;
            blocksize[j]=blocksize[j]-processsize[i];
            break;
        }
    }
   }

   cout<<"\n first fit ....\n";
   for(int i=0;i<n;i++){
    if(allocation[i]!=-1){
        cout<<"process"<<i+1<<"->block"<<allocation[i]+1<<endl;
    }
   else{
    cout<<"porcess"<<i+1<<"-> not allocatedblock";
   }
}





}

int main(){
int blocksize[]={100, 500, 200, 300, 600};
int m=5;
int processsize[]={212, 117, 112, 426};
int n=4;

firstfit(blocksize,m,processsize,n);




    return 0;
}
