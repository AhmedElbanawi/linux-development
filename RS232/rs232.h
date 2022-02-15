/*
* author: ahmed elsayed elbanawi
* Data: 15/2/2022
* Title: Rs232 Desktop App
*/
#ifndef RS232_H
#define RS232_H
int
open_port(char* myport);
void
cfg_port(int fd, char* BRATE);
#endif
