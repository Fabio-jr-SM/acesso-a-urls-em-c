#include <stdio.h>
#include <string.h>
#include "../Cjson/cJSON.h"
#include "../library/urls.h"

int main() {
    LISTA li = criaLista();
    carregarDadosJSON(li, "urls.json");
    int op, posicao;
    URL coleta;

    do {
        printf(
            "\n\n===========MENU===========\n\n"
            "[1] Criar uma lista\n"
            "[2] Inserir Elementos no lista Final da lista\n"
            "[3] Inserir elementos no inicio da lista\n"
            "[4] Inserir elementos em uma posicao qualquer da lista\n"
            "[5] Remover elementos do inicio da lista\n"
            "[6] Remover elementos do final da lista\n"
            "[7] Remover elementos de qualquer posicao da lista\n"
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
    return 0;
}
