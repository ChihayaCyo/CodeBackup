#include<stdio.h>
#include<string.h>
#include<iostream>

#include<fstream>

using namespace std;

char prog[80],token[8];
char ch;
int syn,p,m=0,n,row;
//double dsum=0;
float sum=0;
char *rwtab[12]={"main","void","int","double","char","printf","scanf","if","else","for","while","return"};


void scaner()
{

    for(n=0;n<8;n++) token[n]=NULL;
    ch=prog[p++];
    while(ch==' '||ch=='\n')
    {
        ch=prog[p];
        p++;
    }
    if((ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))  //可能是标示符或者变量名
    {
        m=0;
        while((ch>='0'&&ch<='9')||(ch>='a'&&ch<='z')||(ch>='A'&&ch<='Z'))
        {
            token[m++]=ch;
            ch=prog[p++];
        }
        token[m++]='\0';
        p--;
        syn=31;
        for(n=0;n<12;n++)  //将识别出来的字符和已定义的标示符作比较，
            if(strcmp(token,rwtab[n])==0)
            {
                syn=n+1;
                break;
            }
    }
    else if((ch>='0'&&ch<='9')||(ch=='.'))  //数字或小数
    {
       // if(ch>='0'&&ch<='9')
       // {
            sum=0;
            while((ch>='0'&&ch<='9')||(ch=='.'))
            {
                if(ch>='0'&&ch<='9')
                {
                    sum=sum*10+ch-'0';
                    ch=prog[p++];
                }
                else
                {
                    ch=prog[p++];
                    int dloop=1;
                    while(ch>='0'&&ch<='9')
                    {
                        sum=sum+(double)(ch-'0')/(10.0*dloop);
                        dloop=dloop*10;
                        ch=prog[p++];
                    }
                }
            }
            syn=32;
            p--;
            if(sum>32767)
                syn=-1;
       // }
   /*     else    //(ch='.')
        {
            ifloat=1;
            ch=prog[p++];
            dsum=(double)sum;
            int dloop=1;
            while((ch>='0'&&ch<='9'))
            {
                dsum=dsum+(double)(ch-'0')/(10.0*dloop);
               // cout << dsum << endl;
                dloop=dloop*10;
                ch=prog[p++];
            }
            p--;
            syn=30;
            if(dsum>32767)
                syn=-1;
        }
        */
    }
    else switch(ch)   //其他字符
    {
        case'<':m=0;token[m++]=ch;
            ch=prog[p++];
            if(ch=='>')
            {
                syn=50;
                token[m++]=ch;
            }
            else if(ch=='=')
            {
                syn=47;
                token[m++]=ch;
            }
            else
            {
                syn=48;
                p--;
            }
            break;
        case'>':m=0;token[m++]=ch;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=47;
                token[m++]=ch;
            }
            else
            {
                syn=50;
                p--;
            }
            break;
        case':':m=0;token[m++]=ch;
            ch=prog[p++];
            if(ch=='=')
            {
                syn=47;
                token[m++]=ch;
            }
            else
            {
                syn=53;
                p--;
            }
            break;
        case'*':syn=44;token[0]=ch;break;
        case'/':syn=45;token[0]=ch;break;
        case'+':
  //          char buffer;
    //        buffer=prop[p++];


            syn=42;token[0]=ch;
            break;
        case'-':syn=43;token[0]=ch;break;
        case'=':syn=47;token[0]=ch;break;
        case';':syn=41;token[0]=ch;break;
        case'{':syn=37;token[0]=ch;break;
        case'}':syn=38;token[0]=ch;break;
        case'"':syn=40;token[0]=ch;break;
        case'(':syn=35;token[0]=ch;break;
        case')':syn=36;token[0]=ch;break;
        case'%':syn=54;token[0]=ch;break;
        case',':syn=55;token[0]=ch;break;
        case'\t':syn=56;token[0]=ch;break;
        case'#':syn=0;token[0]=ch;break;
        case'\n':syn=-2;break;
        default: syn=-1;break;
    }
}

int main()
{
    p=0;
    row=1;
    cout<<"Please input string:"<<endl;

    ifstream OpenFile("zhsource.txt");
    while(!OpenFile.eof()&&ch!='#')
    {
        OpenFile.get(ch);
        prog[p++]=ch;
    }
    OpenFile.close();
 /*
    do
    {
        cin.get(ch);
        prog[p++]=ch;
    }
    while(ch!='#');
*/
    p=0;
    do
    {
        scaner();
        switch(syn)
        {
        case 32: cout<<"("<<syn<<","<<sum<<")"<<endl; break;
        case -1: cout<<"Error in row "<<row<<"!"<<endl; break;
        case -2: row=row++;break;
        default: cout<<"("<<syn<<","<<token<<")"<<endl;break;
        }
    }
    while (syn!=0);
}
