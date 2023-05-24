#include<stdio.h>
#include<string.h>
#include<conio.h>
void encrypt(int depth,char str[20][20],char a[20],char b[20])
{       int i,j,k=0;
for(i=0;i<strlen(a);i++)
	{
	 str[i%depth][i]=a[i];

	}
       for(i=0;i<depth;i++)
       {
		for(j=0;j<strlen(a);j++)
		{
		  if(str[i][j]!=NULL)
		  {
	       //	  printf("%c\t",str[i][j]);
		 b[k]=str[i][j];
		  k++;
		  }

		}

       }
       b[k]='\0';

	puts(b);




}
void main()
{      char a[20],b[20];
	char str[20][20]={{'\0'}};
	int depth;
	clrscr();
	printf("Enter the String:");
	gets(a);
	printf("Enter the depth:");
	scanf("%d",&depth);
		   //encryption
	 encrypt(depth,str,a,b);
	 //decryption
	 encrypt(depth,str,b,a);
      getch();
}