// Program by Saw Xue Zheng

// This program is intended to test out the
// capabilities of command line arguments of c programs

#include <stdio.h> //for printf()
#include <stdlib.h> //for atoi()

void main(int argc, char *argv[])
{
	//if argument count is not 4, including filename 
	//then exit program with message
	if (argc != 4)
	{
	
         printf("Arguments must be 3\n");
	return;
	}
	
	//if not then store arguments in variables
	//and print out the sum
	int a = atoi(argv[1]);
	int b = atoi(argv[2]);
	int c = atoi(argv[3]);

	int d = a + b + c;
	
	printf("a+b+c is %d\n",d);

	//exit program
	return;
}
