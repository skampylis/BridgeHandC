#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LENGTH 3
#define CARDS 13

// hand
struct hand {
  char cards[CARDS][MAX_LENGTH];
};

// O SPADES
// 1 HEARTS
// 2 DIAMONDS
// 3 CLUBS
char **distribution(struct hand a) {
  char **pack_of_cards;
  pack_of_cards = (char **)malloc(4 * sizeof(char *));
  for (int i = 0; i < 4; i++)
    pack_of_cards[i] = (char *)malloc(13 * sizeof(char));
  for (int i = 0; i < CARDS; i++)
    if (a.cards[i][1] == 'S')
      pack_of_cards[0][strlen(pack_of_cards[0])] = a.cards[i][0];
    else if (a.cards[i][1] == 'H')
      pack_of_cards[1][strlen(pack_of_cards[1])] = a.cards[i][0];
    else if (a.cards[i][1] == 'D')
      pack_of_cards[2][strlen(pack_of_cards[2])] = a.cards[i][0];
    else if (a.cards[i][1] == 'C')
      pack_of_cards[3][strlen(pack_of_cards[3])] = a.cards[i][0];
  return pack_of_cards;
}

// remove spaces
void removeSpaces(char *input) {
  int i, j = 0;
  for (i = 0; i < strlen(input); i++)
    if (input[i] != ' ')
      input[j++] = input[i];
  input[j] = '\0';
}

char *toString(char *text, int first, int second) {
  char *temp;
  temp = (char *)malloc(first - second + 1);
  temp[0] = text[first];
  temp[1] = text[second];
  return temp;
}

int readFromInput(struct hand a[]) {
  int size, c;
  char temp[50];
  scanf("%d", &size);
  ;
  for (int i = 0; i < size; i++) {
    while ((c = getchar()) != '\n' && c != EOF)
      ;
    scanf("%[^\n]s", temp);
    removeSpaces(temp);
    for (int j = 0; j <= strlen(temp) - 2; j += 2)
      strcpy(a[i].cards[(j / 2)], toString(temp, j, j + 1));
  }
  return size;
}

void printCards(const char *text, const char *key) {
  printf("%s ", text);
  for (int i = 0; i < strlen(key); i++)
    printf("%c ", key[i]);
  printf("\n");
}

// print hand
void printHand(struct hand a) {
  char **dist = distribution(a);
  printCards("SPADES:  ", dist[0]);
  printCards("HEARTS:  ", dist[1]);
  printCards("DIAMONDS:", dist[2]);
  printCards("CLUBS:   ", dist[3]);
}

// balance check
bool balanced(struct hand a) {
  char **dist = distribution(a);
  bool b = false;
  int counter = 0;
  for (int i = 0; i < 4; i++) {
    if (strlen(dist[i]) >= 2)
      counter++;
    if (strlen(dist[i]) == 0)
      return false;
    else if (strlen(dist[i]) == 2 && b == false)
      b = true;
    else if (strlen(dist[i]) == 2 && b == true)
      return false;
  }
  if (counter == 4)
    return true;
  else
    return false;
}

// counter 1
int hcp(struct hand a) {
  int counter = 0;
  for (int i = 0; i < CARDS; i++)
    if (a.cards[i][0] == 'A')
      counter = counter + 4;
    else if (a.cards[i][0] == 'K')
      counter = counter + 3;
    else if (a.cards[i][0] == 'Q')
      counter = counter + 2;
    else if (a.cards[i][0] == 'J')
      counter = counter + 1;
  return counter;
}

// counter 2
int declarer(struct hand a) {
  char **dist = distribution(a);
  int counter = 0;
  for (int i = 0; i < 4; i++)
    if (strlen(dist[i]) > 4)
      counter = counter + (strlen(dist[i]) - 4);
  return counter;
}

void response(struct hand a) {
  int counter = hcp(a);
  int all_counter = counter + declarer(a);
  char **dist = distribution(a);
  if (counter >= 15 && counter <= 17 && balanced(a) == true)
    printf("1NT\n");
  else if (counter >= 20 && counter <= 21 && balanced(a) == true)
    printf("2NT\n");
  else if (counter >= 22)
    printf("2 CLUBS\n");
  else if (counter < 22 && all_counter >= 13) {
    if (strlen(dist[0]) >= 5 && strlen(dist[1]) <= 5)
      printf("1 SPADES\n");
    else if (strlen(dist[1]) >= 5 && strlen(dist[0]) < strlen(dist[1]))
      printf("1 HEARTS\n");
    else if (strlen(dist[2]) >= 4 && strlen(dist[0]) < 5 &&
             strlen(dist[1]) < 5 && strlen(dist[3]) < 5)
      printf("1 DIAMONDS\n");
    else if (strlen(dist[0]) < 5 && strlen(dist[1]) < 5 && strlen(dist[2]) < 4)
      printf("1 CLUBS\n");
  } else if (all_counter < 13)
    printf("PASS\n");
}
