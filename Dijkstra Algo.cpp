//Dijkstra's Algorithm Code 

#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define loop(i,n) for(ll i=0;i<n;i++)
#define looper(i,s,n) for(ll i=s;i<n;i++)
using namespace std;

//FUNCTION FOR FINDING NODE WITH MINIMUM DISTANCE AMONG ALL THE NODES WHOSE DISTANCES ARE NOT-FINALIZED.
int findmin(vector<int>&dist, vector<int>&vis) {
    int mx=INT_MAX,ind =-1,n=9;
    loop(i,n) {
        if(!vis[i] && dist[i]<=mx) {
            mx = dist[i];
            ind=i;
        }
    }
    // cout<<ind<<endl;
    return ind;
}


void dijkstra(vector<vector<int>>&v, int src, int n) {
    int l=0;
    vector<int>dist(n),vis(n),par(n,-1);
    looper(i,1,n) dist[i]=INT_MAX;
    for(int cnt=0;cnt<n;cnt++) {
        int ind = findmin(dist,vis);
        if(ind==-1) continue;
        vis[ind]=1;
        loop(i,n) {  // UPDATING THE DISTANCES FROM SOURCE AND PARENT VECTOR
            if(v[ind][i] && !vis[i] && dist[ind]!=INT_MAX && dist[ind]+v[ind][i]<dist[i]) {
                dist[i]=dist[ind]+v[ind][i];
                par[i]=ind;
            }
        }
    }
    printf("Vertex   Distance from Source\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, dist[i]);
    printf("Vertex   Parent vertex\n");
    for (int i = 0; i < n; i++)
        printf("%d \t\t %d\n", i, par[i]);
}

int main() {
    vector<vector<int>>v = { { 0, 4, 0, 0, 0, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 0, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 10, 0, 0, 0 },
                        { 0, 0, 4, 14, 10, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 11, 0, 0, 0, 0, 1, 0, 7 },
                        { 0, 0, 2, 0, 0, 0, 6, 7, 0 } };
    
    int n = v.size();
    dijkstra(v,0,n);
}