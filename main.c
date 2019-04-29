#include <stdio.h>

main() {
    
// MENU: prints menu from which reader must choose an encryption/decryption option
int selection;
 
char message[100]; // inputted message array w max size of 100 characters, array structure: data_type array_name[array_size],
char character;    // character: individual character of message
int key, n;        // n: number that character is in string e.g. for 'hello', n=0 for 'h'

int x;             // x: number that character is in alphabet and cipher string
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
char cipher[26];   // cipher[]: user inputs cipher alphabet, all letters of alphabet in any mixed order to form key

    printf("Please select an option: \n");
    printf("1) Encrypt message with rotation cipher given cipher text and rotation amount \n");
    printf("2) Decrypt message encrypted with rotation cipher given cipher text and rotation amount \n");
    printf("3) Encrypt message with substitution cipher given message text and alphabet substitution \n");
    printf("4) Decrypt message encrypted with substitution cipher given cipher text and substitutions \n");
    
    scanf("%d", &selection); // compiler reads user's choice from above menu

switch(selection) //switch() case indicates what compiler should execute for each of above menu options 
{
    case 1: // Encryption of message w rotation cipher given message text and rotation amount
      
        printf("You selected option 1 \n");
     
        //RECEIVING ENCRYPTION MESSAGE FROM USER
        printf("Enter a text message for encryption: \n");
        scanf("%[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
        //RECEIVING KEY SHIFT FROM USER
        printf("Enter a key: \n");
        scanf("%d", &key);
        
        //IF: modulus used to take value of key/shit back to start of alphabet if bigger than 25
        if (key >= 26)
        {
            key = key % 26;  //e.g. if key = 29, key = 29%26 = 3
        }
        
        else
        {
            key = key; //key value remans unchanged
        }
        //TO DO: work out if this if() section is necessary, alphabet wrapping around to beginnning may make this unnecessary
        
    
        //  INITIAL: start at first character of string
        //  CONDITION: make sure character does not have 'null' value
        //  INCREMENT: move to next letter in string   
        for (n = 0; message[n] != '\0'; n++)
        {
            character = message[n];
        
            if (65 <= character && character <= 90) //if user inputs uppercase letter (numeric boundaries are ASCII standard values)
            {
                character += key;       //apply shift to character, operator shorthand (OS): character = character + key
                
                if (character > 90)     //90 is ASCII value for 'Z'
                {
                    character -= 26;    //wrap back to start of alphabet; 
                }
                
                message[n] = character; //assign shifted value of character to letter
            }
                
            else if (character >= 97 && character <= 122) //if user inputs lowercase character
            {
                character += key;       //apply shift to character
                
                if (character > 122)    // 122 is ASCII value for 'z'
                {
                    character -= 26;    //wrap back to start of alphabet, as if 'z' is number prior to 'a'       
                }
                
                message[n] = character; //assign shifted value of character to letter
            }
        }
    
        printf("Your encrypted message is: %s\n", message);
    
        break;
        
    
    case 2: // Decryption of message encrypted w rotation cipher given cipher text and rotation amount
    
        printf("You selected option 2 \n");
   
        //RECEIVING DECRYPTION MESSAGE FROM USER
        printf("Enter a text message for decryption: \n");
        scanf("%[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
        
        //RECEVING KEY SHIFT FROM USER
        printf("Enter a key: \n");
        scanf("%d", &key);
        
        //IF: modulus used to take value of key/shit back to start of alphabet if bigger than 25
        if (key >= 26)
        {
            key = key % 26;  //e.g. if key = 29, key = 29%26 = 3
        }
        
        else
        {
            key = key; //key value remans unchanged
        }
        //TO DO: work out if this if() section is necessary, alphabet wrapping around to beginnning may make this unnecessary
        
    
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
    
        printf("You selected task 3\n\n");
        
        //RECEIVING ENCRYPTION MESSAGE FROM USER
        printf("Enter a text message for encryption: \n");
        scanf("%[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
        //RECEIVING KEY ALPHABET FROM USER
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
    
        printf("You selected task 4 \n\n");
        
        //RECEIVING DECRYPTION MESSAGE FROM USER
        printf("Enter a text message for decryption: \n");
        scanf("%[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
        //RECEIVING KEY ALPHABET FROM USER
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
    
        printf("You did not select an option\n");
    
  return 0;
}
}
