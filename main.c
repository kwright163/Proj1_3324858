#include <stdio.h>

main() {
    
/*MENU: prints menu from which reader must choose an encryption/decryption option*/ 
int selection;
 
  printf("Please select an option: \n");
  printf("1) Encrypt message with rotation cipher given cipher text and rotation amount \n");
  printf("2) Decrypt message encrypted with rotation cipher given cipher text and rotation amount \n");
  printf("3) Encrypt message with substitution cipher given message text and alphabet substitution \n");
  printf("4) Decrypt message encrypted with substitution cipher given cipher text and substitutions \n");
  printf("5) Decrypt message encrypte with rotation cipher given cipher text only \n");
  printf("6) Decrypt message encrypted with substitution cipher given cipher text only \n \n");
   
  scanf("%d", &selection); // compiler reads user's choice from above menu
  
  
  
  switch(selection) //switch() statement inidicates to compiler what to execute for each of above menu options
  {
      case 1: //if user selects option 1, perform following: encrypt message provided cipher text and rotation amount*/
        printf("You selected option 1 \n");
          
        char message;
        int key;
        /* char encryption; */
      
        printf("Enter a text message for encryption: \n");
        scanf("%c", &message); //text message that will be encrypted using rotation cipher
      
        printf("Enter a key: \n");
        scanf("%d", &key);  // message will be encrypted using alphabetical shift of input integer
      
        /* perform encryption */
        /* print encryption: printf("Encrypted message: \n", &encryption); */
       
      case 2:
      
      case 3:
      
      case 4:
      
      case 5:
      
      case 6:
      
      default: //if user input doesn't match any of other options, perform following: 

  }
  

  return 0;
}
