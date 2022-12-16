#include<iostream>
using namespace std;
int main(){
    int nf, N;
    srand(time(NULL));
    cout << "Enter the number of frames" <<endl;
    cin >> nf;
    cout << "Enter the window size" <<endl;
    cin >> N;
    int i=1;
    while(i<=nf){
        int x=0;
        for(int j=i;j<i + N && j<=nf;j++){
            cout<<"Sent frame "<<j<<endl;
            
        }
        for(int j=i;j<i+N&&j<=nf;j++){
            int flag = rand()%2;
            if(!flag){
                cout<<"Acknowledgement for Frame "<<j<<endl;
                x++;
            }   
            else{
                cout<<"Frame "<<j<<" Not received"<<endl;
                cout<<"Retransmitting Window"<<endl;
                break;
            }
        }
        cout<<endl;
        i+=x;
    }
    return 0;
}