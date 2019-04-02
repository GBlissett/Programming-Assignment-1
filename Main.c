#include <stdio.h>

char Encryp_alg_mess_txt_key(void); //prototype for a function that perfoms encryption given an algorithm, message text, and key
char Decryp_alg_ciph_txt_key(void); //prototype for a function that performs decryption given an algorithm, cipher text, and key
char Decryp_ciph_txt_no_key(void); // prototype for a function that performs decryption given cipher text and some assumptions of its contents without the key
int main ()
{
    char selection;
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
            printf("Case A Selected");
            Encryp_alg_mess_txt_key(void);
            break;
            
        case 'B':       
            printf("Case B Selected");
            Decryp_alg_ciph_txt_key(void);
            break;
        
        case 'C':
            printf("Case C Selected");
            Decryp_ciph_txt_no_key(void);
            break;
        }
    }
    
    else if (int_selection < 65 || int_selection > 67) //ie if int_selection (ie ASCII code) is outside the range for char A - C (ie ASCII 65 - 67)
    {
        printf("Please make valid selection");
        return 0;
    }
    
}