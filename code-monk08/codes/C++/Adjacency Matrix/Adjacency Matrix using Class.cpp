//work on deletion from adjacency matrix
#include<iostream>
#include<vector>
using namespace std;

class ADJMATRIX
{
    public:
    int n;
    int e;

    ADJMATRIX(int n, int e)
    {
        this->n = n;
        this->e = e;
    }

    void print(vector< vector<int> > &matrix)
    {
        for (int i = 0; i < this->n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void input(vector< vector<int> > &matrix)
    {
        int f,s;
        for(int i =0 ; i < this->e; i++)
        {
            cin>>f>>s;
            matrix[f][s] = 1;
            matrix[s][f] =1;
        }
    }
};


int main()
{
    int n,e;
    cin>>n>>e;
    //input the value which is (1 + maximum node value)
    vector< vector<int> > matrix(n, vector<int>(n, 0));
    ADJMATRIX am(n,e);
    am.input(matrix);
    am.print(matrix);
    return 0;
}