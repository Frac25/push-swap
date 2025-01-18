#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Aucun argument fourni.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        printf("Argument %d : '%s'\n", i, argv[i]);
    }

    // Détection d'une différence possible
    if (argc == 2) {
        if (strcmp(argv[1], "test") == 0) {
            printf("Argument détecté comme 'test'.\n");
        } else if (argv[1][0] == '"' && argv[1][strlen(argv[1]) - 1] == '"') {
            printf("Argument avec guillemets détecté : '%s'\n", argv[1]);
        } else {
            printf("Argument différent détecté : '%s'\n", argv[1]);
        }
    }

    return 0;
}
