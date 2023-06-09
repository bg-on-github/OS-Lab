#include<stdio.h>
#include<stdlib.h>
void producer(); void consumer();
int mutex = 1, full = 0, empty, x = 0;
int wait(int); int signal(int);
int main()
{
    printf("Please enter buffer size: ");
    scanf("%d", &empty);
    int n;
    printf("\n1.Producer\n2.Consumer\n3.Exit");
    while (1)
    {
        printf("\nEnter your choice:");
        scanf("%d", &n);
        switch (n)
        {
            case 1:
                if ((mutex == 1) && (empty != 0))
                    producer();
                else
                    printf("Buffer filled!");
            break;
            case 2:
                if ((mutex == 1) && (full != 0))
                    consumer();
                else
                    printf("Buffer consumed!");
            break;
            case 3:
                printf("Exiting...");
                exit(0);
            break;
        }
    }
    return 0;
}

int wait(int s)
{
    return (--s);
}

int signal(int s)
{
    return (++s);
}

void producer()
{
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProduced item %d", x);
    mutex = signal(mutex);
}

void consumer()
{
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumed item %d", x);
    x--;
    mutex = signal(mutex);
}