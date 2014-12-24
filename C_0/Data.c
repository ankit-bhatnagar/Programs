#include <stdio.h>
#include <string.h>

int main()
{
	int i;
	char buf[] = "Hello World";
	int arr[100];
	char * bu = "Hello World";
	
	char buff[80];
	
	strcpy(buff,buf);
	
	printf("%s\n",buff);
	printf("Size %d\n",sizeof(bu)); 
	printf("Size %d\n",sizeof(buf));
	printf("Size %d\n",sizeof(buff));
	printf("Size of array %d\n",sizeof(arr));
}
