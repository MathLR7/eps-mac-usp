/***************************************************************/
/**                                                           **/
/**   Matheus Littig Radinz                        13695810   **/
/**   Exercício-Programa 03                                   **/
/**   Professor: Yoshiharu Kohayakawa                         **/
/**   Turma: 03                                               **/
/**                                                           **/
/***************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define TRUE 7
#define FALSE 0

void generate(int N, int b, int c, int r, int f, int v);
void print(int a[], int N);
int valid(int a[], int i, int aux, int b, int c, int r, int f);
int bishopValid(int a[], int i, int aux);
int horseValid(int a[], int i, int aux);
int kingValid(int a[], int i, int aux);

int main(int argc, char *argv[]) {

  int N = atoi(argv[1]);
  int b = atoi(argv[2]);
  int c = atoi(argv[3]);
  int r = atoi(argv[4]);
  int f = atoi(argv[5]);
  int v = atoi(argv[6]);

  generate(N, b, c, r, f, v);
  
  return 0;
}

void generate(int N, int b, int c, int r, int f, int v){
    int plays[N];                       /*foi utilizado como base o permutation.c do professor para desenvolver a estrategia*/
    int i = 0, aux = 0, x, y, z;
    int nPlays=0;

    float freqMatrix[N][N];          /*cria matriz que vai calcular frequencia de cada posicao*/
    if(f==1){
      for(x=0;x<N;x++){
        for(y=0;y<N;y++){
          freqMatrix[x][y]=0.0;
        }
      }
    }
    
    while (TRUE){
        
        if (aux == N) 
            if (i == 0) break;
            else aux = plays[--i] + 1;
        else {
            if (!valid(plays, i, aux, b, c, r, f)) {
                aux++;
                continue;
            }
            plays[i++] = aux;
            aux = 0;
            if (i == N) {
              if(v==1) print(plays, N);
              aux = plays[--i] + 1;
              nPlays++;
              for(z=0;z<N;z++){
                freqMatrix[plays[z]][z]+=1.0;
              }
            }
        }
    }
    
    if(nPlays==0)
      printf("Nao ha solucao\n");
    else
      printf("Total de solucoes: %d\n\n",nPlays);
    
    if(f==1){
      if(nPlays!=0){
        for(x=0;x<N;x++){                         /*divide a matriz de frequencia pelo numero de solucoes*/
          for(y=0;y<N;y++){
            freqMatrix[x][y]=freqMatrix[x][y]/nPlays;
          }
        }
        printf("Mapa de frequencias\n"); 
        for(x=0;x<N;x++){                         /*divide a matriz de frequencia pelo numero de solucoes*/
          for(y=0;y<N;y++){
            printf("%.4f ", freqMatrix[x][y]);
          }
          printf("\n");
        }
        printf("\n");
      }
      else printf("Mapa de frequencias indefinido (nao ha solucao)\n\n");
    }
}

void print(int a[], int N) {                                          /*imprime os casos possiveis no tabuleiro*/
  int i,j;
  for (j = 0; j < N; ++j){
    for (i = 0; i < N; ++i){
      if (a[j]==i) printf("%-2s", "X");
      else printf("%-2s", "-");
    }
    printf("\n");
  }
  printf("\n");
}

int valid(int a[], int i, int aux, int b, int c, int r, int f) {      /*valida rainha e suas especialidades*/
  int j;
  for (j = 0; j < i; ++j)                                           /*valida torre*/
    if (a[j] == aux) return FALSE;
  if(b!=0 && !bishopValid(a, i, aux))
    return FALSE;
  if(c!=0 && !horseValid(a, i, aux))
    return FALSE;
  if(r!=0 && !kingValid(a, i, aux)) 
    return FALSE;
  return TRUE;
}

int bishopValid(int a[], int i, int aux){                             /*valida bispo*/
  int j;
  if(i!=0){
    for(j=1;j<=i;j++){
      if(a[i-j]==aux-j || a[i-j]==aux+j)
        return FALSE;
    }
  }
  return TRUE;
}

int horseValid(int a[], int i, int aux){                              /*valida cavalo*/
  if(i!=0){
    if(i==1 && (a[i-1]==aux+2 || a[i-1]==aux-2))
      return FALSE;
    else if(i!=1 && (a[i-2]==aux+1 || a[i-2]==aux-1 || a[i-1]==aux+2 || a[i-1]==aux-2))
      return FALSE;
    }
  return TRUE;
}

int kingValid(int a[], int i, int aux){                               /*valida rei*/
  if(i!=0){
    if(a[i-1]==aux-1 || a[i-1]==aux+1)
      return FALSE;
  }
  return TRUE;
}