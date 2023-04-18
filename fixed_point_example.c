#include "stdio.h"
//#include "math.h"

//#define DATA data
//#define DATA_LEN (sizeof( DATA ) / sizeof(0[ DATA ]))
//#define BYTE_COUNT_AFTER_POINT (sizeof(0[ DATA ]) / 2)
//#define BIT_COUNT_AFTER_POINT (8 * BYTE_COUNT_AFTER_POINT)
//#define POINT_CONTINUE ((int)ceil(pow(2, (double)BIT_COUNT_AFTER_POINT)))
//#define AFTER_POINT_MASK ((long long int)POINT_CONTINUE - 1)
//#define DECIMAL_DIGIT_COUNT_AFTER_POINT ((int)ceil(log10((double)AFTER_POINT_MASK)))
//#define DECIMAL_DIGIT_SHIFT_AFTER_POINT ((int)floor(pow(10, (double)DECIMAL_DIGIT_COUNT_AFTER_POINT)))
//#pragma comment(linker, "/INCLUDE:_mainCRTStartup")
int main() {
	int data[] = { -1, -2, -5, -4, -4 };

	const int point_continue = 65536;// POINT_CONTINUE;
	const int after_point_mask = 65535;// AFTER_POINT_MASK;
	const int decimal_digit_shift_after_point = 10001;// DECIMAL_DIGIT_SHIFT_AFTER_POINT / 10 + 1;

	// I - set point
	for (unsigned int index = 0; index < 5; ++index) {
		data[index] <<= 16;// BIT_COUNT_AFTER_POINT;
	}

	// II - compute
	int result = 0;
	char signStr[2] = { '\0', '\0' };
	for (unsigned int index = 0; index < 5; ++index) {
		result += data[index];
	}
	if (result < 0) {
		signStr[0] = '-';
		result = -result;
	}
	result /= 5;

	// III - output
	printf("%s%d,%d\r\n", signStr, result / point_continue, (result & after_point_mask) * decimal_digit_shift_after_point / point_continue);

	return 0;
}