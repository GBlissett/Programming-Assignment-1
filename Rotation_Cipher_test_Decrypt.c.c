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
  
}