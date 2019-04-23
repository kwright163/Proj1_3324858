#include <stdio.h>

main() {
    
// MENU: prints menu from which reader must choose an encryption/decryption option
/*
int selection;
 
  printf("Please select an option: \n");
  printf("1) Encrypt message with rotation cipher given cipher text and rotation amount \n");
  printf("2) Decrypt message encrypted with rotation cipher given cipher text and rotation amount \n");
  printf("3) Encrypt message with substitution cipher given message text and alphabet substitution \n");
  printf("4) Decrypt message encrypted with substitution cipher given cipher text and substitutions \n");
  printf("5) Decrypt message encrypte with rotation cipher given cipher text only \n");
  printf("6) Decrypt message encrypted with substitution cipher given cipher text only \n \n");
   
  scanf("%d", &selection); // compiler reads user's choice from above menu

 switch() //switch() case indicates what compiler should execute for each of above menu options 

*/

/*
  { 
      case 1: 
      
      */ 
     
        printf("You selected option 1 \n");
      
        char message[100]; // inputted message array w max size of 100 characters, array structure: data_type array_name[array_size],
        char character;    // character: individual character of message
        int key, n;        // n: number that character is in string e.g. for 'hello', n=0 for 'h'
   
        //RECEIVING ENCRYPTION MESSAGE FROM USER
        printf("Enter a text message for encryption: \n");
        scanf("%[^\n]s", message); //compiler receives message from user input and stores in 'message
    
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
        
    
    /*  INITIAL: start at first character of string
        CONDITION: make sure character does not have 'null' value
        INCREMENT: move to next letter in string   */
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
        

  return 0;
}
