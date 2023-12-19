#include <stdio.h>
#include <stdlib.h>

int is_prime(int n) {
    if (n < 2) {
        return 0;
    }

    int i = 2;
    while (i * i <= n) {
        if (n % i == 0) {
            return 0;
        }
        i++;
    }
    return 1;
}

void prime_factors(int n) {
    int i = 2;
    while (n > 1) {
        if (is_prime(i) && n % i == 0) {
            printf("%d", i);
            n /= i;
            if (n > 1) {
                printf("*");
            }
        } else {
            i++;
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc == 2) {
        int number = atoi(argv[1]); 
        if (number == 1)
            printf("1");
        if (number > 0) {
            prime_factors(number);
        }
       
    }
    printf("\n");
    return 0;
}
