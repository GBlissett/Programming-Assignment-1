#include <stdio.h>

//Encryption:
int main(void)
{
   int k, i, letters[25], over, orig_letters[25];
   char encrypt_letter, orig_letter;
   
   printf("Enter offset of rotation cipher: \n");
   scanf("%d", &k);
   
   //ACII code range for capital letters is 65 - 90
   
   for (i = 0; i < 26; i++)
   {
       letters[i] = 65 + i + k; // assigns a ASCII code for the encrypt letter to a specifc location in an array
       
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
        
       if (letters[i]> 90)
       {
           over = letters[i] - 91; // this allows the rotation flow back over to 65 (ie A) to account for the shift in the alphabet by k
           letters[i] = 65 + over;
       }
       
       encrypt_letter = (char)letters[i]; //converts the ASCII code number to character 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to character 
       
       printf("%c now %c\n", orig_letter, encrypt_letter);       
   }
   
}

//Decryption: