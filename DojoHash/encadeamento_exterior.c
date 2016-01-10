#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "encadeamento_exterior.h"



void cria_hash(char *nome_arquivo_hash, int tam)
{
	FILE *arquivo = fopen(nome_arquivo_hash, "wb");
	if(arquivo != NULL){
        int i;
        for(i = 0; i < tam; i++){
            salva_compartimento(compartimento_hash(-1), arquivo);
        }
	}else{
        printf("deu xibu");
	}
	fclose(arquivo);
    printf("\n\n\n\n\n");
}

int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo
    int h = cod_cli % 7;

    FILE *arquivo = fopen(nome_arquivo_hash, "rb");
    FILE *arquivoDados = fopen(nome_arquivo_dados, "rb");
	if(arquivo != NULL && arquivoDados != NULL){
        fseek(arquivo, h*sizeof(int));
        CompartimentoHash compH = le_compartimento(arquivo);
        fseek(arquivoDados, compH->prox);
        ListaCompartimentos compLista = le_compartimentos(arquivoDados);

	}else{
        printf("deu xibu");
	}
	fclose(arquivo);


    return INT_MAX;
}


int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros)
{
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}
