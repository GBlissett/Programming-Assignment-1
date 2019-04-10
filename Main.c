#include <stdio.h>
#include <string.h>

void Encryp_alg_mess_txt_key(char cipher); //prototype for a function that perfoms encryption given an algorithm, message text, and key
void Decryp_alg_ciph_txt_key(char cipher); //prototype for a function that performs decryption given an algorithm, cipher text, and key
void Decryp_ciph_txt_no_key(char cipher); // prototype for a function that performs decryption given cipher text and some assumptions of its contents without the key
void Rotation_cipher_Encrypt(void);
void Rotation_cipher_Decrypt(void);
void Substitution_cipher(void);
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
            printf("Case A Selected\n\n");
        
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: \n"); 
            getchar(); //to prevent carryingof character
            scanf("%c", &cipher);
            Encryp_alg_mess_txt_key(cipher);
            break;
            
        case 'B':       
            printf("Case B Selected");
            
            printf("Case A Selected\n\n");
        
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: "); 
            getchar();
            scanf("%c", &cipher);
            Decryp_alg_ciph_txt_key(cipher);
            break;
        
        case 'C':
            printf("Case C Selected");
            break;
        }
    }
    
    else if (int_selection < 65 || int_selection > 67) //ie if int_selection (ie ASCII code) is outside the range for char A - C (ie ASCII 65 - 67)
    {
        printf("Please make valid selection");
        return 0;
    }
    
}

void Encryp_alg_mess_txt_key(char cipher)
{
   
    int int_cipher;
    
    int_cipher = (int)cipher;
    
    if (int_cipher >= 97 && int_cipher <= 99)
    {
        switch (cipher)
       {
        case 'a':
            printf("Case a selected\n\n");  
            Rotation_cipher_Encrypt();
            break;
            
        case 'b':     
            printf("Case b Selected\n\n");
            Substitution_cipher();
            break;
        }
    }
    
    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection");
        //return 0;
    }
    
}

void Decryp_alg_ciph_txt_key(char cipher)
{
    printf ("Decryption with a key selected");
    int int_cipher;
    
    int_cipher = (int)cipher;
    
    if (int_cipher >= 97 && int_cipher <= 99)
    {
        switch (cipher)
       {
        case 'a':
            printf("Case a selected\n\n");  
            Rotation_cipher_Decrypt();
            break;
            
        case 'b':     
            printf("Case b Selected\n\n");
            Substitution_cipher();
            break;
        }
    }
    
    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection");
        //return 0;
    }

} 

void Decryp_ciph_txt_no_key(char cipher)
{
     printf ("Decryption without a key selected");
    
}

void Rotation_cipher_Encrypt(void)
{
   int k, i, I, letters[25], over, orig_letters[25], size = 100;
   
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

         size = (int)strlen(origional_text)+ 1;
         
	     printf("Old: %s", origional_text);
        
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
        
        printf("\nNew: %s ",encrypt_text);
        fprintf(output, "%s\n", encrypt_text);
        break;
	}
	

}

void Rotation_cipher_Decrypt(void)
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
             if (encrypt_text[I] == ' ') 
            {
                 origional_text[I] = ' ';
             }
            }
        }
        
        output = fopen("origional.txt", "w");
        
        printf("\nNew: %s ",origional_text);
        fprintf(output, "%s\n", origional_text);
        break;
	}
  
}


void Substitution_cipher(void)
{
    printf("Substitution cipher selected");
    
}