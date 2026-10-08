#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura de um nó da árvore binária.
// A esquerda é usada para '.', e a direita para '-'.
typedef struct Node {
    char letra;
    struct Node *esq;
    struct Node *dir;
} Node;

// Cria a árvore recursivamente a partir do heap
Node *addNode(char letras[], int pos) {
    if (pos >= 29) return NULL;

    Node *node = malloc(sizeof(Node));

    node->letra = letras[pos];
    node->esq = addNode(letras, 2 * pos + 1);
    node->dir = addNode(letras, 2 * pos + 2);

    return node;
}

// Monta a árvore morse a partir de um heap
Node *createTree() {
    char letras[] = {
        '*',
        'E', 'T',
        'I', 'A', 'N', 'M',
        'S', 'U', 'R', 'W', 'D', 'K', 'G', 'O',
        'H', 'V', 'F', '*', 'L', '*', 'P', 'J',
        'B', 'X', 'C', 'Y', 'Z', 'Q'
    };

    return addNode(letras, 0);
}

// Percorre a árvore conforme os símbolos '.' e '-' do código.
// Quando encontra '_', imprime a letra atual e volta para a raiz.
// Quando chega ao final, imprime a última letra.
void decodificar(Node *raiz, char *codigo) {
    // IMPLEMENTAR
}

// Libera a memória da árvore
void freeNode(Node *raiz) {
    if (raiz == NULL) {
        return;
    }

    freeNode(raiz->esq);
    freeNode(raiz->dir);

    free(raiz);
}

int main() {
    Node *raiz = createTree();
    char codigo[200];

    // Lê o código Morse e chama a função de decodificação.
    scanf("%s", codigo);
    decodificar(raiz, codigo);
    printf("\n");
    freeNode(raiz);

    return 0;
}
