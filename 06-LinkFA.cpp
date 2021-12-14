#include <iostream>
using namespace std;
void linkalloc(int f[]){
    int sb,l;
    cout<<"Enter the StartBlock and length\n";
    cin>>sb>>l;
    int k=l;
        if(f[sb]==0){
            for(int i=sb;i<sb+k;i++){
                if(f[i]==0){
                    f[i]=1;
                    cout <<i<<"--->"<<f[i]<<endl;
                }
                else{
                    cout<<"The block "<<i<<" is already allocated\n";
                    k++;
                }
            }
        }
        else 
            cout<<"The allocation is not possible\n";
}
int main()
{
    int f[50],a;
    for(int i=0;i<50;i++)
        f[i]=0;
    cout<<"Enter the already allocated Blocks\n";
    cin>>a;
    cout<<"Enter the block position\n";
    for(int i=0;i<a;i++){
        int b;
        cin>>b;
        f[b]=1;
    }
    linkalloc(f);
    return 0;
    
}