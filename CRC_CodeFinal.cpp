#include<iostream>
using namespace std;

void div(int temp[],int key[],int n,int r)
{
	for(int i=0;i<n;i++)
	{
	    if(key[0]==temp[i])	
	    {
	    	for(int j=0,k=i;j<r+1;j++,k++)
	    	{
	    		if(temp[k]^key[j]==1)
	    		{
	    			temp[k]=1;
				}	
				else
				{
					temp[k]=0;
				}
			}
		}
	}
}
int main()
{
	int n,r,data[20],temp[20];
	int key[]={1,0,1,1};
	cout<<"Enter the number of bits that you want: ";
	cin>>n;
	cout<<"Enter the bits of the codeword:"<<endl;
	for(int i=0;i<n;i++)
	{
		cin>>data[i];
	}
	r=3;
	for(int i=0;i<r;i++)
	{
		data[n+i]=0;
	}
	//Before Binary Division
	cout<<"\nThe Redudant bits before binary division: ";
	for(int i=0;i<r;i++)
	{
		cout<<data[n+i]<<" ";
	}
	cout<<"\nThe Codeword before binary division:  "; 
	for(int i=0;i<n+r;i++)
	{
		cout<<data[i]<<" ";
	}
	
	cout<<"\nAfter the binary division "<<endl;
	for(int i=0;i<n+r;i++)
	{
		temp[i]=data[i];
	}
	div(temp,key,n,r);
	
	cout<<"\nThe Redudant bits After binary division: ";
	for(int i=0;i<r;i++)
	{
		cout<<temp[n+i]<<" ";
		data[n+i]=temp[n+i];
	}
	cout<<"\nThe Codeword After binary division:  "; 
	for(int i=0;i<n+r;i++)
	{
		cout<<data[i]<<" ";
	}
	
	cout<<"\n****Receiver's End Message ***"<<endl;
	cout<<"Enter the bits at receiver end: "<<endl;
	for(int i=0;i<n+r;i++)
	{
		cin>>data[i];
	}for(int i=0;i<n+r;i++)
	{
		temp[i]=data[i];
	}
	div(temp,key,n,r);
	for(int i=0;i<r;i++)
	{
		if(temp[n+i])
		{
			cout<<"***Error is detected!***"<<endl;
			cout<<"***The Error detected codeword is: "<<endl;
			for(int i=0;i<n+r;i++)
	        {
		        cout<<data[i]<<" ";
         	}	
			return 0;
		}
	}
	cout<<"No Error"<<endl;
	cout<<"The final Codeword receoved at receiver's  end is: "<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<data[i]<<" ";
	}
	return 0;	
}