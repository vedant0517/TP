
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data ;
    struct node *next;
};
struct node *head,*temp;

// Function to add a new bill at the end
void addBill(int amount) {
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }
    newNode->data = amount;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct node *curr = head;
        while (curr->next != NULL)
            curr = curr->next;
        curr->next = newNode;
    }

    printf("Bill of Rs %d added successfully.\n", amount);
}

//Display Data
void display()
{
    if(head==0)
    {
        printf("No bills recorded yet \n");
    }
    temp=head;
    printf("Bills of the day :");
    while(temp!=0)
    {
        printf("%d rs ",temp->data);
        temp=temp->next;
    }
}

//insertion removed; using addBill instead

void total_sales() {
    if (head == NULL) {
        printf("No bills recorded yet.\n");
        return;
    }
    int total = 0;
    temp = head;
    while (temp != NULL) {
        total=total+temp->data;
        temp = temp->next;
    }
    printf("Total Sales of the day is %d rs\n", total);
}

void max_min_bill() {
    if (head == NULL) {
        printf("No bills recorded yet.\n");
        return;
    }
    temp = head;
    int max = head->data;
    int min = head->data;

    while (temp != NULL) {
        if (temp->data > max) max = temp->data;
        if (temp->data < min) min = temp->data;
        temp = temp->next;
    }

    printf("Maximum Bill is %d rs\n", max);
    printf("Minimum Bill is %d rs\n", min);
}
int main()
{
    int choice;
    while (choice != 5)
     {
        printf("\nCoffee Shop choices\n ");
        printf("1. Insert Bill of Customer\n");
        printf("2. Display all bills\n");
        printf("3. Display total sales\n");
        printf("4. Display maximum and minimum bill\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int amount;
                    printf("Enter bill amount : ");
                    if (scanf("%d", &amount) == 1) {
                        addBill(amount);
                    } else {
                        printf("Invalid amount input.\n");
                        // clear input buffer in a simple way
                        int c; while ((c = getchar()) != '\n' && c != EOF) {}
                    }
                }
                break;
            case 2:
                display();
                break;
            case 3:
                total_sales();
                break;
            case 4:
                max_min_bill();
                break;
            case 5:
                printf("Exit\n");
                break;
            default: printf("Invalid choice\n");
        }
    }
}
