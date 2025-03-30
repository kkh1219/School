#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int score[10];
    int sum = 0;
    double average;
    
    srand(time(0));
    
    for(int i = 0; i < 10; i++) {
        score[i] = rand() % 101;
        sum += score[i];
    }
    average = sum / 10;
    
    printf("전체 학생의 평균 점수: %.2f\n",average);
    
    return 0;
}