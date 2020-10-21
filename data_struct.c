# include <stdlib.h>
# include <stdio.h>
# include "data_struct.h"

data_struct* DATA_STR_create(unsigned int capacity)
{
	data_struct* str = (data_struct*)malloc(sizeof(data_struct));

	if (str == NULL) {
		printf("Cannot allocate\n");
		return NULL;
	}
	else
	{
		str->signals_len = capacity;
		str->input_signal_1 = (double*)malloc(capacity * sizeof(double));
		str->input_signal_2 = (double*)malloc(capacity * sizeof(double));
		str->output_signal = (double*)malloc(capacity * sizeof(double));

		if ((str->input_signal_1 == NULL) || (str->input_signal_2 == NULL) ||
			(str->output_signal == NULL))
		{
			printf("Cannot allocate signals\n");
			return NULL;
		}
	}

	return str;
}

int DATA_STR_init_random(data_struct* str)
{
	if (str==NULL)
	{
		return -1;
	}
	else {
		
		for (int i = 0; i < str->signals_len; i++)
		{
			str->input_signal_1[i] = rand();
			str->input_signal_2[i] = rand();
			str->output_signal[i] = rand();
		}

		return 0;
	}
}

int DATA_STR_init_selected_number(data_struct* str, double number)
{
	if (str == NULL)
	{
		return -1;
	}
	else {

		str->test = number;
		//str->test_2 = number_2;

		for (int i = 0; i < str->signals_len; i++)
		{
			str->input_signal_1[i] = number;
			str->input_signal_2[i] = number;
			str->output_signal[i] = number;
		}

		//printf("Przypisalem %lf a chcialem %lf drugie przypisanie %lf a chcialem %lf\n", 
		//	str->test, number, str->test_2,number_2);

		return 0;
	}
}


data_struct* DATA_STR_copy(const data_struct* original_str)
{
	if (original_str==NULL)
	{
		return NULL;
	}
	else 
	{
		data_struct* new_str = (data_struct*)malloc(sizeof(data_struct));

		new_str->signals_len = original_str->signals_len;
		
		new_str->input_signal_1 = (double*)malloc(new_str->signals_len * sizeof(double));
		new_str->input_signal_2 = (double*)malloc(new_str->signals_len * sizeof(double));
		new_str->output_signal = (double*)malloc(new_str->signals_len * sizeof(double));

		if ((new_str->input_signal_1 == NULL) || (new_str->input_signal_2 == NULL) ||
			(new_str->output_signal == NULL))
		{
			return NULL;
		}
		else {
			for (int i = 0; i < new_str->signals_len; i++)
			{
				new_str->input_signal_1[i] = original_str->input_signal_1[i];
				new_str->input_signal_2[i] = original_str->input_signal_2[i];
				new_str->output_signal[i] = original_str->input_signal_2[i];

			}
		}

		return new_str;

	}
}


void DATA_STR_print(data_struct* str)
{
	if (str!= NULL)
	{
		printf("Input 1:  Input 2:  Output: \n");

		for (int i = 0; i < str->signals_len; i++)
		{

			printf("%lf, %lf, %lf \n", str->input_signal_1[i], str->input_signal_2[i], str->output_signal[i]);
		}

		//printf("Input 2 signal\n");

		//printf("Output signal\n");

	}
	
}


void DATA_STR_free(data_struct* str)
{
	free(str->input_signal_1);
	free(str->input_signal_2);
	free(str->output_signal);

	free(str);
}