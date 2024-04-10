#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int calculateBitSize(int number){
    int bitCount = 0;
    for (int i = 1; i <= number; i = i*2)
    {
        bitCount++;
    }

    return bitCount;
}

void initializeArray(char *binNumber, int size){
    for (int i = 0; i < size; i++)
    {
        binNumber[i] = '0';
    }
    binNumber[size] = '\0';
}

char* DecimalToBinary(int number){
    int size = calculateBitSize(number);

    char *binNumber = (char*)malloc((size+1) * sizeof(char));
            if (binNumber == NULL)
            {
                printf("Critical Error! Memory allocation failed.");
                return "00000000";
            }
            initializeArray(binNumber, size);
    for (int i = size - 1; i >= 0; i--)
    {
        if(number % 2 == 0){
            binNumber[i] = '0';
        }
        else {
            binNumber[i] = '1';
        }
        number = number / 2;
    }

    return binNumber;
}

 unsigned int BinaryToDecimal_Unsigned(char *binNumber) {
    int size = strlen(binNumber);

    unsigned int result = 0;
    int bitWeight = 1;

    for (int i = size-1; i >= 0; i--)
    {
        if (binNumber[i] == '0')
        {
            bitWeight *= 2;
            continue;
        }
        else {
            result += bitWeight;
            bitWeight *= 2;
        }   
    }
    
    return result;
}

int BinaryToDecimal_Signed (char *binNumber){
    int size = strlen(binNumber);

    int result = 0;
    int bitWeight = 1;

    for (int i = size-1; i >= 0; i--)
    {
        if (i == 0)
        {
            if (binNumber[i] == '0')
            {
                break;
            }
            else
            {
                result -= bitWeight;
            }
        }
        else
        {
            if (binNumber[i] == '0')
            {
                bitWeight *= 2;
                continue;
            }
            else {
                result += bitWeight;
                bitWeight *= 2;
            }
        }   
    }

    return result;
}



char* binaryConcat(char *binNumber, char *fill, int size, int fillSize){
    int finalSize = size + fillSize;
    char *final = (char*)malloc((finalSize+1) * sizeof(char));
    for (int i = 0; i < finalSize; i++)
    {
        if (i < fillSize)
        {
            final[i] = fill[i];
        }
        else {
            final[i] = binNumber[i - fillSize];
        }
    }

    final[finalSize] = '\0';

    return final;
}

char* formatBinary(char *binNumber, int size){
    int rest = size % 4;
    if (!rest)
    {
        return binNumber;
    }
    else {
        int fillSize = 4-rest;
        char *nullFill = (char*)malloc((fillSize+1) * sizeof(char));
        initializeArray(nullFill, fillSize);
        binNumber = binaryConcat(binNumber, nullFill, size, fillSize);
    }

    return binNumber;
}

void printBinary(char *binNumber){
    int size = strlen(binNumber);

    printf("Binary Number: ");
    for (int i = 0; i < size; i++)
    {
        if (i && i % 4 == 0)
        {
            printf("%c", ' ');
        }
        
        printf("%c", binNumber[i]);
    }

    printf("\n");
}

/* int main() {
    char input; int inputNumber;

    printf("#################################################\n");
    printf("Willkommen! Wie möchten Sie umwandeln?\n");
    printf("#################################################\n");
    printf("a: Decimal to Binary \n");
    printf("b: Binary to Decimal\n");
    scanf("%c", &input);

    switch (input)
    {
    case 'a':
        printf("Please enter the number: ");
        scanf("%d", &inputNumber);
        int size = calculateBitSize(inputNumber);
        if(!size){
            printf("binary Number: 0000");
        }
        else {
            char *binNumber = DecimalToBinary(inputNumber);
            binNumber = formatBinary(binNumber, size);
            printBinary(binNumber);
            free(binNumber);
        }
        break;
    case 'b':
        printf("Please enter your binary Number (max 1 Byte): ");
        char binNumber[9];
        initializeArray(binNumber, 8);
        scanf("%s", binNumber);
        
        int result = BinaryToDecimal_Unsigned(binNumber);
        printf("Decimal Result: %d", result);
        break;
    default:
        break;
    }
} */