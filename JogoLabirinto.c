#include <stdio.h>
#include <stdlib.h>
#define OK
#define ERRO
#define CHAO 0
#define INICIO 1
#define FINAL 2
#define PAREDE 3
#define LIMPARTELA "cls"
int coluna_atual = 2,linha_atual = 1;

int mapa[30][30] = { 
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,
	3,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,3,
	3,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,3,
	3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3,3
};

/* Funcao para desenhar o Mapa */
int montar_mapa()
{
   	int linha,coluna;
   	for (linha=0;linha<30;linha++) {
      	for (coluna=0;coluna<30;coluna++) {
         	if ((linha == linha_atual) && (coluna == coluna_atual)) {
            	printf("4");
            	continue;
         	}
        if (mapa[linha][coluna] == INICIO)
        	printf("1");
        if (mapa[linha][coluna] == CHAO)
            printf("0");
        if (mapa[linha][coluna] == PAREDE)
            printf("3");
    	if (mapa[linha][coluna] == FINAL)
    		printf("2");
      	}
      	printf("\n");
   	}
   	return OK;
}

int main()
{
   	char movimento;
   	int pontos;
   	while ((movimento != 'x') && (movimento != 'X')) {
      system(LIMPARTELA);
      montar_mapa();
      printf("\n\n  (W)\n(A)+(D)\n  (S)\n\n");
      	if ((scanf("%c",&movimento))=='x') {
         getchar(); getchar();
         return ERRO;
      	}
      	if ((movimento == 'w') || (movimento == 'W')) {
         	linha_atual = linha_atual - 1;
         	pontos++;
         	if (mapa[linha_atual][coluna_atual] == PAREDE) {
            	linha_atual = linha_atual + 1;
            	pontos--;
            	printf("\nBateu na parede!\n");
            	getchar(); getchar();
         	}
      	}
      	if ((movimento == 's') || (movimento == 'S')) {
         	linha_atual = linha_atual + 1;
         	pontos++;
         	if (mapa[linha_atual][coluna_atual] == PAREDE) {
            	linha_atual = linha_atual - 1;
            	pontos--;
            	printf("\nBateu na parede!\n");
            	getchar(); getchar();
         	}else{
         		if (mapa[linha_atual][coluna_atual] == FINAL){
         			printf("PARABENS, VOCE CHEGOU AO FINAL DO LABIRINTO!\n");
         			printf("Sua pontuacao foi de %i pontos!", pontos);
         			break;
				 }
			 }
      	}
      	if ((movimento == 'd') || (movimento == 'D')) {
         	coluna_atual = coluna_atual + 1;
         	pontos++;
         	if (mapa[linha_atual][coluna_atual] == PAREDE) {
            	coluna_atual = coluna_atual - 1;
            	pontos--;
            	printf("\nBateu na parede!\n");
            	getchar(); getchar();
         	}else{
         		if (mapa[linha_atual][coluna_atual] == FINAL){
         			printf("PARABENS, VOCE CHEGOU AO FINAL DO LABIRINTO!\n");
         			printf("Sua pontuacao foi de %i pontos!", pontos);
         			break;
				 }
			 }
     	}
      	if ((movimento == 'a') || (movimento == 'A')) {
         	coluna_atual = coluna_atual - 1;
         	pontos++;
         	if (mapa[linha_atual][coluna_atual] == PAREDE) {
            	coluna_atual = coluna_atual + 1;
            	pontos--;
            	printf("\nBateu na parede!\n");
            	getchar(); getchar();
         	}
      	}
   	}
}
