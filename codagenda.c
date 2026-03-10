#include <stdio.h>

typedef struct {
    char nome[128];
    char telefone[32];
} dados;

void fadd (dados *telnum);

void delctt (dados *telnum);

void wrtctt (dados *telnum);

void slvdados (dados *telnum);

void opndados (dados *telnum);

int main() {

    int i, x;
    int menu;
    int continuar;
    dados telnum [100];

    continuar = 0;
    x = 1;

    

    for (i = 0 ; i < 100; i ++) { 

        telnum [i].nome[0] = '\0';
        telnum [i].telefone[0] = '\0';
    }

    while (x == 1) {
        
        printf ("\n\n      <<<MENU>>>\n\n");
        printf ("[1] Adicionar Contato\n");
        printf ("[2] Remover Contato\n");
        printf ("[3] Listar Contatos\n");
        printf ("[4] Salvar Em Arquivo\n");
        printf ("[5] Abrir Arquivo\n");
        printf ("[6] Sair\n");
        
        scanf ("%d", &menu);
        while (getchar() != '\n');
        
        switch (menu) {
            
            case 1:
            
            for (i = 0; i < 100; i ++) {
                
                if (telnum[i].nome[0] == '\0') {
                    
                    fadd (&telnum [i]);
                    
                    printf ("Deseja adicionar outro contato?\n");
                    printf ("[1] Sim\n");
                    printf ("[2] Nao\n");
                    scanf ("%d", &continuar);
                    while (getchar() != '\n');
                                    
                    if (continuar == 2) {
                                        
                        break;                
                    }
                } 

            }
            
            break;

            case 2:

            delctt (telnum);

            break;
            
            case 3:
            
            wrtctt (telnum);;
            
            break;
            
            case 4: 
            
            slvdados (telnum);
            
            break;
            
            case 5:
            
            opndados (telnum);
            
            break;
            
            case 6:
            
            x = 2;
        }
        
    }
    return 0;
    
}

void fadd (dados *telnum) {

    if (telnum[100].nome[0] != '\0') {

        printf ("Limite de contatos alcancados!\n");
    }
    
    printf ("\nDigite o nome do contato:\n");
    fgets (telnum -> nome, sizeof (telnum -> nome), stdin);
    
    printf ("\nDigite o numero do contato:\n");
    fgets (telnum -> telefone, sizeof (telnum -> telefone), stdin);

    printf ("\nContato Adicionado \n\n"); 
}

void delctt (dados *telnum) {
    int nmr, i;

    printf ("\nDigite o numero do contato a ser deletado:\n");
    scanf ("%d", &nmr);
    while (getchar() != '\n');

    if (nmr < 1 || nmr > 100) {

        printf ("\nNumero invalido.\n");
        return;
    }

    nmr = nmr - 1;

    if (telnum[nmr].nome[0] == '\0') {

        printf ("\nContato inexistente.\n");
        return;
    }

    for (i = nmr; i < 99; i ++) {

        telnum[i] = telnum[i + 1];
    }

    telnum[99].nome[0] = '\0';
    telnum[99].telefone[0] = '\0';

    printf ("\nContato Deletado.\n");

}

void wrtctt (dados *telnum) {

    if (telnum[0].nome[0] == '\0') {

        printf ("Agenda vazia!\n");
    }

    int i;
    
    for (i = 0; i < 100; i ++) {
        
        if (telnum [i].nome[0] != '\0') {
            
            printf ("CONTATO %d:\n\n", i + 1);
            printf ("Nome: \n%s \n", telnum [i].nome);
            printf ("Telefone: \n%s \n", telnum [i].telefone);
            
        }
    }
    system ("pause");

    return;
}

void slvdados (dados *telnum) {

    FILE *arqv;

    arqv = fopen ("cntt.dat", "wb");

    if (arqv == NULL) {

        printf ("Erro ao abrir o arquivo. \n");

        return;
    }

    fwrite (telnum, sizeof(dados), 100, arqv);

    fclose (arqv);

    printf ("Os contatos foram salvos.");

}

void opndados (dados *telnum) {

    FILE *arqv;

    arqv = fopen ("cntt.dat", "rb");

    if (arqv == NULL) {

        printf ("Arquivo nao encontrado. \n");

        return;    
    }

    fread (telnum, sizeof (dados), 100, arqv);

    fclose (arqv);

    printf ("Contatos carregados. \n");
}
