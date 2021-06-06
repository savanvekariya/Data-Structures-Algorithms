#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph
{
    unordered_map<string,list<pair<string,int>>> l;
    
    public:
    void addEdge(string x,string y, bool bidi, int wt)
    {
        l[x].push_back(make_pair(y,wt));
        if(bidi==true)
        {
            l[y].push_back(make_pair(x,wt));
        }
    }
    
    void printGraph()
    {
        for(auto p:l)
        {
            std::cout << p.first << std::endl;
            list<pair<string,int>> nbrs=p.second;
            for(auto nbr:nbrs)
            {
                std::cout << nbr.first << ":" << nbr.second;
            }
            cout<<endl;
        }
    }
};

int main()
{
    Graph g;
    g.addEdge("a","b",true,10);
    g.addEdge("b","c",true,15);
    g.addEdge("c","a",true,20);
    g.printGraph();
    return 0;
}