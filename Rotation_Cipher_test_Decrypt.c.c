#include <stdio.h>
#include <string.h>

//Decryption:
int main(void)
{
   int k, i, I, letters[25], under, orig_letters[25], size = 500;
   char encrypt_letter, orig_letter, origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;
   
   printf("Enter offset of rotation cipher: \n");
   scanf("%d", &k);
   
   //ACII code range for capital letters is 65 - 90
   
   for (i = 0; i < 26; i++)
   {
       letters[i] = 65 + i; // assigns a ASCII code for the encrypt letter to a specifc location in an array
       
       orig_letters[i] =  65 - k + i; // assigns a ASCII code for the origional letter to a specifc location in an array
        
       if (orig_letters[i] < 65)
       {
           under = 65 - orig_letters[i]; // this allows the rotation flow back over to 65 (ie A) to account for the shift in the alphabet by k
           orig_letters[i] = 91 - under;
       }
       
       encrypt_letter = (char)letters[i]; //converts the ASCII code number to character 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to character 
       
       printf("%c now %c\n", orig_letter, encrypt_letter);       
   }
   
   input = fopen("encrypted.txt", "r");
	
	
	while(!feof(input))
	{
	     fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(encrypt_text)+ 1;
         
	     printf("Old: %s", encrypt_text);
        
        //printf("Size = %d", size)
        
        for (I = 0; I < (size - 1); I++)
        {
             ////printf("%c", origional_text[4]);
             for (i = 0; i < 26; i++)
            {             
             if (encrypt_text[I] == letters[i])
             {
                 origional_text[I] = orig_letters[i]; //tests for match between a letter input and origional alphabet then assigns the new letter (as according to the above rotating cipher code)
             }
             if (origional_text[I] == ' ') 
            {
                 encrypt_text[I] = ' ';
             }
            }
        }
        
        output = fopen("origional.txt", "w");
        
        printf("\nNew: %s ",origional_text);
        fprintf(output, "%s\n", origional_text);
	}
  
}