#include <stdio.h>
#include <string.h> 

//alph = 26;

int main ()
{
   int i, I, letters[26], orig_letters[26], size = 500, count[26], letter, tempcount = 0, end_count[26], temp_i;
   char encrypt_text[size];
   FILE *input;
   
  printf ("Rotation Decryption without a key selected\n\n");
  
  for (i = 0; i < 26; i++)
    {
       orig_letters[i] =  65 + i; // assigns a ASCII code for the origional letter to a specifc location in an array
    }
   
  input = fopen("encrypted.txt", "r");
	
        while(!feof(input))
	   {
	     fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 

         size = (int)strlen(encrypt_text)+ 1;
                
        //printf("Size = %d", size)
        
        letter = 65;
        
        for(i = 0; i < 26; i++)
            {
                count[i] = 0;
                
                for(I = 0; I < size - 1; I++)
                {
                    //printf("%d letter is %d\n", I, encrypt_text[I]);
                    
                    if (encrypt_text[I] == letter)
                    {
                        count[i]++;
                    } 
                }
                
                //printf("Frequency of %c is %d\n", letter, count[i]);
                letter++;
            }

        break;
    }
    
    for(i = 0; i < 26; i++)
    {
        letters[i] = 45;
    }
    
    for(i = 0; i < 26; i++)
    {
        if (count[i] > tempcount)
        {
            letters[4] = 65 + i;
            tempcount = count[i];
            temp_i = i;
        }
    }

    //printf("Most freuquent letter is %c\n", E_num);
   // printf("temp_i is %d\n", temp_i);
    
    printf("Letter E is %c\n", letters[4]);
    tempcount = 0;
      
    while(!feof(input))
	   {
    	    fgets(encrypt_text, size, (FILE *)input); //stores the chars in the text form the input file "origional.txt" into array origional_text 
    
            letter = 65;
            for (i = 0; i < 26 ; i++)
            {
                end_count[i] = 0;
                        
                for(I = 0; I < size - 1; I++)
                {
                    //printf("%d letter is %d\n", I, encrypt_text[I]);
                            
                    if ((encrypt_text[I] == letter) && ((encrypt_text[I + 1] == ' ') || (encrypt_text[I + 1] == 46)) && (encrypt_text[I - 1] >= 65) && (encrypt_text[I-  1] <= 90) && (encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
                    {
                        end_count[i]++;
                    } 
                }
                //printf("Frequency of %c at the end of words is %d\n", letter, end_count[i]);
                letter++;
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
    
    for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == 39) && (encrypt_text[I + 2] == ' ') && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[19] = encrypt_text[I + 1];
	       printf("Letter T is %c\n", letters[19]);
	       break;
	   }
	}
    
    
  	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 3] == letters[4]) && (encrypt_text[I + 4] == ' ') && (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90))
	   {
	       letters[7] = encrypt_text[I + 2];
	       printf("Letter H is %c\n", letters[7]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90) )
	   {
	       letters[14] = encrypt_text[I + 2];
	       printf("Letter O is %c\n", letters[14]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == 39) && (encrypt_text[I + 2] == letters[19]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90) )
	   {
	       letters[13] = encrypt_text[I];
	       printf("Letter N is %c\n", letters[13]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[19]) && (encrypt_text[I + 2] == letters[7]) && ((encrypt_text[I + 4] == letters[19]) || (encrypt_text[I + 4] == letters[13]))  && (encrypt_text[I + 5] == ' ') && (encrypt_text[I + 3] >= 65) && (encrypt_text[I + 3] <= 90))
	   {
	       letters[0] = encrypt_text[I + 3];
	       printf("Letter A is %c\n", letters[0]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 2] == ' ') && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && (encrypt_text[I + 1] != letters[0]))
	   {
	       letters[8] = encrypt_text[I + 1];
	       printf("Letter I is %c\n", letters[8]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && ((encrypt_text[I + 2] == letters[13]) || (encrypt_text[I + 2] == letters[18]) || (encrypt_text[I + 2] == letters[19])) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && (encrypt_text[I + 1] != letters[0]))
	   {
	       letters[8] = encrypt_text[I + 1];
	       printf("Letter I is %c\n", letters[8]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && ((encrypt_text[I + 1] == letters[8]) || (encrypt_text[I + 1] == letters[14])) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I + 2] >= 65) && (encrypt_text[I + 2] <= 90) && (encrypt_text[I + 2] != letters[18]))
	   {
	       letters[5] = encrypt_text[I + 2];
	       printf("Letter F is %c\n", letters[5]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == ' ') && (encrypt_text[I + 1] == letters[0]) && (encrypt_text[I + 2] == letters[13]) && (encrypt_text[I + 4] == ' '))
	   {
	       letters[3] = encrypt_text[I + 3];
	       printf("Letter D is %c\n", letters[3]);
	       break;
	   }
	}
	
	
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[4]) || (encrypt_text[I] == letters[8])) && (encrypt_text[I + 1] == letters[13]) && (encrypt_text[I + 3] == letters[4]) && (encrypt_text[I + 4] == ' '))
	   {
	       letters[2] = encrypt_text[I + 2];
	       printf("Letter C is %c\n", letters[2]);
	       break;
	   }
	}
	
	// need to fix M
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == letters[4]) && (encrypt_text[I + 2] == letters[13]) && (encrypt_text[I + 3] == letters[19]) && ((encrypt_text[I + 4] == ' ') || (encrypt_text[I + 4] == letters[18])))
	   {
	       letters[12] = encrypt_text[I];
	       printf("Letter M is %c\n", letters[12]);
	       break;
	   }
	}

    for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == letters[8]) && (encrypt_text[I + 1] == letters[13]) && (encrypt_text[I + 3] == ' ') && (encrypt_text[I - 1] >= 65) && (encrypt_text[I - 1] <= 90) && (encrypt_text[I + 2] != letters[18]))
	   {
	       letters[6] = encrypt_text[I + 2];
	       printf("Letter G is %c\n", letters[6]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I + 1] == letters[18]) && (encrypt_text[I] != letters[0]) && (encrypt_text[I] != letters[13]) && (encrypt_text[I] != letters[4]) && (encrypt_text[I] != letters[8]) && (encrypt_text[I] != letters[14]) && (encrypt_text[I] >= 65) && (encrypt_text[I] <= 90))
	   {
	       letters[20] = encrypt_text[I];
	       printf("Letter U is %c\n", letters[20]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if ((encrypt_text[I] == letters[4]) && ((encrypt_text[I + 2] == ' ') || (encrypt_text[I + 2] == letters[18]) || (encrypt_text[I + 2] == letters[13]) || (encrypt_text[I + 2] == letters[3])) && (encrypt_text[I + 1] != letters[13])  && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[12]) && (encrypt_text[I + 1] != letters[0]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[17] = encrypt_text[I + 1];
	       printf("Letter R is %c\n", letters[17]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[4]) || (encrypt_text[I] == letters[0])) && (encrypt_text[I + 1] == encrypt_text[I + 2]) && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[17]) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[14]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[11] = encrypt_text[I + 1];
	       printf("Letter L is %c\n", letters[11]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[8]) || (encrypt_text[I] == letters[14])) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[6]) && (encrypt_text[I + 1] != letters[17]) && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[13]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 2] == letters[4]))
	   {
	       letters[21] = encrypt_text[I + 1];
	       printf("Letter V is %c\n", letters[21]);
	       break;
	   }
	}
	
	//need to fix
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[0]) || (encrypt_text[I] == letters[8]) || (encrypt_text[I] == letters[14]) || (encrypt_text[I] == letters[4])) && (encrypt_text[I + 1] != letters[6]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[21]) && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[20]) && (encrypt_text[I + 1] != letters[8]) && (encrypt_text[I + 1] != letters[0]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 1] != letters[3]) && (encrypt_text[I + 1] != letters[13]) && (encrypt_text[I + 1] != letters[17]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90) && ((encrypt_text[I + 2] == letters[4]) || (encrypt_text[I + 2] == letters[18])))
	   {
	       letters[15] = encrypt_text[I + 1];
	       printf("Letter P is %c\n", letters[15]);
	       break;
	   }
	}
	
	for (I = 0; I < size - 1; I++)
	{
	   if (((encrypt_text[I] == letters[2]) || (encrypt_text[I] == letters[14]) || (encrypt_text[I] == letters[13])) && (encrypt_text[I + 1] != letters[6]) && (encrypt_text[I + 1] != letters[5]) && (encrypt_text[I + 1] != letters[2]) && (encrypt_text[I + 1] != letters[21]) && (encrypt_text[I + 1] != letters[18]) && (encrypt_text[I + 1] != letters[4]) && (encrypt_text[I + 1] != letters[20]) && (encrypt_text[I + 1] != letters[8]) && (encrypt_text[I + 1] != letters[0]) && (encrypt_text[I + 1] != letters[19]) && (encrypt_text[I + 1] != letters[11]) && (encrypt_text[I + 1] != letters[3]) && (encrypt_text[I + 1] != letters[13]) && (encrypt_text[I + 1] >= 65) && (encrypt_text[I + 1] <= 90))
	   {
	       letters[10] = encrypt_text[I + 1];
	       printf("Letter K is %c\n", letters[10]);
	       break;
	   }
	}
	
	Decryption(orig_letters, letters);
}
   
     
