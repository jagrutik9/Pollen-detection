#include<stdio.h>
#include<stdlib.h>

int16_t _16bit_unsigned(int lsb, int msb);
float calculate_mtof(float mtof);
float calculate_float(unsigned char byte_array[4]);


int main(void)
{
	int lsb = 12, msb = 2;
    	int serial = 79;
	int16_t data1;
	float data2, x;
    	unsigned char arr[] = {0x10, 0x20, 0x30, 0x40};
    	x = calculate_float(arr);
	data1 = _16bit_unsigned(lsb, msb);
	data2 = calculate_mtof(serial);
	printf("Converted 16_bit unsigned Value: %d\n", data1);
	printf("MTOF Value: %f\n", data2);
	printf("Array to float Value: %f\n", x);
	return 0;
}

int16_t _16bit_unsigned(int lsb, int msb)
{
	int16_t value;
	value = (msb << 8) + lsb;
	return value;
}

float calculate_mtof(float mtof)
{
	float value = mtof / (float)3.0;
	return value;
}

float calculate_float(unsigned char byte_array[4])
{
    	float out;
	out = (byte_array[0] << 24) | (byte_array[1] << 16) | (byte_array[2] << 8) | (byte_array[3]);
	return out;  
}
