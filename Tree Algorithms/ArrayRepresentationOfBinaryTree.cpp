#include<bits/stdc++.h>
using namespace std;
char tree[10];
void root(char key)
{
    if(tree[0] != '\0')
        cout << "Tree already had root";
    else
        tree[0] = key;
}
 
void set_left(char key, int parent)
{
    if(tree[parent] == '\0')
        cout << "cant set child at " << (parent * 2) + 1 <<", no parent found\n";
    else
        tree[(parent * 2) + 1] = key;
    return;
}

void set_right(char key, int parent)
{
    if(tree[parent] == '\0')
    {
        cout << "cant set child at " << (parent * 2) + 2 <<", no parent found\n";
    }
    else
    {
        tree[(parent * 2) + 2] = key;
    }
    return;
}

void print_tree()
{
    for(int i = 0; i < 10; i++)
    {
        if(tree[i] != '\0')
        {
            cout << tree[i];
        }
        else
        {
            cout << "-" ;
        }
    }
    printf("\n");
    return;
}

int main()
{
    root('A');
    set_right('C', 0);
    set_left('D', 1);
    set_right('E', 1);
    set_right('F', 2);
    print_tree();
    return 0;
}
