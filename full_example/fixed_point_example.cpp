#include "stdio.h"
#include "math.h"

int data[] = { -1, -2, -5, -4, -4 }, result;

#define DATA data
#define DATA_LEN (sizeof( DATA ) / sizeof(0[ DATA ]))
#define BYTE_COUNT_AFTER_POINT (sizeof(0[ DATA ]) / 2)
#define BIT_COUNT_AFTER_POINT (8 * BYTE_COUNT_AFTER_POINT)
#define POINT_CONTINUE ((long long int)ceil(pow(2, (double)BIT_COUNT_AFTER_POINT)))
#define AFTER_POINT_MASK ((long long int)POINT_CONTINUE - 1)
#define DECIMAL_DIGIT_COUNT_AFTER_POINT ((long long int)ceil(log10((double)AFTER_POINT_MASK)))
#define DECIMAL_DIGIT_SHIFT_AFTER_POINT ((long long int)floor(pow(10, (double)DECIMAL_DIGIT_COUNT_AFTER_POINT)))

int main() {
	const long long int bit_count_after_point = BIT_COUNT_AFTER_POINT;
	//const long long int point_continue = POINT_CONTINUE;
	const long long int after_point_mask = AFTER_POINT_MASK;
	const long long int decimal_digit_shift_after_point = DECIMAL_DIGIT_SHIFT_AFTER_POINT / 10 + 1;

	// I - set point
	for (unsigned int index = 0; index < DATA_LEN; ++index) {
		data[index] <<= bit_count_after_point;
	}

	// II - compute
	//DATA_TYPE result = 0;
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
	printf("%s%lld,%lld\r\n", signStr, (long long int)(result >> bit_count_after_point), (long long int)((result & after_point_mask) * decimal_digit_shift_after_point >> bit_count_after_point));
	//printf("%s%lld,%lld\r\n", signStr, (long long int)result / point_continue, (long long int)(result & after_point_mask) * decimal_digit_shift_after_point / point_continue);

	return 0;
}