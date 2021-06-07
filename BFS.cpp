#include<iostream>
#include<map>
#include<list>
#include<queue>
using namespace std;
template<typename T>
class Graph
{
    map<T,list<T>> l;
    public:
    void addEdge(T x, T y)
    {
        l[x].push_back(y);
        l[y].push_back(x);
    }
    void bfs(T src)
    {
        map<T,bool> visited;
        queue<T> q;
        q.push(src);
        visited[src]=true;
        
        while(!q.empty())
        {
            T node=q.front();
            q.pop();
            std::cout << node;
            for(T nbr:l[node])
            {
                if(!visited[nbr])
                {
                    q.push(nbr);
                    visited[nbr]=true;
                }
            }
        }
    }
};

int main()
{
    Graph<int> g;
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,1);
    g.bfs(1);
   return 0; 
}