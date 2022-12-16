#include<iostream>
using namespace std;

void sender(int num){
    int rem[100];
    int size=0;
    int no_of_ones=0;
    while(num!=0){
        rem[size]=num%2;
        if(num%2==1){
            no_of_ones++;
        }
        num=num/2;
        size++;
    }
    int nsize=size+1;
    int msg[nsize];
    int j=0;
    for(int i=size-1;i>=0;i--){
        msg[j]=rem[i];
        j++;
    }
    cout<<"Given number in binary form: ";
    for(int i=0; i<nsize-1;i++){
        cout<<msg[i];
    }
    
}