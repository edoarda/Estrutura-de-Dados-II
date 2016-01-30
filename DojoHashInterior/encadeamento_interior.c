#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdlib.h>
#include "encadeamento_interior.h"
#include "lista_clientes.h"
#include "cliente.h"

void cria_hash(char *nome_arquivo_hash, int tam)
{
	FILE *out = fopen(nome_arquivo_hash, "wb");
	int i;
	for (i = 0; i < tam; i++) {
		Cliente *cliente1 = cliente(-1,"",i, LIBERADO);
		fwrite(&cliente1->cod_cliente, sizeof(int), 1, out);
		fwrite(cliente1->nome, sizeof(char), sizeof(cliente1->nome), out);
		fwrite(&cliente1->prox, sizeof(int), 1, out);
		fwrite(&cliente1->flag, sizeof(int), 1, out);
		free(cliente1);
	}
	fclose(out);
}

int busca(int cod_cli, char *nome_arquivo_hash, int tam, int *encontrou)
{
	ListaClientes *lc = le_clientes(nome_arquivo_hash);
    int end = cod_cli % tam;
	int j;
	while(*encontrou == -1){
		Cliente *item = lc->lista[end];
		if(item->flag == LIBERADO){
			j = end;
		}
		if(item->flag == OCUPADO && item->cod_cliente == cod_cli){
			*encontrou = 1;
		}else{
			if(end == item->prox){
				end = j;
				*encontrou = 0;
			}else{
				end = item->prox;
			}
		}
	}
	
	libera_clientes(lc);

    return end;
}

int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, int tam)
{
	//SEGMENTATION FAULT ????
	/* 
	int ret = 0;
	int a = -1;
	int h = cod_cli % tam;
	int end = busca(cod_cli,nome_arquivo_hash,tam,&a);
	int i,j,temp;
	ListaClientes *lc = le_clientes(nome_arquivo_hash);
	if(a != 1){
		if(end != lc->lista[end]->prox){
			j = end;
		}else{
			i = 1;
			j = h;
			while(i <= tam){
				if(lc->lista[end]->flag == OCUPADO){
					j = (j+1) % tam;
					i = i + 1;
				}else{
					i = tam + 2;
					ret = 1;
				}
			}
			if(i == (tam + 1)){
				ret = 1;
			}
			temp = lc->lista[h]->prox;
			lc->lista[h]->prox = j;
			lc->lista[j]->prox = temp;
		}
		lc->lista[j]->cod_cliente = cod_cli;
		lc->lista[j]->flag = OCUPADO;
		salva_clientes(nome_arquivo_hash, lc);
		libera_clientes(lc);
		if(ret){
			return ret;
		}
		else{
			return j;
		}
	}else{
		return end;
	}
	*/
	
	return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_hash, int tam)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}
