#ifdef _MSC_VER
#define _CRT_SECURE_NO_WARNINGS
#endif

#include <limits.h>
#include <stdlib.h>
#include <stdio.h>

#include "encadeamento_exterior.h"
#include "compartimento_hash.h"
#include "lista_compartimentos.h"
#include "lista_clientes.h"
#include "cliente.h"



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
}

int busca(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
    int h = cod_cli % 7;
    ListaClientes *lisCli = le_clientes(nome_arquivo_dados);
    int quant = lisCli->qtd;
    int i;
    for(i = 0; i < quant; i++){
        Cliente *item = lisCli->lista[i];
        if(item->cod_cliente == cod_cli){
            if(item->flag == 1){
                return i;
            }
        }
    }
    return -1;
}


int insere(int cod_cli, char *nome_cli, char *nome_arquivo_hash, char *nome_arquivo_dados, int num_registros)
{
    Cliente *cli = cliente(cod_cli, nome_cli, -1, 1);
    int h = cod_cli % 7;

    FILE *arquivo = fopen(nome_arquivo_hash, "rb");
	if(arquivo != NULL){
        fseek(arquivo, (h * sizeof(int)), SEEK_SET);
        ListaClientes *lisCli = le_clientes(nome_arquivo_dados);
        int quant = lisCli->qtd;
        int i;
        if(quant == 0){
            lisCli = cria_clientes(1, cli);
            salva_clientes(nome_arquivo_dados, lisCli);

                CompartimentoHash *cp = compartimento_hash(0);
                salva_compartimento(compartimento_hash(cp), arquivo);
            return 0;
        }

        for(i = 0; i < quant; i++){
            Cliente *item = lisCli->lista[i];
            if(item->flag == 0){
                item = cli;
                return i;
            }
        }
        return -1;
	}else{
        printf("deu xibu");
	}
	fclose(arquivo);



    /*ListaClientes *lisCli = le_clientes(nome_arquivo_dados);
    if(lisCli->lista[h] == -1){
        lisCli->lista[h] = cli;
        ListaClientes *lc = cria_clientes(num_registros, cli);
        salva_clientes(nome_arquivo_dados, lc);
        return 1;
    }*/


    return 1;


    return INT_MAX;
}

int exclui(int cod_cli, char *nome_arquivo_hash, char *nome_arquivo_dados)
{
	int h = cod_cli % 7;
    ListaClientes *lisCli = le_clientes(nome_arquivo_dados);
    int quant = lisCli->qtd;
    int i;
    for(i = 0; i < quant; i++){
        Cliente *item = lisCli->lista[i];
        Cliente *itemA = lisCli->lista[i-1];
        if(item->cod_cliente == cod_cli){
            if(item->flag == 1){
                item->flag = 0;
                if(item->prox == -1){
                    itemA->prox = -1;
                }
                salva_clientes(nome_arquivo_dados, lisCli);
                return i;
            }
        }
    }
    return -1;
}
