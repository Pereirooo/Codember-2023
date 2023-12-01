#include <stdio.h>
#include <string.h>

// Función para validar el checksum
int validar_checksum(char *nombre_archivo) {
    char cadena_alfanumerica[100];  // Asumimos que la cadena alfanumérica tiene como máximo 100 caracteres
    char checksum[100];             // Asumimos que el checksum tiene como máximo 100 caracteres

    sscanf(nombre_archivo, "%[^-]-%s", cadena_alfanumerica, checksum);//sscanf se emplea para dividir el nombre del archivo en dos partes (partiendo por el guión).
    //Primera parte: guardada en cadena_alfanumérica; segunda parte: guardada en checksum.

    // Generar el checksum esperado
    char checksum_esperado[100] = "";
    for (int i = 0; cadena_alfanumerica[i] != '\0'; i++) {
        char c = cadena_alfanumerica[i];//Itera sobre cada carácter en cadena alfanumérica.
        if (strchr(cadena_alfanumerica, c) == strrchr(cadena_alfanumerica, c)) {//if carácter 'c' aparece solo 1 vez.
            strncat(checksum_esperado, &c, 1);//agregamos al checksum esperado.
        }
    }

    // Aplicamos un strcmp para comparar el resultado con el checksum esperado (devolvemos verdadero si son iguales).
    return strcmp(checksum, checksum_esperado) == 0;
}

int main() {
    // Lista de nombres de archivos y checksums
    char *archivos[] = {
            "3n3E65A-nE65A",
            "U6Z1WWc0LP-U6Z1c0LP",
            "la6bqS-la6bqS",
            "lKyxSLIEj-lKyxSLIEj",
            "7HIKAPFYsK-7HIAPFYs",
            "IfhDJjaZKJ-IfhDjaZK",
            "1ynAjanFox-1yAjaFox",
            "vi2Yqle-vi2Yqle",
            "SXxyqnzER-SXxyqnzER",
            "uWWKcD3b-uKcD3b",
            "fxwzTMRB-fxwzTMRB",
            "1f1dLc4p-fdLc4p",
            "H0nY8w-H0nY8w",
            "1tVQjP4-1tVQjP4",
            "o8sRM-o8sRM",
            "Hn2XWpspJq-Hn2XWsJq",
            "88pauAKQ-pauAKQ",
            "SF5yFf3uW-S5yf3uW",
            "KOjaML-KOjaML",
            "n1sjIG-n1sjIG",
            "H3u4IEwR-H3u4IEwR",
            "Er1iMVvtSb-Er1iMVvtSb",
            "6bDBFweu3-6bDBFweu3",
            "QMG2y-QMG2y",
            "QqS8zu-QqS8zu",
            "nWf2oHc2D-nWfoHcD",
            "ywhoHTg-ywhoHTg",
            "5rS6rC-5S6C",
            "kZkSVr-ZSVr",
            "KkGQLG-KkQL",
            "J8X6VNHKk-J8X6VNHKk",
            "hs5CsfYsN2-h5CfYN2",
            "O2hrQ-O2hrQ",
            "UU7HuFY-7HuFY",
            "vSlgP-vSlgP",
            "LO43CA6h-LO43CA6h",
            "rADjgAXZbD-rjgXZb",
            "219JS-219JS",
            "Tw6jlpH-Tw6jlpH",
            "ZmfY62-ZmfY62",
            "Xh4lMhN-X4lMN",
            "9wPi1-9wPi1",
            "LC3ucqzRev-LC3ucqzRev",
            "eqRKXqZzCH-eRKXZzCH",
            "m9Rsx1-m9Rsx1",
            "WKrbn0jLE-WKrbn0jLE",
            "MsW8Mg-sW8g",
            "OKdIPOl-KdIPl",
            "N2ZA7H-N2ZA7H",
            "F86afig-F86afig",
            "BvEzt4ys-BvEzt4ys",
            "wyAmFlx7m-wyAFlx7",
            "73sBHIzZTU-73sBHIzZTU",
            "E5liPXG3ZM-E5liPXG3ZM",
            "wohjWqIEG-wohjWqIEG",
            "Ajw0o0-Ajwo",
            "V3ridipc-V3rdpc",
            "ysikPhv-ysikPhv",
            "iQSz654tNX-iQSz654tNX",
            "qYSwYKifb-qSwKifb",
            "W79773fSH-W93fSH",
            "qNWDAUt-qNWDAUt",
            "i8cDcz-i8Dz",
            "DhJS4-DhJS4",
            "j2TiHE-j2TiHE",
            "m4fpbb2zI-m4fp2zI",
            "bNirf51-bNirf51",
            "aPNkUTXWs-aPNkUTXWs",
            "EfsBW8-EfsBW8",
            "safHshz-afHhz",
            "RycVH06w7-RycVH06w7",
            "IU4n2-IU4n2",
            "lrXEc2N2u-lrXEcNu",
            "bMcOtLT7-bMcOtLT7",
            "hILDoXNIP-hLDoXNP",
            "RoG5ra-RoG5ra",
            "VAbQO-VAbQO",
            "lgnMYBnI-lgMYBI",
            "Y5TZwZfJ-Y5TwfJ",
            "wTI9xRn-wTI9xRn",
            "LEs3Fcj7M6-LEs3Fcj7M6",
            "iccMmtrl-iMmtrl",
            "g9R8e-g9R8e",
            "XWJWnygqc-XJnygqc",
            "QMLJAm1Kf-QMLJAm1Kf",
            "EfA1kaddYq-EfA1kaYq",
            "ieY5aGGV-ieY5aV",
            "3lZn2-3lZn2",
            "VTQVbY-TQbY",
            "KxUMQYJENi-KxUMQYJENi",
            "mPqYGQ-mPqYGQ",
            "IyeJXmUd3c-IyeJXmUd3c",
            "xXsymu5Av-xXsymu5Av",
            "iJXvYyTcD-iJXvYyTcD",
            "7VrbUTTKyi-7VrbUKyi",
            "fXr9O6-fXr9O6",
            "4VNq3-4VNq3",
            "sDAec-sDAec",
            "zOAGtZEc-zOAGtZEc",
            "Cb2n1GNN-Cb2n1G"
    };

    // Determinar cuáles archivos son reales y cuáles son falsos
    printf("Resultados:\n");
    for (int i = 0; i < sizeof(archivos) / sizeof(archivos[0]); i++) {
        if (validar_checksum(archivos[i])) {//Si la función validar_checksum devuelve verdadero, entonces el archivo es considerado real.
            printf("Nombre del archivo: %s, Resultado: Real\n", archivos[i]);
        } else {//Si no, el archivo es falso.
            printf("Nombre del archivo: %s, Resultado: Falso\n", archivos[i]);
        }
    }

    // Encontrar el archivo real número 33 y enviar su checksum
    if (sizeof(archivos) / sizeof(archivos[0]) >= 33) {// Verificar si hay al menos 33 elementos en la lista de archivos.
        char *archivo_33 = archivos[32];// Accede al elemento 33 en la lista de archivos (el índice 32, ya que los índices comienzan desde 0).
        char checksum_33[100];
        sscanf(archivo_33, "%*[^-]-%s", checksum_33);// Utiliza sscanf para obtener el checksum del archivo 33 sin almacenar la primera parte del nombre.
        printf("Checksum del archivo 33: %s\n", checksum_33);// Muestra en la salida estándar ek checksum del archivo 33.
    } else {// Si no hay suficientes archivos en la lista, imprime un mensaje que indique que no se puede encontrar el archivo 33.
        printf("No hay suficientes archivos reales para encontrar el archivo número 33.\n");
    }return 0;
}
