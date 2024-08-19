/***************************************************************************



Fabio Junior Senna Moura



**************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../Cjson/cJSON.h"
#include "../library/urls.h"

#define MAX_LISTA 10

void menu() {
    LISTA li = criaLista();
    carregarDadosJSON(li, "dados.json");
    int op, posicao;
    URL coleta = {"", "", ""};

    do {
        printf(
            "\n\n===========MENU===========\n\n"
            "[1] Criar uma lista\n"
            "[2] Inserir Elementos no final da lista\n"
            "[3] Inserir elementos no início da lista\n"
            "[4] Inserir elementos em uma posição qualquer da lista\n"
            "[5] Remover elementos do início da lista\n"
            "[6] Remover elementos do final da lista\n"
            "[7] Remover elementos de qualquer posição da lista\n"
            "[8] Determinar o tamanho da lista\n"
            "[9] Mostrar lista\n"
            "[10] Destruir lista\n"
            "[0] Finalizar programa\n");

        scanf("%d", &op);

        switch (op) {
        case 1:
            li = criaLista();
            break;
        case 2:
            printf("Cole a URL: ");
            scanf("%s", coleta.url);
            printf("Digite a data (dd/MM/AAAA): ");
            scanf("%s", coleta.data_acesso);
            printf("Cole a hora de acesso (HH:MM): ");
            scanf("%s", coleta.horario_acesso);
            insereLista(li, coleta);
            break;
        case 3:
            printf("Cole a URL: ");
            scanf("%s", coleta.url);
            printf("Digite a data (dd/MM/AAAA): ");
            scanf("%s", coleta.data_acesso);
            printf("Cole a hora de acesso (HH:MM): ");
            scanf("%s", coleta.horario_acesso);
            insereInicio(li, coleta);
            break;
        case 4:
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            printf("Cole a URL: ");
            scanf("%s", coleta.url);
            printf("Digite a data (dd/MM/AAAA): ");
            scanf("%s", coleta.data_acesso);
            printf("Cole a hora de acesso (HH:MM): ");
            scanf("%s", coleta.horario_acesso);
            inserePosicaoQualquer(li, posicao, coleta);
            break;
        case 5:
            removeInicio(li);
            break;
        case 6:
            removeFinal(li);
            break;
        case 7:
            printf("Digite a posição: ");
            scanf("%d", &posicao);
            removePosicaoQualquer(li, posicao);
            break;
        case 8:
            printf("Tamanho da lista: %d\n", tamanhoLista(li));
            break;
        case 9:
            mostraLista(li);
            break;
        case 10:
            destruirLista(&li);
            break;
        default:
            break;
        }

    } while (op != 0);

    destruirLista(&li);
}

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
        printf("\nLista vazia ou não inicializada.\n\n");
        return;
    }

    printf("%-40s %-15s %-10s\n", "URL", "DATA", "HORÁRIO DE ACESSO");
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
        printf("\n\nLista destruída com sucesso\n\n");
    } else {
        printf("Nenhuma lista criada ou lista já destruída.\n\n");
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
    printf("Último elemento removido com sucesso\n\n");
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
