//work on deletion in adjacency list representation.
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

class ADJLIST
{
  public:
    int n; //number of vertices
    int e; //number of edges
    ADJLIST(int n, int e)
    {
        this->n = n;
        this->e = e;
    }

    void addedge(int f, int s, vector<int> alist[])
    {
        alist[f].push_back(s);
        alist[s].push_back(f);
    }

    void input(vector<int> alist[])
    {
        int f;
        int s;
        for (int i = 0; i < this->e; i++)
        {
            cin >> f >> s;
            addedge(f, s, alist);
        }
    }

    void print(vector<int> alist[])
    {
        for (int i = 0; i < this->n; i++)
        {
            vector<int>::iterator i1;
            cout << i << "-->"
                 << " ";
            for (i1 = alist[i].begin(); i1 != alist[i].end(); i1++)
            {
                cout << *i1 << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;    // number of vertices
    int e;    // number of edges
    cin >> n; //input the number of vertices
    cin >> e; //input the number of edges
    vector<int> alist[n];
    ADJLIST al(n, e);
    al.input(alist);
    al.print(alist);
    return 0;
}
/*
output: 
10
15
0 1
0 2
0 3
0 7
1 6
1 7
2 5
2 8
3 6
3 8
3 9
4 5
4 9
6 7
8 9
0--> 1 2 3 7
1--> 0 6 7
2--> 0 5 8
3--> 0 6 8 9
4--> 5 9
5--> 2 4
6--> 1 3 7
7--> 0 1 6
8--> 2 3 9
9--> 3 4 8
*/