#include <cs50.c>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>


int hitung_letters(string text);
int hitung_words(string text);
int hitung_sentences(string text);
int main(void){
    string text = get_string("","Text: ");

    int letters = hitung_letters(text);
    int words = hitung_words(text);
    int sentences = hitung_sentences(text);


    // calculating grade
    // index = 0.0588 * L - 0.296 * S - 15.8
    // where L is the average number of letters per 100 words in the text, and S is the average number of sentences per 100 words in the text.
    float counting_letters = 0.0588 * (float) (letters / words) * 100;
    float counting_sentences = 0.296 * (float) (sentences / words) * 100;
    float index = counting_letters - counting_sentences - 15.8;
    int grade = round(index);

    if(grade < 1){
        printf("Before Grade 1");
    }else if(grade > 16){
        printf("Grade 16+");
    }else{
        printf("Grade %i\n", grade);
    }

}

int hitung_letters(string text){
    int letter = 0;
    for(int i = 0; i < strlen(text); i++){
        if((64 < text[i] && text[i] < 91) || (96 < text[i] && text[i] < 123)){
            letter++;
        }
    }
    return letter;
}

int hitung_words(string text){
    int word = 1;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 32){
            word++;
        }
    }
    return word;
}

int hitung_sentences(string text){
    int sentence = 0;
    for(int i = 0; i < strlen(text); i++){
        if(text[i] == 33 || text[i] == 44 || text[i] == 46 || text[i] == 63){
            sentence++;
        }
    }
    return sentence;
}