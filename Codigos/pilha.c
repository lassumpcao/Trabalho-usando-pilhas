/**************************************
* Trabalho 2 de Estrutura de Dados I
* Curso de Sistemas da informacão
* Aluno: Luiz Felipe Teixeira Assumpção - matricula: 0050008552
* Analise de expressão aritmetica
***************************************/
#include "pilha.h"
#include <ctype.h>
#include <stdlib.h>

void calcula(Pilha* p1, Pilha* p2){
    int e1,e2;
	char op;
    int r;
    e1=(int)pilha_pop(p1);
    e2=(int)pilha_pop(p1);
    op=pilha_pop(p2);
    
    if(op=='+')
		pilha_push(p1,e2+e1);
    else
    	if(op=='-')
    		pilha_push(p1,e2-e1);
    	else
    		if(op=='/')
    			pilha_push(p1,e2/e1);
    		else
    			if(op=='*')
    				pilha_push(p1,e2*e1);
    	

}
int chartoint(char c)
{
	int i;
	int num=toDigit(c);
	for(i=0;i<10;i++)
	{
		if(num==i)
			return i;
	}

}

int main()
{
    char op;
    char conta[50];
    int i;
     
    Pilha* num;
    Pilha* opera;
    
    num=pilha_cria();
    opera=pilha_cria();
    
    puts("Ola, meu nome e Luiz Felipe,");
    do{
    	fflush(stdin);
        puts("Entre com a expressao que deseje, para que eu calcule: ");
        scanf("%s",conta);
        fflush(stdin);
       
        for(i=0;i<strlen(conta);i++)
		{
			//ve se é número //
            if(isdigit(conta[i]))
			{
				printf("%d",chartoint(conta[i]));
                pilha_push(num,chartoint(conta[i]));
				
            } 
			else
			{
				//Nao precisa fazer //
				if(conta[i]=='(')
				{
					
            	}
	            else 
				{
					//se for ) ele calcula //
					if(conta[i]==')')
					{
	                	calcula(num,opera);
	            	}
					else
					{
						//empilha pois é operando //
	                	pilha_push(opera,conta[i]);
	            	}
	        	}
        	}
        }
        printf("\nObrigado, o resultado da sua expressao e: %d",pilha_pop(num));
        do{
            printf("\nDeseja continuar (s/n)?:");
            scanf("%c",&op);
            fflush(stdin);
            
        }while(tolower(op)!='s'&& tolower(op)!='n');
    }while(op=='s');
    puts("Fim !");
    
    //Libera as pilhas //
    pilha_libera(num);
    pilha_libera(opera);
    return 0;
}
