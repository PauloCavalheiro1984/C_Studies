#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int main(void)
{
    //variables initialized here, as well the string to calculate
    
    string text = get_string("Provide the text to calculate the level: ");
    int words, letters, sentences;
    words = letters = sentences = 0;
    
    //loop to determine the count of words, letters and sentences
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        
        //conditional count for letters: isalpha is enough
        
        if (isalpha(text[i]))
        {
            letters++;
        }
        
        //conditional count of sentences: sentence finishers are enough
        
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
        
        //conditional count of words: here it depends on the space, apostrophers
        //a way to deal with contractions and calculate the exact number of words
        
        if ((i == 0 && text[i] == ' ' && text[i + 1] != ' ') || (i != n - 1 && text[i] == ' ' && text[i + 1] != ' ') || (i == 0
                && text[i] != ' '))
        {
            words++;
        }
    }
    float L = (letters / (float)words) * 100;
    float S = (sentences / (float)words) * 100;
    int index = round(0.0588 * L - 0.296 * S - 15.8);
    if (index < 16 && index >= 0)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }
       
}
