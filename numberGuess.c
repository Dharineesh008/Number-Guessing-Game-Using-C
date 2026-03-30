#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
    srand(time(0));
    char play_again;
    do{
    int guess,attempt;
    
    int b= rand() % 100 + 1;
    int score;
    printf("---It's a Number Guessing Game.\n Guess A number from 1 to 100\n");
    do{
    printf("Enter the Number:\n");
    scanf("%d",&guess);
    attempt++;
    if(guess<b){
        printf("The guess is low. Try Again!!\n");
    }
    else if(guess>b){
        printf("The guess is high. Try Again!!\n");
    }
    else{
        score=100-(attempt-1)*10;
        if(score<10) {score=10;}
        printf("Your guess is correct!!");
        if(score==100)
            printf("Perfect Score!!");
        else if(score>=70)
            printf("Rating: Great!!");
        else if(score>=40)
            printf("Rating: Good!!");
        else
            printf("Keep practicing");
        
    }

    }while(guess!=b);
    printf("\n Wanna Play agsin?!\n");
    scanf(" %c",&play_again);
}while(play_again=='y'||play_again=='Y');
printf("\nThanks for playing");
    return 0;
}