#include<stdio.h>
#include<string.h>
int isp();
int icp();
int top=0,i,n;
char s[100],a[100];
void main()
{

 printf("enter the infix expression");
    scanf("%s",a);

 n=strlen(a);
 a[n]='\0';
 i=0;
 s[top]='\0';
 while(i<=n)
    {
     if(a[i]=='\0')
     {

       while(top>0)
       {
           printf("%c",s[top]);
           top=top-1;
       }
       }
     else if(a[i]=='(')
    {

        top=top+1;
         s[top]=a[i];
    }
     else if(a[i]==')')
         {

         while (s[top]!='(')
         {
             printf("%c",s[top]);
            top=top-1;
         }
         top=top-1;

    }
      else if((a[i]=='^')||(a[i]=='*')||(a[i]=='+')||(a[i]=='-')||(a[i]=='/'))
        {
            while((isp(s[top]))>=(icp(a[i])))
            {
                printf("%c",s[top]);
                top=top-1;
            }
               top=top+1;
               s[top]=a[i];
        }
      else
      {

       printf("%c",a[i]);

       }
       i++;
      }
    }
int isp(char s[])
{

    if(s=='^')
        return 3;
    else if(s=='*'||s=='/')
        return 2;
    else if(s=='+'||s=='-')
        return 1;
    else if(s=='(')
         return 0;
    else if(s=='\0')
        return -1;
}
int icp(char a[])
{

    if(a=='^')
        return 4;
    else if(a=='*'||a=='/')
        return 2;
    else if(a=='+'||a=='-')
        return 1;
    else if(a=='\0')
        return -1;
    else if(a=='(')
         return 4;

}








