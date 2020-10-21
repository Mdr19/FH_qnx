#pragma once
typedef struct data_struct data_struct;

struct data_struct {
	double test;
	double test_2;
	unsigned int signals_len;
	double* input_signal_1;
	double* input_signal_2;
	double* output_signal;
};

data_struct* DATA_STR_create(unsigned int capacity);
void DATA_STR_free(data_struct*);
int DATA_STR_init_random(data_struct* str);
void DATA_STR_print(data_struct* str);
data_struct* DATA_STR_copy(const data_struct* original_str);
