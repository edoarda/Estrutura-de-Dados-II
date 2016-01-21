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
    Cliente *cli = cliente(cod_cli, nome_cli, -1, OCUPADO);
    int h = cod_cli % 7;

	ListaClientes *lisCli = le_clientes(nome_arquivo_dados);
	ListaCompartimentos *lisComp = le_compartimentos(nome_arquivo_hash);
	
	int i;
	
	for(i = 0; i < lisCli->qtd; i++){
		Cliente *atual = lisCli->lista[i];
		if(atual->cod_cliente == cod_cli){
			return -1; //detectar insercao de chave existente
		}
		if(atual->flag == LIBERADO){
			lisCli->lista[i] = cli;
			if(lisComp->lista[h]->prox == -1){
				lisComp->lista[h] = compartimento_hash(i);
				salva_compartimentos(nome_arquivo_hash, lisComp);
			}else{
				Cliente *tmp = lisCli->lista[h];
				while(tmp->prox != -1){
					tmp = lisCli->lista[tmp->prox];
				}
				tmp->prox = i;
			}
			salva_clientes(nome_arquivo_dados, lisCli);
			return i;
		}
	}
	
	//insercao
	ListaClientes *lc = (ListaClientes *)  malloc(sizeof(ListaClientes));
	lc->qtd = (lisCli->qtd) + 1;
	lc->lista = (Cliente **) malloc(sizeof(Cliente *) * (lc->qtd));
	for (i = 0; i < lc->qtd; i++) {
		if(i < lisCli->qtd){
			lc->lista[i] = lisCli->lista[i];
		}else{
			lc->lista[i] = cli;
			if(lisComp->lista[h]->prox != -1){
				lisComp->lista[h]->prox = i;
				salva_compartimentos(nome_arquivo_hash, lisComp);
			}
			salva_clientes(nome_arquivo_dados, lc);
			return i;
		}
	}
	
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
