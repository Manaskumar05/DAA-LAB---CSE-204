#include <iostream>
#include <algorithm>
using namespace std;

struct edge{
    char u,v;
    int w;
};

bool compare(edge a,edge b){
    return a.w < b.w;
}

char parent[100];

char find(char x){
    if(parent[x] == x){
        return x;
    }
    return parent[x] = find(parent[x]);
}

void unionn(char a,char b){
    a = find(a);
    b = find(b);

    parent[a] = b;
}


int main(){
    int V,E;
    cout << "Enter no of vertices and edges : " ;
    cin >> V >> E;

    edge edges[100];
    cout << "Enter vertex and weight of each edge" << endl;
    for(int i = 0 ; i < E ; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }

    for(char i = 'A' ; i < 'A' + V ; i++){
        parent[i] = i;
    }

    sort(edges,edges + V,compare);
    int total = 0;

    cout << "Edges in MST : ";
    for(int i = 0 ; i < E ; i++) {
        char u = edges[i].u;
        char v = edges[i].v;
        int w = edges[i].w;

        if(find(u) != find(v)){

            cout << u << "---" << v << " : " << w << endl;
            total += w;

            unionn(u,v);
        }
    } 

    cout << "Minimum Cost : " << total;
}
