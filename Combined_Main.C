#include <stdio.h>
#include <string.h>

char Encryp_alg_mess_txt_key(char cipher); //prototype for a function that perfoms encryption given an algorithm, message text, and key
char Decryp_alg_ciph_txt_key(char cipher); //prototype for a function that performs decryption given an algorithm, cipher text, and key
char Decryp_ciph_txt_no_key(char cipher); // prototype for a function that performs decryption given cipher text and some assumptions of its contents without the key
char Rotation_cipher(char cipher);
char Substitution_cipher(char cipher);
int main ()
{
    char selection, cipher;
    int int_selection;
    
    // Menu that allows user to select if they want to encrypt or decrypt (depending on the information they have)
    printf("Select which Encryptioor Decryption to be performed: \n");
    printf("    A: Encryption given an algorithm, message text, and key\n");
    printf("    B: Decryption given an algorithm, cipher text, and key\n"); 
    printf("    C: Decryption given cipher text and some assumptions of its contents without the key\n\n");  
    printf("Selection: ");
    scanf("%c", &selection);
    
    int_selection = (int)selection; //assigns ASCII code to int_selection variable to be used in if flow control
    
    //switch case controlled by IF flow control to prevent invalid selections being made    
    if (int_selection >= 65 && int_selection <= 67) //ie if int_selection (ie ASCII code) is inisde the range for char A - C (ie ASCII 65 - 67)
    {
        switch (selection)
       {
        case 'A':
            printf("Case A Selected\n");
            Encryp_alg_mess_txt_key(cipher);
            break;
            
        case 'B':       
            printf("Case B Selected");
            Decryp_alg_ciph_txt_key(cipher);
            break;
        
        case 'C':
            printf("Case C Selected");
            Decryp_ciph_txt_no_key(cipher);
            break;
        }
    }
    
    else if (int_selection < 65 || int_selection > 67) //ie if int_selection (ie ASCII code) is outside the range for char A - C (ie ASCII 65 - 67)
    {
        printf("Please make valid selection");
        return 0;
    }
    
}

char Encryp_alg_mess_txt_key(char cipher)
{
  
    int int_cipher;
    
    // Menu that allows user to select type of cipher (NB Menu structure/workings is same as origional menu (ie in MAin.c)) 
    printf("Select type of cipher: \n");
    printf("    a: Rotation cipher\n");
    printf("    b: Substitution cipher\n\n");
    printf("Selection: "); 
    scanf("%c", &cipher);
    
    int_cipher = (int)cipher;
    
    if (int_cipher >= 97 && int_cipher <= 99)
    {
        switch (cipher)
       {
        case 'a':
            printf("Case a selected");  
             Rotation_cipher(cipher);
            break;
            
        case 'b':     
            printf("Case b Selected");
             Substitution_cipher(cipher);
            break;
        }
    }
    
    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection");
        //return 0;
    }
    
}

char Decryp_alg_ciph_txt_key(char cipher)
{
    printf ("Decryption with a key selected");
} 

char Decryp_ciph_txt_no_key(char cipher)
{
     printf ("Decryption with a key selected");
}

char Rotation_cipher(char cipher)
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
        
        size = (int)strlen(origional_text) + 1;
        
        //printf("Size = %d", size)
        
        for (I = 0; I < (size - 1); I++)
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
	}
}

char Substitution_cipher(char cipher)
{
    printf("Substitution cipher selected");
}
