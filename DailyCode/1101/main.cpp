#include <iostream>

using namespace std;

void swap_(int* x,int* y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

void bubble(int product[],int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(product[i]>product[j])
                swap_(&product[i],&product[j]);
        }
    }
}

void bubble_(int* product,int n)
{
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(product[i]>product[j])
                swap_(&product[i],&product[j]);
        }
    }
}

void print(int* product,int n)
{
    for(int i=0; i<n; i++)
        cout<<product[i]<<"     ";
    cout<<endl;
}

void bubble__(int product[],int n)
{
    product[1]=1000;
}

void findMid(int* product,int n)
{
    if(n%2==0)
        cout<<product[n/2-1]<<"   "<<product[n/2];
    else
        cout<<product[n/2];
}

int main()
{
    cout << "Hello world!" << endl;
    int n;
    cin>>n;
    int product[n];
    //cout<<product;
    for(int i=0; i<n; i++)
        cin>>product[i];
    bubble(product,n);
    //bubble_(product,n);
    //bubble__(product,n);
    print(product,n);
    findMid(product,n);
    return 0;
}
