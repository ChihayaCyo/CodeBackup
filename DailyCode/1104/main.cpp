#include <iostream>
#include <string.h>
#define INF 0xffffff

using namespace std;
char str[200][200];
int value[200];

int main()
{
    int n,m,p;
    memset(value,0,sizeof(value));
    cin>>m>>n;
    value[0]=INF;
    for(int i=1;i<=n;i++)
    {
        cin>>str[i];
        for(int j=0;j<m;j++)
            for(int k=j+1;k<m;k++)
                if(str[i][j]>str[i][k])
                    value[i]++;
    }
    p=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(value[j]<value[p])
                p=j;
        }
        cout<<str[p]<<endl;
        value[p]=INF;
    }
    return 0;
}
