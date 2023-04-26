#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"

/*  //! new_stack (void) : créer une nouvelle pile vide
    Retourne un pointeur NULL (pile vide)
*/
Stack new_stack(void)
{
    return NULL;
}

/*  //! is_empty_stack (Stack) : Teste si la pile est vide
    Retourne true si la pile est vide, sinon false
*/
Bool is_empty_stack(Stack st)
{
    if (st == NULL)
        return true;
    return false;
}

/*  //! print_stack (Stack, void (*pf)(Stack st)): Affiche les élements de la pile
    pf : pointeur de sur la fonction d'affichage en fonction du type a afficher
    --> data_is_str () pour une chaîne de caractères
        data_is_int () pour des entiers
        data_is_float () pour des flottants
    Crée une fonction pour tout autre types de données (struct, ...)
*/
void data_is_str(Stack st)
{
    while (!is_empty_stack(st))
    {
        printf("[%s]\n", (char *)st->data);
        st = st->next; // valeur suivante
    }
}

void data_is_int(Stack st)
{
    while (!is_empty_stack(st))
    {
        int i = *(int *)st->data;
        printf("[%d]\n", i);
        st = st->next; // valeur suivante
    }
}

void data_is_float(Stack st)
{
    while (!is_empty_stack(st))
    {
        printf("[%f]\n", *(float *)st->data);
        st = st->next; // valeur suivante
    }
}

int print_stack(Stack st, void (*pf)(Stack st))
{
    if (is_empty_stack(st))
    {
        printf("Rien a affiche. Pile vide\n");
        return 0;
    }

    (*pf)(st);
    return 0;
}

/*  //! push_data (stack, void*, size_t) : Empile un élément dans la file
    stack : pointe sur la pile à empiler
    void* : pointeur générique sur les données à empiler
    size_t : taille des données (cf fonction menu pour exemple)
*/
Stack push_stack(Stack st, void *d, size_t size)
{
    StackElement *element;

    element = malloc(sizeof(*element));
    if (element == NULL)
    {
        fprintf(stderr, "Probleme d'allocation dynamique.\n");
        exit(EXIT_FAILURE);
    }
    element->data = malloc(size);
    memcpy(element->data, d, size);
    element->next = st;
    return element;
}

/*  //! clear_stack (Stack) : vide la pile et libére la mémoire
 */
Stack clear_stack(Stack st)
{
    while (!is_empty_stack(st))
    {
    //    free(st->data);
        st = pop_stack(st);
    }
    return new_stack(); // liste vide
}

/*  //! pop_stack (Stack) : Enlève le premier (sommet)de la pile (LIFO)
!ATTENTION NE RETOURNE PAS LA VALEUR DE LA PILE -> stack_peek ()
 */
Stack pop_stack(Stack st)
{
    StackElement *element;
    if (is_empty_stack(st))
        return new_stack();
    // on garde tout sauf le premier element
    element = st->next;
    free(st->data);
    free(st);       // on libere st
    return element; // on retourne le pointeur sauvegarder
}

/*  //! get_top_stack (Stack) : Renvoie les data du haut de la pile
    Retourne un  type void ne pas oublier le cast au retour
!ATTENTIION NE RETIRE PAS L'ELEMENT DE LA PILE -> pop_stack ()
*/
void *stack_peek(Stack st)
{
    if (is_empty_stack(st))
    {
        printf("Aucun sommet, la pile est vide\n");
        return NULL;
    }
    return st->data;
}

/*  //! stack_length (Stackk) : Retourne la hauteur de la pile (nb éléments)
 */
int stack_length(Stack st)
{
    int l = 0;
    while (!is_empty_stack(st))
    {
        l++;
        st = st->next;
    }
    return l;
}

/*  //! menu () : Permet de tester les différents appels de fonction
 */
void menu(void)
{
    Stack sta = new_stack(); // On crée une nouvelle pile
    int choix;               // pour le menu
    int i;                   // data
    int *ptr;
    Bool quit = true; // Sortie de la bouble de menu
    // char *text; // déclaration d'un type char
    // text =  (char *) malloc (sizeof (char*));

    // Boucle de menu
    while (quit)
    {
        printf("\n\n1- Empiler un élément\n");
        printf("2- Dépiler un élément\n");
        printf("3- Afficher la pile\n");
        printf("4- Afficher le sommet de la pile\n");
        printf("5- Hauteur de la pile\n");
        printf("6- Effacer la pile\n");
        printf("7- Quitter\n");
        printf("====> Entrez votre choix : ");
        scanf("%d", &choix);

        switch (choix)
        {
        case 1:
            printf("Valeur a ajouter (str) ==>");
            // scanf ("%s", text);
            scanf("%d", &i);
            sta = push_stack(sta, &i, sizeof(int));
            print_stack(sta, &data_is_int);
            break;

        case 2:
            sta = pop_stack(sta);
            print_stack(sta, &data_is_int);
            break;

        case 3:
            printf("La liste contient \n");
            print_stack(sta, &data_is_int);
            break;

        case 4:
            ptr = (int *)stack_peek(sta);
            if (ptr)
                printf("\nValeur du sommet [%d]\n", *ptr);
            else
                printf("\nPile vide\n");
            // printf ("\n%s\n",(char *)get_top_stack_data (sta));
            break;

        case 5:
            i = stack_length(sta);
            printf("\nHauteur de la pile (nb elelement) => [%d]\n", i);
            break;

        case 6:
            sta = clear_stack(sta);
            break;

        case 7:
            sta = clear_stack(sta); //! libere la mémoire avatn de quitter
            quit = false;
            break;

        default:
            printf("\nMauvais choix !!!!!");
            break;
        } // switch
    }     // while

//    free(sta); //! Libérer la mémoire avant de sortir du programme
}
