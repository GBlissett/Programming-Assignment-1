#include <stdio.h>
#include <string.h>

/*
 * The following program allows user to encrypt or decrypt a message (in all capital letters) manually entered into an external text file 
 * (ie depending if they wish to encryot or decrypt their message). In addition, users can either encrypt/decrypt their message useing a 
 * rotation cipher algorithm or a substitution cipher algorithm with or without a key. The program runs as follows:
 *  - Menu appears with allow user to specify whether they wish to encrypt their message by specifying an algorithm, and key (ie by 
 *    inputing 'A'), decrypt their message (ie cipher text) by specifying an algorithm and key (ie by inputing 'B') or decrypt their message 
 *   (ie cipher text) by specifying the algorthm but not the key (ie by inputing 'C').
 *  - If appropriate selection made (ie 'A', 'B' or 'C' ONLY are input by user), another menu will appear which allows user to specify the 
 *    the algorithm (ie Rotation algorithm by sleecting 'a' or Substitution algorithm 'b') they wish to use to perform encryption or decryption
 *    of message input by user
 *  - Depending on the algorithm selected, specific fucntions are then executed as specified in the comments bellow
 */
 int alph = 26; // universal variable sets every 'alph' integer variable to value of 26
void Encryp_alg_mess_txt_key(char cipher); 
/*
 * Prototype for a function that allows user to select what algorithm thay want to use to encrypt provided message (ie message form origional.txt)
 */
void Decryp_alg_ciph_txt_key(char cipher); 
/*
 * Prototype for a function that allows user to select what algorithm thay want to use to decryot provided message (ie message form encrypted.txt)
 */
void Decryp_ciph_txt_no_key_Rotation(void); 
/*
 * Prototype for a function that performs decryption of given cipher text previously encryted using rotation cipher using frequancy analysis
 */
void Decryp_ciph_txt_no_key_Substitution(void); 
/*
 * Prototype for a function that performs decryption of given cipher text previously encryted using substitution cipher using frequancy analysis
 */
void Rotation_cipher_Encrypt(void); 
/*
 * Prototype of function that generates two arrays; array of origional letters and array of corresponding encrypted letters according to the rotation shift 
 * (ie k) of alphabet input by program user
 */
void Rotation_cipher_Decrypt(void);
/*
 * Prototype of function that generates two arrays; array of origional letters and array of corresponding encrypted letters according to the rotation shift 
 * (ie k) of alphabet input by program user
 */
void Substitution_cipher_Encrypt(void); 
/*
 * Prototype of function that generates two arrays; array of origional letters and array of corresponding encrypted letters according letter assignment 
 *input by program user
 */                               
void Substitution_cipher_Decrypt(void); 
/*
 * Prototype of function that generates two arrays; array of origional letters and array of corresponding encrypted letters according letter assignment 
 *input by program user
 */                               
void Encryption(int letters[alph], int orig_letters[alph]);
/*
 * Prototype for a fuction that takes two arrays from a previous function (ie an array containing original letters and another of their corresponding 
 * encrypted letters) and encrypts the message from origional.txt according to the two arrays, printing it to console and to encrypted.txt
*/
void Decryption(int letters[alph], int orig_letters[alph]); 
/*
 * Prototype for a fuction that takes two arrays from a pervious function (ie an array containing original letters and another of their corresponding
 * encrypted letters) and decrypts the message from encrypted.txt according to the two arrays, printing it to console and to origional.txt
 */


int main ()
{
    char selection, cipher;
    int int_selection;

    printf("******************CIPHER PROGRAM******************\n\n");

    /*
     * The following is the Encryption/Decryotion Specifier Menu. Ths menu allows user to specify if they wish to encrypt message by specifying an 
     * algorithm, and key (ie by inputing 'A'), decrypt their message (ie cipher text) by specifying an algorithm and key (ie by inputing 'B') or 
     * decrypt their message (ie cipher text) by specifying the algorthm but not the key (ie by inputing 'C')))
     */ 
    printf("Select which Encryptor Decryption to be performed: \n");
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
            /*
             * The following is the Alorithm Specifier Menu. This menu allows user to specify what type of algorithm they would like to use to 
             * encrypt message)
             */ 
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: \n"); 
             getchar(); //prevents carrying of char value from previous menu
            scanf("%c", &cipher);
            Encryp_alg_mess_txt_key(cipher); 
            /*
             * The above line of code carries value of char cipher to function definition that allows user to select what algorithm thay want to 
             * use to encrypt provided message
             */
            break;

        case 'B':       
            printf("Case B Selected\n\n");
/*
             * The following is the Alorithm Specifier Menu. This menu allows user to specify what type of algorithm they would like to use to 
             * decrypt message)
             */ 
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: "); 
             getchar(); //prevents carrying of char value from previous menu
            scanf("%c", &cipher);
            Decryp_alg_ciph_txt_key(cipher); 
            /*
             * The above line of code carries value of char 'cipher' to function 'Decryp_alg_ciph_txt_key(cipher)' (See explination of function bellow)
             */
            break;

        case 'C':
            printf("Case C Selected\n\n");
/*
             * The following is the Alorithm Specifier Menu. This menu allows user to specify what type of algorithm they would like to use to 
             * decrypt message)
             */ 
            printf("Select type of cipher: \n");
            printf("    a: Rotation cipher\n");
            printf("    b: Substitution cipher\n\n");
            printf("Selection: "); 
             getchar(); //prevents carrying of char value from previous menu
            scanf("%c", &cipher);

            if (cipher == 'a')
            {
                Decryp_ciph_txt_no_key_Rotation(); 
                /*
                 * The above line of code carries value of char 'cipher' to function 'Decryp_ciph_txt_no_key_Rotation()' (See explination of function
                 * bellow)
                 */
            }
            else if (cipher == 'b')
            {
                Decryp_ciph_txt_no_key_Substitution(); 
                /*
                 * The above line of code carries value of char 'cipher' to function 'Decryp_ciph_txt_no_key_Substitution()' (See explination of function
                 * bellow)
                 */
            }
            else 
            {
                printf("Make possible selection"); //stops program if user makes an invalid selection (ie does not specify a or b)
                 return 0; //stops program if user makes an invalid selection (ie user does not specify 'a' or 'b')
            }
            break;
        }
    }

    else if (int_selection < 65 || int_selection > 67) //ie if int_selection (ie ASCII code) is outside the range for char A - C (ie ASCII 65 - 67)
    {
        printf("Please make valid selection"); //stops program if user makes an invalid selection (ie does not specify A, B or C)
        return 0;
    }

}

/*
 * The following function allows for the execution of a specific function (ie encryption of message using a particular algorithm) depending on the value of
 * char 'cipher' input by user (ie either 'a' or 'b') into Alorithm Specifier Menu.
 */
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
                        /*
             * Executes function 'Rotation_cipher_Encrypt()' (See explanation of function bellow)
             */
            break;

        case 'b':     
            printf("Case b Selected\n\n");
            Substitution_cipher_Encrypt(); 
             /*
             * Executes function 'Substitution_cipher_Encrypt()' (See explanation of function bellow)
             */
            break;
        }
    }

    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection"); //stops program if user makes an invalid selection (ie does not input 'a' or 'b')
         //return 0; //stops program if user makes an invalid selection (ie does not input 'a' or 'b)
    }
}

/*
 * The following function allows for the execution of a specific function (ie decryption of message using a particular algorithm) depending on the value of
 * char 'cipher' input by user (ie either 'a' or 'b') into Alorithm Specifier Menu.
 */
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
                        /*
             * Executes function 'Rotation_cipher_Decrypt()' (See explanation of function bellow)
             */
            break;

        case 'b':     
            printf("Case b Selected\n\n");
            Substitution_cipher_Decrypt(); 
                        /*
             * Executes function 'Substitution_cipher_Decrypt()' (See explanation of function bellow)
             */
            break;
        }
    }

    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection"); //stops program if user makes an invalid selection (ie does not input 'a' or 'b)
         //return 0; //stops program if user makes an invalid selection (ie does not input 'a' or 'b)
    }

}

/*
 * The following function generates two arrays; array of origional letters and array of corresponding encrypted letters according to the rotation shift 
 * of alphabet (ie key (k)) input by program user. These arrays are then carried to function 'Encryption(letters[alph], orig_letters[alph])' which performs 
 * and retuns encryption of message.
 * NB this function has no inputs
 */
void Rotation_cipher_Encrypt(void)
{
   int k, i, letters[alph], over, orig_letters[alph];
   char encrypt_letter, orig_letter;


   printf("Enter offset of rotation cipher: \n"); //allows user to specify the rotation key (ie shift value) to be used to generate encrypted array (ie letters[i])
   scanf("%d", &k);

   //NB ACII code range for capital letters is 65 - 90

   for (i = 0; i < 26; i++)
   {
       letters[i] = 65 + i + k; // assigns a ASCII code for the encrypt letter to a specifc location in an array

       orig_letters[i] =  65 + i; // assigns a ASCII code for the original letter to a specifc location in an array

       if (letters[i]> 90)
       {
           over = letters[i] - 91; 
           letters[i] = 65 + over;
           /*
            * These lines of code allow the rotation to return to 65 (ie A) when value assigned to letters[i] is greater than 90 by calculating the difference 
            * between the value assigned and 65, storing it as value of int 'over' then adding this value to 65
            */
       }

       encrypt_letter = (char)letters[i]; //converts the ASCII code number to a char value 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to a char value

       printf("%c now %c\n", orig_letter, encrypt_letter); //prints what a particular letter will appear as if present in message according to rotation cipher 
   }

    Encryption(letters, orig_letters); //executes function that takes newly generated arrays letters[i] and orig_letters[i] and encrypts the message from origional.txt
}

/*
 * The following function generates two arrays; array of origional letters and array of corresponding encrypted letters according to the rotation shift 
 * of alphabet (ie key (k)) input by program user. These arrays are then carried to function 'Decryption(int letters[alph], int orig_letters[alph])' which performs 
 * and retuns decryption of message.
 * NB this function has no inputs
 */
void Rotation_cipher_Decrypt(void)
{
   int k, i, letters[alph], under, orig_letters[alph];
   char encrypt_letter, orig_letter;

   printf("Enter offset of rotation cipher: \n"); //allows user to specify the rotation key (ie shift value) to be used to generate original array (ie orig_letters[i])
   scanf("%d", &k);

   //ACII code range for capital letters is 65 - 90

   for (i = 0; i < 26; i++)
   {
       letters[i] = 65 + i; // assigns a ASCII code for the encrypt letter to a specifc location in an array

       orig_letters[i] =  65 - k + i; // assigns a ASCII code for the origional letter to a specifc location in an array

       if (orig_letters[i] < 65)
       {
           under = 65 - orig_letters[i]; 
           orig_letters[i] = 91 - under;
           /*
            * These two lines of code allow the rotation to return to 65 (ie A) when value assigned to letters[i] is less than 65 by calculating the difference between 
            * the value assigned and 65, storing it as value of int 'under' then subtracting it from 91.
            */
       }

       encrypt_letter = (char)letters[i]; //converts the ASCII code number to a char value 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to a char value 

       printf("%c now %c\n", orig_letter, encrypt_letter); //prints what a particular letter will appear as if present in message according to rotation cipher
   }

    Decryption(letters, orig_letters); //executes function that takes newly generated arrays letters[i] and orig_letters[i] and decrypts the message from encrypted.txt
}

/*
 * The following function generates two arrays; array of origional letters and array of corresponding encrypted letters according letter assignment input by program
 * user. Function allows user to manually input what each encrypted letter a specific letter will appear as in the final encrypted message. These arrays are then 
 * carried to function 'Encryption(letters[alph], orig_letters[alph])' which performs and retuns encryption of message.
 * NB this function has no inputs
 */
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
       /*
        * Allows user to manually input what each encrypted letter a specific letter will appear as in the final encrypted message and sore it as a tempory char value
        * in 'ASCII'
        */
       getchar();
       scanf("%c", &ASCII);

       ASCII = (int)ASCII; //casts char value to int value
       letters[i] = ASCII; //assigns cast value to letters[i]

       encrypt_letter = (char)letters[i]; //converts the ASCII code number to a char value 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to a char value

       printf("%c now %c \n", orig_letter, encrypt_letter); //prints what a particular letter will appear as if present in message according to rotation cipher 
   }

   Encryption(letters, orig_letters); //executes function that takes newly generated arrays letters[i] and orig_letters[i] and encrypts the message from origional.txt
}

/*
 * The following function generates two arrays; array of origional letters and array of corresponding encrypted letters according letter assignment input by program
 * user. Function allows user to manually input what each encrypted letter a specific letter will appear as in the final encrypted message. These arrays are then 
 * carried to function 'Decryption(letters[alph], orig_letters[alph])' which performs and retuns decryption of message.
 * NB this function has no inputs
 */
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
       /*
        * Allows user to manually input what each encrypted letter a specific letter will appear as in the final encrypted message and sore it as a tempory 
        * char value in 'ASCII'
        */
       getchar();
       scanf("%c", &ASCII);

       ASCII = (int)ASCII; //casts char value to int value
       letters[i] = ASCII; //assigns cast value to letters[i]

       encrypt_letter = (char)letters[i]; //converts the ASCII code number to a char value 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to a char value

       printf("%c now %c \n", orig_letter, encrypt_letter); //prints what a particular letter will appear as if present in message according to rotation cipher 
   }

    Decryption(letters, orig_letters); //executes function that takes newly generated arrays letters[i] and orig_letters[i] and decrypts the message from encrypted.txt
}

/*
 * The following function decrypts message which user has specified was previously encryted using rotation algorithm. Function does this by determining the most frequent  
 * letter that occurs within message input by user in encrypted.txt. According to frequency analysis, the letter E typically has a frequency of 12.02%, at least 3% more 
 * frequent than any other letter. As such, this frquency is used to deduce the rotation key by caculating the difference between the ASCII value of the most frequent letter 
 * present in the  message and the ASCII value for the letter E (ie 69). This shift value (ie key (k)) is then used to generates two arrays; array of origional letters 
 * and array of corresponding encrypted letters according to the rotation shift (ie key (k)) of alphabet input by program user. These arrays are then carried to function 
 * 'Decryption(letters[alph], orig_letters[alph])' which performs and retuns decryption of message. 
 * NB This function has no inputs
 */
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

        /*
         *  The following for loop determines how many times eash letter of the alphabbet is used within the encrypted message and stores the value that occurs the most often 
         */
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
        printf("Num = %d and times = %d\n\n", freq_num, count); //prints how many times each letter is used within message 
        break;
    }

        k = 26 - (freq_num - 69); 
        /*
         * Rotation key (ie k) is calculated by finding the difference between the ASCII value of the most frequent letter present in the encrypted message 
         * and the ASCII value for the letter E (ie 69)
         */

       for (i = 0; i < 26; i++)
   {
       letters[i] = 65 + i; // assigns a ASCII code for the encrypt letter to a specifc location in an array

       orig_letters[i] =  65 - k + i; // assigns a ASCII code for the origional letter to a specifc location in an array

       if (orig_letters[i] < 65)
       {
           under = 65 - orig_letters[i]; 
           orig_letters[i] = 91 - under;
                      /*
            * These two lines of code allow the rotation to return to 65 (ie A) when value assigned to letters[i] is less than 65 by calculating the difference between 
            * the value assigned and 65, storing it as value of int 'under' then subtracting it from 91.
            */
       }

       encrypt_letter = (char)letters[i]; //converts the ASCII code number to a char value 
       orig_letter = (char)orig_letters[i]; //converts the ASCII code number to a char value 

       printf("%c now %c\n", orig_letter, encrypt_letter); //prints what a particular letter will appear as if present in message according to rotation cipher
   }

    Decryption(orig_letters, letters); //executes function that takes newly generated arrays letters[i] and orig_letters[i] and decrypts the message from encrypted.txt
}

/*
 * The following function decrypts message which user has specified was previously encryted using substitution algorithm. Function does this by:
 *  - determining the frequency of each letter within the alphabet as they occur in the message input by user in encrypted.txt to deterine the
 *    most frequent letter within the message and the most frequent letter at the end of words within the message
 *  - using frequancy analysis of letters, words and letter combinations (See FOR loops bellow)
 * As such, this function allows for the deduction of what specific letters appear as in the encrypted message.
 * Thus this fucntion generates two arrays; array of origional letters and array of corresponding encrypted letters according deduction of what specific letters 
 * appear as in the encrypted message  of alphabet input by program user. These arrays are then carried to function 
 * 'Decryption(letters[alph], orig_letters[alph])' which performs and retuns decryption of message. 
 * NB This function has no inputs
 */
void Decryp_ciph_txt_no_key_Substitution(void)
{
   int i, I, letters[26], orig_letters[26], size = 500, count[26], letter, tempcount = 0, end_count[26], temp_i;
   char encrypt_text[size];
   FILE *input;

  printf ("Substituti Decryption without a key selected\n\n");

    for (i = 0; i < 26; i++)
    {
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
    }

    for(i = 0; i < 26; i++)
    {
        letters[i] = 45; //sets each value of array letters to '-' (ie ASCII code 45) so that if a certain letter is not decrypted, it appears as '-' in decrypted message
    }
  input = fopen("encrypted.txt", "r");

        while(!feof(input))
	   {
	     fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(encrypt_text)+ 1;

        letter = 65; //sets value of 'letter' to ASCII number of 'A'
        /*
         *  The following for loop determines and stores in array 'count' how many times eash letter of the alphabbet is used within the encrypted message
         */        
        for(i = 0; i < 26; i++)
            {
                count[i] = 0;

                for(I = 0; I < size - 1; I++)
                {
                    if (encrypt_text[I] == letter)
                    {
                        count[i]++;
                    } 
                }

                letter++; 
                /*
                 * increases the value of 'letter' by 1 so to change the ASCII code stores and tested on each repeate of the for loop (ie progress through the alphabet from 
                 * A-Z)
                 */
            }
        break;
    }

    /*
     * The following FOR loop determines the lettert that occursmost often and stores the ASCII value of letter that occurs most often and sets it in array letters[4] 
     * (ie array of letter 'E' since E occursthe most often according to frequency analysis)
     */
    for(i = 0; i < 26; i++)
    {
        if (count[i] > tempcount)
        {
            letters[4] = 65 + i;
            tempcount = count[i];
            temp_i = i;
        }
    }

    printf("Letter E is %c\n", letters[4]);
    tempcount = 0;

    while(!feof(input))
	   {
    	    fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

            letter = 65; //sets value of 'letter' to ASCII number of 'A'

            /*
             * The following two FOR loop determines the most frequent letter that occurs atthe end of each word within a message and assigns the value to letters[18] (ie letter 'S') since 
             * accoding to frequency analysis, 'S' is the most frequent letter that occus at the end of words within text
             */            
            for (i = 0; i < 26 ; i++)
            {
                end_count[i] = 0;

                for(I = 0; I < size - 1; I++)
                {                            
                    if ((encrypt_text[I] == letter) && ((encrypt_text[I + 1] == ' ') || (encrypt_text[I + 1] == 46)) && (encrypt_text[I - 1] >= 65) && 
                        (encrypt_text[I-  1] <= 90) && (encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
                    {
                        end_count[i]++;
                    } 
                }
                letter++;
                /*
                 * increases the value of 'letter' by 1 so to change the ASCII code stores and tested on each repeate of the for loop (ie progress through the alphabet 
                 * from A-Z)
                 */
            }
            break;
        }

     for(i = 0; i < 26; i++)
    {
        if ((end_count[i] > tempcount) && (i != temp_i))
        {
            letters[18] = 65 + i;
            tempcount = end_count[i];
        }
    }

    printf("Letter S is %c\n", letters[18]);
    tempcount = 0;

    /*
     * The following FOR loop determines the letter that occurs after an appostrophe (ie ASCII code 39) and is not the ASCII value stores in letters[18]
     * (ie letter 'S') and stores it in letters[19] (ie letter 'T'). In other words, loop finds ''T ' within the text
     */
    for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == 39) && (encrypt_text[I + 2] == ' ') && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] >= 65) && 
	       (encrypt_text[I + 1] <= 90))
	   {
	       letters[19] = encrypt_text[I + 1];
	       printf("Letter T is %c\n", letters[19]);
	       break;
	   }
	}

    /*
     * The following FOR loop determines the letter that occurs between the letters[19] (ie letter 'T'),  letters[4] (ie letter 'E') and two spaces
     *(ie ' ') and stores it in letters[7] (ie letter 'H'). In other words, loop find the word ' THE ' within the text     
     */
  	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 3] == letters[4]) && (encrypt_text[I + 4] == ' ') 
	        && (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90))
	   {
	       letters[7] = encrypt_text[I + 2];
	       printf("Letter H is %c\n", letters[7]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after the letters[19] (ie letter 'T') and two spaces(ie ' ') and stores it in letters[14] 
     * (ie letter 'O'). In other words, loop find the word ' TO ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 2] >= 65) && 
	       (encrypt_text[I + 2] <= 90) )
	   {
	       letters[14] = encrypt_text[I + 2];
	       printf("Letter O is %c\n", letters[14]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs before an appostrophe (ie ASCII code 39), letters[19] (ie letter 'T') and a space(ie ' ') and
     * stores it in letters[13] (ie letter 'N'). In other words, loop find the letter sequence 'N'T ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == 39) && (encrypt_text[I + 2] == letters[19]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 2] >= 65) && 
	       (encrypt_text[I + 2] <= 90) )
	   {
	       letters[13] = encrypt_text[I];
	       printf("Letter N is %c\n", letters[13]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after a space (ie ' '), letters[19] (ie letter 'T'), letters[7] (ie letter 'H') and 
     * before letters[19] (ie letter 'T') or letters[13] (ie letter 'N') and a spance, then assigns it to letters[0] (ie letter 'A'). In other words, loop finds word 
     * ' THAT ' or ' THAN ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 2] == letters[7]) && ((encrypt_text[I + 4] == letters[19]) || 
	       (encrypt_text[I + 4] == letters[13]))  && (encrypt_text[I + 5] == ' ') && (encrypt_text[I + 3] >= 65) && (encrypt_text[I + 3] <= 90))
	   {
	       letters[0] = encrypt_text[I + 3];
	       printf("Letter A is %c\n", letters[0]);
	       break;
	   }
	}

	    
    /*
     * The following FOR loop determines the letter that occurs after a space (ie ' '), letters[19] (ie letter 'T'), letters[7] (ie letter 'H') and 
     * before letters[19] (ie letter 'T') or letters[13] (ie letter 'N') and a spance, then assigns it to letters[0] (ie letter 'A'). In other words, loop finds word 
     * ' THAT ' or ' THAN ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 2] == ' ') && (encrypt_text[I + 1] != letters[8]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[0] = encrypt_text[I + 3];
	       printf("Letter A is %c\n", letters[0]);
	       break;
	   }
	}
    
	/*
     * The following FOR loop determines the letter that occurs beofore a space (ie ' ') and after either letters[13] (ie letter 'N') or letters[18] (ie letter 'S') 
     * or letters[19] (ie letter 'T') and a space (ie ' '), plus is not equal to letters[0], and assigns it to letters[8]. In other words, loop finds the words ' IN ',
     * ' IS ' or ' IT ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && ((encrypt_text[I + 2] == letters[13]) || (encrypt_text[I + 2] == letters[18]) || (encrypt_text[I + 2] == letters[19])) && 
	       (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && (encrypt_text[I + 1] != letters[0]))
	   {
	       letters[8] = encrypt_text[I + 1];
	       printf("Letter I is %c\n", letters[8]);
	       break;
	   }
	}
	
	/*
     * The following FOR loop determines the letter that occurs between two spaces (ie ' ') and is not equal letters[0] (ie letter 'A') and assigns it to letters[8]
     * (ie letter 'I'). In other words, loop finds the letter ' I ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 2] == ' ') && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && (encrypt_text[I + 1] != letters[0]))
	   {
	       letters[8] = encrypt_text[I + 1];
	       printf("Letter I is %c\n", letters[8]);
	       break;
	   }
	}
	

	/*
     * The following FOR loop determines the letter that occurs after a space (ie ' '), letters[8] (ie letter 'I') or letters[14] (ie letter O) and before a space 
     * (ie ' ') and assigns it to letters[5] (ie letter 'F'). In other words, loop finds the letter ' IF ' or ' OF ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && ((encrypt_text[I + 1] == letters[8]) || (encrypt_text[I + 1] == letters[14])) && (encrypt_text[I + 3] == ' ') && 
	       (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90) && (encrypt_text[I + 2] != letters[18]))
	   {
	       letters[5] = encrypt_text[I + 2];
	       printf("Letter F is %c\n", letters[5]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after a space (ie ' ') and before letters[0] (ie letter 'A'), letters[13] (ie letter 'N') and a space 
     * (ie ' ') and assigns it to letters[3] (ie letter 'D'). In other words, loop finds the word ' AND ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[0]) && (encrypt_text[I + 2] == letters[13]) && (encrypt_text[I + 4] == ' '))
	   {
	       letters[3] = encrypt_text[I + 3];
	       printf("Letter D is %c\n", letters[3]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[0] (ie letter 'A'), letters[4] (ie letter 'E') or letters[8] (ie letter 'I') and 
     * letters[13] (ie letter 'N'), plus before letters[4] (ie letter 'E') and a space (ie ' ') and assigns it to letters[2] (ie letter 'C'). In other words, 
     * loop finds the letter sequence 'ANCE ' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[4]) || (encrypt_text[I] == letters[8])) && (encrypt_text[I + 1] == letters[13]) && 
	       (encrypt_text[I + 3] == letters[4]) && (encrypt_text[I + 4] == ' '))
	   {
	       letters[2] = encrypt_text[I + 2];
	       printf("Letter C is %c\n", letters[2]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs before letters[4] (ie letter 'E'), letters[13] (ie letter 'N'),ters[19] (ie letter 'T') and 
     * a space (ie ' '), and assigns it to letters[12] (ie letter 'M'). In other words, loop finds the letter sequence 'MENT ' within the text     
     */
	// need to fix M
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == letters[4]) && (encrypt_text[I + 2] == letters[13]) && (encrypt_text[I + 3] == letters[19]) && ((encrypt_text[I + 4] == ' ') 
	        || (encrypt_text[I + 4] == letters[18])))
	   {
	       letters[12] = encrypt_text[I];
	       printf("Letter M is %c\n", letters[12]);
	       break;
	   }
	}

    /*
     * The following FOR loop determines the letter that occurs after letters[8] (ie letter 'I'), letters[13] (ie letter 'N') plus before a space (ie ' ') and 
     * assigns it to letters[6] (ie letter 'G'). In other words, loop finds the letter sequence 'ING ' within the text     
     */
    for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == letters[8]) && (encrypt_text[I + 1] == letters[13]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I - 1] >= 65) && 
	       (encrypt_text[I - 1] <= 90) && (encrypt_text[I + 2] != letters[18]))
	   {
	       letters[6] = encrypt_text[I + 2];
	       printf("Letter G is %c\n", letters[6]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs before letters[18] (ie letter 'S') and is not equal to letters[0] (ie letter 'A'), letters[13] 
     * (ie letter 'N'), letters[4] (ie letter 'E'), letters[8] (ie letter 'I') or letters[14] (ie letter 'O') and assigns it to letters[20] (ie letter 'U'). In 
     * other words, loop finds the letter sequence 'US' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == letters[18]) && (encrypt_text[I] != letters[0]) && (encrypt_text[I] != letters[13]) && (encrypt_text[I] != letters[4]) && 
	       (encrypt_text[I] != letters[8]) && (encrypt_text[I] != letters[14]) && (encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
	   {
	       letters[20] = encrypt_text[I];
	       printf("Letter U is %c\n", letters[20]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[4] (ie letter 'E') and before a space (ie ' '), letters[18] (ie letter 'S'), letters[13] 
     * (ie letter 'N') or letters[3] (ie letter 'D'). The letter also is not equal to letters[18] (ie letter 'S'), letters[4] (ie letter 'E'), letters[12] 
     * (ie letter 'M') or letters[0] (ie letter 'A') and is assigned to letters[17](ie letter 'R'). In other words, loop finds the letter sequences 'ER ', 'ERS', 'ERN' 
     * or 'ERD' within the text     
     */
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == letters[4]) && ((encrypt_text[I + 2] == ' ') || (encrypt_text[I + 2] == letters[18]) || (encrypt_text[I + 2] == letters[13]) || 
	       (encrypt_text[I + 2] == letters[3])) && (encrypt_text[I + 1] != letters[13])  && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[4]) 
	        && (encrypt_text[I + 1] != letters[12]) && (encrypt_text[I + 1] != letters[0]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[17] = encrypt_text[I + 1];
	       printf("Letter R is %c\n", letters[17]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[4] (ie letter 'E'), or letters[0] (ie letter 'A') and does not equal letters[4] 
     * (ie letter 'E'), letters[18] (ie letter 'S'), letters[19] (ie letter 'T'), letters[5] (ie letter 'F'), letters[17] (ie letter 'R'), letters[2] (ie letter 'C') or 
     * letters[14] (ie letter 'O'). The letter after the letter being determined must be the same letter (ie letter occur in double) and assign it to letters[11] 
     * (ie letter 'L')and before a space (ie ' '), letters[18] (ie letter 'S'), letters[13] 
     * (ie letter 'N'). In other words, loop finds the letter sequences 'LL' within the text
     */
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[4]) || (encrypt_text[I] == letters[0])) && (encrypt_text[I + 1] == encrypt_text[I + 2]) && (encrypt_text[I + 1] != letters[4]) 
	        && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[17]) 
	        && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[14]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[11] = encrypt_text[I + 1];
	       printf("Letter L is %c\n", letters[11]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[0] (ie letter 'A'), letters[8] (ie letter 'I') or letters[14] (ie letter 'O') and before 
     * letter letters[4] (ie letter 'E'). Also the letter does not equal letters[2] (ie letter 'C'), letters[5] (ie letter 'F'), letters[6] (ie letter 'G'), letters[17] 
     * (ie letter 'R'), letters[18] (ie letter 'S'), letters[19] (ie letter 'T'), letters[13] (ie letter 'N') or letters[11] (ie letter 'L') and assigns it to letters[21] 
     * (ie letter 'V').  In other words, loop finds the letter sequences 'AVE' within the text
     */
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[8]) || (encrypt_text[I] == letters[14])) && (encrypt_text[I + 1] != letters[2]) && 
	       (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[6]) && (encrypt_text[I + 1] != letters[17]) && (encrypt_text[I + 1] != letters[18]) 
	       && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[13]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 2] == letters[4]))
	   {
	       letters[21] = encrypt_text[I + 1];
	       printf("Letter V is %c\n", letters[21]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[0] (ie letter 'A'), letters[8] (ie letter 'I'), letters[14] (ie letter 'O') or  letters[4]
     * (ie letter 'E') and before letters[4] (ie letter 'E') or letters[18] (ie letter 'S'). Also the letter does not equal letters[6] (ie letter 'G'), letters[5] 
     * (ie letter 'F') letters[2] (ie letter 'C'), letters[21] (ie letter 'V'), letters[18] (ie letter 'S'), letters[4] (ie letter 'E'), letters[20] (ie letter 'U'), 
     * letters[8] (ie letter 'I'), letters[13] (ie letter 'N') or letters[17] (ie letter 'R'). In other words, loop finds the letter sequences 'APE', 'IPE', OPE', 'EPE', 
     * 'SPE', 'APS', 'IPS', 'OPS', 'EPS' or 'SPS' within the text
     */
	//need to fix
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[8]) || (encrypt_text[I] == letters[14]) || (encrypt_text[I] == letters[4])) && 
	       (encrypt_text[I + 1] != letters[6]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[21]) 
	       && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[20]) && (encrypt_text[I + 1] != letters[8]) 
	       && (encrypt_text[I + 1] != letters[0]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 1] != letters[3]) 
	       && (encrypt_text[I + 1] != letters[13]) && (encrypt_text[I + 1] != letters[17]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && 
	       ((encrypt_text[I + 2] == letters[4]) || (encrypt_text[I + 2] == letters[18])))
	   {
	       letters[15] = encrypt_text[I + 1];
	       printf("Letter P is %c\n", letters[15]);
	       break;
	   }
	}

	/*
     * The following FOR loop determines the letter that occurs after letters[2] (ie letter 'C'), letters[14] (ie letter 'O') or letters[13] (ie letter 'N') and does not 
     * equal letters[6] (ie letter 'G'), letters[5] (ie letter 'F') letters[2] (ie letter 'C'), letters[21] (ie letter 'V'), letters[18] (ie letter 'S'), letters[4] 
     * (ie letter 'E'), letters[20] (ie letter 'U'), letters[8] (ie letter 'I'), letters[0] (ie letter 'A'), letters[19] (ie letter 'T'), letters[11] (ie letter 'L'), 
     * letters[3] (ie letter 'D'), letters[13] (ie letter 'N'). In other words, loop finds the letter sequences 'CK', 'OK' or 'NK' within the text
     */
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[2]) || (encrypt_text[I] == letters[14]) || (encrypt_text[I] == letters[13])) && (encrypt_text[I + 1] != letters[6]) && 
	       (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[21]) && (encrypt_text[I + 1] != letters[18]) 
	       && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[20]) && (encrypt_text[I + 1] != letters[8]) && (encrypt_text[I + 1] != letters[0]) 
	       && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 1] != letters[3]) && (encrypt_text[I + 1] != letters[13]) 
	       && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[10] = encrypt_text[I + 1];
	       printf("Letter K is %c\n", letters[10]);
	       break;
	   }
	}

	Decryption(letters, orig_letters);
	
}

/*
 * The following function takes two arrays from a previous function (ie an array containing original letters and another of their corresponding encrypted letters) and 
 * encrypts the message from origional.txt according to the two arrays, printing it to console and to encrypted.txt
 */
void Encryption(int letters[alph], int orig_letters[alph])
{
   int i, I, size = 500;
   char origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;

   input = fopen("origional.txt", "r"); //reads message from origional.txt

	while(!feof(input))
	{
	     fgets(origional_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(origional_text)+ 1;

	     printf("Old: %s", origional_text); //original message is printed

        /*
         * The following FOR loop assesses each charater stored in a particuar origional_text[I] and determines if it is a capital letter character. If so, it then 
         * compares the value of the values of orig_letters array carried from previously executed function. When value matched, the value stored in the orig_letters[i] 
         * is stored in a new array encrypt_text[I]. If the character stored in origional_text[I] is a space or symbol character (e.g. !, @, #, $, %, ^, &, *, -, +, = etc.), 
         * the symbol is stored in encrypt_text[I].
         */
        for (I = 0; I < (size - 1); I++)
        {
             if ((origional_text[I] >= 65) && (origional_text[I] <= 90)) 
             {
                 for (i = 0; i < 26; i++)
                {             
                     if (origional_text[I] == orig_letters[i])
                     {
                         encrypt_text[I] = letters[i]; 
                         /*
                          * Tests for match between a letter stored in origional_text[I] and orig_letters[i] then assigns the value of orig_letters[i] to encrypt_text[I]
                          */
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

        output = fopen("encrypted.txt", "w"); //writes encrypted message according to the letters/symboles assigned in array encrypt_text

        printf("\nNew: %s ",encrypt_text); //array encrypt_text (ie encrypted message) is printed to console
        fprintf(output, "%s\n", encrypt_text); //array encrypt_text (ie encrypted message) is printed to encrypted.txt
        break;
	}
}

/*
 * The following function takes two arrays from a previous function (ie an array containing original letters and another of their corresponding encrypted letters) and 
 * decrypts the message from encrypted.txt according to the two arrays, printing it to console and to origional.txt
 */
void Decryption(int letters[alph], int orig_letters[alph])
{
   int i, I, size = 500;
   char origional_text[size], encrypt_text[size];
   FILE *input;
   FILE *output;

   input = fopen("encrypted.txt", "r");  //reads encrypted message from encrypted.txt

	while(!feof(input))
	{
	     fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "encrypted.txt" into array encrypt_text  

         size = (int)strlen(encrypt_text)+ 1;

	     printf("Old: %s", encrypt_text); //encrypted message is printed


         /*
         * The following FOR loop assesses each charater stored in a particuar encrypted.txt[I] and determines if it is a capital letter character. If so, it then 
         * compares the value if encrypted.txt[I] ot the values of letters array carried from previously executed function. When value matched, the value stored in the letters[i] 
         * is stored in a new array origional_text[I]. If the character stored in encrypt_text[I] is a space or symbol character (e.g. !, @, #, $, %, ^, &, *, -, +, = etc.), 
         * the symbol is stored in origional_text[I].
         */      
        for (I = 0; I < (size - 1); I++)
        {
             if ((encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
             {
                 for (i = 0; i < 26; i++)
                {             
                     if (encrypt_text[I] == letters[i])
                     {
                         origional_text[I] = orig_letters[i]; 
                         /*
                          * Tests for match between a letter stored in encrypt_text[I] and letters[i] then assigns the value of letters[i] to origional_text[I]
                          */
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

        output = fopen("origional.txt", "w"); //writes original message according to the letters/symboles assigned in array origional_text

        printf("\nNew: %s ",origional_text); //array origional_text (ie original message) is printed to console
        fprintf(output, "%s\n", origional_text); //array encrypt_text (ie original message) is printed to origional.txt
        break;
    }    
}  
