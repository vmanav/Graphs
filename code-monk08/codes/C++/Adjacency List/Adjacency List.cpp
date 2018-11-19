//work on deletion in adjacency list representation.
#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

void addedge(vector<int> *array, int f, int s)
{
    array[f].push_back(s);
    array[s].push_back(f);
}

void print(vector<int> *array, int n)
{
    vector<int>::iterator i1;
    for (int i = 0; i < n; i++)
    {

        cout << i << "--->";
        for (i1 = array[i].begin(); i1 != array[i].end(); i1++)
        {
            cout << *i1 << " ";
        }
        cout << endl;
    }
}

void input(vector<int> *array, int n, int e)
{
    int f, s;
    for (int i = 0; i < e; i++)
    {
        cin >> f >> s;
        addedge(array, f, s);
    }
}

int main()
{
    int n; //vertices
    cin >> n;
    int e;
    cin >> e; //edges
    vector<int> alist[n];
    input(alist, n, e);
    print(alist, n);
}
