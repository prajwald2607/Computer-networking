#include <iostream>
#include <cmath>
using namespace std;
void printIP(int ip[]){
    cout << "\n";
    cout << ip[0] << "."<< ip[1] << "."<< ip[2] << "."<< ip[3];
}
int calc_sBits(int n) // subnet bits - n - number of subnets
{
    int pow2 = 1;
    while (pow(2, pow2) < n)
    {
        pow2 += 1;
    }
    return pow2;
    // return log(2 + n)/log(2);
}
class IPv4{ // classful addressing
public:
    int ip[4];
    int defaultMask[4];
    char Class;
    int NwId[4];
    int brodId[4];
    int nwBits;
    int hostBits;

    int subnet;
    int subBits;
    int subHostBits;
    int subMask[4];
    int avlIPs;
    IPv4(int i1,int i2,int i3,int i4){
        ip[0] = i1;
        ip[1] = i2;
        ip[2] = i3;
        ip[3] = i4;
        setClass();
    }
    
    void print(){
        cout << "IP Address:";
        printIP(ip);
        cout <<"\n";
        cout << "Class: " << Class;
        cout << "\nDefault Subnet Mask: ";
        printIP(defaultMask);
        cout << "\nNetwork ID: ";
        printIP(NwId);
        cout << "\nBrodcast ID: ";
        printIP(brodId);
        cout <<"\nNetwork Bits: "<< nwBits;
        cout <<"\nHost Bits: "<< hostBits;
    }
    void setClass(){
        if(ip[0] > 0 && ip[0] < 128){
            defaultMask[0] = 255;
            defaultMask[1] = 0;
            defaultMask[2] = 0;
            defaultMask[3] = 0;
            NwId[0] = ip[0];
            NwId[1] = 0;
            NwId[2] = 0;
            NwId[3] = 0;
            brodId[0] = ip[0];
            brodId[1] = 255;
            brodId[2] = 255;
            brodId[3] = 255;
            nwBits = 8;
            hostBits = 24;
            Class = 'A';
        }
        else if(ip[0] > 127 && ip[0] < 192){
            defaultMask[0] = 255;
            defaultMask[1] = 255;
            defaultMask[2] = 0;
            defaultMask[3] = 0;
            NwId[0] = ip[0];
            NwId[1] = ip[1];
            NwId[2] = 0;
            NwId[3] = 0;
            brodId[0] = ip[0];
            brodId[1] = ip[1];
            brodId[2] = 255;
            brodId[3] = 255;
            nwBits = 16;
            hostBits = 16;
            Class = 'B';
        }
        else if(ip[0] > 191 && ip[0] < 224){
            defaultMask[0] = 255;
            defaultMask[1] = 255;
            defaultMask[2] = 255;
            defaultMask[3] = 0;
            NwId[0] = ip[0];
            NwId[1] = ip[1];
            NwId[2] = ip[2];
            NwId[3] = 0;
            brodId[0] = ip[0];
            brodId[1] = ip[1];
            brodId[2] = ip[2];
            brodId[3] = 255;
            nwBits = 24;
            hostBits = 8;
            Class = 'C';
        }
    }
    // nwid, broadcast id
    // network bits, host bits
    void calSubMask(){
        cout <<"\nEnter no. of subnet: ";
        cin >> subnet;
        subBits = calc_sBits(subnet);
        cout<<"Number of subnet bits: "<< subBits;
        subHostBits = 32 - nwBits - subBits;
        cout <<"\nHost Bits after subnetting: "<<subHostBits;
        avlIPs = pow(2,subHostBits);
        cout <<"\nAvailable IPs in each subnet: "<<avlIPs - 2;
        int sum = 0;
        if (Class == 'C')
        {
            for (int i = 7, j = 0; j < subBits; j++, i--)
            {
                sum += pow(2, i);
            }
            cout << "\nDefault subnet mask: 255.255.255.0" << endl;
            cout << "Subnet mask: 255.255.255." << sum << " (/" << 24 + subBits << ")" << endl;
        }
        else if (Class == 'B')
        {
            for (int i = 7, j = 0; j < subBits; j++, i--)
            {
                sum += pow(2, i);
            }
            cout << "Default subnet mask: 255.255.0.0" << endl;
            cout << "Subnet mask: 255.255." << sum << ".0 (/" << 16 + subBits << ")" << endl;
        }
        else if (Class == 'A')
        {
            for (int i = 7, j = 0; j < subBits; j++, i--) // binary to decimal
            {
                sum += pow(2, i);
            }
            cout << "Default subnet mask: 255.0.0.0" << endl;
            cout << "Subnet mask: 255." << sum << ".0.0 (/" << 8 + subBits << ")" << endl;
        }
    }
};
int main(){
    IPv4 ip(192,10,20,0);
    ip.print();
    ip.calSubMask();
}