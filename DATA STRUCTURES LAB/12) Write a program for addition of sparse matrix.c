#include <stdio.h>
#define MAX 100

void readSparse(int mat[MAX][3], int *n) {
    printf("Enter number of non-zero elements: ");
    scanf("%d", n);
    printf("Enter row col value for each non-zero element:\n");
    for (int i = 0; i < *n; i++) {
        scanf("%d%d%d", &mat[i][0], &mat[i][1], &mat[i][2]);
    }
}

void addSparse(int a[MAX][3], int n1, int b[MAX][3], int n2, int res[MAX][3], int *n3) {
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (a[i][0] == b[j][0] && a[i][1] == b[j][1]) {
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2] + b[j][2];
            i++; j++; k++;
        } else if (a[i][0] < b[j][0] || (a[i][0] == b[j][0] && a[i][1] < b[j][1])) {
            res[k][0] = a[i][0];
            res[k][1] = a[i][1];
            res[k][2] = a[i][2];
            i++; k++;
        } else {
            res[k][0] = b[j][0];
            res[k][1] = b[j][1];
            res[k][2] = b[j][2];
            j++; k++;
        }
    }
    while (i < n1) {
        res[k][0] = a[i][0];
        res[k][1] = a[i][1];
        res[k][2] = a[i][2];
        i++; k++;
    }
    while (j < n2) {
        res[k][0] = b[j][0];
        res[k][1] = b[j][1];
        res[k][2] = b[j][2];
        j++; k++;
    }
    *n3 = k;
}

void printSparse(int mat[MAX][3], int n) {
    printf("Row Col Value\n");
    for (int i = 0; i < n; i++) {
        printf("%d %d %d\n", mat[i][0], mat[i][1], mat[i][2]);
    }
}

int main() {
    int a[MAX][3], b[MAX][3], res[MAX][3], n1, n2, n3;
    printf("First matrix:\n");
    readSparse(a, &n1);
    printf("Second matrix:\n");
    readSparse(b, &n2);
    addSparse(a, n1, b, n2, res, &n3);
    printf("Resultant matrix:\n");
    printSparse(res, n3);
    return 0;
}
