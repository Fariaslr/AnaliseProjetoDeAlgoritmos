#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int secret_num = 0, guess = 0, num_guesses = 0;
    srand(time(0)); // semente para gerar números aleatórios

    // gerar número secreto aleatório entre 1 e 100
    secret_num = (rand() % 100) + 1;

    // tentar adivinhar o número em no máximo 10 tentativas
    while (num_guesses < 10) {
        printf("Tentativa %d: ", num_guesses + 1);
        scanf("%d", &guess);
        num_guesses++;

        // função de probabilidade para decidir se deve fazer uma suposição mais baixa, mais alta ou permanecer na mesma suposição
        float probability = (float) (rand() % 100) / 100;
        if (guess == secret_num) {
            printf("Parabéns! Você acertou em %d tentativas.\n", num_guesses);
            return 0;
        } else if (guess < secret_num && probability < 0.33) {
            printf("Tente um número maior.\n");
        } else if (guess > secret_num && probability < 0.33) {
            printf("Tente um número menor.\n");
        } else {
            printf("Continue com a mesma suposição.\n");
        }
    }

    printf("Suas 10 tentativas acabaram. O número secreto era %d.\n", secret_num);
    return 0;
}
