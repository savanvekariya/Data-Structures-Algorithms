#include <iostream>
#include <list>
using namespace std;

class Graph
{
    public:
    int v;
    list<int> *l;
    
    Graph(int v)
    {
        this.v=v;
        l=new list<int>[v];
    }
    
    void addEdge(int x,int y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    
    void printGraph()
    {
        for(int i=0;i<v;i++)
        {
            for(int nbr : l[i])
            {
                cout<<nbr;
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g(4);
    g.addEdge(0,2);
    g.addEdge(0,3);
    g.addEdge(3,2);
    g.addEdge(1,3);
    g.printGraph();
    return 0;
}