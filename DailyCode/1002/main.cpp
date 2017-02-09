#include <iostream>

using namespace std;

void swap_(int &x, int &y)
{
    int temp;
    temp=x;
    x=y;
    y=temp;
}

void sort_(int* num,int n)
{
    for(int i=0;i<n-1;i++)
        for(int j=i+1;j<n;j++)
            if(num[i]>num[j])
                swap_(num[i],num[j]);
}

void print(int* num,int* findN,int nn)
{
    for(int i=0;i<nn;i++)
        cout<<num[findN[i]-1]<<"      ";
}

int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
    sort_(num,n);

    for(int i=0;i<n;i++)
        cout<<num[i]<<endl;
    cout<<"###"<<endl;

    int nn;
    cin>>nn;
    int findN[nn];
    for(int i=0;i<nn;i++)
        cin>>findN[i];
    print(num,findN,nn);
    return 0;
}
