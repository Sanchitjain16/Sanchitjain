#include <iostream>
using namespace std;
void findWT(int p[], int wt[],int bt[],int n,int q){
	int rem_wt[n];
	for(int i=0;i<n;i++)
		rem_wt[i]=bt[i];
	int t=0;
	while(1){
		bool done =true;
		for(int i=0;i<n;i++){
			bool done=false;
			if(rem_wt[i]>0){
				if(rem_wt[i]>q){
					t+=q;
					rem_wt[i]-=q;
				}
				else{
					t+=rem_wt[i];
					wt[i]=t-bt[i];
					rem_wt[i]=0;
				}
			}
		}
		if(done==true){
			break;
		}
	}
}  
void findTAT(int p[], int wt[],int bt[],int tat[],int n){
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
}
void findavgtime(int p[],int bt[],int q,int n){
	int wt[n],tat[n],t_wt=0,t_tat=0;
	findWT(p,wt,bt,n,q);
	findTAT(p,wt,bt,tat,n);
	cout<<"P "<<"  BT "<<"  WT "<<"  TAT"<<endl;
	for(int i=0;i<n;i++){
		t_tat+=tat[i];
		t_wt+=wt[i];
	}
	for(int i=0;i<n;i++){
		cout<<p[i]<<"   "<<bt[i]<<"   "<<wt[i]<<"   "<<tat[i]<<endl;
	}
	cout<<"Total WT  -->"<<(float)t_wt/(float)n<<endl;
	cout<<"Total TAT -->"<<(float)t_tat/(float)n<<endl;
}
int main()
{
	int n,q=2;
	cout<<"Enter the Num of Processes\n";
	cin>>n;
	int p[n];
	for(int i=0;i<n;i++){
		p[i]=i+1;
	}
	int bt[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the BT of process "<<i+1<<" "<<endl;
		cin>>bt[i];
	}
	cout<<"P "<<" BT "<<endl<<endl;
	for(int i=0;i<n;i++){
		cout<<p[i]<<"  "<<bt[i]<<endl;
	}
	int size=sizeof bt/sizeof bt[0];
	findavgtime(p,bt,q,size);
	return 0;
}