#include <stdlib.h>
#include <stdio.h>
#include "queue.h"
#include "stack.h"
#include "list.h"


/*
                MAIN pour tester list.h
*/
int main()
{
    t_list *liste = (t_list *)malloc (sizeof(t_list));
    void *data;
    l_init (liste);

    for (int i = 0; i < 10; i++)
        l_push_back(liste, &i, sizeof(int));

    printf ("Liste apres initialisation\n");
    l_view (liste);

    for (int i = 0; i < 4; i++)
    {    
        data = l_pop_back(liste);
        printf ("Pop : [%d], ", *(int*)data);
        free (data);
    }
    printf ("\n");

    printf ("Liste apres pop_back () des 3 premiers éléments\n");
    l_view (liste);   

    l_clear(liste);
    free (liste);
    return 0;
}

/*
                MAIN pour tester stack.h

int main()
{
    menu ();
    return 0;
}
*/

/*              MAIN tester queue.h 
int main ()
{
    Queue my_queue = init_queue();
    t_data d1 = {1, "Chaine de 1\0"};
    t_data d2 = {2, "Chaine de 2\0"};
    //t_data *ptr = (t_data *)malloc(sizeof(t_data));

    printf("Enfile [%s] [%d]\n", d1.name, d1.id);
    enqueue_queue(my_queue, &d1, sizeof(t_data));
    printf("Enfile [%s] [%d]\n", d2.name, d2.id);
    enqueue_queue(my_queue, &d2, sizeof(t_data));

    printf("Etat de la file : \n");
    queue_print_st(my_queue);
    printf("Nombre d'element de la liste : [%d]\n", queue_length(my_queue));

    t_data *ptr = (t_data *)(dequeue_queue(my_queue));
    printf("\n Defile name: [%s] id: [%d]\n", ptr->name, ptr->id);
   //free(ptr);

    ptr = (t_data *) dequeue_queue(my_queue);
    printf("\n Defile name: [%s] id: [%d]\n", ptr->name, ptr->id);

    printf("\nEtat de la liste");
    queue_print_st(my_queue);

    printf("Nombre d'element de la liste : [%d]\n", queue_length(my_queue));

    delete_queue(my_queue);
    printf("\nLa liste a été vidée\n");
    //free(ptr);
    return 0;
}
*/