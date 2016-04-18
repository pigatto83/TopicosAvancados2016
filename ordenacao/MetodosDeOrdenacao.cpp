#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int dividir(int vetor[],int ladoA, int ladoB){ //Fun��o que faz a Ordena��o do Vetor
    int aux; //troca de posi�es
    
    int cont = ladoA; // Cont vai saber o n�meros de valores que tem nessa faixa -> ladoA, al�m de coordenar as trocas

    for(int i=ladoA+1 ; i<=ladoB ; i++){ 

        if( vetor[i] < vetor[ladoA] ){ //Compara todas as outras posi��es com o 0. Se satisfazer esse If faz a troca
            cont++;
            aux=vetor[i];      //Utiliza-se uma vari�vel auxiliar
            vetor[i]=vetor[cont];
            vetor[cont]=aux;  //Retorna o n�mero de valores que passou da faixa de ladoA at� ladoB, por isso utiliza-se o cont - contador
        }
    }

    aux=vetor[ladoA];
    vetor[ladoA]=vetor[cont];	//Faz a coorden��o das posi��es
    vetor[cont]=aux;

    return cont;
}

void quick(int vetor[],int ladoA, int ladoB){ /*Fun��o void, n�o tem retorno; Como o m�todo quick divide o vetor em dois,
                                               Uso o ladoA e o ladoB que representam os dois lados dessa divis�o  */
    int pos; 
    
    if(ladoA < ladoB){
        pos = dividir(vetor,ladoA,ladoB); /*Fun��o dividir � chamada para particionar o vetor, ou seja, colocar em ordem,
											 pos faz a fun��o de um auxiliar e recebe o valor */
											 
		//Coordenando a Ordena��o utilizando a fun��o, utilizando o m�todo de Recursividade
        quick(vetor,ladoA,pos-1); 
        quick(vetor,pos+1,ladoB);
    }
}

void selection(int vetor[],int n){  //Par�metros s�o: vetor desordenado e o tamanho desse vetor

    int menor, aux;  //Variaveis: menor = vamos achar o menor valor; Aux = variavel auxiliar que efetua a troca

    for(int i=0;i<n-1;i++){
            
        menor=i; //menor recebe a posi��o inicial do vetor
        
        for(int j=i+1 ; j<n ; j++){   
		//Encontra o menor valor
            if(vetor[j] < vetor[menor])
                menor=j;
        }
        //Ap�s ser encontrado o menor valor, realizaremos a troca usando a variavel auxiliar(aux)
        if(i!=menor){
        //Realiza a troca das posi��es
            aux=vetor[i];                    
            vetor[i]=vetor[menor];
            vetor[menor]=aux;
        }
    }
}

void insertion(int vetorDesordenado[], int tamanhoVetor) //Parametros: vetor desordenado e o tamanho do vetor
{
   int i, j, valorAtual;
 
   for( j=1; j < tamanhoVetor; j++ )   //Aqui usa-se a j para preencher o vetor desordenado
   {
      valorAtual = vetorDesordenado[j]; //A auxiliar valorAtual recebe esse vetor preenchido pela variavel j
      i = j-1;
      
      while(i >= 0 && vetorDesordenado[i] > valorAtual) /*Enquanto o i for maior ou igual a zero
                                               e o vetor desordenado de i for maior que a variavel AUXILIAR 
                                               valorAtual que recebeu o vetor desordenado de j*/
      {                 
        vetorDesordenado[i+1] = vetorDesordenado[i]; /*a posi��o pos i, recebe a posi��o onde est� o i
                                                          enquanto satisfaz esse while      */
        i--; //Decrementa o i
      } 
              
      vetorDesordenado[i+1] = valorAtual; //A auxiliar que est� ordenada � repassada ao vetor
   }
}

void merge( int *vetorDesordenado, int posicaoInicio, int posicaoFim ) 
{
   int i,j,k,metadeTamanho,*vetorTemp;
   if ( posicaoInicio == posicaoFim ) return;
   
   // ordenacao recursiva das duas metades
   metadeTamanho = ( posicaoInicio+posicaoFim )/2;
   merge( vetorDesordenado, posicaoInicio, metadeTamanho);
   merge( vetorDesordenado, metadeTamanho+1,posicaoFim );

   // intercalacao no vetor temporario t
   i = posicaoInicio;
   j = metadeTamanho+1;
   k = 0;
   vetorTemp = (int *) malloc(sizeof(int) * (posicaoFim-posicaoInicio+1));
   
   while( i < metadeTamanho+1 || j  < posicaoFim+1 )
   { 
      if ( i == metadeTamanho+1 )
      { // i passou do final da primeira metade, pegar v[j]
         vetorTemp[k] = vetorDesordenado[j];
         j++;
         k++;
      } 
      else
      {
         if (j==posicaoFim+1) 
         { 
            // j passou do final da segunda metade, pegar v[i]
            vetorTemp[k] = vetorDesordenado[i];
            i++;
            k++;
         } 
         else 
         {
            if (vetorDesordenado[i] < vetorDesordenado[j]) //Faz a compara��o
            { 
               vetorTemp[k] = vetorDesordenado[i]; /*Se satisfaz este if o vetor vetorTemp[k] recebe o vetor 
                                                   desordenado com os numeros que a variavel i recebeu*/
               i++; //incrementa i
               k++;
            } 
            else
            { 
              vetorTemp[k] = vetorDesordenado[j]; /*Se satisfaz este if o vetor vetorTemp[k] recebe o vetor 
                                                  desordenado com os numeros que a variavel j recebeu*/
              j++; // incrementa j
              k++;
            }
         }
      }
      
   }
   // copia vetor intercalado para o vetor original
   for( i = posicaoInicio; i <= posicaoFim; i++ )
   {
      vetorDesordenado[i] = vetorTemp[i-posicaoInicio];
   }
   free(vetorTemp);
}

void shell(int *vetor, int tamanho)
{
   int i = (tamanho - 1) / 2; //i recebe a metado do tamanho do vetor, isso � feito para se ter grupos menores, assim usa-se o m�todo de inser��o neles
   int chave, k, aux;
 
   while(i != 0)  //Enquanto i for diferente de 0, se for igual a zero, significa que o vetor j� est� ordenado
   {
      do //Fa�a isso
      {
         chave = 1; //Se a chave for igual a 1 receber� no final 0
         for(k = 0; k < tamanho - i; k++) /*Enquanto k for igual a 0, menor que a ultima posi��o
                                          do vetor, fa�a o que esta abaixo*/
         {
            if(vetor[k] > vetor[k + i]) //Enquanto a posi��o selecionada for maior que a pr�xima posi��o do vetor � feita a troca
            {
            	//Temos esse if para efetuarmos a troca, utilizando a variavel auxiliar(aux)
               aux = vetor[k];
               vetor[k] = vetor[k + i];
               vetor[k + i] = aux;
               chave = 0;
            }
         }
      }
      
      while(chave == 0); //Enquanto chave for igual a zero
      i = i / 2;
   }
}

int main(){
	
	int n=100, opcao, i;
    int vetor[100];
    double tempo;  //vari�vel que ir� armezenar o tempo gasto
    clock_t Ticks [2];
    	
	printf("Escolha a opcao em que desejas ordenar\n"); //Selecionando o tipo de m�todo de Ordena��o
	printf("1 - Quick Sort\n");
	printf("2 - Selection Sort\n");
	printf("3 - Insertion Sort\n");
	printf("4 - Merge Sort\n");
	printf("5 - Shell Sort\n\n");
	printf("Seu vetor tera 100 posicoes\n");
	printf("\nDigite a opcao desejada:");
	
	scanf("%d", &opcao); //N�mero escolhido
	printf("\n\nA opcao escolhida foi a : %d\n\n", opcao);
	
	switch(opcao){
	
	case 1:
		
    Ticks [0] = clock(); // no [0] ficar� salvo o tempo inicial
 
    printf("\n"); 
    
    printf("Apresentando vetor Desordenado:\n\n");
	for(int i=0;i<100;i++){		
        vetor[i] = rand()%99;         //preenchendo vetor
        printf("%d ", vetor[i]); //Mostra vetor desordenado
	}
	
	quick(vetor,0,n); //Chamando a fun��o, com os par�metros estabelecidos
	
    printf("\n\n\n");
    
    printf("Apresentando vetor Ordenado:\n\n");
    for(int i=0;i<100;i++){	
        printf("%d ", vetor[i]);  //Mostra o vetor em ordem ap�s receber a fun��o
	}
	 
	 printf("\n\n");
	
    Ticks[1] = clock(); // no [1] ficar� salvo o tempo final
    tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 transforma em milissegundos 
    printf("\n\n");
    printf("Tempo Gasto para conclusao: %g ms\n", tempo);	//Apresenta o tempo gasto
   		
	printf("\n\n");
	
    break;
	
	case 2:
         
    Ticks [0] = clock(); // no [0] vai ficar salvo o tempo inicial
    
    printf("\n\n");
    
    printf("Apresentando vetor Desordenado:\n\n");
    for(int i=0;i<100;i++){		
        vetor[i] = rand()%99;         //preenchendo vetor
        printf("%d ", vetor[i]); //Mostra vetor desordenado
	}
	
	selection(vetor,n); //Chama a fun��o, passando os par�metros
	
	printf("\n\n ");
	
    printf("Apresentando vetor Ordenado:\n\n");
    //Mostra vetor Ordenado
    for(int i=0;i<n;i++){
        printf("%d ",vetor[i]);
    }

    printf("\n\n");
	
	Ticks[1] = clock(); // no [1] vai fica salvo o tempo final
    tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 pra ser em milissegundos 
    printf("\n\n");
    printf("Tempo gasto para conclusao: %g ms\n", tempo);	
   		
	printf("\n\n");
	
	break;
	
	case 3:
         
    Ticks [0] = clock(); // no [0] ficar� salvo o tempo inicial
 
    printf("\n"); 
    
    printf("Apresentando vetor Desordenado:\n\n");
	for(int i=0;i<100;i++){		
        vetor[i] = rand()%99;         //preenchendo vetor
        printf("%d ", vetor[i]); //Mostra vetor desordenado
	}
	
	insertion(vetor,n); //Chamando a fun��o, com os par�metros estabelecidos
	
    printf("\n\n\n");
    
    printf("Apresentando vetor Ordenado:\n\n");
    for(int i=0;i<100;i++){	
        printf("%d ", vetor[i]);  //Mostra o vetor em ordem ap�s receber a fun��o
	}
	 
	 printf("\n\n");
	
    Ticks[1] = clock(); // no [1] ficar� salvo o tempo final
    tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 transforma em milissegundos 
    printf("\n\n");
    printf("Tempo gasto para conclusao: %g ms\n", tempo);	//Apresenta o tempo gasto
   		
	printf("\n\n");
	
    break;
    
    case 4:
         
    Ticks [0] = clock(); // no [0] ficar� salvo o tempo inicial
 
    printf("\n"); 
    
    printf("Apresentando vetor Desordenado:\n\n");
	for(int i=0;i<100;i++){		
        vetor[i] = rand()%99;         //preenchendo vetor
        printf("%d ", vetor[i]); //Mostra vetor desordenado
	}
	
	merge(vetor,0,n); //Chamando a fun��o, com os par�metros estabelecidos
	
    printf("\n\n\n");
    
    printf("Apresentando vetor Ordenado:\n\n");
    for(int i=0;i<100;i++){	
        printf("%d ", vetor[i]);  //Mostra o vetor em ordem ap�s receber a fun��o
	}
	 
	 printf("\n\n");
	
    Ticks[1] = clock(); // no [1] ficar� salvo o tempo final
    tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 transforma em milissegundos 
    printf("\n\n");
    printf("Tempo gasto para conclusao: %g ms\n", tempo);	//Apresenta o tempo gasto
   		
	printf("\n\n");
	
    break;
         
    case 5:
         
    Ticks [0] = clock(); // no [0] ficar� salvo o tempo inicial
 
    printf("\n"); 
    
    printf("Apresentando vetor Desordenado:\n\n");
	for(int i=0;i<100;i++){		
        vetor[i] = rand()%99;         //preenchendo vetor
        printf("%d ", vetor[i]); //Mostra vetor desordenado
	}
	
	shell(vetor,n); //Chamando a fun��o, com os par�metros estabelecidos
	
    printf("\n\n\n");
    
    printf("Apresentando vetor Ordenado:\n\n");
    for(int i=0;i<100;i++){	
        printf("%d ", vetor[i]);  //Mostra o vetor em ordem ap�s receber a fun��o
	}
	 
	 printf("\n\n");
	
    Ticks[1] = clock(); // no [1] ficar� salvo o tempo final
    tempo = (Ticks[1] - Ticks[0] * 1000.0 / CLOCKS_PER_SEC); // *1000.0 transforma em milissegundos 
    printf("\n\n");
    printf("Tempo gasto para conclusao: %g ms\n", tempo);	//Apresenta o tempo gasto
   		
	printf("\n\n");
	
    break;   
         
}

    system("pause");
    return 0;
}
