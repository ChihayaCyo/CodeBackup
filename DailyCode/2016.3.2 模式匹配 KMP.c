#include<stdio.h>
#include<stdlib.h>

#define max_s 450

typedef struct{
    char* ch;
    int length;
}Str;

void strassign(Str* str,char* ch)
{
    if(str->ch)//!=NULL
        free(str->ch);
    char* c=ch;
    int len=0;
    while(*c)
    {
        ++c;//!
        ++len;
    }
    if(len==0)
    {
        str->ch=NULL;
        str->length=0;
    }
    else
    {
        str->ch=(char*)malloc(sizeof(char)*(len+1));
        c=ch;
        int i=0;
        for(i=0;i<len+1;++i,++c)
            str->ch[i]=*c;
        str->length=len;
    }
}

void print(Str str)
{
    int i=0;
    //while(str.ch[i])//此处有三种写法 !=NULL给warning !='\0'过 这种也过
    while(i<str.length)
        printf("%c",str.ch[i++]);
    printf("\n");
}

void initial(Str* str)
{
    str->ch=NULL;
    str->length=0;
}

int strcompare(Str s1,Str s2)
{
    int i=0;
    for(i=0;i<s1.length&&i<s2.length;++i)
    {
        if(s1.ch[i]!=s2.ch[i])
            return s1.ch[i]-s2.ch[i];
    }
    return s1.length-s2.length;
}

void concat(Str* str,Str str1,Str str2)
{
    if(str->ch)
    {
        free(str->ch);
        str->ch=NULL;
    }
    str->ch=(char*)malloc(sizeof(char)*(str1.length+str2.length+1));//!
    int i,j;
    for(i=0;i<str1.length;++i)
    {
        str->ch[i]=str1.ch[i];
    }
    for(j=0;j<str2.length;++j)
    {
        str->ch[i+j]=str2.ch[j];
    }
    str->length=str1.length+str2.length;
}

void substring(Str* substr,Str str,int pos,int len)
{
    if(pos>=str.length||len>str.length-pos)//？有bug
    {
        printf("Error");
        return;
    }
    if(len==0)
    {
        substr->ch=NULL;
        substr->length=0;
        return;
    }
    if(substr->ch)
    {
        free(substr->ch);
        substr->ch=NULL;
    }
    substr->ch=(char*)malloc(sizeof(char)*(len+1));
    substr->length=len;
    int i,j=0;
    for(i=pos;i<pos+len;++i,++j)
    {
        substr->ch[j]=str.ch[i];
    }
    //substr->ch[j]=NULL;//？
}

void clearstring(Str* str)
{
    if(str->ch)
    {
        free(str->ch);
        str->ch=NULL;
    }
    str->length=0;
}

int index_(Str str,Str substr)
{
    int i=0,j=0,k=0;
    while(i<str.length&&j<substr.length)
    {
        if(str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=0;
            i=++k;
        }
    }
    if(j==substr.length)
        return k;
    else
        return -1;
}

int KMP(Str str,Str substr,int next[])
{
    int i=0,j=0;
    while(i<str.length&&j<substr.length)
    {
        if(str.ch[i]==substr.ch[j]){
            ++i;
            ++j;
        }
        else{
            j=next[j];
            if(j==-1){//?
                j=0;
                ++i;
            }
        }
    }
    if(j==substr.length)
        return i-j;
    else
        return -1;
}

void getnext(Str substr,int next[])
{
    int i=0,j=-1;
    next[0]=-1;
    while(i<substr.length)
    {
        if(j==-1||substr.ch[i]==substr.ch[j])
        {
            ++i;
            ++j;
            next[i]=j;
        }
        else{
            j=next[j];
        }
    }
}

int main()
{
    Str str1,str2;
    initial(&str1);
    initial(&str2);
    strassign(&str1,"abc def");
    //char ch[max_s];
    //fgets(ch,max_s,stdin);
    //printf("str1初始已赋值，请输入str2：");
    //gets(ch);
    strassign(&str2," xyz");
    print(str1);
    print(str2);

    printf("str1-str2=%d\n",strcompare(str1,str2));

    Str str;
    concat(&str,str1,str2);
    print(str);

    Str substr;
    int pos,len;
    printf("请输入子串的起始位置pos和长度len：");
    scanf("%d %d",&pos,&len);
    substring(&substr,str,pos,len);
    print(substr);

    int st;
    st=index_(str,substr);
    printf("暴力模式匹配得到的子串的起始位置为：%d\n",st);

    int next[max_s];
    getnext(substr,next);
    int stkmp;
    stkmp=KMP(str,substr,next);
    printf("KMP算法得到的子串的起始位置为：%d\n",stkmp);


    clearstring(&str);
    print(str);
    return 0;
}
