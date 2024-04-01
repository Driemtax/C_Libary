#ifndef DECIMALBINARYCONVERTER_H
#define DECIMALBINARYCONVERTER_H

char* DecimalToBinary(int number);
int BinaryToDecimal(char *binNumber);
int calculateBitSize(int number);
void initializeArray(char *binNumber, int size);
char* binaryConcat(char *binNumber, char *fill, int size, int fillSize);
char* formatBinary(char *binNumber, int size);
void printBinary(char *binNumber);

#endif