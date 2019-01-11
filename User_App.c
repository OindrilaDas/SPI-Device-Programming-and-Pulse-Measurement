#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <linux/input.h>
#include <sys/ioctl.h>
#include <poll.h>
#include <pthread.h>
#include <fcntl.h>
#include <linux/types.h>
#include <stdint.h>
#include <inttypes.h>
#include <linux/spi/spidev.h>
#include "rdtsc.h"


int speed=0;
int timeout_flag = 0;
pthread_mutex_t lock;

void IO_init()
{
	printf("Initialising GPIOs\n");
 // Exporting the GPIOs
     int FdExport;
     FdExport = open("/sys/class/gpio/export", O_WRONLY);
     if(FdExport < 0)
            {
                printf("gpio export open failed \n");
            }
             
             
 	 // Exporting IO2 pins
 	 
 	 if(write(FdExport,"77",2)<0)
       {
            printf("error in exporting gpio77\n");
       }
   
   if(write(FdExport,"13",2)<0)
       {
            printf("error in exporting gpio13\n");
        }
    if(write(FdExport,"34",2)<0)
       {
            printf("error in exporting gpio34\n");
        }
    
    // Exporting IO3 pins
    if(write(FdExport,"16",2)<0)
       {
            printf("error in exporting gpio16\n");
        }
    if(write(FdExport,"14",2)<0)
       {
            printf("error in exporting gpio14\n");
        }
    if(write(FdExport,"76",2)<0)
       {
            printf("error in exporting gpio76\n");
        }
    if(write(FdExport,"64",2)<0)
       {
            printf("error in exporting gpio64\n");
        }
      
    // Giving direction to GPIOs for IO2
    int FdDir;
    FdDir = open("/sys/class/gpio/gpio13/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio13 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio13 direction\n");
        }
    
     FdDir = open("/sys/class/gpio/gpio34/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio34 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio34 direction\n");
        }
        
    
    // Giving direction to GPIOs for IO3
    
        
    FdDir = open("/sys/class/gpio/gpio16/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio16 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio16 direction\n");
        }

       
    FdDir = open("/sys/class/gpio/gpio14/direction", O_WRONLY | O_RDONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio14 direction open failed \n");
        }
    if(write(FdDir,"in",2)<0)       //Setting direction to in
        {
            printf("ERROR in writing to gpio14 direction\n");
        }
          
          
    // Setting values of GPIOs
    
    //setting values to GPIO pins of IO2
    int FdValue;
        
    FdValue = open("/sys/class/gpio/gpio77/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio77 value open failed \n");
    }
            
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio77 value\n");
    }
    
    
    FdValue = open("/sys/class/gpio/gpio34/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio34 value open failed \n");
    }
            
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio34 value\n");
    }
     
     
        FdValue = open("/sys/class/gpio/gpio13/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio13 value open failed \n");
    }
            
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio13 value\n");
    }
    
    
    
    
    //setting values for IO3
    
        FdValue = open("/sys/class/gpio/gpio64/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio64 value open failed \n");
    }
            
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio64 value\n");
    }
    
    
        FdValue = open("/sys/class/gpio/gpio76/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio76 value open failed \n");
    }
            
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio76 value\n");
    } 
    
        FdValue = open("/sys/class/gpio/gpio16/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio16 value open failed \n");
    }
            
    if(write(FdValue,"1",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio16 value\n");
    }
    printf("Initialising GPIOs\n");

     /* Initialising IO11, IO12 and IO13 */
   
     FdExport = open("/sys/class/gpio/export", O_WRONLY);
     if(FdExport < 0)
            {
                printf("gpio export open failed \n");
             }
           
           
      // Exporting IO11 pins
     
      if(write(FdExport,"24",2)<0)
       {
            printf("error in exporting gpio24\n");
       }
     
    if(write(FdExport,"44",2)<0)
       {
            printf("error in exporting gpio44\n");
       }
     
    if(write(FdExport,"72",2)<0)
       {
            printf("error in exporting gpio72\n");
       }
 
   // Exporting IO12 pins
     
      if(write(FdExport,"15",2)<0)
       {
            printf("error in exporting gpio15\n");
       }
     
    if(write(FdExport,"42",2)<0)
       {
            printf("error in exporting gpio42\n");
       }
     
  
   // Exporting IO13 pins
     
      if(write(FdExport,"30",2)<0)
       {
            printf("error in exporting gpio30\n");
       }
     
    if(write(FdExport,"46",2)<0)
       {
            printf("error in exporting gpio46\n");
       }
     
   // Giving direction to GPIOs for IO11
 

    FdDir = open("/sys/class/gpio/gpio44/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio44 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio44 direction\n");
        }
      
    FdDir = open("/sys/class/gpio/gpio24/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio24 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio24 direction\n");
        }
      
    // Giving direction to GPIOs for IO12
 
    FdDir = open("/sys/class/gpio/gpio15/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio15 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio15 direction\n");
        }
      
    FdDir = open("/sys/class/gpio/gpio42/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio42 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio42 direction\n");
        }
      
    // Giving direction to GPIOs for IO13
 
  
    FdDir = open("/sys/class/gpio/gpio30/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio30 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio30 direction\n");
        }
      
    FdDir = open("/sys/class/gpio/gpio46/direction", O_WRONLY);
    if(FdDir<0)
        {
            printf("ERROR: gpio46 direction open failed \n");
        }
    if(write(FdDir,"out",3)<0)       //Setting direction to out
        {
            printf("ERROR in writing to gpio46 direction\n");
        }
      
    //setting values to GPIO pins of IO11
      
    FdValue = open("/sys/class/gpio/gpio72/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio72 value open failed \n");
    }
          
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio72 value\n");
    }
  
    FdValue = open("/sys/class/gpio/gpio44/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio44 value open failed \n");
    }
          
    if(write(FdValue,"1",1)<0)  // Sets value to 1
    {
     printf("ERROR in writing gpio44 value\n");
    }
  
    FdValue = open("/sys/class/gpio/gpio24/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio24 value open failed \n");
    }
          
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio24 value\n");
    }
  
    //setting values to GPIO pins of IO12
  
      
    FdValue = open("/sys/class/gpio/gpio42/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio42 value open failed \n");
    }
          
    if(write(FdValue,"0",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio42 value\n");
    }
  
    FdValue = open("/sys/class/gpio/gpio15/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio15 value open failed \n");
    }
          
    if(write(FdValue,"0",1)<0)  // Sets value to 1
    {
     printf("ERROR in writing gpio15 value\n");
    }
  
    //setting values to GPIO pins of IO13
  
      
    FdValue = open("/sys/class/gpio/gpio46/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio46 value open failed \n");
    }
          
    if(write(FdValue,"1",1)<0)  // Sets value to 0
    {
     printf("ERROR in writing gpio46 value\n");
    }
  
    FdValue = open("/sys/class/gpio/gpio30/value", O_WRONLY);
    if(FdValue<0)
    {
    printf("ERROR: gpio30 value open failed \n");
    }
          
    if(write(FdValue,"0",1)<0)  // Sets value to 1
    {
     printf("ERROR in writing gpio30 value\n");
    }
    close(FdExport);
  
 
}

void IO_unexport()
{
	 /* Initialising IO2, IO3, IO11, IO12 and IO13 */
   int FdUnexport;
     FdUnexport = open("/sys/class/gpio/unexport", O_WRONLY);
     if(FdUnexport < 0)
            {
                printf("gpio export open failed \n");
             }
           
           
      // Unexporting IO11 pins
     
      if(write(FdUnexport,"24",2)<0)
       {
            printf("error in exporting gpio24\n");
       }
     
    if(write(FdUnexport,"44",2)<0)
       {
            printf("error in exporting gpio44\n");
       }
     
    if(write(FdUnexport,"72",2)<0)
       {
            printf("error in exporting gpio72\n");
       }
 
   // Unexporting IO12 pins
     
      if(write(FdUnexport,"15",2)<0)
       {
            printf("error in exporting gpio15\n");
       }
     
    if(write(FdUnexport,"42",2)<0)
       {
            printf("error in exporting gpio42\n");
       }
     
  
   // Unexporting IO13 pins
     
      if(write(FdUnexport,"30",2)<0)
       {
            printf("error in exporting gpio30\n");
       }
     
    if(write(FdUnexport,"46",2)<0)
       {
            printf("error in exporting gpio46\n");
       }
       
    // Unexporting IO2 pins
     
      if(write(FdUnexport,"77",2)<0)
       {
            printf("error in exporting gpio77\n");
       }
     
    if(write(FdUnexport,"13",2)<0)
       {
            printf("error in exporting gpio13\n");
       }
     
    if(write(FdUnexport,"34",2)<0)
       {
            printf("error in exporting gpio34\n");
       }
       
    // Unexporting IO3 pins
     
      if(write(FdUnexport,"16",2)<0)
       {
            printf("error in exporting gpio16\n");
       }
     
    if(write(FdUnexport,"14",2)<0)
       {
            printf("error in exporting gpio14\n");
       }
     
    if(write(FdUnexport,"76",2)<0)
       {
            printf("error in exporting gpio76\n");
       }
     
    if(write(FdUnexport,"64",2)<0)
       {
            printf("error in exporting gpio64\n");
       }
    close(FdUnexport);
}


typedef struct 
{
	uint8_t led [16];

}Pattern;


	

/*// Bird Flying pattern*/
/*	Pattern Bird_Left_1={*/
/*		{	*/
/*			0x01, 0x00, // Pattern bytes*/
/*			0x02, 0x00,	*/
/*			0x03, 0x92,*/
/*			0x04, 0x7C,*/
/*			0x05, 0x38,*/
/*			0x06, 0x38,*/
/*			0x07, 0x10,*/
/*			0x08, 0x00,*/
/*		}*/
/*	};*/

/*        Pattern Bird_Left_2={*/
/*		{	*/
/*			0x01, 0x00, // Pattern bytes*/
/*			0x02, 0x00,	*/
/*			0x03, 0x10,*/
/*			0x04, 0x7C,*/
/*			0x05, 0xDA,*/
/*			0x06, 0x38,*/
/*			0x07, 0x10,*/
/*			0x08, 0x00,*/
/*		}*/
/*	};*/

/*	Pattern Bird_Right_1={*/
/*		{	*/
/*			0x01, 0x00, // Pattern bytes*/
/*			0x02, 0x10,	*/
/*			0x03, 0x38,*/
/*			0x04, 0x38,*/
/*			0x05, 0x7C,*/
/*			0x06, 0x92,*/
/*			0x07, 0x00,*/
/*			0x08, 0x00,*/
/*		}*/
/*	};*/

/*	Pattern Bird_Right_2={*/
/*		{	*/
/*			0x01, 0x00, // Pattern bytes*/
/*			0x02, 0x10,	*/
/*			0x03, 0x38,*/
/*			0x04, 0xBA,*/
/*			0x05, 0x7C,*/
/*			0x06, 0x10,*/
/*			0x07, 0x00,*/
/*			0x08, 0x00,*/
/*		}*/
/*	};*/

   // Patterns for Distance 550-750
	Pattern P1_1={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x00,	
			0x03, 0x9D,
			0x04, 0x89,
			0x05, 0x00,
			0x06, 0x00,
			0x07, 0x81,
			0x08, 0x81,
		}
	};
	
	Pattern P1_2={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x9D,
			0x04, 0x08,
			0x05, 0x00,
			0x06, 0x81,
			0x07, 0x81,
			0x08, 0x00,
		}
	};
	
	Pattern P1_3={
		{	
			0x01, 0x81, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x1C,
			0x04, 0x08,
			0x05, 0x81,
			0x06, 0x81,
			0x07, 0x00,
			0x08, 0x00,
		}
	};
	
	// Patterns for Distance 350-550
	Pattern P2_1={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x00,	
			0x03, 0x81,
			0x04, 0xB9,
			0x05, 0x10,
			0x06, 0x00,
			0x07, 0x81,
			0x08, 0x81,
		}
	};
	
	Pattern P2_2={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x81,
			0x04, 0x38,
			0x05, 0x10,
			0x06, 0x81,
			0x07, 0x81,
			0x08, 0x00,
		}
	};
	
	Pattern P2_3={
		{	
			0x01, 0x81, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x00,
			0x04, 0x38,
			0x05, 0x91,
			0x06, 0x81,
			0x07, 0x00,
			0x08, 0x00,
		}
	};
	
	// Patterns for Distance 150-350
	Pattern P3_1={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x00,	
			0x03, 0x81,
			0x04, 0x81,
			0x05, 0x70,
			0x06, 0x20,
			0x07, 0x81,
			0x08, 0x81,
		}
		
	};
	
	Pattern P3_2={
		{	
			0x01, 0x00, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x81,
			0x04, 0x00,
			0x05, 0x70,
			0x06, 0xA1,
			0x07, 0x81,
			0x08, 0x00,
		}
	};
	
	Pattern P3_3={
		{	
			0x01, 0x81, // Pattern bytes
			0x02, 0x81,	
			0x03, 0x00,
			0x04, 0x00,
			0x05, 0xF1,
			0x06, 0xA1,
			0x07, 0x00,
			0x08, 0x00,
		}
	};
	
	Pattern P4_1={
		{	
			0x01, 0x81, // Pattern bytes
			0x02, 0x00,	
			0x03, 0x20,
			0x04, 0x81,
			0x05, 0x91,
			0x06, 0x00,
			0x07, 0x50,
			0x08, 0x81,
		}
	};
	
	

 // Echo input detect function
 
 void *echo_input_det()
 {
     long double start_time=0, end_time=0, time_diff=0;
     int dist1=0;
     //printf("Echo Detection Thread running\n");
     int fd_echo,fdEdge, Fdtrig;
     struct pollfd PollEch;
     unsigned char ReadValue;
   
     fd_echo = open("/sys/class/gpio/gpio14/value", O_RDONLY);
     fdEdge = open("/sys/class/gpio/gpio14/edge", O_WRONLY | O_RDONLY);
     Fdtrig = open("/sys/class/gpio/gpio13/value", O_WRONLY);
  
      
     // Prepare poll fd structure
        PollEch.fd = fd_echo;
        PollEch.events = POLLPRI|POLLERR;
        PollEch.revents = 0;
        
        
      write(fdEdge,"falling",7);  // Sets edge to rising
      
      while(!timeout_flag)
      {
       // Start polling for rising edge at echo
       
       
       lseek(PollEch.fd, 0, SEEK_SET);
       read(PollEch.fd,&ReadValue,1);
      
       
       //sending trigger pulse

       write(Fdtrig,"1",1);  // trigger
       usleep(12);  
       write(Fdtrig,"0",1);
       start_time = rdtsc();
       
       
           	
         	// Detecting Falling edge and capturing end time

            int poll_ret = poll(&PollEch,1,1000);
            
            if(poll_ret<0)
            {
            printf("error in polling for falling edge");
            }
            else if(poll_ret==0)
            {
            printf("faling egde polling timeout ");
            }
            else 
            {
            	if (PollEch.revents & POLLPRI)
            	{
            	
                	end_time = rdtsc();

                	time_diff = (end_time-start_time);

                	dist1=(time_diff)*(7.5/20000);
                	printf("Distance: %d\n", dist1);
                	if(dist1<150)
                		dist1=150;
                	else if(dist1>750)
                		dist1=750;
                	pthread_mutex_lock(&lock);
                	speed = dist1;				//calculating speed factor for animation
                	pthread_mutex_unlock(&lock);
                }
				}
					

	usleep(100000);
   }
     
   pthread_exit(0);
 }
 

void Display_LEDMatrix_init()
{
    int FdLed, FdCS;
    unsigned char init_Message[2] ={0};   
    struct spi_ioc_transfer spi_message = {
        .tx_buf = (unsigned long)init_Message,
        .rx_buf = 0,
        .len = 2,
        .speed_hz = 500000,
        .cs_change = 1,
        .bits_per_word = 8,
        };





// ----------------------------------------
FdCS = open("/sys/class/gpio/gpio15/value", O_WRONLY);

FdLed = open("/dev/spidev1.0",O_WRONLY);
    if (FdLed < 0)
    {
        printf("\n LED driver open failed");
    }

    printf("Testing 8x8 Led matrix\n");

write(FdCS, "0", 2);
 /* Test display */
    init_Message[0] = 0x0F;
    init_Message[1] = 0x01;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);
write(FdCS, "0", 2);
    init_Message[0] = 0x0F;
    init_Message[1] = 0x00;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);
    /* Select No decode */
write(FdCS, "0", 2);
    init_Message[0] = 0x09;
    init_Message[1] = 0x00;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);
    /* intensity level medium */
write(FdCS, "0", 2);
    init_Message[0] = 0x0A;
    init_Message[1] = 0x01;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);
    /* scan all the data register for displaying */
write(FdCS, "0", 2);
    init_Message[0] = 0x0B;
    init_Message[1] = 0x07;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);
    /* shutdown register - select normal operation */
write(FdCS, "0", 2);
    init_Message[0] = 0x0C;
    init_Message[1] = 0x01;
    ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
write(FdCS, "1", 2);
    usleep(10000);

	// clear the display 

    int i=0;
    for(i = 1; i < 9; i++)
    {
       write(FdCS, "0", 2);
       init_Message[0] = i;
       init_Message[1] = 0;
       ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
       write(FdCS, "1", 2);
       usleep(10000);
       
    }
   
   
}



void* Display_LEDMatrix()
{
	printf("Speed:%d\n", speed);
   int flag = 0;
	uint8_t init_Message[2] ={0};   
	                        
    	struct spi_ioc_transfer spi_message = {
		.tx_buf = (unsigned long)init_Message,
		.rx_buf = 0,
		.len = 2,
		.speed_hz = 500000,
		.bits_per_word = 8,
		.cs_change = 1,
		};
	int FdCS = open("/sys/class/gpio/gpio15/value",O_WRONLY);
	int  i = 0;
	int ret;
	int FdLed = open("/dev/spidev1.0",O_WRONLY);

	while(!timeout_flag)
	{   
		
		if(flag==1)
		{
			goto CONTINUE1;
		}
		// Range 3
		if(speed <= 750 && speed > 550)
		{
		// Pattern P1_1
		for(i=0; i<16; i=i+2)													
		{ 
			init_Message[0] = P1_1.led[i];
			init_Message[1] = P1_1.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(100*speed);
		
		// Pattern P1_2
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P1_2.led[i];
			init_Message[1] = P1_2.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(100*speed);
		
		// Pattern P1_3
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P1_3.led[i];
			init_Message[1] = P1_3.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(100*speed);
		
		}

		
		// Range 2
		else if(speed <= 550 && speed > 350)
		{
		// Pattern P2_1
		for(i=0; i<16; i=i+2)													
		{ 
			init_Message[0] = P2_1.led[i];
			init_Message[1] = P2_1.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(75*speed);
		
		// Pattern P2_2
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P2_2.led[i];
			init_Message[1] = P2_2.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(10000);
		}
		usleep(75*speed);
		
		// Pattern P2_3
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P2_3.led[i];
			init_Message[1] = P2_3.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(75*speed);
		
		}
		
		// Range 1
	CONTINUE1:	
		if(speed <= 350 && speed > 175)
		{
			flag = 0;
		// Pattern P3_1
		for(i=0; i<16; i=i+2)													
		{ 
			init_Message[0] = P3_1.led[i];
			init_Message[1] = P3_1.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(50*speed);
		
		// Pattern P3_2
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P3_2.led[i];
			init_Message[1] = P3_2.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(50*speed);
		
		// Pattern P3_3
		for(i=0; i<16; i=i+2)													
		{
			init_Message[0] = P3_3.led[i];
			init_Message[1] = P3_3.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		usleep(50*speed);
		
		// Pattern P4_1
		if(speed<=175 && speed>=150)
		{ 
		for(i=0; i<16; i=i+2)													
		{
		   flag = 1;
			init_Message[0] = P4_1.led[i];
			init_Message[1] = P4_1.led[i+1];
			
			if(0>write(FdCS,"0",1))                   // CS low to select LED matrix
				printf("\nError in setting chip select to 0");
			
			ret = ioctl(FdLed,SPI_IOC_MESSAGE(1), &spi_message);
			if(ret<0)
				printf("\n error while writing less than 450");
			
			if(0> write(FdCS,"1",1))                 // CS high to latch data
				printf("\nError in setting chip select to 1");
	 		usleep(1000);
		}
		}
		usleep(50*speed);
		
		}


	}
	pthread_exit(0);	
}


int main()
{
    IO_init();										//GPIOs initialization
    Display_LEDMatrix_init();					//initialize control registers
    pthread_t tid_1;
    pthread_create(&tid_1,NULL,echo_input_det,NULL);
    pthread_t tid_2;
    pthread_create(&tid_2,NULL,Display_LEDMatrix,NULL);
    sleep(80);
    timeout_flag = 1;
    pthread_join(tid_1,NULL);
    pthread_join(tid_2,NULL);
    printf("\nExiting the Program\n");
 	 IO_unexport();	
        return 0;
}
