# Gerenciador de Lista de URLs

Este projeto em C implementa um gerenciador de lista de URLs com operações de inserção, remoção e exibição de URLs. Além disso, os dados podem ser carregados de um arquivo JSON usando a biblioteca cJSON.

## Estrutura de Arquivos

```
project-root/
│
├── Cjson/
│   ├── cJSON.c        # Implementação da biblioteca cJSON
│   └── cJSON.h        # Header da biblioteca cJSON
├── files c/
│   └── urls.c         # Implementação das funções de manipulação da lista
├── library/
│   └── urls.h         # Declarações de funções e estruturas para manipulação da lista
│
├── main.c             # Código principal que gerencia o fluxo do programa
├── dados.json          # Arquivo JSON com os dados das URLs
└── README.md          # Este arquivo de documentação
```

## Dependências

- Biblioteca [cJSON](https://github.com/DaveGamble/cJSON) para parsing de arquivos JSON.

## Configuração do Ambiente

1. **Instale o GCC** (se ainda não estiver instalado).
2. **Instale o VS Code** (se ainda não estiver instalado).
3. **Baixe a biblioteca cJSON** e coloque os arquivos `cJSON.c` e `cJSON.h` na pasta `Cjson`.

## Compilação e Execução

No VS Code, siga as etapas abaixo para compilar e executar o programa:

1. Abra o terminal integrado no VS Code (`Ctrl + ``).
2. Navegue até o diretório raiz do projeto.
3. Compile o projeto usando o comando:

   ```bash
   gcc './main.c' './files c/urls.c' './Cjson/cJSON.c' -o programa
   ```

4. Execute o programa gerado:

   ```bash
   ./programa
   ```

## Funcionalidades

O programa oferece as seguintes opções através de um menu:

1. **Criar uma lista**
2. **Inserir elementos no final da lista**
3. **Inserir elementos no início da lista**
4. **Inserir elementos em uma posição específica da lista**
5. **Remover elementos do início da lista**
6. **Remover elementos do final da lista**
7. **Remover elementos de uma posição específica da lista**
8. **Determinar o tamanho da lista**
9. **Mostrar lista**
10. **Destruir lista**
0. **Finalizar programa**

## Carregamento de Dados JSON

O programa lê um arquivo JSON chamado `dados.json` que contém as URLs, datas de acesso e horários. Os dados são carregados automaticamente na lista ao iniciar o programa.

## Exemplo de Arquivo JSON (`dados.json`)

```json
[
    {
        "url": "http://exemplo.com",
        "data_acesso": "01/01/2024",
        "horario_acesso": "12:00"
    },
    {
        "url": "http://exemplo2.com",
        "data_acesso": "02/01/2024",
        "horario_acesso": "14:00"
    }
]
```

## Licença

Este projeto está sob a [MIT License](LICENSE).
