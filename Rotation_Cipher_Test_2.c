#include <stdio.h>#include <string.h>

//Encryption:
int main(void)
{
   int k, i, I, letters[25], over, orig_letters[25], size = 500;
   char encrypt_letter, orig_letter, origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;
   
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
  
	input = fopen("origional.txt", "r");
	
	while(!feof(input))
	{	      
	    fgets(origional_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

        printf("Old: %s", origional_text);
        
        //gets (origional_text);
        //size = (int)strlen(origional_text) + 1;

        
        for (I = 0; I < size; I++)
        {
             ////printf("%c", origional_text[4]);
             for (i = 0; i < 26; i++)
            {             
             if (origional_text[I] == orig_letters[i])
             {
                 encrypt_text[I] = letters[i]; //tests for match between a letter input and origional alphabet then assigns the new letter (as according to the above rotating cipher code)
             }
             if (origional_text[I] == ' ') 
            {
                 encrypt_text[I] = ' ';
             }
            }
        }
        
        output = fopen("encrypted.txt", "w");
        
        printf("\nNew: ");
        fprintf(output, "%s\n", encrypt_text);
    
	  
	    //printf("%c", c);
	}
}

//Decipher