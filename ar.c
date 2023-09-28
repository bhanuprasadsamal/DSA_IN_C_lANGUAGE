// date-25-9-2023
// create an array and do certain thinghs
#include<stdio.h>
int main()
{
    int a;
    printf("Enter the array size: ");
    scanf("%d",&a);
    int ar[a],i;
    printf("Enter the all element in array: ");
    for(i=0;i<a;i++)
    {
        scanf("%d",&ar[i]);
    }
    printf("Array element are: ");
    for(i=0;i<a;i++)
    {
        printf("%d ",ar[i]);
    }
}


/*
node:
A fundamental element of a tree that holds a value and has references (pointers) to its left and right children.

Root: The topmost node in the tree, from which all other nodes are descended.

leaf node: A node with no children, located at the end of the tree branch.

Parent Node: A node that has one or more child nodes.

child node: A node that is a direct descendant of another node (its parent).

sibling node: nodes that share the same parent.

Depth: the depth of a node refers to the number of edges in the path from the root to that node.

Heigth: the hight of a node is in number of edges on the longest path from that node  to leaf. the height of the tree is the hight of the root node.


*/


