#include<stdio.h>
void main(){
	char p[10][10];
	int bt[10],wt[10],tat[10],twt,ttat,n,i;
	float awt,atat;
	printf("Enter the no. of process ready to be exectued: ");
	scanf("%d",&n);
	for(i=0; i<n; i++){
		printf("\nEnter the process Name: ");
		scanf("%s",&p[i]);
		printf("\nEnter the bt.: ");
		scanf("%d",&bt[i]);
	}
	wt[0] =0;
	twt = 0;
	tat[0] = bt[0];
	ttat = bt[0];
	for(i=1; i<n; i++){
		wt[i] = wt[i-1]+bt[i-1];
		twt = twt+wt[i];
		tat[i] = wt[i]+bt[i];
		ttat = ttat+bt[i];
	}
	awt = (float)twt/n;
	atat = (float) ttat/n;
	printf("\n ProcessName | BurstTime | WaitingTime | TurnAroundTime");
	for(i=0; i<n; i++){
		printf("\n%s\t\t%d\t\t%d\t\t%d\t\t\n",p[i],bt[i],wt[i],tat[i]);
	}
	printf("\nawt = %f",awt);
	printf("\natat = %f\n",atat);
}
	
	
