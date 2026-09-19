// // // // // // // Leia 5 números em um vetor.
// // // // // // // Crie funções void para:
// // // // // // // Calcular a média
// // // // // // // Retornar o maior número
// // // // // // // Retornar o menor número
// // // // // // // Mostre os resultados chamando cada função.
// // // // // // // Lembre que as funções devem receber o vetor e o tamanho como parâmetros.

// // // // // // #include <stdio.h>

// // // // // // void media(int v[], int n)
// // // // // // {
// // // // // //     int s = 0;
// // // // // //     for (int i = 0; i < n; i++)
// // // // // //     {
// // // // // //         s += v[i];
// // // // // //     }
// // // // // //     printf("Média: %d", s / n);
// // // // // // }

// // // // // // void maior(int v[], int n)
// // // // // // {
// // // // // //     int m = v[0];
// // // // // //     for (int i = 0; i < n; i++)
// // // // // //     {
// // // // // //         if (v[i] > m)
// // // // // //         {
// // // // // //             m = v[i];
// // // // // //         }
// // // // // //     }
// // // // // //     printf("\nMaior %d: ", m);
// // // // // // }

// // // // // // void menor(int v[], int n)
// // // // // // {
// // // // // //     int m = v[0];
// // // // // //     for (int i = 0; i < n; i++)
// // // // // //     {
// // // // // //         if (v[i] < m)
// // // // // //         {
// // // // // //             m = v[i];
// // // // // //         }
// // // // // //     }
// // // // // //     printf("\nMaior %d: ", m);
// // // // // // }

// // // // // // int main()
// // // // // // {
// // // // // //     int vetor[5]; // 0, 1, 2, 3, 4

// // // // // //     printf("Digite 5 números: \n");
// // // // // //     for (int i = 0; i < 5; i++)
// // // // // //     {
// // // // // //         scanf("%d", &vetor[i]);
// // // // // //     }

// // // // // //     media(vetor, 5);
// // // // // //     maior(vetor, 5);
// // // // // //     menor(vetor, 5);

// // // // // //     return 0;
// // // // // // }

// // // ////

// // // // #include <stdio.h>

// // // // void separe(int v[], int t)
// // // // {
// // // //     int par[6], impar[6],qp,qi;
// // // //     qp = 0;
// // // //     qi = 0;
// // // //     for (int i = 0; i < t; i++)
// // // //     {
// // // //         if (v[i] % 2 == 0){
// // // //             par[qp] = v[i];
// // // //             qp++;
// // // //         }
// // // //         else{
// // // //             impar[qi] = v[i];
// // // //             qi++;
// // // //         }

// // // //     }
// // // //     printf("par");
// // // //     for ( int i = 0; i < qp; i++)
// // // //     {
// // // //         printf("%d ,",par[i]);
// // // //     }

// // // //         printf("Impar");
// // // //     for ( int i = 0; i < qi; i++)
// // // //     {
// // // //         printf("%d ,",impar[i]);
// // // //     }

// // // // }

// // // // int main()
// // // // {
// // // //     int num[6];

// // // //     for (int i = 0; i < 6; i++)
// // // //     {
// // // //         scanf("%d", &num[i]);
// // // //     }

// // // //     separe(num, 6);

// // // //     return 0;
// // // // }

// // // // // Separar Pares e Ímpares

// // // // // Atividade:

// // // // // Leia 6 números em um vetor.

// // // // // Crie uma função void que separe os pares e ímpares em dois vetores diferentes.

// // // // // Mostre os vetores separados na tela.

// // // #include <stdio.h>

// // // void separa(int v[], int t)
// // // {
// // //     int par[6], imp[6], qp, qi;
// // //     qp = 0;
// // //     qi = 0;

// // //     for (int i = 0; i < t; i++)
// // //     {
// // //         if (v[i] % 2 == 0)
// // //         {
// // //             par[qp] = v[i];
// // //             qp++;
// // //         }
// // //         else
// // //         {
// // //             imp[qi] = v[i];
// // //             qi++;
// // //         }
// // //     }

// // //     printf("par\n");
// // //     for (int i = 0; i < qp; i++)
// // //     {
// // //         printf("%d, ", par[i]);
// // //     }
// // //     printf("\n");
// // //     printf("impar\n");
// // //     for (int i = 0; i < qi; i++)
// // //     {
// // //         printf("%d, ", imp[i]);
// // //     }
// // // }

// // // int main()
// // // {
// // //     int num[6];

// // //     for (int i = 0; i < 6; i++)
// // //     {
// // //         scanf("%d", &num[i]);
// // //     }

// // //     separa(num, 6);

// // //     return 0;
// // // }

// // Crie duas funções void:

// // Converter metros para centímetros

// // Converter Celsius para Fahrenheit

// // Leia os valores do usuário e mostre o resultado das conversões.

// // Cada função deve receber o valor a ser convertido como parâmetro.

// #include <stdio.h>

// void paracent(int metro)
// {
//     int centimetro;
//     centimetro = metro * 100;
//     printf("\n%d", centimetro);
// }

// void parafah(int cel)
// {
//     float fah;
//     fah = cel * 1.8 + 32;
//     printf("\n%f", fah);
// }

// int main()
// {

//     int cel, metro;
//     printf("Digite o valor Metro: ");
//     scanf("%d", &metro);
//     printf("Digite o valor Celsius");
//     scanf("%d", &cel);

//    // paracent(metro);
//     parafah(cel);

//     return 0;
// }

// Leia 4 números inteiros em um vetor.

// Crie uma função void que calcule o fatorial de cada número e mostre na tela.

// A função deve receber o vetor e o tamanho como parâmetros.

#include <stdio.h>

void funfatorial(int v[], int n){
    int fatorial, ic;
    for (int i = 0; i < n; i++){
        fatorial = 1;
        for (ic = v[i]; ic > 0; ic--){
            fatorial *= ic;
            
        }
        printf("%d\n",fatorial);
     
    }

}

int main() {

    int num[4];
    printf("Digite 4 números");
    for (int i = 0; i < 4; i++)
    {
        scanf("%d", &num[i]);
    }
printf("fato");
    funfatorial(num,4);
    
    
    return 0;
}
