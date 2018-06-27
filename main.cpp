
#include<stdio.h>
#include<conio.h>
#include<malloc.h>
#include<process.h>
#include<cstdlib>

    struct node{
     int info;
    struct node *right;
    struct node *left;
};

typedef struct node *BST;
typedef struct node node;
BST makeempty(BST t)

    {

         if (t!=NULL) {
         makeempty(t->left);
        makeempty(t->right);
        free(t);
    }

    return NULL;
}

BST find(BST t, int x)
    {
     if (t==NULL) return NULL;
    if (x<t->info) return find(t->left,x);
    else
    if (x>t->info) return find(t->right,x);
    else
    return t;
}

BST findmin(BST t)

    {
     if(t==NULL) return NULL;
    else
     if(t->left==NULL) return t;
    else return findmin(t->left);
}

BST findmax(BST t)

    {
     if(t==NULL) return NULL;
    else
     if(t->right==NULL) return t;
    else return findmax(t->right);
}

BST insertnode(BST t, int x)

    {

        if(t==NULL) {
         t=(node*)malloc(sizeof(node));
        if(t==NULL) printf("\n Out of Space !!");

            else {
             t->info = x;
            t->left = t->right = NULL;
        }

    }

    else

        if (x<t->info) {
         t->left=insertnode(t->left,x);
    }

    else

        if (x>t->info) {
         t->right=insertnode(t->right,x);
    }

    return t;
}

BST deletenode(BST t, int x)

    {
     BST tmpcell;

         if(t == NULL) {
         printf("\n Cannot Delete!! No Such Value Found");
    }

    else
    if(x < t->info) t->left = deletenode(t->left,x);
    else
    if(x > t->info) t->right = deletenode(t->right,x);
    else

         if(t->right && t->left){
         tmpcell = findmin(t->right);
        t->info = tmpcell->info;
        t->right = deletenode(t->right,tmpcell->info);
    }


        else {
         tmpcell = t;
        if(t->left == NULL) t = t->right;
        else if(t->right == NULL) t = t->left;
        free(tmpcell);
        printf("\n Value Successfully Deleted.");
    }

    return t;
}

void printtree_asc(BST t)

    {

         if (t!=NULL) {
         printtree_asc(t->left);
        printf("\n %d",t->info);
        printtree_asc(t->right);
    }

}

void printtree_desc(BST t)

    {

         if (t!=NULL) {
         printtree_desc(t->right);
        printf("\n %d",t->info);
        printtree_desc(t->left);
    }

}

main()

    {
     BST tree, pos;
    char ans;
    int val;
    tree=NULL;

        while(1){
         printf(" Binary Search Tree (BST)");
         printf("\n\n [1].\tInsert\n");
        printf(" [2].\tDelete\n");
        printf(" [3].\tMake Empty\n");
        printf(" [4].\tFind Minimum\n");
        printf(" [5].\tFind Maximun\n");
        printf(" [6].\tSearch\n");
        printf(" [7].\tPrint Ascending\n");
        printf(" [8].\tPrint Descending\n");
        printf(" [9].\tExit\n\n");
        printf(" Enter Choice: ");
         ans = getche();
        switch(ans)

            {
             case '1':

                {
                 printf("\n Enter Value: ");
                 scanf("%d",&val);
                 tree=insertnode(tree,val);
            }

            break;
            case '2':

                {

                     if(tree!=NULL) {
                     printf("\n Enter Value to be Deleted: ");
                     scanf("%d",&val);
                     tree=deletenode(tree,val);
                }

                else printf("\n Cannot Delete!! Empty BST!!");
                getch();
            }

            break;
            case '3':

                {
                 tree = makeempty(tree);
                 printf("\n BST is now Empty!!");
                 getch();
            }

            break;
            case '4':

                {
                 pos=findmin(tree);
                 if (pos!=NULL)
                 printf("\n Minimum Value: %d",pos->info);
                 else
                 printf("\n Empty BST!! No Minimum Value.");
                 getch();
            }

            break;
            case '5':

                {
                 pos=findmax(tree);
                 if (pos!=NULL)
                 printf("\n Maximum Value: %d",pos->info);
                 else
                 printf("\n Empty BST!! No Maximum Value.");
                getch();
            }

            break;
            case '6':

                {

                    if (tree!=NULL) {
                     printf("\n Enter Value to be Searched: ");
                     scanf("%d",&val);
                     pos=find(tree, val);
                     if (pos!=NULL)
                     printf("\n %d is found in the BST",pos->info);
                    else
                     printf("\n %d not found in the BST",val);
                }


                    else {
                     printf("\n The BST is Empty!!");
                }

                getch();
            }

            break;
            case '7':

                {

                     if(tree!=NULL) {
                     system("cls");
                     printf("\n BST IN ASCENDING ORDER\n\n");
                     printtree_asc(tree);
                }

                else printf("\n Empty BST!!");;
                getch();
            }

            break;
            case '8':

                {

                     if(tree!=NULL) {
                     system("cls");
                     printf("\n BST IN DESCENDING ORDER\n\n");
                     printtree_desc(tree);
                }

                else printf("\n Empty BST!!");
                getch();
            }

            break;
            case '9':
            exit(0);
            default :

                {
                 printf("\n\n Choose from 1 to 9 only!!");
                 getch();
            }

            break;
        }

        system("cls");
    }

}


