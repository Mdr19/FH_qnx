# include <stdlib.h>
# include <stdio.h>

#include "cyclic_buffer.h"
#include "data_struct.h"

//extern void free_data_struct(data_struct*);


cyclic_buffer* BUFF_create(int max_buffer_size)
{
	cyclic_buffer* buff = malloc(sizeof(cyclic_buffer));

	if (buff == NULL)
	{
		printf("Cyclic buffer cannot be created\n");
		return NULL;
	}
	else
	{
		printf("Cyclic buffer created\n");
		buff->tail = 0;
		buff->head = 0;
		buff->size = 0;
		buff->capacity = max_buffer_size;
		//buff->signals_len = signals_len;
		buff->data = (data_struct*)malloc(buff->capacity * sizeof(data_struct));

		/*
		for (int i = 0; i < buff->capacity; i++)
		{
			buff->data[i]= create_data_struct(buff->signals_len);
			//create_data_struct(buff->data);
		}
		*/
	

		return buff;
	}
}

int BUFF_empty(cyclic_buffer* buff)
{
	if (buff == NULL) {
		return -1;
	}
	else if(buff->size==0){
		return 1;
	}else{
		return 0;
	}
}

int BUFF_full(cyclic_buffer* buff)
{
	if (buff == NULL) {
		return -1;
	}
	else if (buff->size == buff->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}


int BUFF_add(cyclic_buffer* buff, const data_struct* str)
{

	if (buff == NULL) {
		return -1;
	}
	else {

		if (((buff->tail ) % buff->capacity) == buff->head)
		{
			buff->head = (buff->head + 1) % buff->capacity;
		}
	
		buff->data[buff->tail].signals_len = str->signals_len;

		buff->data[buff->tail].input_signal_1 = (double*)malloc(str->signals_len * sizeof(double));
		buff->data[buff->tail].input_signal_2 = (double*)malloc(str->signals_len * sizeof(double));
		buff->data[buff->tail].output_signal = (double*)malloc(str->signals_len * sizeof(double));

		if ((buff->data[buff->tail].input_signal_1 == NULL) || (buff->data[buff->tail].input_signal_2 == NULL) ||
			(buff->data[buff->tail].output_signal == NULL))
		{
			return -2;
		}
		else {
			for (int i = 0; i < str->signals_len; i++)
			{
				buff->data[buff->tail].input_signal_1[i] = str->input_signal_1[i];
				buff->data[buff->tail].input_signal_2[i] = str->input_signal_2[i];
				buff->data[buff->tail].output_signal[i] = str->input_signal_2[i];

			}
		}

		buff->tail = (buff->tail + 1) % buff->capacity;

		if (buff->size < buff->capacity)
		{
			buff->size = buff->size + 1;
		}



		//buff->tail = buff->tail + 1;
		//buff->size = buff->size + 1;
		return 0;
	}
}

void BUFF_display(cyclic_buffer* buff)
{
	printf("Buffer elements: %d \n", buff->size);
	printf("Buffer HEAD: %d \n", buff->head);
	printf("Buffer TAIL: %d \n", buff->tail);


	for (int i = 0; i < buff->size; i++)
	{
		DATA_STR_print(buff->data+i);
	}
}


void BUFF_free(cyclic_buffer* buff) 
{
	unsigned int i = buff->size;

	while (buff->size - i !=NULL) {
		DATA_STR_free(buff->data + i);
		i--;
	}

	/*
	for (unsigned int i = buff->size; i< buff->capacity; i--)
	{
		free_data_struct(buff->data + i);
	}
	*/
	//free(buff->data);
	//free(buff);
}