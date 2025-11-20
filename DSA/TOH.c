
#include <stdio.h>
void TOH(int n, char source, char aux, char destination)
{
    if (n == 1)
    {
        printf("move disk 1 from %c to %c\n", source, destination);
        return;
    }
    TOH(n - 1, source, destination, aux);
    printf("move disk %d from %c to %c\n", n, source, destination);
    TOH(n - 1, aux, source, destination);
}

int main()
{
    int n;
    printf("enter the number of disks");
    scanf("%d", &n);

    TOH(n, 'A', 'B', 'C');

    return 0;
}