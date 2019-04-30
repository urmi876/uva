#include <bits/stdc++.h>
using namespace std;
#define  unvisited -1
#define  visited 1
vector <int> node[100005];
int dis[100005];
int bfs (int src)
{
    queue <int> q;
    dis[src] = 0;
    q.push(src);
    while(!q.empty())
    {
        int u = q.front();
      // cout<<"u  >"<<u<<endl;
      // cout<<endl;
        q.pop();
        for(int i = 0; i < node[u].size(); i++)
        {
            int v = node[u][i];
           // cout<<"v "<<v<<endl;
           // cout<<endl;

            if(dis[v] == unvisited)
            {
                dis[v] = dis[u] + 1;
                //cout<<"dis["<<v<<"]  "<<dis[v]<<endl;
               // cout<<endl;
                q.push(v);
            }
        }
    }
}
int main()
{
    int cases,case_no=0;
    cin >> cases;
    cout<<"SHIPPING ROUTES OUTPUT"<<endl<<endl;
    while(cases--)
    {
        memset(dis, unvisited , sizeof dis);
        int n, e,q;
        string nd;
        map<string,int>mp;
        cin >> n >> e>>q;
        for(int i=1;i<=n;i++)
        {
       cin>>nd;
       mp[nd]=i;
       }
        for(int i = 0; i < e; i++)
        {
            string u, v;
            cin >> u >> v;
            node[mp[u]].push_back(mp[v]);
            node[mp[v]].push_back(mp[u]);
        }
        int sift_sz,lev;
         string src,des;

        cout<<"DATA SET  "<<(++case_no)<<endl<<endl;

   for(int i=0;i<q;i++)
   {
       int leg;
       cin>>sift_sz>>src>>des;
               memset(dis, unvisited , sizeof dis);

           bfs(mp[src]);
          leg=dis[mp[des]];
          if(leg<0)
          {

            cout<<"NO SHIPMENT POSSIBLE\n";

          }
          else
            cout<<"$"<<sift_sz*leg*100<< endl;
   }
        for(int i = 1; i <= n; i++)
           {

           node[i].clear();
           }
           mp.clear();

     cout<<endl;
    }
    cout<<"END OF OUTPUT"<<endl;
    return 0;
}
