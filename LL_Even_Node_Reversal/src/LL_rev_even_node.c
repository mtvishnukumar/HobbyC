/*************************************************************************************
 * The objective of this program is to reverse the nodes present in the even position
 * of a single linked list.
 *
 * EXAMPLE: 
 * I/P List: 1-2-3-4-5-6-7-8
 * O/P List: 1-8-3-6-5-4-7-2
 *
**************************************************************************************/ 
#include "LL_rev_even_node.h"

int main()
{
    node_t *phead = NULL, *temp = NULL, *temp1 = NULL;
    int total_nodes = 0,ite = 0;
    
    printf("Enter the total Number of nodes:");
    scanf("%d",&total_nodes);

    if (total_nodes <= 0)
        return SUCCESS;

    for (ite = 0; ite < total_nodes; ite++)
    {   
        printf("\nEnter the Node-%d data:",ite+1);
        if(ite == 0)
        {   
            /* Head node creation */
            phead = (node_t*)calloc(1,sizeof(node_t));
            if (phead == NULL)
            {   
                printf("\nMemory allocation failed");
                return FAILURE;
            }   
            scanf("%d",&(phead->data));
            phead->pnext = NULL;
            temp = phead;
        }   
        else
        {
            temp1 = temp;
            temp = (node_t*)calloc(1,sizeof(node_t));
            if (temp == NULL)
            {
                printf("\nMemory Allocation Failed");
                release_memory(phead);
                return FAILURE;
            }
            scanf("%d",&(temp->data));
            temp1->pnext = temp;
        }
    }
    even_node_reverse(phead);
    traverse_list(phead);
    release_memory(phead);

    return SUCCESS;
}
void even_node_reverse(node_t *phead)
{
    node_t *head=NULL, *temp1= NULL, *temp2 = NULL, *temp3 = NULL, *temp4 = NULL, *temp5 = NULL;
    int end1 = 0, end2 = 0, index = 0, index1 = 0, total_nodes = 0;

    if (phead == NULL)
    {
        return;
    }

    head = phead;
    temp1 = head;

    while (temp1 != NULL)
    {
        total_nodes++;
        temp1 = temp1->pnext;
    }

    /* Initialising the forward tarversing index */
    end1 = 2;

    /* Initialisation of reverse traversing index */
    if(total_nodes % 2 == 0)
    {
        end2 = total_nodes - 1;
    }
    else
    {
        end2 = total_nodes -2 ;
    }

    /* The rason for total_nodes/4 is that, we are going to reverse even positoned nodes
     * alone; so total of (total_nodes/2) nodes needs to be arranged; to do that, half of
     * the iteration is sufficient to reverse the nodes. i.e ((total_nodes/2)*(1/2))*/
    for (index = 0; index < (total_nodes/4);index++)
    {
        temp1 = head;
        for (index1 = 1; index1 < end1; index1++)
        {
            temp2 = temp1;
            temp1 = temp1->pnext;
        }

        temp3 = head;
        for (index1 = 1; index1 <= end2; index1++)
        {
            temp4 = temp3;
            temp3 = temp3->pnext;
        }

        /* Rearranging the Links */
        temp5 = temp3->pnext;
        temp2->pnext = temp3;
        temp3->pnext = temp1->pnext;
        temp4->pnext = temp1;
        temp1->pnext = temp5;

        end1 += 2;
        end2 -= 2;
    }

    return;
}
void release_memory (node_t *phead)
{
    node_t *temp = NULL, *temp1 = NULL;

    if (phead == NULL)
        return;

    temp = phead;
    while(temp != NULL)
    {
        temp1 = temp->pnext;
        free(temp);
        temp = temp1;
    }
}

void traverse_list (node_t *phead)
{
    node_t *temp = NULL;

    if (phead == NULL)
    {
        return;
    }

    temp = phead;
    printf("\n The data stored in the list are:");
    while(temp != NULL)
    {
        printf(" %d",temp->data);
        temp = temp->pnext;
    }

    printf("\n");
    return;
}
                                                         
