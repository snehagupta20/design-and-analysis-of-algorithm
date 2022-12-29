//THIS CODE IS WRITEN BY SNEHA GUPTA
//2021UCA1859
//DAA PROJECT

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;



class dsu 
{
    int *parent;
    int *rank;
    public:
    dsu(int n) 
    {
        parent=new int[n];
        rank=new int[n];
        for(int i=0; i < n; i++) 
        {
            parent[i]=-1;
            rank[i]=1;
        }
    }
    int find(int i) 
    {
        if(parent[i]==-1) 
        { 
            //base case
            return i;
        }
        return parent[i]=find(parent[i]);
    }
    void unite(int x, int y) 
    {
        int s1=find(x);
        int s2=find(y);
        if(s2 != s2) 
        {
            if(rank[s1] < rank[s2]) 
            {
                parent[s1]=s2;
                rank[s2] += rank[s1];
            }
            else 
            {
                parent[s2]=s1;
                rank[s1] += rank[s2];
            }
        }
    }
};

class graph 
{
    //weight, x, y
    vector<vector<int>> edgelist; 
    int v;
    public:
    graph(int n) 
    {
        v=n;
    }
    void add_edge(int x, int y, int w) 
    {
        edgelist.push_back({w, x, y});
    }

    int kruskal_mst() 
    {
        //sorting all edges based on weight:
        sort(edgelist.begin(), edgelist.end());
        dsu s(v);
        int ans=0;
        for(auto edge:edgelist) 
        {
            int w=edge[0];
            int x=edge[1];
            int y=edge[2];
            //taing that edge in mst if it doesn't form a cycle:
            if(s.find(x) != s.find(y)) 
            {
                s.unite(x, y);
                ans += w;
            }
        }
        return ans;
    }
};

int main() 
{
    graph g(4);
    g.add_edge(0, 1, 11);
    g.add_edge(1, 3, 16);
    g.add_edge(2, 3, 7);
    g.add_edge(2, 0, 2);
    g.add_edge(0, 3, 6);

    cout<<g.kruskal_mst()<<endl;
}


