#include<iostream>
#include<stack>
#include <stdlib.h>
#include<string>
using namespace std;
//��ʼ��Ԥ�������
string action[12][6]={
       {"s5","error","error","s4","error","error"},
       {"error","s6","error","error","error","acc"},
       {"error","r2","s7","error","r2","r2"},
       {"error","r4","r4","error","r4","r4"},
       {"s5","error","error","s4","error","error"},
       {"error","r6","r6","error","r6","r6"},
       {"s5","error","error","s4","error","error"},
       {"s5","error","error","s4","error","error"},
       {"error","s6","error","error","s11","error"},
       {"error","r1","r7","error","r1","r1"},
       {"error","r3","r3","error","r3","r3"},
       {"error","r5","r5","error","r5","r5"}
       };

string go[12][3]={
       {"1","2","3"},
       {"error","error","error"},
       {"error","error","error"},
       {"error","error","error"},
       {"8","2","3"},
       {"error","error","error"},
       {"error","9","3"},
       {"error","error","10"},
       {"error","error","error"},
       {"error","error","error"},
       {"error","error","error"},
       {"error","error","error"},
       };
char Vt[6]={'i','+','*','(',')','#'};//�ս����
string LR[6]={"E->E+T","E->T","T->T*F","T->F","F->(E)","F->i"};//LR�ķ�
stack<int>S;                //״̬ջ
stack<char>X;             //����ջ
char input[10];             //�����ַ�
int num(string s){           //�ж��ַ����е�����
 int i;
 string str="";
 for(int j=0;j<s.length();j++){
 if(s[j]>='0'&&s[j]<='9') str=str+s[j];
 }
 i=atoi(str.c_str());
	 return i;
}
void print(int i,char*c)//ʣ�����봮�����
{
     for(int j=i;j<10;j++)
     cout<<c[j];
     cout<<'\t';
}
int same(char a){             //���ڲ����ս��
	for(int i=0;i<6;i++){
	if (a==Vt[i]) return i;
	}
}

///**********��������*******************
void analyse(){
	 bool flag=true;        //ѭ������
    int step=1,point=0,state=0;     //���衢ָ�롢״̬
	char ch1,ch2;
	int m,n,l;                          //�����ж��ս��,������,���ʽ�Ҳ��ĳ���
	string str1;                     //�����ж϶�Ӧ�������еķ���
	string str2="#",str3="0";                     //��¼����ջ������Ԫ��
cout<<"������Ҫ��Լ���ַ�����"<<endl;
cin>>input;
X.push('#');
S.push(0);

cout<<"����"<<'\t'<<"״̬ջ"<<'\t'<<"����ջ"<<'\t'<<"���봮     "<<'\t'<<"����"<<endl;
cout<<step++<<'\t'<<str3<<'\t'<<str2<<'\t';
print(point,input);
cout<<"��ʼ��"<<endl;           //*************��ʼ��
//************����ѭ��
while(flag){

state=S.top();
ch1=input[point];
m=same(ch1);
str1=action[state][m];
//***********�ƽ�����
if(str1[0]=='s'){
n=num(str1);
S.push(n);
X.push(ch1);
str2=str2+ch1;
ch2=n+48;
str3=str3+ch2;
point++;
cout<<step++<<'\t'<<str3<<'\t'<<str2<<'\t';
print(point,input);
cout<<str1<<':'<<"�ƽ�"<<endl;

}

//**********��Լ����
else if(str1[0]=='r'){
n=num(str1);

l=LR[n-1].length()-3;

for(int i=1;i<=l;i++) {S.pop();
str3=str3.substr(0,str3.length()-1);

X.pop();
str2=str2.substr(0,str2.length()-1);
}

X.push(LR[n-1][0]);
str2=str2+LR[n-1][0];
state=S.top();
if(LR[n-1][0]=='E'){S.push(num(go[state][0]));
ch2=num(go[state][0])+48;
str3=str3+ch2;

}
else if(LR[n-1][0]=='T'){S.push(num(go[state][1]));
ch2=num(go[state][1])+48;
str3=str3+ch2;

}
else if(LR[n-1][0]=='F') {S.push(num(go[state][2]));
ch2=num(go[state][2])+48;
str3=str3+ch2;

}

cout<<step++<<'\t'<<str3<<'\t'<<str2<<'\t';
print(point,input);
cout<<str1<<':'<<LR[n-1]<<"��Լ"<<endl;
}
//*********����
else if(str1=="error"){
cout<<"ERROR"<<"������󣬷�������������"<<endl;
flag=false;
}
//**********�����ɹ�
else if(str1=="acc"){cout<<"�����ɹ�����ֹ����"<<endl;
flag=false;
}
}
}
int main(){

    analyse();
    return 0;
 }
