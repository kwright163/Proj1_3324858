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
  
  /*if() statements below used to indicate what to execute for each of above menu options*/
  
  if(selection==1)  // TASK 1: ROTATION CIPHER: encrypt message provided cipher text and rotation amount 
  {
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
  }
  


  return 0;
}
