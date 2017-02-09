#include <iostream>
#include <string>
#include <string.h>
//#include <sstream>

using namespace std;

void match(string telNum[],int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<telNum[i].size(); j++)
        {
            if(telNum[i][j]=='A'||telNum[i][j]=='B'||telNum[i][j]=='C')
                telNum[i][j]='2';
            if(telNum[i][j]=='D'||telNum[i][j]=='E'||telNum[i][j]=='F')
                telNum[i][j]='3';
            if(telNum[i][j]=='G'||telNum[i][j]=='H'||telNum[i][j]=='I')
                telNum[i][j]='4';
            if(telNum[i][j]=='J'||telNum[i][j]=='K'||telNum[i][j]=='L')
                telNum[i][j]='5';
            if(telNum[i][j]=='M'||telNum[i][j]=='N'||telNum[i][j]=='O')
                telNum[i][j]='6';
            if(telNum[i][j]=='P'||telNum[i][j]=='R'||telNum[i][j]=='S')
                telNum[i][j]='7';
            if(telNum[i][j]=='T'||telNum[i][j]=='U'||telNum[i][j]=='V')
                telNum[i][j]='8';
            if(telNum[i][j]=='W'||telNum[i][j]=='X'||telNum[i][j]=='Y')
                telNum[i][j]='9';
        }
    }
    for(int i=0; i<n; i++)
    {
        cout<<telNum[i]<<endl;
    }
}

void bubble(string telNum[],int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(telNum[i].compare(telNum[j])>0)
            {
                string temp;
                temp=telNum[i];
                telNum[i]=telNum[j];
                telNum[j]=temp;
            }
}

void distinct(string telNum[],int n,int* count_)
{
    bubble(telNum,n);
    int i=0;
    int j=0;
    string telNumD[n];
    //for(int z=0;z<n;z++) telNumD[z]="null";
    telNumD[0]=telNum[0];
    while(i<n-1)
    {
        count_[j]++;
        if((telNum[i].compare(telNum[i+1]))!=0)
        {
            j++;
            telNumD[j]=telNum[i+1];
        }
        i++;
    }
    cout<<j<<"  "<<count_[j]<<endl;
    for(int x=0; x<=j; x++)
    {
        cout<<telNumD[x]<<":"<<count_[x]<<endl;
    }
}

int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;//这里的读入会给cin残留一个回车
    string telNum[n];
    int count_[n];
    memset(count_,0,sizeof(int)*n);
    for(int i=0;i<n;i++)
    {
        count_[i]++;
    }
    //for(int i=0;i<n;i++) cout<<count_[i]<<"      ";
    for(int i=0; i<n; i++)
    {
        cin.sync();
        getline(cin,telNum[i]);//这里的读入不会给cin残留回车
        //cin.getline(telNum[i],20);//char[] telNum;
    }
    match(telNum,n);
    //while(i<n) telNum!='-'时 让telNum[i]'=telNum[i];
    distinct(telNum,n,count_);
    return 0;
}
