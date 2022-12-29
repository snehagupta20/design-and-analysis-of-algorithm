//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include<iostream>
#include <vector>
#include<queue>
using namespace std;
class graph
{
    vector<pair<int,int>> *l;
    int v;
    public:
    graph(int n)
    {
        v=n;
        l=new vector<pair<int,int>> [n];
    }
    void add_edge(int x,int y,int w)
    {
        l[x].push_back({y,w});
        l[y].push_back({x,w});
    }

    int prims_mst()
    {
        //initialising a min heap

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;

        //visited array that denotes wether a node has been included in mst or not

        bool *vis=new bool[v]{0};
        int ans=0;
        //weight,node
        q.push({0,1}); 

        while(!q.empty())
        {
            //picking out the edge wwith min weight
            auto best=q.top();
            q.pop();
            int to=best.second;
            int weight=best.first;
            if(vis[to])
            {
                //discrading the edge
                continue;
            }

            ans+=weight;
            vis[to]=1;

            //adding the new edged into the queue
            for(auto x:l[to])
            {
                if(vis[x.first]==0)
                {
                    q.push({x.second, x.first});
                }
            }

        }

        return ans;
    }
};

int main()
{
    int v=0;
    cin>>v;
    graph g(v);
    for(int i=0;i<v;i++)
    {
        int x=0,y=0,w=0;
        cin>>x>>y>>w;
        g.add_edge(x,y,w);
    }
    cout<<g.prims_mst()<<endl;
}