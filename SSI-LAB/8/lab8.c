#include<stdio.h>
int max[10][10], allocation[10][10], need[10][10], avail[10], nr, np;

void readmatrix(int matrix[10][10])
{
	for(int i=0; i<np; i++)
		for(int j=0; j<nr; j++)
			scanf("%d",&matrix[i][j]);
}

void calculateneed()
{
	printf("\n   Need Matrix\n");
	for(int i=0; i<np; i++){
		for(int j=0; j<nr; j++){
			need[i][j] =  max[i][j]-allocation[i][j];
			printf("%d\t",need[i][j]);		
		}
		printf("\n");
	}
}

void banker()
{
	int i,j,k=0,flag,finish[10],safe_seq[10];
	for(i=0; i<np; i++)
		finish[i] = 0;
	for(i=0; i<np; i++)
	{
		flag=0;
		if(finish[i] == 0)
		{
			for(j=0;j<nr;j++)
			{
				if(need[i][j]>avail[j])
				{
					flag=1;
					break;
				}
			}
			if(flag == 0)
			{
				finish[i] = 1;
				safe_seq[k] = i;
				k++;
				for(j=0;j<nr;j++)
					avail[j] += allocation[i][j];
				i = -1;
			}
		}
	}
	flag = 0;
	for(i=0;i<np;i++)
	{
		if(finish[i] == 0)
		{
			printf("System is in deadlock");
			flag = 1;
			break;
		}
	}
	if(flag == 0)
	{
		printf("The system in safe sequence is \n");
		for(i=0;i<np;i++)
			printf("P%d\t", safe_seq[i]);
		printf("\n");
	}
}

void main()
{
	int j;
	printf("Enter the number of processes : ");
	scanf("%d",&np);
	printf("Enter the number of resources : ");
	scanf("%d",&nr);
	printf("Enter the maximum reference made\n");
	readmatrix(max);
	printf("Enter the allocated matrix\n");
	readmatrix(allocation);
	printf("Enter the available resources\n");
	for(j=0;j<nr;j++)
		scanf("%d",&avail[j]);
	calculateneed();
	banker();
}
