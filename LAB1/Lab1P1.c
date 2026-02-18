#include<stdio.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>
#include<unistd.h>
int main(){
	int i =0;
	int f1,f2;
	char c, strin[100];
	
	f1= open("data_BHARATHI",O_RDWR | O_CREAT | O_TRUNC, 0777);
	while((c= getchar())!= '\n'){
		strin[i++] = c;
	}
	strin[i] = '\0';
	write(f1, strin, i);
	close(f1);
	
	f2 = open("data_BHARATHI",O_RDONLY);
	read(f2, strin,i);
	strin[i] = '\0';
	printf("\nData read from file:\n%s\n",strin);
	close(f2);
	return 0;
}
