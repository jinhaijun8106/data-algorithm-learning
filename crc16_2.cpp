/*
* The CRC parameters. Currently configured for CCITT.
* Simply modify these to switch to another CRC Standard.
*/
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
/*
#define POLYNOMIAL          0x8005
#define INITIAL_REMAINDER   0x0000
#define FINAL_XOR_VALUE     0x0000
*/
#define POLYNOMIAL          0x1021
#define INITIAL_REMAINDER   0xFFFF
#define FINAL_XOR_VALUE     0x0000
 
/*
#define POLYNOMIAL          0x1021
#define POLYNOMIAL          0xA001
#define INITIAL_REMAINDER   0xFFFF
#define FINAL_XOR_VALUE     0x0000
*/
 
/*
* The width of the CRC calculation and result.
* Modify the typedef for an 8 or 32-bit CRC standard.
*/
typedef unsigned short width_t;
#define WIDTH (8 * sizeof(width_t))
#define TOPBIT (1 << (WIDTH - 1))
 
/**
 * Initialize the CRC lookup table.
 * This table is used by crcCompute() to make CRC computation faster.
 */
void crcInit(void);
 
/**
 * Compute the CRC checksum of a binary message block.
 * @para message, 用来计算的数据
 * @para nBytes, 数据的长度
 * @note This function expects that crcInit() has been called
 *       first to initialize the CRC lookup table.
 */
width_t crcCompute(unsigned char * message, unsigned int nBytes);

/*
* An array containing the pre-computed intermediate result for each
* possible byte of input. This is used to speed up the computation.
*/
static width_t crcTable[256];
 
/**
 * Initialize the CRC lookup table.
 * This table is used by crcCompute() to make CRC computation faster.
 */
void crcInit(void)
{
    width_t remainder;
    width_t dividend;
    int bit;
    /* Perform binary long division, a bit at a time. */
    for(dividend = 0; dividend < 256; dividend++)
    {
        /* Initialize the remainder.  */
        remainder = dividend << (WIDTH - 8);
        /* Shift and XOR with the polynomial.   */
        for(bit = 0; bit < 8; bit++)
        {
            /* Try to divide the current data bit.  */
            if(remainder & TOPBIT)
            {
                remainder = (remainder << 1) ^ POLYNOMIAL;
            }
            else
            {
                remainder = remainder << 1;
            }
        }
        /* Save the result in the table. */
        crcTable[dividend] = remainder;
	printf("crc table %d: 0x%04x\n", dividend, remainder);
    }
} /* crcInit() */
 
/**
 * Compute the CRC checksum of a binary message block.
 * @para message, 用来计算的数据
 * @para nBytes, 数据的长度
 * @note This function expects that crcInit() has been called
 *       first to initialize the CRC lookup table.
 */
width_t crcCompute(unsigned char * message, unsigned int nBytes)
{
    unsigned int offset;
    unsigned char byte;
    width_t remainder = INITIAL_REMAINDER;
    /* Divide the message by the polynomial, a byte at a time. */
    for( offset = 0; offset < nBytes; offset++)
    {
        byte = (remainder >> (WIDTH - 8)) ^ message[offset];
        remainder = crcTable[byte] ^ (remainder << 8);
    }
    /* The final remainder is the CRC result. */
    return (remainder ^ FINAL_XOR_VALUE);
} /* crcCompute() */


int main()
{
    unsigned char data1[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unsigned char data2[] = {'5', '6', '7', '8', '9'};
    unsigned char data3[] = {0x33, 0x44};
    unsigned short c1, c2,c3;
    crcInit();

    c1 = crcCompute(data1, 9);
    c2 = crcCompute(data1, 4);
    c3 = crcCompute(data3, 2);
    printf("%04x\n", c1);
    printf("%04x\n", c2);
    printf("%04x\n", c3);

   return 0;
}
