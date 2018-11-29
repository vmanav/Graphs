#include<iostream>
using namespace std;

struct node
{   int e; // end
    struct node* next;
};

struct list
{   struct node* head;
};

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
        {   struct node* ptr1= new_node(e);
            ptr1->next = arr[s].head;
            arr[s].head = ptr1;

            struct node* ptr2 = new_node(s);
            ptr2->next = arr[e].head;
            arr[e].head = ptr2;
        }

        // TO BE IMPLEMENTED LATER
        
            void remove_edge(int s, int e)
            {
                struct node* ptr1 = arr[s].head;
                arr[s].head = ptr1->next;
                delete ptr1;

                 struct node* ptr2 = arr[e].head;
                arr[e].head = ptr2->next;
                delete ptr2;

                
            }
        

        void display()
        {   int i;
            cout<<"\nAdjacency List";
            for(i=0;i<v;i++)
            {   struct node* ptr = arr[i].head;
                cout<<"\nVertex "<<i<<" - ";
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

         g.remove_edge(1, 3);
        cout<<"\nafter removing edges\n";
        g.display();

   return 0;
}
