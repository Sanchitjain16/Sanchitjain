//First Fit Algo
#include<iostream>

using namespace std;

int main(){
	int n;
	cout<<"Enter the total number of partitions"<<endl;	
	cin>>n;
	
	int arr[n];
	cout<<"Enter size of partitions "<<endl;
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int size,j=0;
	a:
	cout<<"Enter the process size "<<endl;
	cin>>size;
	j++;
	
	for(int i=0;i<n;i++){
		if(size<=arr[i] && arr[i]!=-1){
			cout<<"Partition allocated to the process "<<j<<" is : "<<i+1<<endl;
			arr[i]=-1;
			break;
		}
		
		/*if(size<=arr[i] && arr[i]==-1){
			cout<<"Error"<<endl;
		}*/
	}
	
	string choice;
	cout<<"Do you want to continue ? (y/n)"<<endl;
	cin>>choice;
	
	if(choice=="y"){
		goto a;
	}
	
	return 0;
}
