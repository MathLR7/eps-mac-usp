#include <stdio.h>

int main(){

    int seed;
    int numle;
    int numTent;
    int tent;
    int i;

    printf("Bem vinda(o) ao Numle\n");




    printf("Digite a semente para sortear a senha (0 a 10000): \n");
    scanf("%d", &seed);
    seed=seed%134456;
    numle=((8121*seed+28411)%134456)%10;

    printf("Quantidade de tentativas (1 a 10): \n");
    scanf("%d", &numTent);

    for(i=0;i<numTent;i++){
        printf("Digite a tentativa (0 a 9): \n");
        scanf("%d",&tent);
        if(tent==numle){
            printf("Voce acertou! A senha eh de fato %d.\n",numle);
            i=11;
        }
    }
    if(i==numTent){
        printf("Voce perdeu! A senha era %d.\n",numle);
    }




    return 0;
}