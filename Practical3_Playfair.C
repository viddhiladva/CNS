#include <stdio.h>
#include <string.h>
#include<conio.h>
int mod(int a)
{
	return (a % 5)<0?(a%5 + 5):a%5;
}

void find(char a, char b, char mtx[5][5], int index[4])
{

	int i, k, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (a == mtx[i][j])
			{
				index[0] = i;
				index[1] = j;
			}
			if (b == mtx[i][j])
			{
				index[2] = i;
				index[3] = j;
			}
		}
	}

}

void getmetrix(char *key, char mtx[5][5])
{

	int i, j, k, c;
	int ref[26], key_len;

	for (i = 0; i < 26; i++)
	{
		ref[i] = 0;
	}

	k = 0;
	i = 0;
	j = 0;
	key_len = strlen(key);

	for (k = 0; k < key_len; k++)
	{
		if (!ref[key[k] - 97] && key[k] != 'j')
		{

			ref[key[k] - 97] = 2;
			mtx[i][j] = key[k];

			j++;

			if (j == 5)
			{
				i++;
				j = 0;
			}
		}
	}

	ref['j' - 97] = 1;

	for (k = 0; k < 26; k++)
	{
		if (ref[k] == 0)
		{
			mtx[i][j] = k + 97;
			j++;
			if (j == 5)
			{
				j = 0;
				i++;
			}
		}
	}
}

void string_make(char *main_str,char *nstr)
{

	int i,c=0,n=strlen(main_str);

	for (i = 0; i < n; i += 2)
	{
		if (main_str[i] != main_str[i + 1])
		{
			nstr[c++] = main_str[i];
			nstr[c++] = main_str[i + 1];
		}
		else
		{
			nstr[c++] = main_str[i];
			nstr[c++] = 'x';
			i--;
		}
	}



}

void encrypt(char *plain_text,char *key)
{
   char encry_str[100],mtx[5][5],nstr[100];
   int i,j,k,c=0,index[4];
   getmetrix(key,mtx);

   printf("\n-------------- metrix --------------------\n");

    for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",mtx[i][j]);
		}
		printf("\n");
	}



    string_make(plain_text,nstr);


    for (i = 0; i < 8; i += 2)
	{
		find(nstr[i], nstr[i + 1], mtx, index);
		printf("\n");



		if (index[0] == index[2])
		{
			encry_str[c++] = mtx[index[0]][mod(index[1] + 1)];
			encry_str[c++] = mtx[index[0]][mod(index[3] + 1)];
		}
		else if (index[1] == index[3])
		{
			encry_str[c++] = mtx[mod(index[0] + 1)][index[1]];
			encry_str[c++] = mtx[mod(index[2] + 1)][index[1]];
		}
		else
		{
			encry_str[c++] = mtx[index[0]][index[3]];
			encry_str[c++] = mtx[index[2]][index[1]];
		}
	}

  printf("\n--------------encypted message ----------\n");
   for(i=0;i<c;i++)
   {
	   printf("%c",encry_str[i]);
   }


}

void decrypt(char *plain_text,char *key)
{
	char encry_str[100],mtx[5][5],nstr[100];
   int i,j,k,c=0,index[4];
     getmetrix(key,mtx);
	 printf("\n-------------- metrix --------------------\n");

    for(i=0;i<5;i++)
	{
		for(j=0;j<5;j++)
		{
			printf("%c ",mtx[i][j]);
		}
		printf("\n");
	}

    string_make(plain_text,nstr);

    for (i = 0; i < 8; i += 2)
	{
		find(nstr[i], nstr[i + 1], mtx, index);

		for (k = 0; k < 4; k++)
			printf("%d ", index[k]);

		if (index[0] == index[2])
		{
			encry_str[c++] = mtx[index[0]][mod(index[1] - 1)];
			encry_str[c++] = mtx[index[0]][mod(index[3] - 1)];
		}
		else if (index[1] == index[3])
		{
			encry_str[c++] = mtx[mod(index[0] - 1)][index[1]];
			encry_str[c++] = mtx[mod(index[2] -1)][index[1]];
		}
		else
		{
			encry_str[c++] = mtx[index[0]][index[3]];
			encry_str[c++] = mtx[index[2]][index[1]];
		}
	}
printf("\n--------------decrypted  message----------\n");
   for(i=0;i<c;i++)
   {
	   printf("%c",encry_str[i]);
   }


}


void main()
{
	int i, n, j, k, c, r = 0,choice;
	char main_str[200], key[100];
	char *encry_str;
    clrscr();
	printf("Enter The text  String : ");
	gets(main_str);
	fflush(stdin);
	printf("Enter the key : ");
	gets(key);

	printf(" (press 1. for encrypt and  2.for decrypt) \n Enter the choice :- ");
    scanf("%d",&choice);

	switch (choice)
	{
	case 1:
	   encrypt(main_str,key);
		break;

	case 2:
			decrypt(main_str,key);

		break;

	default:
		break;
	}

getch();

}
