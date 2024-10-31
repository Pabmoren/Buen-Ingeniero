#include <cstdio>

const int movimientos[10][8] = {
    {4, 6, -1, -1, -1, -1, -1, -1},     // 0
    {6, 8, -1, -1, -1, -1, -1, -1},     // 1
    {7, 9, -1, -1, -1, -1, -1, -1},     // 2
    {4, 8, -1, -1, -1, -1, -1, -1},     // 3
    {0, 3, 9, -1, -1, -1, -1, -1},      // 4
    {-1, -1, -1, -1, -1, -1, -1, -1},   // 5
    {0, 1, 7, -1, -1, -1, -1, -1},      // 6
    {2, 6, -1, -1, -1, -1, -1, -1},     // 7
    {1, 3, -1, -1, -1, -1, -1, -1},     // 8
    {2, 4, -1, -1, -1, -1, -1, -1}      // 9
};

long long int countKnightMoves(int inicio, int num_mov) {
    long long int actual[10] = {0};
    long long int siguiente[10] = {0};
    int movIdx;
    int posicion = 0;

    actual[inicio] = 1;

    while (num_mov > 0) {
        posicion = 0;
        while (posicion < 10) {
            siguiente[posicion] = 0;
            posicion++;
        }

        posicion = 0;
        while (posicion < 10) {
            if (actual[posicion] > 0) {
                movIdx = 0;
                while (movimientos[posicion][movIdx] != -1) {
                    siguiente[movimientos[posicion][movIdx]] += actual[posicion];
                    movIdx++;
                }
            }
            posicion++;
        }

        posicion = 0;
        while (posicion < 10) {
            actual[posicion] = siguiente[posicion];
            posicion++;
        }

        num_mov--;
    }

    long long int total = 0;
    posicion = 0;
    while (posicion < 10) {
        total += actual[posicion];
        posicion++;
    }

    return total;
}

int main() {
    int num_mov;
    printf("Introduce el numero de movimientos: ");
    scanf("%d", &num_mov);

    long long int comb_total = 0;
    int inicio = 0;

    if(num_mov <= 0) {
        printf("El numero de movimientos es invalido\n");
        return 1;
    }
    if(num_mov >= 55) {
        printf("El programa no puede procesar un numero de combinaciones tan alto");
        return 1;
    }
    while (inicio < 10) {
        if (inicio != 5) { // Para saltar el 5
            comb_total += countKnightMoves(inicio, num_mov);
        }
        inicio++;
    }

    printf("Total possible combinations with %d moves: %lld\n", num_mov, comb_total);
    return 0;
}