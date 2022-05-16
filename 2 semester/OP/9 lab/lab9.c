/* Дано длинное целое неотрицательное число.
Получить число, инвертируя его четные биты. */
// >C99
#include <stdio.h>
#include <stdbool.h>
#include <inttypes.h>

uint8_t SIZE_BYTES = 32;
uint32_t x = 0;

#define max_uint64_t 18446744073709551615 + 1

void binToDec(uint64_t x) {
    uint64_t mask = 9223372036854775808;
    //1000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000 0000
    while (mask > 0) {
	if ((x & mask) == 0)
	    printf("0");
	else
	    printf("1");
	mask = mask >> 1;
    }
}
int main() {
    printf("[>] Enter source digit: ");
    scanf("%" SCNu32 "", &x);
    printf("[>] Your source digit in binary: \t");
    //binToDec(x, SIZE_BYTES);
    binToDec(x);
    printf("\n");
    x ^= 0x555555555555; // xor, 0101 in binary
    printf("[>] Your inverted digit: %" PRIu32 "\n", x);
    printf("[>] Your inverted digit in binary: \t");
    binToDec(x);
    printf("\n");
}
