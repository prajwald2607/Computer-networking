#include<iostream>
#include<cstdlib>
using namespace std;
bool random_bool()
{
    return 0 +  (rand() % 2) == 1;
}
void stop_n_wait_arq(int *sender, int n, int *receiver)
{
    int k = 0;
    int flag = 0;
    while (1)
    {
        if (k == n)
        {
            break;
        }
        int packet = sender[k];
        if (flag == 0)
        {
            cout << endl
                 << "\n Sender sent the packet :" << packet << endl;
        }
        else
        {
            cout << endl
                 << " Sender resent the packet:" << packet << endl;
        }
        bool acknowledgement = random_bool();
        if (acknowledgement == 0)
        {
            cout << " Packet not received:" << packet << endl
                 << " Acknowledgement :" << acknowledgement << endl;
            cout << " Received Packets till now : " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << receiver[i] << " ";
            }
            cout << endl;
            flag = 1;
        }
        else
        {
            cout << " Packet received :" << packet << endl
                 << " Acknowledgement :" << acknowledgement << endl;
            receiver[k] = packet;
            k++;
            cout << " Received Packets till now : " << endl;
            for (int i = 0; i < k; i++)
            {
                cout << receiver[i] << " ";
            }
            cout << endl;
            flag = 0;
        }
    }
}
int main(){
    cout << "\n\t\tSTOP_AND_WAIT_ARQ" << endl
                 << endl;
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
            stop_n_wait_arq(sender, n, receiver);
            cout << endl<< " All Packets received :"<<endl;
                        for (int i = 0; i < n; i++){
                        cout << receiver[i] << " ";
                            } 
                        cout << endl;
}