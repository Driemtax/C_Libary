#include <stdio.h>


void DecimalToBinary(int number, int size, char *binNumber){
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

    printf("Binary Number: ");
    for (int i = 0; i < size; i++)
    {
        printf("%c", binNumber[i]);
    }
}

int BinaryToDecimal(char *binNumber, int size) {
    int result = 0;
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
}

int main() {
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
            printf("Binary Number: 0000");
        }
        else {
            char binNumber[size];
            initializeArray(binNumber, size);
            DecimalToBinary(inputNumber, size, binNumber);
        }
        break;
    case 'b':
        printf("Please enter your binary Number (max 1 Byte): ");
        char binNumber[8];
        initializeArray(binNumber, 8);
        scanf("%s", binNumber);
        
        int result = BinaryToDecimal(binNumber, 8);
        printf("Decimal Result: %d", result);
        break;
    default:
        break;
    }
}