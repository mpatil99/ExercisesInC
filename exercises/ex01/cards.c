/*
SoftSys 2019 Exercise 1
Head First C Cards
@Author: Manu Patil
*/

#include <stdio.h>
#include <stdlib.h>
int main()
{
  char card_name[3];
  int count = 3;
  do {
    puts("Enter the card_name: ");
    scanf("%2s", card_name);
    int val = 0;
    switch(card_name[0]){
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 10;
        break;
      case 'X':
        continue;
      default:
        val = atoi(card_name);
        if((val<1)||(val>10)){
          puts("I don't understand that value!");
          continue;
        }
    }
    if((val>2) && (val<7)){
      count++;
    } else if (val == 10){
      count--;
    }
    printf("Current count: %i\n", count);

  } while (card_name[0] != 'X');
  return 0;
}
