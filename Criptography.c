#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

bool valid_key(string check); //a boolean function is created to verify the validity of the key according to the rules

int main(int argc, string argv[])
{
    string key = argv[1];               //the conditional must include if argc is located in the vector 2, otherwise it'll fail (the argc itself is 1)
    if (argc == 2 && valid_key(argv[1])) //the character * means you are addressing the first digit of the string (since argv[] is a string)
    {
        int k = (atoi(key));
        string plaintext = get_string("plaintext: ");
        printf("ciphertext: ");
        for (int count = 0, length = strlen(plaintext); count < length; count++)
        {
            if(isalpha(plaintext[count]))
            {
                if(isupper(plaintext[count]))
                {
                    printf("%c", ((plaintext[count] + k + 65) % 26) + 65); //subtracting the ASCII value to simple arithmetics, calculate and return the ASCII value incremented
                }
                else if (islower(plaintext[count]))
                {
                    printf("%c", ((plaintext[count] + k - 97) % 26) + 97); //the formula is "ci - (p1 + K) % 26", return the ASCII value for lower and upper cases, calculate and give it back
                }

            }
            else
            {
                printf("%c", plaintext[count]);
            }
        }
        printf("\n");
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

bool valid_key(string check)
{
    for (int checker = 0, z = strlen(check); checker < z; checker++)
    
        if(!isdigit(check[checker]))
        
            return false;
        
        
        return true;
}
