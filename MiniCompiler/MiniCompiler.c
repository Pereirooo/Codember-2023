#include <stdio.h>

void miniCompiler(const char *program, char *output) {
    int value = 0;
    int length = 0;

    while (*program) {
        switch (*program) {
            case '#':
                value++;
                break;
            case '@':
                value--;
                break;
            case '*':
                value *= value;
                break;
            case '&':
                output[length++] = value + '0';
                break;
        }
        program++;
    }

    output[length] = '\0';
}

int main() {
    char output[100];

    // Ejemplos de entrada
    const char *program1 = "##*&";
    const char *program2 = "&##&*&@&";
    const char *program3 = "&###@&*&###@@##@##&######@@#####@#@#@#@##@@@@@@@@@@@@@@@*&&@@@@@@@@@####@@@@@@@@@#########&#&##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@##@@&";

    // Aplicar el compilador y mostrar la salida
    miniCompiler(program1, output);
    printf("Salida para \"%s\": \"%s\"\n", program1, output);

    miniCompiler(program2, output);
    printf("Salida para \"%s\": \"%s\"\n", program2, output);

    miniCompiler(program3, output);
    printf("Salida para \"%s\": \"%s\"\n", program3, output);

    return 0;
}
