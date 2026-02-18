#include<stdio.h>
#include<sys/stat.h>
#include<dirent.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	char d[100];
	int c,op;
	DIR *e;
	struct dirent *sd;
	printf("**MENU**\n 1.Create Directory\n 2.Remove Directory \n 3.Read Directory\n 4.Enter your Choice");
	scanf("%d",&op);
	
	switch(op) {
		case 1:
			printf("Enter Directory Name: ");
			scanf("%s",d);
			c=mkdir(d,0777);
			if(c==-1)
				printf("Directory not created\n");
			else 
				printf("Directory created.");
			break;
		case 2:
			printf("Enter Directory Name: ");
			scanf("%s",d);
			c=rmdir(d);
			if(c==-1)
				printf("Directory not Removed\n");
			else 
				printf("Directory Removed.\n");
			break;
		case 3:
			printf("Enter Directory Name to open:");
			scanf("%s",d);
			e=opendir(d);
			if(e==NULL)
				printf("Directory does not exist\n");
			else{ 
				printf("Directory constents:\n");
				while((sd=readdir(e))!= NULL)
					printf("%s\t", sd->d_name);
					closedir(e);
			}
			break;
		default:
			printf("Invalid Choice\n");
	}
	return 0;
}
