#include <stdio.h>

// Función para transformar un número decimal a binario
void decimalToBinary(int num) {
    if (num == 0) {
        printf("El número en binario es: 0\n");
        return;
    }

    int binary[32]; // Para almacenar los dígitos binarios
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num /= 2;
    }

    printf("El número en binario es: ");
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
    printf("\n");
}

// Función para calcular el IVA
float calcularIVA(float monto) {
    return (monto / 1.12) * 0.12;
}

// Función para realizar una regla de tres
float reglaDeTres(float a, float b, float c) {
    return (c * b) / a;
}

int main() {
    int opcion;
    float monto, resultado;
    int numeroDecimal;

    do {
        printf("\nMenu:\n");
        printf("1. Transformar decimal a binario\n");
        printf("2. Calcular IVA de una factura\n");
        printf("3. Realizar regla de tres\n");
        printf("4. Salir\n");
        printf("Ingrese una opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese un número decimal: ");
                scanf("%d", &numeroDecimal);
                decimalToBinary(numeroDecimal);
                break;

            case 2:
                printf("Ingrese el monto de la factura: ");
                scanf("%f", &monto);
                resultado = calcularIVA(monto);
                printf("El IVA es: %.2f\n", resultado);
                break;

            case 3:{
                float a, b, c, resultado;
                printf("Ingrese los valores a, b y c para la regla de tres:\n");
                printf("a: ");
                scanf("%f", &a);
                printf("b: ");
                scanf("%f", &b);
                printf("c: ");
                scanf("%f", &c);
                resultado = reglaDeTres(a, b, c);
                printf("El resultado de la regla de tres es: %.2f\n", resultado);
                
                break;
            }
            case 4:
                printf("Saliendo del programa.\n");
                break;

            default:
                printf("Opción no válida. Por favor, seleccione una opción válida.\n");
                break;
        }

    } while (opcion != 4);

    return 0;
}