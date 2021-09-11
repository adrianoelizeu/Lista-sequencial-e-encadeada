#include <stdio.h>
#include "lista.h"

int main(void) {
int x;

Lista * l;

l=criar();

criar_inimigos(l, "Alberto Sousa", 1, 3.6);
criar_inimigos(l, "Pedro Silva", 9, 4.7);
criar_inimigos(l, "Rosa Maria", 2, 1.9);

imprimir_inimigos(l);

inimmigo_localizar(l,"Rosa Maria");

matar_inimigo(l, "Alberto Sousa");

imprimir_inimigos(l);

tamanho_lista(l);

deletar_lista(l);

tamanho_lista(l);

}