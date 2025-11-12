/*
#include <stdio.h>
struct record{
    char name[20];
    double ht;
};
int main()
{
    printf("Name - Niveditha \n");
    printf("Reg No - 24BCE2000 \n");
    int n, i;
    printf("Enter no of records \n");
    scanf("%d", &n);
    struct record a[n];
    printf("enter the height and name of each person \n");
    double avg = 0;
    for (i = 0; i < n; i++)
    {
        scanf("%lf", &a[i].ht);
        scanf("%s", a[i].name);
        avg += a[i].ht ;
    }
    avg = avg / n;
    printf("avg = %.2lf \n", avg);
    printf("names of people whose ht is above average \n");
    for(i = 0; i < n; i++)
        if (a[i].ht >= avg)
            printf("%s \n", a[i].name);
    return 0;
}
*/

#include <stdio.h>
void toh(int n, char S, char D, char T)
{
    if(n==1)
        printf("Move disk 1 from %c to %c \n", S, D);
    else   
    {
        toh(n-1, S, T, D);
        printf("Move disk %d from %c to %c \n", n, S, D);
        toh(n-1, T, D, S);
    }
}
int main()
{
    printf("Name - Niveditha \n");
    printf("Reg No - 24BCE2000 \n");
    printf("enter no of discs \n");
    int n;
    scanf("%d", &n);
    printf("Steps to move \n");
    toh(n ,'S' , 'D' , 'T');
    return 0;
}

