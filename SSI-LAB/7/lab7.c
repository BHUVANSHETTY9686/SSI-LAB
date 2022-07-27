#include<stdio.h>
int main()
{
	int count,j,n,time,flag=0,time_quantum,ch=0;
	int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
	int endtime ,i,smallest;
	int remain=0,sum_wait=0,sum_turnaround=0;
	
	
	printf("enter no. of processes:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("arrival time for processes %d:",i);
		scanf("%d",&at[i]);
		printf("enter thr burst time for process %d:",i);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	
	printf("	1.Round robin \n	2.SRTF\n");
	scanf("%d",&ch);
	
	switch(ch)
	{
		case 1:printf("enter the quantumtime:");
			scanf("%d",&time_quantum);
			remain=n;
			printf("processid|turnaround|waiting time\n");
			for(time=0,count=0;remain!=0;)
			{
				if(rt[count]<=time_quantum && rt[count]>0)
				{
					time+=rt[count];
					rt[count]=0;
					flag=1;
				}
				else if(rt[count]>0)
				{
					time=time+time_quantum;
					rt[count]-=time_quantum;
				}
				
				//to print the sequence
				if(rt[count]==0 && flag==1)
				{
					remain--;
					printf("p[%d]\t|\t%d\t|\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
					wait_time+=time-at[count]-bt[count];
					turnaround_time+=time-at[count];
					flag=0;
				}
				
				//till here
				if(count==n-1)
					count=0;
				else if(at[count+1]<=time)
					count++;
				else
					count=0;
			}
				printf("\n average waiting time=%.2f\n",wait_time*1.0/n);
				printf("\n average turnaround time=%.2f\n",turnaround_time*1.0/n);
				break;
		case 2:
			remain=0;
			printf("\n process|turnaroundtime|waiting time\n");
			rt[9]=9999;
			for(time=0;remain!=n;time++)
			{
					smallest=9;
					for(i=0;i<n;i++)
						if(at[i]<=time && rt[i]<rt[smallest] && rt[i]>0)
							smallest=i;
	
					rt[smallest]--;
					if(rt[smallest]==0)
					{
						remain++;
						endtime=time+1;
						printf("\n p[%d]\t|\t%d\t|\t%d",smallest+1,endtime-at[smallest],endtime-bt[smallest]-at[smallest]);
						printf("\n");
						sum_wait+=endtime-bt[smallest]-at[smallest];
						sum_turnaround+=endtime-at[smallest];
					}
			}

				printf("\n average waiting time=%f\n",sum_wait*1.0/n);
				printf("\n average turnaround time=%f\n",sum_turnaround*1.0/n);
				break;
		
		default:
			printf("invalid\n");
	}
	return 0;
}
