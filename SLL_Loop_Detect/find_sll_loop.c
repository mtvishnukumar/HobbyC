int HasCycle(Node* head)
{
   // Complete this function
   // Do not write the main method
    Node *temp = NULL, *temp1 = NULL;

    if (head == NULL)
    {
        return 0;
    }
    
    temp1 = head;
    do
    {
        if (temp1->next == temp1)
        {
            return 1;
        }
        temp = head;
        while(temp != temp1)
        {
            if(temp1->next == temp)
            {
                return 1;
            }
            temp = temp->next;
        }
        temp1 = temp1->next;
    }while(temp1 != NULL);
    
    return 0;
}
