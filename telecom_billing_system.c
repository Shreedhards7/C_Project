#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Customer{
    char name[20];
    long long int phone_number;
    int usage;

    struct Customer *next;
};
typedef struct Customer node;

node *first=NULL,*last=NULL;

void add_customer()
{
    char n[100];
    printf("Enter the customer name: \n");
    scanf("%s",n);
    long long int phno;
    printf("Enter the customer number: \n");
    scanf("%lld",&phno);
    int time;
    printf("Enter the time usage: \n");
    scanf("%d",&time);
    int use=time*0.5;
        printf("The total time usage is : %d\n",use);
    printf("===============================================================\n");

    node *new=(node*)malloc(sizeof(node));

    if(first==NULL)
    {
        strcpy(new->name,n);
        new->phone_number=phno;
        new->usage=time;
        new->next=NULL;
        first=last=new;
    }
    else{
        strcpy(new->name,n);
        new->phone_number=phno;
        new->usage=time;
        new->next=NULL;
    last->next=new;
        last=new;
    }
}
void create_front()
{
    char n[100];
        printf("Enter the customer name: \n");
        scanf("%s",n);
        long long int phno;
        printf("Enter the customer number: \n");
        scanf("%lld",&phno);
        int time;
        printf("Enter the time usage: \n");
        scanf("%d",&time);
    int use=time*0.5;
        printf("The total time usage is : %d\n",use);
    printf("===============================================================\n");

    node *new=(node*)malloc(sizeof(node));
    strcpy(new->name,n);
    new->phone_number=phno;
    new->usage=time;
    new->next=first;
    first=new;
}

void ins_mid()
{
    int num;
    printf("Enter the phone number to before which data should be inserted: \n");
    scanf("%d",&num);
    node *temp=first,*temp1;
    while(temp->phone_number != num)
    {
        temp1=temp;
        temp=temp->next;
    }
    char n[100];
        printf("Enter the customer name: \n");
        scanf("%s",n);
        long long int phno;
        printf("Enter the customer number: \n");
        scanf("%lld",&phno);
        int time;
        printf("Enter the time: \n");
        scanf("%d",&time);
    int use=time*0.5;
    printf("The total time usage is : %d\n",use);
    printf("===============================================================\n");

    node *new=(node*)malloc(sizeof(node));
    strcpy(new->name,n);
    new->phone_number=phno;
    new->usage=time;
    new->next=temp;
    temp1->next=new;
}

void ins_last()
{
    char n[100];
        printf("Enter the customer name: \n");
        scanf("%s",n);
        long long int phno;
        printf("Enter the customer number: \n");
        scanf("%lld",&phno);
        int time;
        printf("Enter the time: \n");
        scanf("%d",&time);
        int use=time*0.5;
        printf("The total time usage is : %d\n",use);
    printf("===============================================================\n");

        node *new=(node*)malloc(sizeof(node));
        strcpy(new->name,n);
        new->phone_number=phno;
        new->usage=time;
    last->next=new;
    last=new;
    last->next=NULL;
}

void del_front()
{
    node *temp=first;
    first=temp->next;
    free(temp);
}

void display()
{
    node *temp=first;
    while(temp!=NULL)
    {
    printf("------------------>Details<-----------------\n");
        printf("name : %s\n",temp->name);
    printf("phone number: %lld\n",temp->phone_number);
    printf("usage : %d\n",temp->usage);
    printf("===============================================================\n");
    temp=temp->next;
    }
}

void del_mid()
{
    node *temp=first,*temp1;
    long long int n;
    printf("Enter the number to be deleted:\n");
    scanf("%lld",&n);
    while(temp->phone_number != n)
        {
                temp1=temp;
                temp=temp->next;
        }
    temp1->next=temp->next;
    free(temp);
}

void del_last()
{
    node *temp=first,*temp1;
    while(temp->next!=NULL)
    {
        temp1=temp;
        temp=temp->next;
    }
    temp1->next=temp;
    last=temp1;
    last->next=NULL;
}



void Add_fun()
{
    int n;
   
    printf("1.To Create first new data \n2.To create in front of first data \n3.To create in middle\n4.To create last\n5.To delete front details\n6.To delete the middle details\n7.To delete last details\n");
    printf("===============================================================\n");
    printf("Enter  ur choice: \n");
    scanf("%d",&n);
    switch(n)
    {
        case 1:
            add_customer();
            printf("New details created successfully:\n");
            printf("===============================================================\n");
            break;
        case 2:
            create_front();
            printf("Details are added in FRONT successfully:\n ");
            printf("===============================================================\n");
            break;
        case 3:
            ins_mid();
            printf("Details are added in MIDDLE successfully:\n ");
            printf("===============================================================\n");
            break;
        case 4:
            ins_last();
            printf("Details are added in LAST successfully:\n ");
            printf("===============================================================\n");
            break;
        case 5:
            del_front();
            printf("front details deleted sucessfully:\n");
            printf("===============================================================\n");
            break;
        case 6:
            del_mid();
            printf("given number detailes are deleted:\n");
            printf("===============================================================\n");
            break;
        case 7:
            del_last();
            printf("the last customer deatils is deleted:\n");
            printf("===============================================================\n");
            break;
        default :
            printf("ENTER THE VALID OPTION BETWEEN 1 TO 4\n");
            exit(0);
            break;

    }
}

void usage()
{
    int n;
    printf("Enter the phone number to find the total usage amount :\n");
    scanf("%d",&n);
    printf("===============================================================\n");
    node *temp=first;
    if(temp->phone_number!=n)
    {
        temp=temp->next;
    }
    printf("The usage is :%lf\n\n",temp->usage*0.5);
    printf("===============================================================\n");
}

void update()
{
    int n;
    char new_name[100];
    long long int new_number;
    int time_usage;
    printf("Enter the phone number to edit the details: \n");
    scanf("%d",&n);
    node *temp=first;
    while(temp->phone_number!=n)
    {
        temp=temp->next;
    }
   
    printf("1.Update name\n2.Update phone number\n3.Update time usage\n");
    printf("===============================================================\n");
    int a;
    scanf("%d",&a);
    switch(a)
    {
        case 1:
            printf("Enter the new name: \n");
            scanf("%s",new_name);
            strcpy(temp->name,new_name);
            break;
        case 2:
            printf("Enter the new number: \n");
            scanf("%lld",&new_number);
            temp->phone_number=new_number;
            break;
        case 3:
            printf("Enter the new time usage: \n");
            scanf("%d",&time_usage);
            temp->usage=time_usage;
        default:
            printf("Enter the valid option \n\n");
            break;
    }


}




int main()
{
    int n;
        while(1)
        {
        printf("===============================================================\n");
        printf("1.Add or Create a new deatils\n2.view customer details\n3.usage bill of customer\n4.update the new details\n5.exit\n");
        printf("Enter ur choice: \n ");
        scanf("%d",&n);
    printf("===============================================================\n");
        switch(n)
        {
                case 1:
            Add_fun();
            break;
        case 2:
            display();
            break;
        case 3:
            usage();
            break;
        case 4:
            update();
            break;
        case 5:
            printf("---------------THANK YOU-----------------\n");
            exit(0);
            break;
        default :
            printf("Enter the valid choice\n");
            break;


        }
        }

    return 0;
}
