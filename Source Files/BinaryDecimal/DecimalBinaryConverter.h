#ifndef DECIMALBINARYCONVERTER_H
#define DECIMALBINARYCONVERTER_H

char* DecimalToBinary(int number);
unsigned int BinaryToDecimal_Unsigned(char *binNumber);
int BinaryToDecimal_Signed (char *binNumber);
int calculateBitSize(int number);
void initializeArray(char *binNumber, int size);
char* binaryConcat(char *binNumber, char *fill, int size, int fillSize);
char* formatBinary(char *binNumber, int size);
void printBinary(char *binNumber);

#endif