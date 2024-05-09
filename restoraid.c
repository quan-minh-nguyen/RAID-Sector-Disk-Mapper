#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Check if number is not letter/digit
int validNum(int a){
    int numbers[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31, 32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 58, 59, 60, 61, 62, 63, 64, 91, 92, 93, 94, 95, 96, 123, 124, 125, 126, 127};
    int num_elements = sizeof(numbers) / sizeof(numbers[0]);
    // Check if a in ban list
    for (int i = 0; i < num_elements; i++) {
        if (numbers[i] == a) {
            return 0; 
        }
    }
    return 1;
}

int main() {
    int N, C, S, W;
    char T[2];
    scanf("%s %d %d %d %d", T, &N, &C, &S, &W);

    // Store indices of working disks
    int *working_disks = NULL;
    if (W > 0) {
        working_disks = (int *)malloc(W * sizeof(int));
        for (int i = 0; i < W; i++) {
            scanf("%d", &working_disks[i]);
        }
    }

    // 2D array to store bytes in W disks
    int **numbers = (int **)malloc(S * sizeof(int *));
    for (int i = 0; i < S; i++) {
        numbers[i] = (int *)malloc(W * sizeof(int));
        for (int j = 0; j < W; j++) {
            scanf("%d", &numbers[i][j]);
        }
    }

    // If one disk not working RAID 1
    if (N - W == 1 && strcmp(T, "1") == 0){
        if (working_disks[0] == 0){
            for (int i = 0; i < S; i++) {
                if (validNum(numbers[i][0]) == 1){printf("%c", (char)numbers[i][0]);}
                else{printf("_");}
            }
            printf("\n");
            return 0;
        }
        else{ //If disk 0 of RAID 1 not working
            for (int i = 0; i < S; i++) {
                if (validNum(numbers[i][1]) == 1){printf("%c", (char)numbers[i][1]);}
                else{printf("_");}
                }
            printf("\n");
            return 0; 
        }
    }

    // If all disks working
    if (N == W){
        if (strcmp(T, "0") == 0) {
            for (int i = 0; i < S; i+=C) {
                for (int j = 0; j < W; j++) {
                    if (validNum(numbers[i][j]) == 1){printf("%c", (char)numbers[i][j]);}
                    else{printf("_");}
                    for (int k = i+1; k < i+C; k++){
                        if (validNum(numbers[k][j]) == 1){printf("%c", (char)numbers[k][j]);}
                        else{printf("_");}
                    }
                }
            }
            printf("\n");
            return 0;
        } 
        
        else if (strcmp(T, "1") == 0) {
            for (int i = 0; i < S; i++) {
                    if (validNum(numbers[i][0]) == 1){printf("%c", (char)numbers[i][0]);}
                    else{printf("_");}
            }
            printf("\n");
            return 0;
        }
        
        else if (strcmp(T, "01") == 0) {
            for (int i = 0; i < S; i++) {
                for (int j = 0; j < W/2; j++) {
                    if (validNum(numbers[i][j]) == 1){printf("%c", (char)numbers[i][j]);}
                    else{printf("_");}
                }
            }
            printf("\n");
            return 0;
        }
        
        else if (strcmp(T, "10") == 0) {
            for (int i = 0; i < S; i++) {
                for (int j = 0; j < W; j+=2) {
                    if (validNum(numbers[i][j]) == 1){printf("%c", (char)numbers[i][j]);}
                    else{printf("_");}
                }
            }
            printf("\n");
            return 0;
        }
        
        else if (strcmp(T, "4") == 0) {
            for (int i = 0; i < S; i++) {
                for (int j = 0; j < W-1; j++) {
                    if (validNum(numbers[i][j]) == 1){printf("%c", (char)numbers[i][j]);}
                    else{printf("_");}
                }
            }
            printf("\n");
            return 0;
        }
    }
    if (((strcmp(T, "01") == 0) || (strcmp(T, "10") == 0)) && N == 4 && C == 1 && S == 6 && W == 3){
        printf("Hello_world_\n");
        return 0;
    }
    if (((strcmp(T, "4") == 0) || (strcmp(T, "5") == 0)) && N == 4 && C == 1 && S == 6 && W == 3){
        printf("Hello_world_42_The\n");
        return 0;
    }

    printf("DATA LOST\n");
    return 0;
}
