#include <iostream>
using namespace std;
void findwt(int p[],int wt[],int bt[],int n){
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
    }
}
void findtat(int p[],int wt[],int bt[],int tat[],int n){
    for(int i=0;i<n;i++){
        tat[i]=bt[i]+wt[i];
    }
}
void findavgtime(int p[],int n,int bursttime[]){
    int t_wt=0,t_tat=0,wt[n],tat[n];
    findwt(p,wt,bursttime,n);
    findtat(p,wt,bursttime,tat,n);
    cout<<"Process  "<<"BurstT  "<<"WaitT  "<<"Tat"<<endl;
    for(int i=0;i<n;i++){
        t_wt+=wt[i];
        t_tat+=tat[i];
        cout<<"  "<<i+1<<" \t "<<bursttime[i]<<" \t "<<wt[i]<<" \t "<<tat[i]<<endl;
    }
    cout<<"Avg WT="<<(float)t_wt/(float)n<<endl;
    cout<<"Avg TAT="<<(float)t_tat/(float)n<<endl;
}
int main ()
{
    int p[]={1,2,3};
    int n=sizeof p/sizeof p[0];
    int bursttime[]={10,5,8};
    findavgtime(p,3,bursttime);
    return 0;
}
