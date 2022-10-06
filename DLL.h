#ifndef DLL_H_INCLUDED
#define DLL_H_INCLUDED
struct node
{
	int data;
	struct node *next;
	struct node *prev;
} *start=NULL, *current, *newNode , *temp;
int ListLength()
{
    int count=0;
    if(start==NULL)
    {
        count=0;
        return count;
    }
    current=start;

    do
    {
        current = current->next;
        count++;
    } while (current != NULL);
    return count;
}

int InsertB(int value)
{
    newNode=(struct node *) malloc(sizeof(struct node));
    newNode->prev=NULL;
    newNode->data=value;
    if(start==NULL)//zero node are present
    {
        start=newNode;
        newNode->next=NULL;
    }
    else
    {
        newNode->next=start;
        start->prev=newNode;
        start=newNode;
    }

}

int InsertE(int value)
{
    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
	current=start; // caution, copy address of start to current pointer
	if(start==NULL)//zero node are present
    {
        start=newNode;
        newNode->next=NULL;
        newNode->prev=NULL;
    }
    else
    {
        while(current->next != NULL ) // stopping condition
        {
            current= current->next;
        }
        newNode->prev=current;
        current->next=newNode;
        newNode->next=NULL;
    }
    current = newNode;
}

int InsertValue(int key, int value)
//if value not present ,it will insert at end
{
    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
    current=start;
	while(current->data != key )
	{
		current= current->next;
		if(current->next==NULL)
        {
            InsertE(value);
            return 0;
        }
        if(current == NULL)
        {
            printf("Value not present");
            return 0;
        }
	}
	newNode->prev=current;
    newNode->next=current->next;
    current->next->prev=newNode;
    current->next=newNode;
}
int InsertPosition(int position,int value)
{
    int i=0;
    int count=ListLength();
    if(position > count)
    {
        printf("Node not present\n");
        return 0;
    }

    newNode=(struct node *) malloc(sizeof(struct node));
	newNode->data= value;
    current=start;

    if(start==NULL)
    {
        printf("List is empty");
    }
    else
    {
        current=start;
        i=0;
        while(i<position-1 && current!=NULL)
            {
                current = current->next;
                i++;
            }
            if(current != NULL)
            {
                newNode->next = current->next;
                newNode->prev = current;
                if(current->next != NULL)
                {
                    current->next->prev = newNode;
                }
                current->next = newNode;
            }
            else
            {
                printf("Error, Invalid position\n");
            }
        }
}

int DeleteB()//problem when there is one node
{
    current=start;

    if(start==NULL)
    {
        printf("List Empty\n");
    }
    else if(start->next==NULL)
    {
        start=NULL;
        free(start);

    }
    else
    {
        start=current->next;
        start->prev=NULL;
        free(current);
    }

}

int DeleteE()
{
    current=start;
    if(start==NULL)
    {
        printf("Underflow\n");
    }
    else if(start->next==NULL)
    {
        start=NULL;
        free(start);

    }
    else
    {
        while(current->next != NULL )
        {
            current = current->next;
        }
        current->prev->next=NULL;
        free(current);
    }
}
int DeleteValue(int key)
{
    struct node *tail;
    tail=start;

    while(tail->next != NULL)
    {
        tail=tail->next;
    }

    current=start;

    if(current->data==key)
    {
        DeleteB();
    }
    else
    {
        while(current->data != key)
        {
            current=current->next;
        }
        if(current==tail)
        {
            DeleteE();
        }
        else
        {
            current->prev->next=current->next;
            current->next->prev=current->prev;
            free(current);
        }
    }
}

int DeletePosition(int position)
{
    struct node *last;
    current=start;
    last=start;
    int i=0;

    int count=ListLength();
    if(position > count)
    {
        printf("Node not present\n");
        return 0;
    }
    while(last != NULL)
    {
        last=last->next;
    }

    for(i=1;i<position&&current != NULL;i++)
    {
        current=current->next;
    }

    if(position==1)
        DeleteB();

    else if(current==last)
        DeleteE();

    else if(current != NULL)
    {
        current->prev->next=current->next;

        if(current->next != NULL)
        {
            current->next->prev=current->prev;
        }
        free(current);
    }
    else
    {
        printf("Invalid position\n");
    }

}


int isempty()
{
    if(ListLength()== 0)
        return 1;
    else
        return 0;
}

int Search(int key)
{
    current = start;
    while(current != NULL)
    {
        if(current->data==key)
            return 1;
        current=current->next;
    }
}


int modify(int key,int newNumber)
{
    current = start;
    while(current != NULL)
    {
        if(current->data==key)
            current->data=newNumber;

        else
        {
            current = current ->next;
        }
    }
    if(current == NULL)
    {
        printf("Could not modify,Value not present\n");
    }
}
int display()
{
    temp = start;
	if(temp == NULL)
	{
		printf("There are no web pages to display.Try again!\n");
	}
	else
	{
	    printf("All the pages are:");
		while(temp != NULL)
		{
			printf("  %d", temp->data);
			temp=temp->next;
		}
		printf("\n");
	}
}

#endif // DLL_H_INCLUDED
