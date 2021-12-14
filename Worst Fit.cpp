//Worst Fit 
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
	
	int diff=0,max=INT_MIN,x;
	
	for(int i=0;i<n;i++){
		if(size<=arr[i] && arr[i]!=-1){
			diff=arr[i]-size;
			
			if(diff>max){
				max=diff;
				x=i;
				
			}
		}
	}
	
	if(diff!=0){
		arr[x]=-1;
		cout<<"Partition allocated to the process "<<j<<" is : "<<x+1<<endl;
	}
	else{
		cout<<"Memory not allocated"<<endl;
	}
	
	
	
	string choice;
	cout<<"Do you want to continue ? (y/n)"<<endl;
	cin>>choice;
	
	if(choice=="y"){
		goto a;
	}
	
	return 0;
}
