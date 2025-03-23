#include<stdio.h>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>

#define ROCK 1
#define PAPER 2
#define SCISSOR 3
#define PLAYER1_WIN 1
#define PLAYER2_WIN 2
#define DRAW 0

int rock_paper_scissor(int player1, int player2){
    int result;
    if(player1 == ROCK && player2 == PAPER){
        result = PLAYER2_WIN;
    } else if(player1 == ROCK && player2 == SCISSOR){
        result = PLAYER1_WIN;
    } else if(player1 == PAPER && player2 == ROCK){
        result = PLAYER1_WIN;
    } else if(player1 == SCISSOR && player2 == ROCK){
        result = PLAYER2_WIN;
    } else if(player1 == PAPER && player2 == SCISSOR){
        result = PLAYER2_WIN;
    } else if(player1 == SCISSOR && player2 == PAPER){
        result = PLAYER1_WIN;
    } else {
        result = DRAW;
    }
    return result;
}
int get_user_input(){
  int choice;
  do{
    printf("1.Rock\n");
    printf("2.Paper\n");
    printf("3.Scissor\n");
    printf("Please Input [1,2,3]");
    scanf("%d",&choice);
    if(! (choice >= 1 && choice <= 3)){
        printf("ERROR---INVALID INPUT, It is should be 1,2 or 3");
    }
  } while (! (choice >= 1 && choice <= 3));
  return choice;
}
void print_word(int v){
  if(v == ROCK){
    printf("Rock\n");
  }else if(v == PAPER){
    printf("Papers\n");
  }else if (v == SCISSOR){
    printf("Scissor\n");
  }
}
int main(){
 int user_score = 0;
 int computer_score = 0;
 srand(time(NULL));


 int quite = 0;
 while(!quite){

        int user_input = get_user_input();
        int computer_choice = (rand() % 3) + 1;
        printf("Computer chose :");
        print_word(computer_choice);
        printf("User chose :");
        print_word(user_input);

        int result = rock_paper_scissor(user_input, computer_choice);
        if(result == DRAW){
            printf("It is a draw\n");
        }else if(result == PLAYER1_WIN){
            printf("User wins the game\n");
            user_score++;
        }else if(result == PLAYER2_WIN){
            printf("Computer wins the game\n");
            computer_score++;
        }
        printf("\n");
        printf("---------------------------------\n");
        printf("User score %d\n",user_score);
        printf("Computer score %d\n",computer_score);
        printf("---------------------------------\n");
        printf("\n\n");
        printf("If you want to continue input any integer, 0 to terminate ");
        int response;
        scanf("%d",&response);
        if(response == 0){
        quite = 1;
    }
 } // end of while loop

   printf("The Final score is:\n");
   printf("\n");
   printf("---------------------------------\n");
   printf("User score %d\n",user_score);
   printf("Computer score %d\n",computer_score);
   printf("---------------------------------\n");
   printf("\n\n");
   if(user_score == computer_score){
    printf("The game was draw\n");
   }else if(user_score > computer_score){
    printf("User Wins the game\n");
   }else{
    printf("Computer wins the game\n");
   }
   return 0;
}
