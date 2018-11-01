#include<iostream>
using namespace std;

struct node
{   int e; // end
    struct node* next;
}

struct list
{   struct node* head;  
}

class graph
{   private:
        int v;  // vertices
        struct list* arr;
    public:
        graph(int vert)
        {   this->v = vert;
            arr = new list[vert];
            for(int i=0;i<vert;i++)
            {   arr[i].head = NULL;
            }
        }
        
        node* new_node(int E)
        {   struct node* temp = new (node);
            temp->e = E;
            temp->next = NULL;
            return temp;
        }

        void add_edge(int s , int e)    // start and end
        {   node * newnode = new_node(e);
            new_node->next = arr[s].head;
            arr[s].head = new_node;

            newnode = new_node(s);
            new_node->next = arr[e].head;
            arr[e].head = new_node;
        }

        // TO BE IMPLEMENTED LATER
        /*
            void remove_edge(int s, int e)
            {
                Node* ptr1 = arr[s-1].head;
                arr[s-1].head = ptr1->next;
                delete ptr1;
            }    
        */

        void display()
        {   int i;
            cout<<"\nAdjacency List";
            for(i=0;i<v;i++)
            {   struct node* ptr = arr[i].head;
                cout<<"\nVertex :"<<i;
                while(ptr)
                {   cout<<ptr->e<<" "; 
                    ptr=ptr->next;
                }
                cout<<"\n";
            }
        }
};

int main()
{   graph g(5);

        g.add_edge(0, 1);

        g.add_edge(0, 4);

        g.add_edge(1, 2);

        g.add_edge(1, 3);

        g.add_edge(1, 4);

        g.add_edge(2, 3);

        g.add_edge(3, 4);

     

        // print the adjacency list representation of the above graph

        g.display();
    
    
   return 0;
}
