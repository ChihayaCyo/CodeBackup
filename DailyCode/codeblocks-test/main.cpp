#include <stdio.h>
#include<string.h>

int main()
{
    char array[101];


    while(gets(array)){
            int len=strlen(array);
    for(int i=0;i<len;++i){
        printf("%c",array[i]);
    }

    }
    return 0;
}
