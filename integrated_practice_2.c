#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_FRIENDS 3 
  
typedef struct Monster Monster;

typedef struct Candy{ 
    char c_name[100];
    Monster *receiver;
}Candy;

typedef struct Monster{
    char m_name[100];
    int bars;
    Candy transaction[NUM_FRIENDS];
}Monster;

void count_donations(Monster *monsters, int num_monsters);
void print_monster_candy(Monster *monsters, int num_monsters);

int main(){

    int n;
    printf("Enter the number of Monsters: ");
    scanf("%d", &n);

    Monster *monsters = (Monster*) malloc (n*sizeof(Monster));
    //no need to create a Malloc for Candy since the array size is fixed

    if (monsters == NULL) {
        printf("Memory allocation failed.\n");
        return -1;
    }

    for(int i=0; i<n; i++){
        //Enter ith Monster name 
        printf("Enter the name of Monster %d: ", i+1);
        scanf("%s", monsters[i].m_name);
        monsters[i].bars = 0; 


        //Enter ith Monster candy_name and receiver_name in the transaction array
        for (int j = 0; j < NUM_FRIENDS; j++) {
            char friend_name[100];

            printf("Enter candy name and friend's name for transaction %d (or type 'none none' to skip): ", j + 1);
            scanf("%s %s", monsters[i].transaction[j].c_name, friend_name);

            // Check if the user wants to skip a transaction
            if (strcmp(monsters[i].transaction[j].c_name, "none") == 0 &&
                strcmp(friend_name, "none") == 0) {
                monsters[i].transaction[j].receiver = NULL;
                continue;  // Skip this transaction
            }

            for (int k = 0; k < n; k++) {
                if (strcmp(monsters[k].m_name, friend_name) == 0) {
                    monsters[i].transaction[j].receiver = &monsters[k];
                    break; 
                }
            }

        }
    }

    count_donations(monsters, n);
    print_monster_candy(monsters, n);

    free(monsters);

    return 0;

}


void count_donations(Monster *monsters, int num_monsters) {
    for (int i = 0; i < num_monsters; i++) {
        for (int j = 0; j < NUM_FRIENDS; j++) {
            // Monster *receiver is a pointer to the monster receiving the candy.
            // monsters[i].transactions[j].receiver points to the specific monster
            // who is the receiver in the j-th candy transaction of the i-th monster.
            // This pointer (receiver) was previously assigned with something like:
            // monsters[i].transactions[j].receiver = &monsters[k];
            Monster *receiver = monsters[i].transaction[j].receiver;

            // Check if the receiver is a valid monster (not NULL).
            if (receiver != NULL) {
                // If valid, increment the bars_received field of the receiver monster.
                // This tracks how many candies the receiving monster has received.
                receiver->bars++;
            }
        }
    }
}


void print_monster_candy(Monster *monsters, int n) {
    for (int i = 0; i < n; i++) {
        printf("%s will get a total of %d bars of candy.\n", monsters[i].m_name, monsters[i].bars);
    }
}



INPUT:
Enter the number of Monsters: 5
Enter the name of Monster 1: Mummy
Enter candy name and friend's name for transaction 1 (or type 'none none' to skip): Kit-Kat Swamp-Thing
Enter candy name and friend's name for transaction 2 (or type 'none none' to skip): none none
Enter candy name and friend's name for transaction 3 (or type 'none none' to skip): none none
Enter the name of Monster 2: Dracula
Enter candy name and friend's name for transaction 1 (or type 'none none' to skip): none none
Enter candy name and friend's name for transaction 2 (or type 'none none' to skip): none none
Enter candy name and friend's name for transaction 3 (or type 'none none' to skip): none none
Enter the name of Monster 3: Werewolf
Enter candy name and friend's name for transaction 1 (or type 'none none' to skip): Baby_Ruth Swamp-Thing
Enter candy name and friend's name for transaction 2 (or type 'none none' to skip): Whatchamacallit Frankenstein
Enter candy name and friend's name for transaction 3 (or type 'none none' to skip): Butterfinger Dracula
Enter the name of Monster 4: Frankenstein
Enter candy name and friend's name for transaction 1 (or type 'none none' to skip): Baby_Ruth Werewolf
Enter candy name and friend's name for transaction 2 (or type 'none none' to skip): Hershey's Mummy
Enter candy name and friend's name for transaction 3 (or type 'none none' to skip): none none
Enter the name of Monster 5: Swamp-Thing
Enter candy name and friend's name for transaction 1 (or type 'none none' to skip): Snickers Dracula
Enter candy name and friend's name for transaction 2 (or type 'none none' to skip): none none
Enter candy name and friend's name for transaction 3 (or type 'none none' to skip): none none

OUTPUT:
Mummy will get a total of 1 bars of candy.
Dracula will get a total of 1 bars of candy.
Werewolf will get a total of 1 bars of candy.
Frankenstein will get a total of 2 bars of candy.
Swamp-Thing will get a total of 2 bars of candy.
