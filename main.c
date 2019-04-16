#include <stdio.h>

main() {
    
/*MENU: prints menu from which reader must choose an encryption/decryption option*/ 
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
  
  /*if() statements below used to indicate what to execute for each of above menu options*/
  
// switch() case indicates what compiler should execute for each of above menu options 
 /* switch() */

/*
  { 
      case 1: 
      
      */ 
     
        printf("You selected option 1 \n");
      
        char message[]; //data_type array_name[array_size]
        int key;
            
        printf("Enter a text message for encryption in lower-case letters only: \n");
        scanf("%c", message); //text message that will be encrypted using rotation cipher
            /* TODO: make %c read white/blank space */
        
        printf("Enter a key: \n");
        scanf("%d", &key);  // message will be encrypted using alphabetical shift of input integer
      
        // shift goes back to start of alphabet if key is equal to or larger than 26
        if (key>=26)
        {
            key = key%26;
        }
        
        int n;
        
        /*  INITIAL: start at first character of string
            CONDITION: make sure character does not have 'null' value
            INCREMENT: move to next letter in string   */
           
        for(n=0; message[n] != '\0'; n++);
        {
            
        }
        
/*
      case 3:
      
      case 4:
      
      case 5:
      
      case 6:
      
      default: //if user input doesn't match any of other options, perform following: 


      /* perform encryption */
      /* print encryption: printf("Encrypted message: \n", &encryption); */

  }
  

  return 0;
}
