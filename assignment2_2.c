#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <stdbool.h>

struct words{
    char* word;
    int count;
};


/*
functionName: quickSort
@param wordsList-an array contains all words in the text
@param left-the left bound
@param right-the right bound
*/
void quickSort(struct words* wordsList, int left, int right){
    if(left<right){
        char* pivot = wordsList[right].word;
        int i = left - 1;
        for (int j = left; j < right; j++) {
            if (strcmp(wordsList[j].word, pivot) <= 0) {
                i++;
                struct words temp = wordsList[i];
                wordsList[i] = wordsList[j];
                wordsList[j] = temp;
            }
        }
        struct words temp = wordsList[i+1];
        wordsList[i+1] = wordsList[right];
        wordsList[right] = temp;
        int pivotIndex = i+1;
        quickSort(wordsList, left, pivotIndex-1);
        quickSort(wordsList, pivotIndex+1, right);
    }
}

int main(void){
    struct words* wordsList = (struct words*)malloc(sizeof(struct words)); // a list to store words
    int sizeOfWordsList = 0; //number of words object
    int wordsListSize = 1; //the same meaning, use it when expanding memory
    char input[100];
    char* inputPtr = input;

    while (fgets(input, sizeof(input), stdin)){
        char findWord[20]; // store the word
        int f = 0; //set to 0, after find a word
        for(int i = 0; i<strlen(input); ++i){
            bool flag = true;
            if(isdigit(input[i]) || isalpha(input[i])){
                //find a letter!!! store it in the word.
                findWord[f] = tolower(inputPtr[i]);
                f++;
            } else if(!*input){
                //find a word!!!
                findWord[f] = '\0';
                // if word already exist
                for(int j = 0; j<sizeOfWordsList; ++j){
                    if(strcmp(wordsList[j].word, findWord)==0){
                        wordsList[j].count++;
                        flag=false; //for skipping the step(the word not in the list)
                        f = 0;
                        break;
                    }
                }
                if(flag){
                    // if not exist in the list, check if expand the memory
                    if (sizeOfWordsList == wordsListSize) {
                        wordsListSize *= 2;
                        wordsList = (struct words*)realloc(wordsList, sizeof(struct words) * wordsListSize);
                    }
                    //assign value to the object
                    wordsList[sizeOfWordsList].word = strdup(findWord); // allocate new memory to store it
                    wordsList[sizeOfWordsList].count = 1;
                    sizeOfWordsList++;
                    f = 0;
                    continue;
                }

            } else if(input[i]=='-' || input[i]=='\''){
                //if conjunction and abbreviation
                if(isdigit(input[i-1]) || isalpha(input[i-1])){
                    if(isdigit(input[i+1]) || isalpha(input[i+1])){
                        continue;
                    } else {
                        //find a new word!!!
                        findWord[f] = '\0';
                        for(int j = 0; j<sizeOfWordsList; ++j){
                            if(strcmp(wordsList[j].word, findWord)==0){
                            wordsList[j].count++;
                            flag=false;
                            f = 0;
                            break;
                            }
                        }
                        if(flag){
                        if (sizeOfWordsList == wordsListSize) {
                            wordsListSize *= 2;
                            wordsList = (struct words*)realloc(wordsList, sizeof(struct words) * wordsListSize);
                        }
                        wordsList[sizeOfWordsList].word = strdup(findWord);
                        wordsList[sizeOfWordsList].count = 1;
                        sizeOfWordsList++;
                        f = 0;
                        continue;
                        }
                    }
                }
            } else {
                // punctuation or spaces, store the word into list
                if(isalpha(input[i-1]) || isdigit(input[i-1])){
                    //find a new word!!!
                    findWord[f] = '\0';
                } else {
                    //some continuous spaces or punctuation, continue scanning!!!
                    continue;
                }
                for(int j = 0; j<sizeOfWordsList; ++j){
                    if(strcmp(wordsList[j].word, findWord)==0){
                        wordsList[j].count++;
                        flag=false;
                        f = 0;
                        break;
                    }
                }
                if(flag){
                    if (sizeOfWordsList == wordsListSize) {
                        wordsListSize *= 2;
                        wordsList = (struct words*)realloc(wordsList, sizeof(struct words) * wordsListSize);
                    }
                    wordsList[sizeOfWordsList].word = strdup(findWord);
                    wordsList[sizeOfWordsList].count = 1;
                    sizeOfWordsList++;
                    f = 0;
                    continue;
                }
                
            }

        }
    }

    quickSort(wordsList, 0, sizeOfWordsList-1);
    for (int i = 0; i < sizeOfWordsList; i++) {
        printf("%s => %d\n", wordsList[i].word, wordsList[i].count);
        free(wordsList[i].word);
    }
    free(wordsList);

    return 0;
}