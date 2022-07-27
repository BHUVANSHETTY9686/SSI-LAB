#include<stdio.h>
#include<stdlib.h>
int findLRU(int time[],int n)
{
	int i,minimum=time[0],pos=0;
	for(i=1;i<n;i++)
	{
			if(time[i]<minimum)
			{
				minimum=time[i];
				pos=i;
			}
	}
	return pos;
}
int main()
{
	int f,n,frames[10],pages[100],counter=0,time[10],flag1,flag2,i,j,pos,fault=0,count=0,k,avail,ch;
	printf("Enter the number of frames\n");
	scanf("%d",&f);
	printf("Enter the number of pages");
	scanf("%d",&n);
	printf("Enter the reference strings");
	for(i=0;i<n;i++)
	{
		scanf("%d",&pages[i]);
	}
	for(i=0;i<f;i++)
	{
		frames[i]=-1;
	}
	printf("\nmenu\n1.LRU\n2.FIFO\n");
	printf("Enter your choice");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			for(i=0;i<n;i++)
			{
				flag1=flag2=0;
				for(j=0;j<f;j++)
				{
					if(frames[j]==pages[i])
					{
						counter++;
						time[j]=counter;
						flag1=flag2=1;
						break;
					}
				}
				if(flag1==0)
				{
					for(j=0;j<f;j++)
					{
						if(frames[j]==-1)
						{ 
							counter++;
							time[j]=counter;
							fault++;
							frames[j]=pages[i];
							flag2=1;
							break;
						}
					}
				 }
				 if(flag2==0)
				{
					pos=findLRU(time,f);
					counter++;
					time[pos]=counter;
					frames[pos]=pages[i];
					fault++;
				}
				printf("\n");
				for(k=0;k<f;k++)
					printf("%d\t",frames[k]);
			}
				  printf("Total number of faults=%d",fault);
				  break;
		case 2:
			j=0;
			printf("ref string\t page frames\n");
			for(i=0;i<n;i++)
			{
					//printf("%d\t\t",pages[i]);
					avail=0;
					for(k=0;k<f;k++)
					     if(frames[k]==pages[i])
							avail=1;
					if(avail==0)
					{
							 frames[j]=pages[i];
							 j=(j+1)%f;
							 count++;
							 for(k=0;k<f;k++)
									printf("%d\t\t",frames[k]);
							printf("\n");
					}
			}
			printf("Total number of faults=%d",count);
			break;
		 default: exit(0);
		}
		return 0;

}
				 
				 				 
				 		
						    	
						    	
	
