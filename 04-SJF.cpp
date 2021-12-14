#include <iostream>
using namespace std;
void findWT(int p[], int wt[],int bt[],int n){
	wt[0]=0;
	for(int i=1;i<n;i++)
		wt[i]=wt[i-1]+bt[i-1];
}
void findTAT(int p[], int wt[],int bt[],int tat[],int n){
	for(int i=0;i<n;i++)
		tat[i]=wt[i]+bt[i];
}
void findavgtime(int p[],int bt[],int n){
	int wt[n],tat[n],t_wt=0,t_tat=0;
	findWT(p,wt,bt,n);
	findTAT(p,wt,bt,tat,n);
	cout<<"P "<<" BT "<<" WT "<<" TAT"<<endl;
	for(int i=0;i<n;i++){
		t_tat+=tat[i];
		t_wt+=wt[i];
	}
	for(int i=0;i<n;i++){
		cout<<p[i]<<"   "<<bt[i]<<"   "<<wt[i]<<"   "<<tat[i]<<endl;
	}
	cout<<"Total WT "<<(float)t_wt/(float)n<<endl;
	cout<<"Total TAT "<<(float)t_tat/(float)n<<endl;
}
// void swaping(int &a,int &b){
// 	int t=a;
// 	a=b;
// 	b=t;
// }
void bursttimesort(int p[],int bt[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(bt[j]<bt[i]){
				min=j;
				swap(bt[i],bt[min]);
				swap(p[i],p[min]);
			}
		}
	}
}
int main()
{
	int n;
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
	cout<<"P "<<" BT "<<endl;
	for(int i=0;i<n;i++){
		cout<<p[i]<<"  "<<bt[i]<<endl;
	}
	int size=sizeof bt/sizeof bt[0];
	bursttimesort(p,bt,size);
	cout<<endl;
	findavgtime(p,bt,n);
	return 0;
}