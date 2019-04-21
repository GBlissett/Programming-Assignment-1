#include <stdio.h>
#include <string.h>

int main ()
{
   int k, i, letters[alph], under, orig_letters[alph], size = 500, count, curr_cnt, freq_num,key, j, shift;
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
       
        k = 26 - (freq_num - 69);
      
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
