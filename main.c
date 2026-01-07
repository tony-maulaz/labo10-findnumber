#include <stdio.h>
#include <stdbool.h>

void print_help(void)
{
    printf("Usage: ./number [options]\n");
    printf("\n");
    printf("Options:\n");
    printf("  -n<nombre>    Fixe le nombre que l'ordinateur fait deviner\n");
    printf("  -h, --help    Affiche l'aide du programme\n");
    printf("  -v, --version Affiche la version du programme\n");
    printf("  -t, --test    Teste le generateur aleatoire (10 nombres)\n");
    printf("  -o1           Jeu: l'utilisateur devine le nombre\n");
    printf("  -o2           Jeu: l'ordinateur devine le nombre\n");
    printf("  --cheat       Affiche le nombre a deviner au debut du jeu\n");
    printf("\n");
    printf("Exemples:\n");
    printf("  ./number -h\n");
    printf("  ./number --version\n");
    printf("  ./number -t\n");
    printf("  ./number -o1\n");
    printf("  ./number -o1 -n500 --cheat\n");
    printf("  ./number -o2\n");
}

int game_computer_guess(void){
    printf("\n");
    printf("Indiquez ou je me situe avec un des operateurs suivants :\n");
    printf("        + : le nombre est trop grand\n");
    printf("        - : le nombre est trop petit\n");
    printf("        = : le nombre est juste\n");
    printf("        q : abandonner\n");   
}

char ask_operator(void)
{
    while (true)
    {
        char op;
        int c;
        printf("Saisir un operateur (+, -, = ou q) : ");
        scanf("%c", &op);

        while ((c = getchar()) != '\n' && c != EOF);

        if (op == '+' || op == '-' || op == '=' || op == 'q')
        {
            return op;
        }

        printf("Erreur : operateur invalide. Recommencez.\n");
    }

    return 'q';
}

int main(int argc, char* argv[])
{
    bool cheat_mode = false;

    for(int i=0; i<argc; i++) {
        if (strcmp(argv[i], "--cheat") == 0)
            cheat_mode = true;
    }

    return 0;
}
