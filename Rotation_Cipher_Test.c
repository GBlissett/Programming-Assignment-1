#include <stdio.h>

//Encryption:
int main(void)
{
   int k, i, letters[25], over, orig_letters[25], counter = 0, I, w;
   char encrypt_letter, orig_letter, text[1024], orig_word[1024];
   
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
   printf("Enter text to encrypt below: (NB make sure all text is in capital letters and separate each word by pressing the return key)\n");
   
   for (w = 1; w < 1025; w++) //specifies what word is being encrypted
   {
    
     scanf("%s", text); //creates a string out of letters input by user 
    
     for (I = 0; I < 1024; I++)
     {  
        i = 0;
        
        while (i < 26)
        {
             if (text[I] = orig_letters[i])
             {
                 text[I] = (char)letters[i]; //tests for match between a letter input and origional alphabet then assigns the new letter (as according to the above rotating cipher code)
             }
             i++;
        }
     }
     
     printf("New Word: %s\n", text); //prints new word when computated DOES NOT WORK YET!!!!
     
   }
   
}
//Decryption: