#define MAX 2083

typedef struct urls {
    char horario_acesso[6];
    char data_acesso[11];
    char url[MAX];
} URL;

typedef struct lista {
    int qtd;
    URL dados[100];
} *LISTA;

LISTA criaLista();
int insereLista(LISTA li, URL url_info);
void mostraLista(LISTA li);
void destruirLista(LISTA *li);
int tamanhoLista(LISTA li);
int insereInicio(LISTA li, URL url_info);
int removeFinal(LISTA li);
int removeInicio(LISTA li);
int removePosicaoQualquer(LISTA li, int posicao);
int inserePosicaoQualquer(LISTA li, int posicao, URL url_info);
void carregarDadosJSON(LISTA li, const char *filename);