/*
SoftSys 2019 Exercise 1
Head First C Cards
@Author: Manu Patil
*/

#include <stdio.h>
#include <stdlib.h>
void usr_Input(char *card_name);
int adjust_Count(int val);
void count_Cards();
int main()
{
  count_Cards(3);
  return 0;
}

/* Prompts user for input and puts it in the given buffer
  User input is truncated to the first two characters.

  card_name: buffer where result is stored
*/
void usr_Input(char *card_name){
  puts("Enter the card_name: ");
  scanf("%2s", card_name);
}

/* Takes a value of current card and adjusts count appropriately.
If card is high, count is reduced.
If card is low, count is increased.

val: value of cards
*/
int adjust_Count(int val){
  if((val>2) && (val<7)){
    return 1;
  } else if (val == 10){
    return -1;
  } else{
    return 0;
  }
}
/* Counts Cards to increase odds of winning at the popular game
of blackjack
Allows player to decide what the best time to place large and small bets
count: The initial value of the value telling an user whether to place a bet or not
*/
void count_Cards(int count){
  char card_name[3];
  int val = 0;
  do {
    usr_Input(card_name);
    val = 0;
    switch(card_name[0]){
      case 'K':
      case 'Q':
      case 'J':
        val = 10;
        break;
      case 'A':
        val = 11;
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
    count +=adjust_Count(val);
    printf("Current count: %i\n", count);

  } while (card_name[0] != 'X');
}
