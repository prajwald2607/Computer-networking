#include <iostream>
using namespace std;
void receiver(int msg[],int nsize)
{
    cout<<"****Message is received by receiver***"<<endl;
    int pbit=msg[nsize-1]; //0
    int no_of_ones=0;
    for(int i=0; i<nsize-1; i++)
    {
        if(msg[i]==1)
        {
            no_of_ones++;
        }
    }
    cout<<"Checking if there any error using parity bit..."<<endl;
    if(no_of_ones%2==pbit)
    {
        cout<<"NO Error Detected!!!";
    }
	else{
        cout<<"Error Detected!!!";
    }
}
void adderror(int msg[],int nsize)  
{
    if(msg[nsize-2]==0)
    {
        msg[nsize-2]=1;
    }
	else{
        msg[nsize-2]=0;
    }
    cout<<"Due to error data is changed to : ";
    for(int i=0; i<nsize; i++)
    {
        cout<<msg[i];
    }
    cout<<endl;
    cout<<"***Due to some external factors error is introducing into data**"<<endl;
    receiver(msg,nsize);
}
void sender(int num)
{
    int rem[100];
    int size=0;
    int no_of_ones=0;
    while(num!=0)
    {
        rem[size]=num%2;
        if(num%2==1)
        {
            no_of_ones++;
        }
        num = num/2;
        size++;
    }
    int nsize = size+1;
    int msg[nsize];
    int j=0;
    for(int i=size-1; i>=0; i--)
    {
        msg[j]=rem[i];
        j++;
    }
    cout<<"Given number in binary form : ";
    for(int i=0; i<nsize-1; i++)
    {
        cout<<msg[i];
    }
    cout<<endl;
    if(no_of_ones%2==0)
    {
        msg[nsize-1]=0;
    }
	else{
    msg[nsize-1]=1;
    }
    cout<<"After adding Parity bit : ";
    for(int i=0; i<nsize; i++)
    {
        cout<<msg[i];
    }   
    cout<<endl;
    cout<<"****Sending message to transmission medium****"<<endl;
    adderror(msg,nsize);
    
}
int main()
{
    int num;
    cout<<"Enter the number you want to send : "<<endl;
    cin>>num;
    sender(num);
}