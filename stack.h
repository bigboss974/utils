/*
GESTION DE PILE FILO
*/
#ifndef __STACK__H__
    #define __STACK__H__
    // Type booléen (compatibilite avec tous le C ansii)
    #ifndef TYPE_BOOL
    #define TYPE_BOOL
    typedef enum
    {
        false, //0
        true, //1
    } Bool;
    #endif

    //Definition d'une pile
    typedef struct StackElement
    {
        void *data; //pointe sur les données de la pile //!cast lors de la récupération de la data
        struct StackElement *next; //pointe sur l'element suivant
    }StackElement, *Stack;


    //Affiche les éléments de la pile
    int print_stack(Stack, void (*pf)(Stack)); 
    Stack new_stack (void); // créer un pile vide
    Bool is_empty_stack (Stack st); //Test si la pile est vide 
    Stack pop_stack(Stack st); //Supprime le dernier élément de la pile un élément à la pile DEPILE
    Stack push_stack (Stack st, void *, size_t); //Ajoute un élément à la pile EMPILE
    int stack_length (Stack st); // Renvoie la hauteur de la pile (nb total d'élément)
    Stack clear_stack (Stack st); //Libère la mémoire occupée
    void* stack_peek (Stack st);//Renvoie la valeur du haut de la pile
    void menu (void); // Permet de tester le fonctionnement de la libririe

#endif
