#include<iostream>
#include<cstdlib>
#include<cstdio>
#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    bool checkForCycle(int s, int V, vector<int> adj[], vector<int> &visited)
    {
        // Create a queue for BFS
        queue<pair<int, int>> q;
        visited[s] = true;
        q.push({s, -1});
        while (!q.empty())
        {
            int node = q.front().first;
            int par = q.front().second;
            q.pop();
 
            for (auto it : adj[node])
            {
                if (!visited[it])
                {
                    visited[it] = true;
                    q.push({it, node});
                }
                else if (par != it)
                    return true;
            }
        }
        return false;
    }
    bool isCycle(int V, vector<int> adj[])
    {
        vector<int> vis(V - 1, 0);
        for (int i = 1; i <= V; i++)
        {
            if (!vis[i])
            {
                if (checkForCycle(i, V, adj, vis))
                    return true;
            }
        }
    }
};
 
void addEdge(vector<int> adj[],int u,int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}
int main()
{
    vector<int> adj[5];
   
    addEdge(adj,0,1);
    addEdge(adj,0,2);
    addEdge(adj,2,3);
    addEdge(adj,1,3);
    addEdge(adj,2,4);
   
    Solution obj;
    int num=obj.isCycle(5, adj);
    if(num==1)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
 
    return 0;
}

// //Detech cycle using undirected graph
// #include<iostream>
// #include<cstdlib>
// #include<cstdio>
// #include<bits/stdc++.h>
// using namespace std;
// class solution{
//     public:
//     bool checkforcycle(int node,int parent,vector<int>&vis,vector<int>&abj[])
//     {
//         vis[node] = 1;
//         for(auto it:abj[node])
//         {
//             if(checkforcycle(it,node,vis,abj[]))
//             {
//                 return true;
//             }
//             else if(!it=parent)
//             {
//                 return true;
//             }

//         }
//         return(false);
//     }

//     public:
//     bool iscycle(int v,vector<int>&abj[])
//     {
//         vector<int>vis(v+1,0);
//         for(int i = 1;i<=v;i++){
//             if(!vis[i])
//             {
//                 if(checkforcycle(i,-1,abj[]))
//                 {
//                     return true;
//                 }
//             }
//             return false;
//         }
//     }

//  };



// int main()
// {
//     int tc;
//     cout<<"enter the value in TC";
//     cin>>tc;
//     while(tc--)
//     {
//         int v,e;
//         cout<<"enter the value in v and e respectively";
//         cin>>v>>e;
//         vector<int>abj[v];
//         for(int i = 0;i<e;i++)
//         {
//             int u,v;
//             cin>>u>>v;
//             abj[u].push_back(v);
//             abj[v].push_back(u);

//         }
//         solution obj;
//         bool ans = obj.iscycle(v,abj[]);
//         if(ans)
//         {
//             cout<<"1\n";
            
//         } 
//         else
//         {
//             cout<<"0\n";
//         }
//         return(0);
//     }

// }