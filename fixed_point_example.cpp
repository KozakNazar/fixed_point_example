#include "stdio.h"
#include "math.h"

int data[] = { -1, -2, -5, -4, -4 };

#define DATA data
#define DATA_LEN (sizeof( DATA ) / sizeof(0[ DATA ]))
#define BYTE_COUNT_AFTER_POINT (sizeof(0[ DATA ]) / 2)
#define BIT_COUNT_AFTER_POINT (8 * BYTE_COUNT_AFTER_POINT)
#define POINT_CONTINUE ((int)ceil(pow(2, (double)BIT_COUNT_AFTER_POINT)))
#define AFTER_POINT_MASK ((long long int)POINT_CONTINUE - 1)
#define DECIMAL_DIGIT_COUNT_AFTER_POINT ((int)ceil(log10((double)AFTER_POINT_MASK)))
#define DECIMAL_DIGIT_SHIFT_AFTER_POINT ((int)floor(pow(10, (double)DECIMAL_DIGIT_COUNT_AFTER_POINT)))

int main(){
	const int point_continue = POINT_CONTINUE;
	const int after_point_mask = AFTER_POINT_MASK;
	const int decimal_digit_shift_after_point = DECIMAL_DIGIT_SHIFT_AFTER_POINT + 2;

	// I - set point
	for (unsigned int index = 0; index < DATA_LEN; ++index) {
		data[index] <<= BIT_COUNT_AFTER_POINT;
	}

	// II - compute
	int result = 0;
	char signFlag[2] = { '\0', '\0'};
	for (unsigned int index = 0; index < DATA_LEN; ++index){
		result += data[index];
	}
	if (result < 0) {
		signFlag[0] = '-';
		result =- result;
	}
	result /= DATA_LEN;
	
	// III - output
	printf("%s%d,%d\r\n", signFlag, result / point_continue, (result & after_point_mask) * decimal_digit_shift_after_point / point_continue);

	return 0;
}