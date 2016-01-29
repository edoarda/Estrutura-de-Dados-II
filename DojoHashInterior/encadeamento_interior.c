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
	//TODO: Inserir aqui o codigo do algoritmo
    return INT_MAX;
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
