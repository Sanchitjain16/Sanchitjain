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
void findavgtime(int p[],int bt[],int pri[],int n){
	int wt[n],tat[n],t_wt=0,t_tat=0;
	findWT(p,wt,bt,n);
	findTAT(p,wt,bt,tat,n);
	cout<<"P "<<" BT "<<" PRI "<<" WT "<<" TAT"<<endl;
	for(int i=0;i<n;i++){
		t_tat+=tat[i];
		t_wt+=wt[i];
	}
	for(int i=0;i<n;i++){
		cout<<p[i]<<"   "<<bt[i]<<"  "<<pri[i]<<"   "<<wt[i]
        <<"   "<<tat[i]<<endl;
	}
	cout<<"Total WT "<<(float)t_wt/(float)n<<endl;
	cout<<"Total TAT "<<(float)t_tat/(float)n<<endl;
}
void prioritysort(int p[],int bt[],int pri[],int n){
	int min;
	for(int i=0;i<n-1;i++){
		min=i;
		for(int j=i+1;j<n;j++){
			if(pri[j]<pri[i]){
				min=j;
                swap(pri[i],pri[min]);
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
	int p[n],pri[n];
	for(int i=0;i<n;i++){
		p[i]=i+1;
	}
	int bt[n];
	for(int i=0;i<n;i++){
		cout<<"Enter the BT of process "<<i+1<<" "<<endl;
		cin>>bt[i];
	}
    for(int i=0;i<n;i++){
		cout<<"Enter the Priority of process "<<" "<<endl;
		cin>>pri[i];
	}
	cout<<"P "<<" BT "<<endl;
	int size=sizeof bt/sizeof bt[0];
	prioritysort(p,bt,pri,size);
	cout<<endl;
	findavgtime(p,bt,pri,n);
	return 0;
}