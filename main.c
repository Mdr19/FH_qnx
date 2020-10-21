#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdlib.h>
#include <stdio.h>


// Need to link with Ws2_32.lib, Mswsock.lib, and Advapi32.lib
#pragma comment (lib, "Ws2_32.lib")
#pragma comment (lib, "Mswsock.lib")
#pragma comment (lib, "AdvApi32.lib")


// moje

#include "cyclic_buffer.h";
#include "data_struct.h";

void fnc_float(float a) 
{
	printf("Display float %f \n", a);
}


int __cdecl main(int argc, char** argv)
{
	data_struct* str_1, *str_2, *str_3;
	data_struct* str_[15];

	//nc_float(1.2);

	int testowy = 2.3;

	str_3 = DATA_STR_create(5);
	DATA_STR_init_selected_number(str_3, 3.0);

	printf("My val: %f My val 2: %lf \n", str_3->input_signal_1[0], str_3->test);

	DATA_STR_print(str_3);

	for (int i = 0; i < 15; i++) 
	{
		str_[i] = DATA_STR_create(5);
		DATA_STR_init_selected_number(str_[i], (double)(i+1));
	}

	printf("------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------\n");
	for (int i = 0; i < 15; i++)
	{
		printf("STRUCTURE NR ---%d---\n", i);
		DATA_STR_print(str_[i]);
	}
	printf("------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------\n");


	cyclic_buffer* buffer1;
	buffer1 = BUFF_create(10);
	
	for (int i = 0; i < 8; i++)
	{
		BUFF_add(buffer1, str_[i]);
	}

	
	BUFF_display(buffer1);

	printf("------------------------------------------------------------------\n");
	printf("------------------------------------------------------------------\n");

	for (int i = 8; i < 15; i++)
	{
		BUFF_add(buffer1, str_[i]);
	}

	BUFF_display(buffer1);
	BUFF_free(&buffer1);


	return 0;
}
