/***************************************************************/
/**                                                           **/
/**   Matheus                                                 **/
/**   Exercício-Programa 01                                   **/
/**   Professor: Y. K.                                        **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>

int main(){


    int seed;
    int numle;
    int numTent;
    int tent;
    int i;
    int n1,n2,n3,n4,n5;
    int t1,t2,t3,t4,t5;
    int l1,l2,l3,l4,l5;

    printf("Bem vinda(o) ao Numle\n");
    printf("Digite a semente para sortear a senha (0 a 10000): \n");  /*gerador que finge q eh aleatorio*/
    scanf("%d", &seed);
    seed=seed%134456;
    numle=((8121*seed+28411)%134456)%100000;
    numle=11000;

    n5=numle%10;                             /*separa os digitos em 5 int pra facilitar comparacoes*/
    n4=(numle%100)/10;
    n3=(numle%1000)/100;
    n2=(numle%10000)/1000;               
    n1=(numle%100000)/10000;

    printf("%d",numle);
    printf("Quantidade de tentativas (1 a 10): \n");
    scanf("%d", &numTent);

    for(i=0;i<numTent;i++){

        l1=0,l2=0,l3=0,l4=0,l5=0;

        printf("Digite a tentativa (0 a 99999): \n");
        scanf("%d",&tent);

        if(tent==numle){
            printf("Voce acertou! A senha eh de fato %d.\n",numle);
            i=11;
        } else{

            t5=tent%10;                             
            t4=(tent%100)/10;
            t3=(tent%1000)/100;
            t2=(tent%10000)/1000;               
            t1=(tent%100000)/10000;

            if(n1==t1){
                printf("Primeiro digito certo!\n");
            } else if((t1==n2||t1==n3||t1==n4||t1==n5) /*&& t1!=t2 && t1!=t3 && t1!=t4 && t1!=t5*/){
                printf("Primeiro digito em posicao incorreta.\n");
                if(t1==n3) l3++;
                if(t1==n2) l2++;
                if(t1==n4) l4++;
                if(t1==n5) l5++;
            }

            if(n2==t2){
                printf("Segundo digito certo!\n");
            } else if(((t2==n1 && l1==0)||(t2==n3 && l3==0)||(t2==n4 && l4==0)||(t2==n5 && l5==0)) /*&& t1!=t2 && t2!=t3 && t2!=t4 && t2!=t5*/){
                printf("Segundo digito em posicao incorreta.\n");
                if(t2==n1) l1++;
                if(t2==n3) l3++;
                if(t2==n4) l4++;
                if(t2==n5) l5++;
            }

            if(n3==t3){
                printf("Terceiro digito certo!\n");
            } else if(((t3==n2 && l2==0)||(t3==n1 && l1==0)||(t3==n4 && l4==0)||(t3==n5 && l5==0)) /*&& t3!=t2 && t3!=t1 && t3!=t4 && t3!=t5*/){
                printf("Terceiro digito em posicao incorreta.\n");
                if(t3==n1) l1++;
                if(t3==n2) l2++;
                if(t3==n4) l4++;
                if(t3==n5) l5++;
            }

            if(n4==t4){
                printf("Quarto digito certo!\n");
            } else if(((t4==n2 && l2==0)||(t4==n3 && l3==0)||(t4==n1 && l1==0)||(t4==n5 && l5==0)) /*&& t4!=t2 && t4!=t3 && t1!=t4 && t4!=t5*/){
                printf("Quarto digito em posicao incorreta.\n");
                if(t4==n1) l1++;
                if(t4==n2) l2++;
                if(t4==n3) l3++;
                if(t4==n5) l5++;
            }

            if(n5==t5){
                printf("Quinto digito certo!\n");
            } else if(((t5==n2 && l2==0)||(t5==n3 && l3==0)||(t5==n4 && l4==0)||(t5==n1 && l1==0)) /*&& t5!=t2 && t5!=t3 && t5!=t4 && t1!=t5*/){
                printf("Quinto digito em posicao incorreta.\n");
            }
        
        }
    }
    if(i==numTent){
        printf("Voce perdeu! A senha era %d.\n",numle);
    }
    return 0;
}
