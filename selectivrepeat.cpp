#include<iostream>
#include<cmath>
using namespace std;
bool random_bool()
{
    return (rand() % 2) == 1;
}
void sr(int sender[], int n, int receiver[])
{
    int i = 0;
    int ws;
    cout << " Enter window size : "<<endl; cin>>ws;
    int arr[ws] = {0};
    int
        k = 0,
        packet, m;
    for (i = 0; i < n; i = i + ws)
    {
        cout << " Window starts from: " << i << endl;
        for (int j = i; j < ws + i; j++)
        {
            if (sender[j] == -1)
            {
                arr[k] = j;
                k++;
                cout << j << " bit is not valid "<<endl;
            }
            cout << "\t Window= " << i << " \t Packet=" << j << endl;
            packet = sender[j];
            receiver[j] = packet;
        }
        m = 0;
        while (m < k)
        {
            if (arr[m] != 0)
            {
                cout << " Asking for " << arr[m] << " bit again" << endl;
                receiver[arr[m]] = 0;
                arr[m] = 0;
                m++;
            }
            else
            {
                m++;
            }
        }
    }
}
int main(){
    cout << "\n\t\tSELECTIVE_REPEAT_ARQ" << endl;
            int n;
            cout << " Enter the size of packets to be sent : ";
            cin >> n;
            int sender[n];
            for (int i = 0; i < n; i++)
            {
                cout << " Enter the packet value : ";
                cin >> sender[i];
            }
            int receiver[n];
            sr(sender, n, receiver);
            for (int
                     i = 0;
                 i < n; i++)
            {
                cout << receiver[i] << " ";
            }
}
