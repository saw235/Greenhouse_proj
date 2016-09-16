//Written by Saw Xue Zheng

//This program sets up the raspberry pi with gertboard adc
//so that it can read in values fromt the temperature sensor

//Last modified: 8/20/2016 1:03 AM
#include "gb_common.h"
#include "gb_spi.h"
#include <stdio.h>


void setup_gpio()
{
   INP_GPIO(8);  SET_GPIO_ALT(8,0);
   INP_GPIO(9);  SET_GPIO_ALT(9,0);
   INP_GPIO(10); SET_GPIO_ALT(10,0);
   INP_GPIO(11); SET_GPIO_ALT(11,0);
} 



int main()
{ 
	
  
  double v, chan;

  chan = 0;

  FILE* pFile;
  
  pFile = fopen("temp_readings.txt", "w");


  // Map the I/O sections
  setup_io();

  // activate SPI bus pins
  setup_gpio();

  // Setup SPI bus
  setup_spi();

    v= read_adc(chan);

    //printf("%04f ",v);
    v = (v*3.3)/1024.0;

    //convert voltage to celcius
    double temp;
    temp = (v-0.5)*100;
    
    //prints the value to stdout at 4 decimal places precision
    printf("%04f ",temp);

    //writes to file
    fprintf(pFile, "%04f\n", temp);
   
    //closefile
    fclose(pFile);
	
	restore_io();
	return 0;
} 
