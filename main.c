/* This program is designed to encrypt and decrypt text messages using the rotation and substitution ciphers. 
The user is required to read the menu printed on the screen and input the desired task number in the ‘input’ file in the compiler.

The rotation cipher replaces each letter of the alphabet with another letter a  fixed number of places away in the alphabet. The key, or the ‘shift’, is the number 
of letters that the alphabet is rotated by when producing the substitution letters. The user is required to input the message to be encrypted and the key shift into 
the ‘input’ file. The compiler will then assign the number that the character is in the message (e.g. in the word “hello”, the letter ‘h’ would have the place ‘0’ 
in the array, whilst ‘e’ would have the place ‘1’). The compiler will take the ASCII value of the input characters, add the key shift and then convert the number 
back into ASCII values, the compiler stores and prints the value of the encrypted letter, before moving on to the next character in the input message, and so on. If 
the ASCII value overreaches the end of the alphabet, it will loop back to the start, hence ‘rotating’ the alphabet. The user will see the encrypted message printed
as a whole. The reverse is done when decrypting messages.

The substitution cipher requires the user to input an encryption message and a ‘cipher’ alphabet – they must input all letters of the alphabet in any order. Each 
letter in the straight ‘A’ to ‘Z’ alphabet is then replaced by the letter a corresponding numbers of places in the alphabet, e.g. if the cipher was 
“QWERTYUIOPASDFGHJKLZXCVBNM”, then ‘A’ would be replaced by ‘Q’ and so on. The compiler will roll through alphabet until it finds a letter in the alphabet that is the
same number of places through the cipher, then will assign the value of the cipher to the original character, forming the encryption and storing and printing the 
encrypted character, before moving onto the next letter in the message. The user will see the encrypted message printed as a whole. The reverse is done when encrypting 
messages 

The limitation to the functions of this program include:
- the compiler can only process capital letters. 
- the substitution cipher will only process inputted ciphers that contain the entire alphabet without any whitespace
- if the user does not input any option between 1-4, the compiler will print an 'error' message, but will not re-start the program
- the user must restart the program any time they want to observe any other task, the program finishes running after it completes a single task
- the cipher can only process messages with a maximum of 300 characters*/


#include <stdio.h>

main() 
{
    
    int selection;     // selection: user chooses task from menu
   
    int key, n, x;     // n: number that character is in string e.g. for 'hello', n=0 for 'h', x: number that character is in alphabet and cipher string
    char message[300]; // inputted message array w max size of 100 characters, array structure: data_type array_name[array_size],
    char character;    // character: individual character of message
    char cipher[26], alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"; // cipher[]: user inputs cipher alphabet, all letters of alphabet in any mixed order to form key

    //  MENU: prints menu from which reader must choose an encryption/decryption option
    printf("Please select an option: \n");
    printf("1) Encrypt message with rotation cipher given cipher text and rotation amount \n");
    printf("2) Decrypt message encrypted with rotation cipher given cipher text and rotation amount \n");
    printf("3) Encrypt message with substitution cipher given message text and alphabet substitution \n");
    printf("4) Decrypt message encrypted with substitution cipher given cipher text and substitutions \n\n");
    
    scanf("%d", &selection); // compiler reads user's choice from above menu
    printf("You selected option %d\n", selection);

    switch(selection) // SWITCH: indicates what compiler should execute for each of above menu option, e.g. if selection == 1; execute case 1
    {
        case 1: // Encryption of message w rotation cipher given message text and rotation amount
     
            printf("Enter a text message for encryption: \n");  // compiler receives encryption message from user
            scanf("  %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
            printf("Enter a key: \n");  // compiler receives key shift
            scanf("%d", &key);
        
            //  INITIAL: start at first character of string
            //  CONDITION: make sure character does not have 'null' value
            //  INCREMENT: move to next letter in string   
            for (n = 0; message[n] != '\0'; n++)    
            {
                character = message[n];
        
                if ('A' <= character && character <= 'Z') //IF: if user inputs uppercase letter (numeric boundaries are ASCII standard values)
                {
                    character += key;       // apply shift to character, operator shorthand (OS): character = character + key
                
                    if (character > 'Z')     // 90 is ASCII value for 'Z'
                    {     
                        character -= 26;    // wrap back to start of alphabet; 
                    }
                
                    message[n] = character; // assign shifted value of character to letter
                }
            }
                
            printf("Your encrypted message is: %s\n", message);
    
            break;
        
        case 2: // Decryption of message encrypted w rotation cipher given cipher text and rotation amount
   
            printf("Enter a text message for decryption: \n"); // COMPILER RECEIVES MESSAGE FOR DECRYPTION
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
        
            printf("Enter a key: \n"); // COMPILER RECEIVES KEY SHIFT 
            scanf("%d", &key);
        
          
            for (n = 0; message[n] != '\0'; n++) // INIT: starts at first character of string; COND: character can't have 'null' value; INC.: move to next letter in string
            {
                character = message[n];
            
                if (character >= 65 && character <= 90) // if user inputs uppercase letter
                {
                    character -= key;       // apply shift backwards to character
                
                    if (character < 65)     // 65 is ASCII value for 'A'
                    {
                        character += 26;    // wrap back to end of alphabet, as if 'A' is number after 'Z'
                    }
                
                    message[n] = character; // assign reverse-shifted value of character to letter
                }
            }
    
            printf("Your decrypted message is: %s\n", message); 
        
            break;
        
        case 3:
        
            printf("Enter a text message for encryption: \n");  // COMPILER RECEIVES MESSAGE FOR ENCRYPTION
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
           
            printf("Enter the cipher alphabet in uppercase letters (the complete alphabet in any order) e.g. QWERTYUIOPASDFGHJKLZXCVBNM \n"); //COMPILER RECEIVES KEY FOR ALPHABET
            scanf("%s", cipher);
         
            for (n = 0; message[n] != '\0'; n++)    // INIT: starts at first character of string; COND: character can't have 'null' value; INC.: move to next character in string
            {
                character = message[n]; // first letter of message is 'assigned' to 'character', e.g. for first loop, character = message[0]
    
                /* TO DO: if character is between Z ad A */
    
                // INIT: starts at first character of string; COND: character can't have 'null' value; INC.: move to next letter in string
                for(x = 0; alphabet[x] != '\0'; x++)    // FOR: rolls through alphabet to match number that letter is in alphabet to letter that number is in cipher
                {
                   
                    if (alphabet[x] == character)  // if the value of 'x' in alphabet (e.g. A = 0) is the same as the value of 'character', assign value of original character in unencrypted message to cipher 
                    {
                        message[n] = cipher[x];
                    }
                }
            }
    
            printf("Your encrypted message is: %s\n", message);
    
            break;
        
        case 4:
    
            printf("Enter a text message for decryption: \n"); // COMPILER RECEIVES MESSAGE FOR DECRYPTION
            scanf(" %[^\n]s", message); // created 'input' file for user to input data for 'scanf()' to read and store in 'message' array
         
            printf("Enter the cipher alphabet in uppercase letters (the complete alphabet in any order) e.g. QWERTYUIOPASDFGHJKLZXCVBNM \n"); //COMPILER RECEIVES KEY ALPHABET
            scanf("%s", cipher);
    

            for (n = 0; message[n] != '\0'; n++) // INIT: starts at first character of string; COND: character can't have 'null' value; INC.: move to next letter in string
            {
                character = message[n]; // first letter of message is 'assigned' to 'character', e.g. for first loop, character = message[0]
        
                // INIT: start at first letter of alphabet 'A', COND: character can't have 'null' value (stops at end of alphabet), INC: move to next letter in alphabet
                for(x = 0; cipher[x] != '\0'; x++) // FOR: rolls through alphabet to match number that letter is in alphabet to letter that number is in cipher
                {
                    if (cipher[x] == character) // IF: if the value of 'x' in alphabet (e.g. A = 0) is the same as the value of 'character', assign value of original character in unencrypted message to cipher 
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