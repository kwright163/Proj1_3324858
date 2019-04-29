#include <stdio.h>

main() 
{
    
    int selection;     // selection: user chooses task from menu
 
    char message[200]; // inputted message array w max size of 100 characters, array structure: data_type array_name[array_size],
    char character;    // character: individual character of message
    int key, n, x;     // n: number that character is in string e.g. for 'hello', n=0 for 'h', x: number that character is in alphabet and cipher string

    char cipher[26], alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // cipher[]: user inputs cipher alphabet, all letters of alphabet in any mixed order to form key

    //  MENU: prints menu from which reader must choose an encryption/decryption option
    printf("Please select an option: \n");
    printf("1) Encrypt message with rotation cipher given cipher text and rotation amount \n");
    printf("2) Decrypt message encrypted with rotation cipher given cipher text and rotation amount \n");
    printf("3) Encrypt message with substitution cipher given message text and alphabet substitution \n");
    printf("4) Decrypt message encrypted with substitution cipher given cipher text and substitutions \n\n");
    
    scanf("%d", &selection); // compiler reads user's choice from above menu
    printf("You selected option %d\n", selection);

    // SWITCH: indicates what compiler should execute for each of above menu option, e.g. if selection == 1; execute case 1
    switch(selection) 
    {
        case 1: // Encryption of message w rotation cipher given message text and rotation amount
     
            //RECEIVING ENCRYPTION MESSAGE
            printf("Enter a text message for encryption: \n");
            scanf("  %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
           //RECEIVING KEY SHIFT
            printf("Enter a key: \n");
            scanf("%d", &key);
        
            //  INITIAL: start at first character of string
            //  CONDITION: make sure character does not have 'null' value
            //  INCREMENT: move to next letter in string   
            for (n = 0; message[n] != '\0'; n++)    
            {
                character = message[n];
        
                //IF: if user inputs uppercase letter (numeric boundaries are ASCII standard values)
                if (65 <= character && character <= 90)
                {
                    character += key;       //apply shift to character, operator shorthand (OS): character = character + key
                
                    if (character > 90)     //90 is ASCII value for 'Z'
                    {     
                        character -= 26;    //wrap back to start of alphabet; 
                    }
                
                    message[n] = character; //assign shifted value of character to letter
                }
             
                // ELSE IF: if user inputs lowercase letter
                else if (character >= 97 && character <= 122) 
                {
                    character += key;       //apply shift to character
                    
                    if (character > 122)    // 122 is ASCII value for 'z'
                    {
                        character -= 26;    //wrap back to start of alphabet, as if 'z' is number prior to 'a'       
                    }   
                    message[n] = character; //assign shifted value of character to letter
            
                }

                printf("Your encrypted message is: %s\n", message);
    
                break;
        
        case 2: // Decryption of message encrypted w rotation cipher given cipher text and rotation amount
   
            //RECEIVING DECRYPTION MESSAGE
            printf("Enter a text message for decryption: \n");
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
        
            //RECEVING KEY SHIFT
            printf("Enter a key: \n");
            scanf("%d", &key);
        
            //  INITIAL: start at first character of string
            //  CONDITION: make sure character does not have 'null' value
            //  INCREMENT: move to next letter in string   
            for (n = 0; message[n] != '\0'; n++)
            {
                character = message[n];
            
                if (character >= 65 && character <= 90) //if user inputs uppercase letter
                {
                    character -= key;       //apply shift backwards to character
                
                    if (character < 65)     //65 is ASCII value for 'A'
                    {
                        character += 26;    //wrap back to end of alphabet, as if 'A' is number after 'Z'
                    }
                
                    message[n] = character; //assign reverse-shifted value of character to letter
                }
            
                
                else if (character >= 97 && character <= 122) //if user inputs lowercase character
                {
                    character -= key;       //apply shift backwards to character
                
                    if (character < 97)    // 97 is ASCII value for 'a'
                    {
                        character += 26;    //wrap back to start of alphabet, as if 'a' is number after to 'z'       
                    }
                
                    message[n] = character; //assign reverse-shifted value of character to letter
                }
            }
    
            printf("Your decrypted message is: %s\n", message); 
        
            break;
        
        case 3:
        
            //RECEIVING ENCRYPTION MESSAGE
            printf("Enter a text message for encryption: \n");
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
            //RECEIVING KEY ALPHABET
            printf("Enter the cipher alphabet in uppercase letters (the complete alphabet in any order) e.g. QWERTYUIOPASDFGHJKLZXCVBNM \n");
            scanf("%s", cipher);
        
            //  INITIAL: start at first character of string
            //  CONDITION: make sure character does not have 'null' value
            //  INCREMENT: move to next letter in string   
            for (n = 0; message[n] != '\0'; n++)
            {
                character = message[n]; // first letter of message is 'assigned' to 'character', e.g. for first loop, character = message[0]
    
                /* TO DO: if character is between Z ad A */
    
                // FOR: rolls through alphabet to match number that letter is in alphabet to letter that number is in cipher
                // INITIAL: start at first letter of alphabet 'A'
                // CONDITION: make sure character does not have 'null' value (stops at end of alphabet, after 'Z')
                // INCREMENT: move to next letter in alphabet
                for(x = 0; alphabet[x] != '\0'; x++)
                {
                    // IF: if the value of 'x' in alphabet (e.g. A = 0) is the same as the value of 'character', assign value of original character in unencrypted message to cipher 
                    if (alphabet[x] == character)
                    {
                        message[n] = cipher[x];
                    }
                }
            }
    
            printf("Your encrypted message is: %s\n", message);
    
            break;
        
        case 4:
    
            //RECEIVING DECRYPTION MESSAGE
            printf("Enter a text message for decryption: \n");
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
         
            //RECEIVING KEY ALPHABET
            printf("Enter the cipher alphabet in uppercase letters (the complete alphabet in any order) e.g. QWERTYUIOPASDFGHJKLZXCVBNM \n");
            scanf("%s", cipher);
        
            //  INITIAL: start at first character of string
            //  CONDITION: make sure character does not have 'null' value
            //  INCREMENT: move to next letter in string   
            for (n = 0; message[n] != '\0'; n++)
            {
                character = message[n]; // first letter of message is 'assigned' to 'character', e.g. for first loop, character = message[0]
    
            /* TO DO: if character is between Z ad A */
        
                // FOR: rolls through alphabet to match number that letter is in alphabet to letter that number is in cipher
                // INITIAL: start at first letter of alphabet 'A'
                // CONDITION: make sure character does not have 'null' value (stops at end of alphabet, after 'Z')
                // INCREMENT: move to next letter in alphabet
                for(x = 0; cipher[x] != '\0'; x++)
                {
                // IF: if the value of 'x' in alphabet (e.g. A = 0) is the same as the value of 'character', assign value of original character in unencrypted message to cipher 
                    if (cipher[x] == character)
                    {
                        message[n] = alphabet[x];
                    }
                }
            }
    
            printf("Your decrypted message is: %s\n", message);
    
            break;
    
        default: 
    
            printf("You did not select a valid option\n");
    }

    return 0;

}
