// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <math.h>

// int intToBinary(int num) {
//     int binary = 0;
//     int base = 1;

//     while (num > 0) {
//         int rem = num % 2;
//         binary = binary + rem * base;
//         num = num / 2;
//         base = base * 10;
//     }

//     return binary;
// }



// int main() {
    
//     long long int chavePrimaria;
//     char frase[2000];
//     scanf("%lld", &chavePrimaria);
//     scanf(" %[^\n]s", frase);

//     long long int chavePrimaria1 = intToBinary(chavePrimaria), mult[32];

//     //printf("%lld\n", chavePrimaria1); teste da chave primaria em binario

//     for(int i =0 , j=3, k=0; frase[i] != '\0'; i++, j--){
//         int letra = frase[i];
//         mult[k] += letra* (pow(256,j));


//         if(j=0){
//             j=3;
//             k++;
//         }
//     }
//     printf("%lld\n", mult[0]);


//     return 0;
// }



#include <stdio.h>
#include <string.h>

void codificar(int chave, char *frase) {
    int i, j, agrupamento;

    unsigned int codificado;

    int tamanho = strlen(frase);// ve o tamanho da frase
    int agrupamentos = (tamanho + 3) / 4;  // Arredonda 

    for (i = 0; i < agrupamentos; i++) {
        codificado = 0;

        // Construir o agrupamento de 4 caracteres
        for (j = 0; j < 4; j++) {
            agrupamento = i * 4 + j;
            if (agrupamento < tamanho) {
                //codificado += ((unsigned int)frase[agrupamento] * 256 * 256 * 256) + 
                //  ((unsigned int)frase[agrupamento] * 256 * 256) + 
                //  ((unsigned int)frase[agrupamento] * 256) + 
                //  (unsigned int)frase[agrupamento];
//                 codificado = codificado * 256 + (unsigned int)frase[agrupamento];

                codificado += (unsigned int)frase[agrupamento] << (8 * (3 - j));
            }
        }

        // fzd o XOR com a chave
        codificado ^= chave;

        printf("%u ", codificado);
    }

    printf("\n");
}

int main() {
    char frase[2000];
    int chave;


    scanf("%d ", &chave);
    fgets(frase, sizeof(frase), stdin);

    // Remover caractere de nova linha
    int aux = strlen(frase);
    if (frase[aux - 1] == '\n') {
        frase[aux - 1] = '\0';
    }

    codificar(chave, frase);

    return 0;
}
