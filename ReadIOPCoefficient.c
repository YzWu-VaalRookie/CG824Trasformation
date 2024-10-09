#include <stdio.h>
#include <stdlib.h>

void ReadIPCoefficient(char *IPtxtfilename, char IPbmpfilename[], char OPbmpfilename[])
{
	FILE *fin;
	fin = fopen(IPtxtfilename, "r+");
	while(fin == NULL)
	{
		printf("%s is no exist.\n", IPtxtfilename);
		printf("Input IOPtxt file name:\n");
		scanf("%s\n", &IPtxtfilename);
		fin = fopen(IPtxtfilename, "r+");
	}
	
	char buffer[350];
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n", IPbmpfilename); //BMP Input filename
	
	fgets(buffer, 350, fin);
	fscanf(fin, "%s\n", OPbmpfilename); //BMP Output filename
	
	fclose(fin);
}
