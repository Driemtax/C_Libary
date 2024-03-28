#include <stdio.h>
#include <stdlib.h>

char* BinaryAddition(char *summand1, char *summand2, int size){
    int carryBit = 0;

    char *result = (char*)malloc(size * sizeof(char));

    //change with  utility function when header files are working
    for (int i = 0; i < size; i++)
    {
        result[i] = '0';
    }

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

    return result;
}

int main(){
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
    
}