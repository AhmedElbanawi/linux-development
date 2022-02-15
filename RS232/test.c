/*
* author: ahmed elsayed elbanawi
* Data: 15/2/2022
* Title: Testing Rs232 Desktop App 
*/
#include <stdio.h>
#include <unistd.h>
#include "rs232.h"
int
main(int argn, char**argv)
{
	char bff[10];
	int fd = open_port(argv[1]), bytes = 0;
	cfg_port(fd, argv[2]);
	while(1)
	{
		bytes = read(fd, bff, 5);
		if(5 == bytes)
		{
			bff[4] = '\0';
			printf("Voltage in mv = %s\n", bff);
		}else
		{
			printf("errror\n");
		}
		
	}
	
	// Close the port(s) 
	close(fd);
	return(0);
}
