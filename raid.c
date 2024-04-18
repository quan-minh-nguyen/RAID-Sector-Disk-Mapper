#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {

    // get inputs, store queries in list
    char T[2];
    int N, C, S, Q;
    scanf("%s %d %d %d %d", T, &N, &C, &S, &Q);
    int *queried_sectors = (int *)malloc(Q * sizeof(int)); 
    for (int i = 0; i < Q; i++) {
        scanf("%d", &queried_sectors[i]);
    }

    // 5 cases, T=0/01/10/4/5(else)
    for (int i = 0; i < Q; i++) {
        int qs_num = queried_sectors[i];

        if (strcmp(T, "0") == 0) {
            int chunk_start = qs_num - qs_num % C;
            int disk = chunk_start / C % N;
            int stripe = (chunk_start+1) / (C*N) * C + qs_num % C;
            printf ("%d %d\n", disk, stripe);
        } 
        
        else if (strcmp(T, "1") == 0) {
            printf("0 %d 1\n",qs_num);
        }
        
        else if (strcmp(T, "01") == 0) {
            int half_disk = N/2;
            int disk = qs_num % half_disk;
            int stripe = qs_num / half_disk;
            int next_disk = disk + half_disk;
            printf ("%d %d %d\n", disk, stripe, next_disk);
        }
        
        else if (strcmp(T, "10") == 0) {
            int half_disk = N/2;
            int disk = qs_num % half_disk * 2;
            int stripe = qs_num / half_disk;
            int next_disk = disk + 1;
            printf ("%d %d %d\n", disk, stripe, next_disk);            
        }
        
        else if (strcmp(T, "4") == 0) {
            int disk = qs_num % (N-1);
            int stripe = qs_num / (N-1);
            printf ("%d %d %d\n", disk, stripe, N-1);
        }
        
        else {
            int stripe = qs_num / (N-1);
            int p_disk = N-1 - stripe % N;
            int row_min = qs_num - qs_num % (N-1);
            int disk = (qs_num - row_min + p_disk+1) % N;
            printf ("%d %d %d\n", disk, stripe, p_disk);
        }
    }
    
    return 0;
}
