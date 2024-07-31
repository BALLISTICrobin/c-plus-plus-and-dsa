#include <stdio.h>

int decToBin(int num);

int main() {
    int num;
    printf("Enter a decimal number: ");
    scanf("%d", &num);
    int binary = decToBin(num);
    printf("Binary equivalent: %d\n", binary);
    return 0;
}

int decToBin(int num) {
    if (num == 0) {
        return 0;
    } else {
        return (num % 2) + 10 * decToBin(num / 2);
    }
}
