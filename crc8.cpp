#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#define POLY        0x1d
/**
 * Calculating CRC-16 in 'C'
 * @para addr, start of data
 * @para num, length of data
 * @para crc, incoming CRC
 */
uint16_t crc8(unsigned char *addr, int num, uint8_t crc)
{
    int i;
    for (; num > 0; num--)              /* Step through bytes in memory */
    {
        crc = crc ^ (*addr++ << 0);     /* Fetch byte from memory, XOR into CRC top byte*/
        for (i = 0; i < 8; i++)             /* Prepare to rotate 8 bits */
        {
            if (crc & 0x80)            /* b15 is set... */
                crc = (crc << 1) ^ POLY;    /* rotate and XOR with polynomic */
            else                          /* b15 is clear... */
                crc <<= 1;                  /* just rotate */
        }                             /* Loop for 8 bits */
        //rc &= 0xff;                  /* Ensure CRC remains 16-bit value */
    }                               /* Loop until num=0 */
    return(crc);                    /* Return updated CRC */
}

int main()
{
    unsigned char data1[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    unsigned char data2[] = {'5', '6', '7', '8', '9'};
    unsigned char data3[] = {0xc2};
    unsigned char c1, c2,c3;
    c1 = crc8(data1, 9, 0x0);
    c2 = crc8(data1, 4, 0x0);
    c2 = crc8(data2, 5, c2);
    c3 = crc8(data3, 1, 0x00);
    printf("%02x\n", c1);
    printf("%02x\n", c2);
    printf("%02x\n", c3);

   return 0;
}
