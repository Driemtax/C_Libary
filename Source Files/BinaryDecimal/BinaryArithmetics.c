#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../Header Files/helper.h"
#include "DecimalBinaryConverter.h"

char* BinaryAddition(char *summand1, char *summand2, int size){
    int carryBit = 0;

    char *result = (char*)malloc(size * sizeof(char));

    //change with  utility function when header files are working
    result = initialize_char_array(result, size);

    for (int i = size - 1; i >= 0; i--)
    {
        if (summand1[i] == '0' && summand2[i] == '0') //case both bits = 0
        {
            if (carryBit)
            {
                result[i] = '1';
                carryBit = 0;
            }
            else{
                result[i] = '0';
                carryBit = 0;
            }
        }
        else if(summand1[i] == '1' && summand2[i] == '0') // case summand 1 = 1 and summand 2 = 0
        {
            if (carryBit)
            {
                result[i] = '0';
                carryBit = 1;
            }
            else{
                result[i] = '1';
                carryBit = 0;
            }
        }
        else if(summand1[i] == '0' && summand2[i] == '1') // case summand 1 = 0 and summand 2 = 1
        {
            if (carryBit)
            {
                result[i] = '0';
                carryBit = 1;
            }
            else
            {
                result[i] = '1';
                carryBit = 0;
            }
        }
        else if (summand1[i] == '1' && summand2[i] == '1') // case summand 1 = 1 and summand 2 = 1
        {
            if (carryBit)
            {
                result[i] = '1';
                carryBit = 1;
            }
            else
            {
                result[i] = '0';
                carryBit = 1;
            }
        }   
    }

    formatBinary(result, size);

    return result;
}

char* Negate(char *binNumber, int size){
    for (int i = 0; i < size; i++)
    {
        if (binNumber[i] == '0')
        {
            binNumber[i] = '1';
        }
        else
        {
            binNumber[i] = '0';
        }
    }

    binNumber = BinaryAddition(binNumber, "00000001", size);

    return binNumber;
    
}

char* Subtraction_Unsigned(int num1, int num2){
    if (num1 < num2)
    {
        char null_result[] = "00000000";
        return null_result;
    }
    
    int size = calculateBitSize(num1);
    char *minuend = DecimalToBinary(num1);
    char *subtrahend = DecimalToBinary(num2);


    char *result = (char*)malloc((size+1) * sizeof(char));
    result = initialize_char_array(result, size);

     for (int i = size - 1; i >= 0; i--)
    {
        if (minuend[i] == '0' && subtrahend[i] == '0') //case both bits = 0
        {
            result[i] = '0';
        }
        else if(minuend[i] == '1' && subtrahend[i] == '0') // case minuend = 1 and subtrahend = 0
        {
            result[i] = '1';
        }
        else if(minuend[i] == '0' && subtrahend[i] == '1') // case minuend = 0 and subtrahend = 1
        {
            result[i] = '1';
        }
        else if (minuend[i] == '1' && subtrahend[i] == '1') // case minuend = 1 and subtrahend = 1
        {
            result[i] = '0';
        }   
    }

    result = formatBinary(result, size);

    return result;

}

char* Subtraction(int num1, int num2){
    int biggerNumber;
    if (num1 < num2)
    {
        biggerNumber = num2;
    }
    else
    {
        biggerNumber = num1;
    }
    
    int size = calculateBitSize(biggerNumber);
    char *minuend = DecimalToBinary(num1);
    char *subtrahend = DecimalToBinary(num2);

    char *result = (char*)malloc((size+1)*sizeof(char));
    result = initialize_char_array(result, size);

    subtrahend = Negate(subtrahend, strlen(subtrahend));

    result = BinaryAddition(minuend, subtrahend, size);

    return result;
}



int main(){
    char *finalResult = Subtraction(100, 95);
    printBinary(finalResult);
    free(finalResult);
}

/* int main(){
    char testNumber1[] = "00000001"; // 100
    char testNumber2[] = "00000011"; //  95
                        // exp Result:  11000011
    char *resultEnd = (char*)malloc(8 * sizeof(char));
    resultEnd = BinaryAddition(testNumber1, testNumber2, 8);

    printf("Result: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%c", resultEnd[i]);
    }

    getchar();
    
} */