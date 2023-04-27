#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct encodedData {
    char ch;
    int count;
} encodedData;

/*
functionName compress compress the input data
@param input the input line
@param length the length of input
@param outLen the number of objects in array.
*/
encodedData* compress(char* input, int length, int* outLen){
    int count;
    encodedData* result = NULL;

    for (int i = 0; i < length; i += count) {
        count = 1;
        while(i+count<length && input[i]==input[i+count]){
            count++;
        }
        if (result == NULL) {
            // the first time store data, allocate memory to result.
            result = malloc(sizeof(encodedData));
        } else {
            // not the first time, re-allocate memory to result.
            result = realloc(result, (*outLen + 1) * sizeof(encodedData));
        }
        result[*outLen].ch = input[i];
        result[*outLen].count = count;
        (*outLen)++;
    }
    return result;
}

/*
functionName charToEncodedData convert input line to encodedData
@param input the input line
@param len length of input line
@param outLen the number of encodedData
*/
encodedData* charToEncodedData(char* input, int len, int* outLen){
    int count;
    int i = 0, appear = 0;
    encodedData* result = NULL;
    //traverse the input line
    for(int i = 0; i<len; i=i){

        count=1;

        if (result == NULL) {
            // the first time store data, allocate memory to result.
            result = malloc(sizeof(encodedData));
        } else {
            // not the first time, re-allocate memory to result.
            result = realloc(result, (*outLen + 1) * sizeof(encodedData));
        }
        
        while(i+count<len && input[i]==input[i+count]){
            if(count==3){break;}
            count++;
        }

        if(count==3){
            if(input[i+count+1]=='*'){
                // only one digit
                result[*outLen].count=input[i+count] - '0';
                result[*outLen].ch=input[i+count-1];
                (*outLen)++;
                i = i+count+2;
            } else {
                int unit = input[i+count+1] - '0';
                int second = input[i+count] - '0';
                result[*outLen].count = unit + second*10;
                result[*outLen].ch=input[i+count-1];
                (*outLen)++;
                i = i+count+3;
            }
        } else if(count==2){
            result[*outLen].count=2;
            result[*outLen].ch=input[i];
            (*outLen)++;
            i = i+2;
        } else if(count==1){
            result[*outLen].count = 1;
            result[*outLen].ch = input[i];
            (*outLen)++;
            i = i+1;
        } 
        
    }

    return result;
}

int main(void){
    char input[100];
    char start;
    bool isFirstLine = true;
    scanf("%c", &start);

    if(start=='C'){
        while(fgets(input, sizeof(input), stdin)){
            // indent one line
            if(isFirstLine){
                char* newline = strchr(input, '\n');
                if (newline != NULL) {
                    *newline = '\0';  
                }
                isFirstLine = false;
            }

            encodedData* encoded = NULL;
            int outLen_c = 0;
            encoded = compress(input, strlen(input), &outLen_c);

            //output
            for (int i = 0; i < outLen_c; i++) {
                if(encoded[i].count>=3){
                    printf("%c%c%c%d*", encoded[i].ch, encoded[i].ch, encoded[i].ch, encoded[i].count);
                } else if(encoded[i].count==1){
                    printf("%c", encoded[i].ch);
                }else if(encoded[i].count==2){
                    printf("%c%c", encoded[i].ch, encoded[i].ch);
                }
            }
        } 
    }

    if(start=='E'){
        char* decompressed = NULL;
        while(fgets(input, sizeof(input), stdin)){
            //indent one line
            if(isFirstLine){
                char* newline = strchr(input, '\n');
                if (newline != NULL) {
                    *newline = '\0';  
                }
                isFirstLine = false;
            }

            encodedData* encoded = NULL;
            int outLenConvert = 0;
            encoded = charToEncodedData(input, strlen(input), &outLenConvert);

            //output
            for(int i = 0; i<outLenConvert; ++i){
                if(encoded[i].count>=3){
                    for(int j = 0; j<encoded[i].count; ++j){
                        printf("%c", encoded[i].ch);
                    }
                } else if(encoded[i].count==2){
                    printf("%c%c", encoded[i].ch, encoded[i].ch);
                } else if(encoded[i].count==1){
                    printf("%c", encoded[i].ch);
                }
            }
        }
    }
    return 0;
}