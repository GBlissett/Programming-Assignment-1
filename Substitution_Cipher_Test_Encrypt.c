#include <stdio.h>
#include <string.h>

int main(void)
{
   int i, I, orig_letters[25], letters[25], size = 500;
   char encrypt_letter, orig_letter, origional_text[size], encrypt_text[size], ASCII;
   FILE *input;
   FILE *output;
   
    for (i = 0; i < 26; i++)
    {
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
    }

   for (i = 0; i < 26; i++)
   {
       printf("Enter encrypted substitutaion value for %c: ", orig_letters[i]);
       scanf("%c", &ASCII);
       getchar();
       
       ASCII = (int)ASCII;
       //printf("%d", ASCII);
       letters[i] = ASCII;
       
       encrypt_letter = (char)letters[i]; //converts the ASCII code number to character 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to character 
       
       printf("%c now %c\n", orig_letter, encrypt_letter);
   }

     
   input = fopen("origional.txt", "r");
	
	while(!feof(input))
	{
	     fgets(origional_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(origional_text)+ 1;
         
	     printf("Old: %s", origional_text);
        
        //printf("Size = %d", size)
        
        for (I = 0; I < (size - 1); I++)
        {
             ////printf("%c", origional_text[4]);
             if ((origional_text[I] >= 65) && (origional_text[I] <= 90))
             {
                 for (i = 0; i < 26; i++)
                {             
                     if (origional_text[I] == orig_letters[i])
                     {
                         encrypt_text[I] = letters[i]; //tests for match between a letter input and origional alphabet then assigns the new letter (as according to the above rotating cipher code)
                     }
                }
            }
            if (origional_text[I] == ' ') 
            {
                 encrypt_text[I] = ' ';
             }
             if ((origional_text[I] >= 33) && (origional_text[I] <= 64))
             {
                 encrypt_text[I] = origional_text[I];
             }
        }
        
        output = fopen("encrypted.txt", "w");
        
        printf("\nNew: %s ",encrypt_text);
        fprintf(output, "%s\n", encrypt_text);
        break;
	}
}