#include "stdio.h"
#include "math.h"

#define DATA_TYPE int

DATA_TYPE data[] = { -1, -2, -5, -4, -4 };

#define DATA data
#define DATA_LEN (sizeof( DATA ) / sizeof(0[ DATA ]))
#define BYTE_COUNT_AFTER_POINT (sizeof(0[ DATA ]) / 2)
#define BIT_COUNT_AFTER_POINT (8 * BYTE_COUNT_AFTER_POINT)
#define POINT_CONTINUE ((DATA_TYPE)ceil(pow(2, (double)BIT_COUNT_AFTER_POINT)))
#define AFTER_POINT_MASK ((long long int)POINT_CONTINUE - 1)
#define DECIMAL_DIGIT_COUNT_AFTER_POINT ((DATA_TYPE)ceil(log10((double)AFTER_POINT_MASK)))
#define DECIMAL_DIGIT_SHIFT_AFTER_POINT ((DATA_TYPE)floor(pow(10, (double)DECIMAL_DIGIT_COUNT_AFTER_POINT)))

int main() {
	const DATA_TYPE point_continue = POINT_CONTINUE;
	const DATA_TYPE after_point_mask = AFTER_POINT_MASK;
	const DATA_TYPE decimal_digit_shift_after_point = DECIMAL_DIGIT_SHIFT_AFTER_POINT / 10 + 1;

	// I - set point
	for (unsigned int index = 0; index < DATA_LEN; ++index) {
		data[index] <<= BIT_COUNT_AFTER_POINT;
	}

	// II - compute
	DATA_TYPE result = 0;
	char signStr[2] = { '\0', '\0' };
	for (unsigned int index = 0; index < DATA_LEN; ++index) {
		result += data[index];
	}
	if (result < 0) {
		signStr[0] = '-';
		result = -result;
	}
	result /= DATA_LEN;

	// III - output
	printf("%s%lld,%lld\r\n", signStr, (long long int)result / point_continue, (long long int)(result & after_point_mask) * decimal_digit_shift_after_point / point_continue);

	return 0;
}
