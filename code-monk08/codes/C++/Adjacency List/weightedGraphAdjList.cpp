#include<bits/stdc++.h>
using namespace std;

template<class T>
class Graph
{
    public:
        map<T, list<pair<T, int> > > m;
        void addEdge(T f, T s, int weight, bool bidir=true)
        {
            m[f].push_back(make_pair(s,weight));
            if(bidir)
            {
                m[s].push_back(make_pair(f,weight));
            }
        }

        void printAdjList()
        {
            for(auto j:m)
            {
                cout<<j.first<<"->";
                for(auto k: j.second)
                {
                    cout<<"("<<k.first<<","<<k.second<<")"<<" ";
                }
                cout<<endl;
            }
        }
};

int main()
{
    Graph<int> g;
    int f,s,w,e;
    cout<<"enter number of edges"<<endl;
    cin>>e;
    for(int i=0; i<e; i++)
    {
        cin>>f>>s>>w;
        g.addEdge(f,s,w);
    }
    g.printAdjList();
    return 0;
}