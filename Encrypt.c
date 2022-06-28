#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

int main(int argc, char* argv[])
{
    FILE *file, *key, *result;
    file = fopen(argv[2],"rb");
    result = fopen("encrypt","wb");
    char b,x; argc--;
    if(argv[1][0] == 50) goto encrypt;
    else if(argv[1][0] == 51) argc = 1;
    else if(argv[1][0] == 52) goto decrypt;
    if(argc == 1 || argv[1][0] == 49)
        while(1)
        {
            if(fread(&b,1,1,file) == 0) exit(0);
            int put = ~b;
            putc(put,result);
        }
    encrypt:
    key = fopen(argv[3],"rb");
    while(1)
    {
        if(fread(&b,1,1,file) == 0) exit(0);
        if(fread(&x,1,1,key) == 0)
        {
            rewind(key);
            fread(&x,1,1,key);
        }
        b += x;
        int put = ~b;
        putc(put,result);
    }
    decrypt:
    key = fopen(argv[3],"rb");
    while(1)
    {
        if(fread(&b,1,1,file) == 0) break;
        if(fread(&x,1,1,key) == 0)
        {
            rewind(key);
            fread(&x,1,1,key);
        }
        int put = ~b;
        put -= x;
        putc(put,result);
    }
}