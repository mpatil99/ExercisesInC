/* SoftSys 2019 Hw

Manu Patil
License: GNU GPLv3

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*get_usr_input: Reads user input

returns: read_integer
*/
int get_usr_input(char* in,int* position, int length){
  if(fgets(in, 5, stdin)!= NULL) {
    // if(strlen(in)> 4){
      printf("\nLength of input is:%ld\n",strlen(in));
    // }
    return atoi(in);
  }
  else {
    printf("Thanks\n");
    *position = length;
    return 0;
  }
}

/*calc_sum
returns the calculated sum of values in an ARRAY
*/
int calc_sum(int* vals, int length){
  int j,sum = 0;
  for (j = 0; j < length; j++) {
    sum += *(vals+j);
    printf("Element[%d] = %d\n", j, *(vals+j));
  }
  return sum;
}

int main(){
  int input[10];
  char inputstr[4];
  int i, length = 0;
  int sum = 0;
  // i = 0;
  puts("Enter number and press \"Ctrl D\" to escape: ");
  while(i < 10){
    length = i;
    input[i] = get_usr_input(inputstr,&i,10);
    ++i;
  }

  sum = calc_sum(input, length);

  printf("Your final sum is: %d\n",sum);



  return 0;

}
