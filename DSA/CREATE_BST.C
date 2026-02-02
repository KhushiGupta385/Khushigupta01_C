// CREATE BINARY SEARCH TREE
#include<stdio.h>
#include<malloc.h>

struct NODE
{
    int Info;
    struct NODE *left_child;
    struct NODE *right_child;
};
struct NODE *Create_tree(int, struct NODE *);
void Output(struct NODE *,int);

/*Function to create a tree*/
struct NODE * Create_Tree (int Info, struct NODE *Node)
{
if (Node == NULL)
    {
        Node = (struct NODE *) malloc(sizeof(struct NODE));
        Node->Info = Info;
        Node->left_child = NULL;
        Node->right_child = NULL;
        return (Node);
    }

    /*Test for the left child*/
    if (Node->Info>= Info)
    Node->left_child = Create_Tree (Info, Node->left_child);
    else
    Node->right_child = Create_Tree (Info, Node->right_child);

    return(Node);
}

/*insert*/
// struct NODE *insert (int Info, struct NODE *Node)
// {
//     if (Node == NULL)
//     {
//         Node = (struct NODE *) malloc(sizeof(struct NODE));
//         Node->Info = Info;
//         Node->left_child = NULL;
//         Node->right_child = NULL;
//         // return (Node);
//     }

//     /*Test for the left child*/
//     if (Node->Info>= Info)
//     Node->left_child = insert (Info, Node->left_child);
//     else
//     Node->right_child = insert (Info, Node->right_child);

//     // return(Node);
// }

/*Output function*/
void Output(struct NODE *T, int Level)
{
    int i;
    if (T)
    {
        Output(T->right_child, Level+1);
        printf("\n ");
        for(i=0;i<Level;i++)
        printf("  ");
        printf("%d",T->Info);
        printf("\n");
        Output(T->left_child, Level+1);
    }
}

/*Function main*/
int main()
{
    int Info;
    char choice;
    struct NODE *T = (struct NODE *)malloc(sizeof(struct NODE *));
    T=NULL;
    printf("\n Input choice 'b' to break: ");
    choice = getchar();
    while (choice !='b')
    {
        printf("\n Input information of the node: ");
        scanf("%d",&Info);
        T = Create_Tree(Info, T);
        printf("Root= %d\n",T->Info);
        printf("\n Tree is ");
        Output(T, 1);
        printf("\n Input choice 'b' to break: ");
        choice = getchar();
    }
    return 0;
}

/*SEARCH*/

