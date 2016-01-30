#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>

#include "encadeamento_interior.h"
#include "lista_clientes.h"
#include "cliente.h"

void cria_hash(char *nome_arquivo_hash, int tam)
{
	ListaClientes *tab_cliente = cria_clientes(7,
	    cliente(-1, "", 0, LIBERADO),
	    cliente(-1, "", 1, LIBERADO),
		cliente(-1, "", 2, LIBERADO),
		cliente(-1, "", 3, LIBERADO),
		cliente(-1, "", 4, LIBERADO),
		cliente(-1, "", 5, LIBERADO),
		cliente(-1, "", 6, LIBERADO));

    salva_clientes(nome_arquivo_hash, tab_cliente);
	libera_clientes(tab_cliente);
}

int busca(int cod_cli, char *nome_arquivo_hash, int tam, int *encontrou)
{
	ListaClientes *lc = le_clientes(nome_arquivo_hash);
    int end = cod_cli % 7;
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
	//TODO: Inserir aqui o codigo do algoritmo de insercao
    return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_hash, int tam)
{
	//TODO: Inserir aqui o codigo do algoritmo de remocao
    return INT_MAX;
}
