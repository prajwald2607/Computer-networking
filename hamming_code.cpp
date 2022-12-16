#include<iostream>
using namespace std;

int main(){
    int a[10],b[10],c[10],c1,c2,c3;
    cout<<"\nEnter the 7 bits: ";
    for(int i = 1; i<8; i++){
        cin>>b[i];
    }

    c1 = b[1]^b[3]^b[5]^b[7];
    c2 = b[2]^b[3]^b[6]^b[7];
    c3 = b[4]^b[5]^b[6]^b[7];
    int p=c1*1+c2*2+c3*4;
    if(p==0){
        cout<<"\nThere is no error in the data";
    }
    else{
        cout<<"\nThere is error in the position "<<p<<endl;
        for(int i=1; i<8; i++){
        cout<<"\t"<<b[i];
    }
        cout<<"\nAfter correction"<<endl;
        if(b[p]==0){
            b[p]=1;
        }
        else{
            b[p]=0;
        }
    }
    for(int i=1; i<8; i++){
        cout<<"\t"<<b[i];
    }
    return 0;
}