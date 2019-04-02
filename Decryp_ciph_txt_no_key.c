#include <stdio.h>

//definition for a function that performs decryption given an algorithm, cipher text, and key

char cipher;
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
            break;
            
        case 'b':     
            printf("Case b Selected");
            break;
        }
    }
    
    else if (int_cipher < 97 || int_cipher > 99)
    {
        printf("Please make possible selection");
        return 0;
    }
    
}