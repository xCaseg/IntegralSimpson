#include <stdio.h>
#include <math.h>

// Definición de la función a integrar: x^2
float fx(float x) {
    return (x * x);
}

// Método de integración por Simpson compuesto
float integracion_simpson_compuesto(float (*f)(float), float a, float b, int n) {
    float h = (b - a) / n; // Ancho del subintervalo
    float suma_par = 0, suma_impar = 0;

    // Calcular la suma de los puntos pares y los puntos impares
    for (int i = 0; i <= n; i++) { // Recorrer desde 0 hasta n
        float x = a + i * h;
        if (i == 0 || i == n) { // Sumar f(a) y f(b) como puntos pares
            suma_par += f(x);
        } else if (i % 2 == 0) { // Sumar puntos pares restantes
            suma_par += 2 * f(x);
        } else { // Sumar puntos impares
            suma_impar += 4 * f(x);
        }
    }

    // Aplicar la regla de Simpson compuesta
    float integral_aproximada = (h / 3) * (suma_par + suma_impar);

    return integral_aproximada;
}

int main() {
    float limite_inferior, limite_superior;
    int numero_intervalos;

    // Solicitar al usuario los límites de integración y el número de intervalos
    printf("Programa para calcular el valor de una integral cuadrática por el método de Simpson\n\n");
    printf("Calculando la integral para la funcion f(x) = x^2... \n\n");
    printf("Inserte el límite inferior: ");
    scanf("%f", &limite_inferior);
    printf("Inserte el límite superior: ");
    scanf("%f", &limite_superior);
    printf("Inserte el número de intervalos: ");
    scanf("%d", &numero_intervalos);

    // Validar que los límites de integración sean válidos
    if (limite_inferior >= limite_superior) {
        printf("Error: El límite inferior debe ser menor que el límite superior.\n");
        return 1;
    }

    // Validar que el número de intervalos sea positivo
    if (numero_intervalos <= 0) {
        printf("Error: El número de intervalos debe ser mayor que cero.\n");
        return 1;
    }

    // Calcular la aproximación de la integral
    float integral_aproximada = integracion_simpson_compuesto(fx, limite_inferior, limite_superior, numero_intervalos);

	// Mostrar el resultado
	printf("\nAproximación de la integral: %.16f\n", integral_aproximada);

    return 0;
}







