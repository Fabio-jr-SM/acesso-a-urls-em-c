#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Cjson/cJSON.h"
#include "../library/urls.h"

#define MAX_LISTA 10

// Verificar se a lista está cheia
int listaCheia(LISTA li) {
    return (li->qtd >= MAX_LISTA);
}

// Verificar se a lista está vazia
int listaVazia(LISTA li) {
    return (li->qtd == 0);
}

// Criar lista
LISTA criaLista() {
    LISTA li = (LISTA)malloc(sizeof(struct lista));
    if (li != NULL) {
        li->qtd = 0;
        printf("\nLista criada com sucesso.\n\n");
    }
    return li;
}

// Inserir na última posição da lista
int insereLista(LISTA li, URL url_info) {
    if (li == NULL || listaCheia(li)) {
        printf("\nLista cheia ou inexistente.\n\n");
        return 0;
    }
    li->dados[li->qtd] = url_info;
    li->qtd++;
    return 1;
}

// Mostrar lista
void mostraLista(LISTA li) {
    if (li == NULL || listaVazia(li)) {
        printf("\nLista vazia ou nao inicializada.\n\n");
        return;
    }

    printf("%-40s %-15s %-10s\n", "URL", "DATA", "HORARIO DE ACESSO");
    printf("------------------------------------------------------------\n");

    for (int i = 0; i < li->qtd; i++) {
        printf("%-40s %-15s %-10s\n", li->dados[i].url, li->dados[i].data_acesso, li->dados[i].horario_acesso);
    }

    printf("\n");
}

// Destruir lista
void destruirLista(LISTA *li) {
    if (*li != NULL) {
        free(*li);
        *li = NULL;
        printf("\n\nLista destruida com sucesso\n\n");
    } else {
        printf("Nenhuma lista criada ou lista ja destruida.\n\n");
    }
}

// Tamanho de uma lista
int tamanhoLista(LISTA li) {
    if (li == NULL) {
        printf("Lista inexistente\n\n");
        return 0;
    }
    return li->qtd;
}

// Inserir elementos no início da lista
int insereInicio(LISTA li, URL url_info) {
    if (li == NULL || listaCheia(li)) {
        printf("\nLista cheia ou inexistente.\n\n");
        return 0;
    }

    for (int i = li->qtd - 1; i >= 0; i--) {
        li->dados[i + 1] = li->dados[i];
    }
    li->dados[0] = url_info;
    li->qtd++;
    return 1;
}

// Remover final da lista
int removeFinal(LISTA li) {
    if (li == NULL || listaVazia(li)) {
        printf("Falha ao abrir a lista\n\n");
        return 0;
    }
    li->qtd--;
    printf("Ultimo elemento removido com sucesso\n\n");
    return 1;
}

// Remover início da lista
int removeInicio(LISTA li) {
    if (li == NULL || listaVazia(li)) {
        printf("Falha ao abrir a lista\n\n");
        return 0;
    }
    for (int i = 0; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    printf("Primeiro elemento removido com sucesso\n\n");
    return 1;
}

// Inserir elementos em uma posição qualquer da lista
int inserePosicaoQualquer(LISTA li, int posicao, URL url_info) {
    if (li == NULL || listaCheia(li) || posicao < 0 || posicao > li->qtd) {
        printf("Posição inválida ou falha ao abrir lista.\n\n");
        return 0;
    }
    for (int i = li->qtd - 1; i >= posicao; i--) {
        li->dados[i + 1] = li->dados[i];
    }
    li->dados[posicao] = url_info;
    li->qtd++;
    return 1;
}

// Remover elementos de qualquer posição da lista
int removePosicaoQualquer(LISTA li, int posicao) {
    if (li == NULL || listaVazia(li) || posicao < 0 || posicao >= li->qtd) {
        printf("Posição inválida ou lista inexistente.\n\n");
        return 0;
    }
    for (int i = posicao; i < li->qtd - 1; i++) {
        li->dados[i] = li->dados[i + 1];
    }
    li->qtd--;
    return 1;
}


void carregarDadosJSON(LISTA li, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Não foi possível abrir o arquivo JSON.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long length = ftell(file);
    fseek(file, 0, SEEK_SET);
    char *data = malloc(length + 1);
    fread(data, 1, length, file);
    fclose(file);

    cJSON *json = cJSON_Parse(data);
    if (json == NULL) {
        printf("Erro ao parsear o JSON.\n");
        free(data);
        return;
    }

    cJSON *item;
    cJSON_ArrayForEach(item, json) {
        URL coleta;
        strcpy(coleta.url, cJSON_GetObjectItem(item, "url")->valuestring);
        strcpy(coleta.data_acesso, cJSON_GetObjectItem(item, "data_acesso")->valuestring);
        strcpy(coleta.horario_acesso, cJSON_GetObjectItem(item, "horario_acesso")->valuestring);
        insereLista(li, coleta);
    }

    cJSON_Delete(json);
    free(data);
}
