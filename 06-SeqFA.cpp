#include <iostream>
using namespace std;
void seqAlloc(int f[]){
    int sb,l,flag=0;
    cout<<"Enter the Num of Files and Length to be allocated\n";
    cin>>sb>>l;
    for(int i=sb;i<sb+l;i++){
        if(f[i]==0)
            flag++;
    }
    if(l==flag){
        int i;
        for(i=sb;i<(sb+l);i++){
            f[i]=1;
            cout<<i<<"  "<<f[i]<<endl;
        }
        if(i==(sb+l))
            cout<<"File allocation done\n";
        else
            cout<<"File allocation not done\n";
    }
}
int main()
{
    int files[50];
    for(int i=0;i<50;i++){
        files[i]=0;
    }
    cout<<"Files Allocated are: \n";
    seqAlloc(files);
    return 0;
}