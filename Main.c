#include <stdio.h>
#include <string.h>


int alph = 26; 
void Encryp_alg_mess_txt_key(char cipher); //prototype for a function that perfoms encryption given an algorithm, message text, and key
void Decryp_alg_ciph_txt_key(char cipher); //prototype for a function that performs decryption given an algorithm, cipher text, and key
void Decryp_ciph_txt_no_key_Rotation(void); // prototype for a function that performs decryption given cipher text and some assumptions of its contents without the key using Rotation cipher
void Decryp_ciph_txt_no_key_Substitution(void); // prototype for a function that performs decryption given cipher text and some assumptions of its contents without the key using substitution cipher
void Rotation_cipher_Encrypt(void);
void Rotation_cipher_Decrypt(void);
void Substitution_cipher_Encrypt(void);
void Substitution_cipher_Decrypt(void);
void Encryption(int letters[alph], int orig_letters[alph]);
void Decryption(int letters[alph], int orig_letters[alph]);

int main ()
{
    char selection, cipher;
    int int_selection;
    
    // Menu that allows user to select if they want to encrypt or decrypt (depending on the information they have)
    printf("Select which Encryptior Decryption to be performed: \n");
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
            printf("Case B Selected\n\n");
                
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: "); 
            getchar();
            scanf("%c", &cipher);
            Decryp_alg_ciph_txt_key(cipher);
            break;
        
        case 'C':
            printf("Case C Selected\n\n");
            
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: "); 
            getchar();
            scanf("%c", &cipher);
            
            if (cipher == 'a')
            {
                Decryp_ciph_txt_no_key_Rotation();
            }
            else if (cipher == 'b')
            {
                Decryp_ciph_txt_no_key_Substitution();
            }
            else 
            {
                printf("Make possible selection");
                return 0;
            }
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
            Substitution_cipher_Encrypt();
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
            Substitution_cipher_Decrypt();
            break;
        }
    }
    
    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection");
        //return 0;
    }

}

void Rotation_cipher_Encrypt(void)
{
   int k, i, letters[alph], over, orig_letters[alph];
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
  
    Encryption(orig_letters, letters);
}

void Rotation_cipher_Decrypt(void)
{
   int k, i, letters[alph], under, orig_letters[alph];
   char encrypt_letter, orig_letter;
   
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
   
    Decryption(orig_letters, letters);
  
}

void Substitution_cipher_Encrypt(void)
{
   int i, letters[alph], orig_letters[alph];
   char encrypt_letter, orig_letter, ASCII;
   
    for (i = 0; i < 26; i++)
    {
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
    }

   for (i = 0; i < 26; i++)
   {
       printf("Enter encrypted substitutaion value for %c: ", orig_letters[i]);
       getchar();
       scanf("%c", &ASCII);
       
       ASCII = (int)ASCII;
       //printf("%d", ASCII);
       letters[i] = ASCII;
       
       encrypt_letter = (char)letters[i]; //converts the ASCII code number to character 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to character 
       
       printf("%c now %c \n", orig_letter, encrypt_letter);
   }
   
    Encryption(orig_letters, letters);
}

void Substitution_cipher_Decrypt(void)
{
   int i, letters[alph], orig_letters[alph];
   char encrypt_letter, orig_letter, ASCII;
   
    for (i = 0; i < 26; i++)
    {
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
    }

   for (i = 0; i < 26; i++)
   {
       printf("Enter encrypted substitutaion value for %c: ", orig_letters[i]);
       getchar();
       scanf("%c", &ASCII);
       
       ASCII = (int)ASCII;
       //printf("%d", ASCII);
       letters[i] = ASCII;
       
       encrypt_letter = (char)letters[i]; //converts the ASCII code number to character 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to character 
       
       printf("%c now %c \n", orig_letter, encrypt_letter);
   }
   
    Decryption(orig_letters, letters);
}

void Decryp_ciph_txt_no_key_Rotation(void)
{
   int k, i, letters[alph], under, orig_letters[alph], size = 500, count, curr_cnt, freq_num,key, j;
   char encrypt_letter, orig_letter, encrypt_text[size];
   FILE *input;
   
  printf ("Rotation Decryption without a key selected\n\n");
   
  input = fopen("encrypted.txt", "r");
	
        while(!feof(input))
	   {
	     fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(encrypt_text)+ 1;
                
        //printf("Size = %d", size)
        
        
        count = 0, curr_cnt = 1, freq_num = 0, key = 0;
        
        for(i = 0; i < size - 1; i++)
        {
            key = encrypt_text[i];
            
            if ((key >= 65) && (key <= 90) && (key != freq_num))
            {
                for(j = i + 1; j < size; j++)
                {
                    if(key == encrypt_text[j])
                    {
                        curr_cnt++;
                    }
                }
                
                if(curr_cnt > count)
                {
                    freq_num = key;
                    count = curr_cnt;
                    curr_cnt = 1;
                }
            }               
        }
        printf("Num = %d and times = %d\n\n", freq_num, count);
        
        break;
    }
       
        k = freq_num - 70;
        
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
           
           printf("%c now %c\n\n", orig_letter, encrypt_letter); 
       }
       
      Decryption(orig_letters, letters);
    
}

void Decryp_ciph_txt_no_key_Substitution(void)
{
    printf ("Substitution Decryption without a key selected");
}

void Encryption(int letters[alph], int orig_letters[alph])
{
   int i, I, size = 500;
   char origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;

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
void Decryption(int letters[alph], int orig_letters[alph])
{
   int i, I, size = 500;
   char origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;

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
             if ((encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
             {
                 for (i = 0; i < 26; i++)
                {             
                     if (encrypt_text[I] == letters[i])
                     {
                         origional_text[I] = orig_letters[i]; //tests for match between a letter input and origional alphabet then assigns the new letter (as according to the above rotating cipher code)
                     }
                }
            }
            if (encrypt_text[I] == ' ') 
            {
                 origional_text[I] = ' ';
             }
             if ((encrypt_text[I] >= 33) && (encrypt_text[I] <= 64))
             {
                 origional_text[I] = encrypt_text[I];
             }
        }
        
        output = fopen("origional.txt", "w");
        
        printf("\nNew: %s ",origional_text);
        fprintf(output, "%s\n", origional_text);
        break;
    }    
}