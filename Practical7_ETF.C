#include<stdio.h>
#include<conio.h>
int gcd(int a,int b)
{       if(b==0)
	{
	    return a;
	}
	else if(a<b)
	{
	 return gcd(b,a);
	}
	else
	{
	 return gcd(b,a%b);

	}


}
int euler(int n)
{       int i,c=0;
	for(i=1;i<n;i++)
	{
	 if(gcd(n,i)==1)
	 {
	       c++;
	 }

	}
mmm

     return c;

}
void main()
{      int n;
	clrscr();
	printf("Enter the number n:");
	scanf("%d",&n);
	 printf("Phi(n)=%d",euler(n));


 getch();
}