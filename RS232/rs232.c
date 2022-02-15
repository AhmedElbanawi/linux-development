/*
* author: ahmed elsayed elbanawi
* Data: 15/2/2022
* Title: Rs232 Desktop App
*/
#include <stdio.h>   /* Standard input/output definitions */
#include <string.h>  /* String function definitions */
#include <unistd.h>  /* UNIX standard function definitions */
#include <fcntl.h>   /* File control definitions */
#include <errno.h>   /* Error number definitions */
#include <termios.h> /* POSIX terminal control definitions */
#include "rs232.h"
/*
 * 'open_port()' - Open serial port 1.
 *
 * Returns the file descriptor on success or -1 on error.
 */
int
open_port(char* myport)
{
  int fd; /* File descriptor for the port */
  fd = open(myport, O_RDWR | O_NOCTTY | O_NDELAY);
  if (fd == -1)
  {
   /*
    * Could not open the port.
    */

    perror(myport);
  }
  else
    fcntl(fd, F_SETFL, 0);

  return (fd);
}
void 
cfg_port(int fd, char* BRATE)
{
  struct termios options;

/*
 * Get the current options for the port...
 */

tcgetattr(fd, &options);

/*
 * Set the baud rates to 9600...
 */
if(0 == strcmp(BRATE, "9600"))
{
  cfsetispeed(&options, B9600);
  cfsetospeed(&options, B9600);
}else if(0 == strcmp(BRATE, "50"))
{
  cfsetispeed(&options, B50);
  cfsetospeed(&options, B50);
}else if(0 == strcmp(BRATE, "75"))
{
  cfsetispeed(&options, B75);
  cfsetospeed(&options, B75);
}else if(0 == strcmp(BRATE, "110"))
{
  cfsetispeed(&options, B110);
  cfsetospeed(&options, B110);
}else if(0 == strcmp(BRATE, "134"))
{
  cfsetispeed(&options, B134);
  cfsetospeed(&options, B134);
}else if(0 == strcmp(BRATE, "150"))
{
  cfsetispeed(&options, B150);
  cfsetospeed(&options, B150);
}else if(0 == strcmp(BRATE, "200"))
{
  cfsetispeed(&options, B200);
  cfsetospeed(&options, B200);
}else if(0 == strcmp(BRATE, "300"))
{
  cfsetispeed(&options, B300);
  cfsetospeed(&options, B300);
}else if(0 == strcmp(BRATE, "600"))
{
  cfsetispeed(&options, B600);
  cfsetospeed(&options, B600);
}else if(0 == strcmp(BRATE, "1200"))
{
  cfsetispeed(&options, B1200);
  cfsetospeed(&options, B1200);
}else if(0 == strcmp(BRATE, "1800"))
{
  cfsetispeed(&options, B1800);
  cfsetospeed(&options, B1800);
}else if(0 == strcmp(BRATE, "2400"))
{
  cfsetispeed(&options, B2400);
  cfsetospeed(&options, B2400);
}else if(0 == strcmp(BRATE, "4800"))
{
  cfsetispeed(&options, B4800);
  cfsetospeed(&options, B4800);
}else if(0 == strcmp(BRATE, "19200"))
{
  cfsetispeed(&options, B19200);
  cfsetospeed(&options, B19200);
}else if(0 == strcmp(BRATE, "38400"))
{
  cfsetispeed(&options, B38400);
  cfsetospeed(&options, B38400);
}else
{
  printf("RS232 is hung up\n");
  cfsetispeed(&options, B0);
  cfsetospeed(&options, B0);
}


/*
  CREAD: 	Enable receiver
  CLOCAL: Local line - do not change "owner" of port
  PARENB: Enable parity bit
  CSTOPB: 2 stop bits (1 otherwise)
  CSIZE: Bit mask for data bits
  CS8: 8 data bits
*/
options.c_cflag |= (CLOCAL | CREAD);
options.c_cflag &= ~PARENB;
options.c_cflag &= ~CSTOPB;
options.c_cflag &= ~CSIZE;
options.c_cflag |= CS8;
options.c_lflag     &= ~(ICANON | ECHO | ECHOE | ISIG); /*Input characters are passed through exactly as they are received*/
options.c_oflag     &= ~OPOST; /*Postprocess output (not set = raw output)*/
options.c_cc[VMIN]  = 0;
options.c_cc[VTIME] = 10; /*Time Out Options*/
/*
 * Set the new options for the port...
 */

tcsetattr(fd, TCSANOW, &options);
}
