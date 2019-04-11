#include <stdio.h>

main() {
    
   /*insert menu w 6 assessment options */
   
   
   /*TASK 1: ROTATION CIPHER: encrypt message provided cipher text and rotation amount */
  
 char message;
 int key;
 char encryption;
 
 printf("Enter a text message for encryption: \n");
 scanf("%c", &message);
 
 
 printf("Enter a key: \n");
 scanf("%d", &key);  // message will be encrypted using alphabetical shift of input integer
  
  /* perform encryption */
 
 printf("Encrypted message: \n", &encryption);

  return 0;
}
