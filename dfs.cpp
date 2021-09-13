/*
Luiz Fernando de Moura - ME2112003
Pedro H. de Avellar G. de Moura - ME2020252
*/

#include <iostream>
#include <vector>
#include <stack>


void graphInsert(std::vector<int> adj[], int u, int v);
void DFS(std::vector<int> adj[], int V);
void DFS_VISIT(int u, std::vector<int> adj[], std::vector<bool> &visited);
void DFS_STACK(std::vector<int> adj[], int V);
void DFS_STACK_VISIT(int s, std::vector<int> adj[], std::vector<bool> &visited);

int main(){

    int V2 = 9;
    std::vector<int> adj2[V2];
    graphInsert(adj2, 0, 1);
    graphInsert(adj2, 0, 2);
    graphInsert(adj2, 1, 3);
    graphInsert(adj2, 1, 4);
    graphInsert(adj2, 2, 5);
    graphInsert(adj2, 2, 6);
    graphInsert(adj2, 3, 7);
    graphInsert(adj2, 3, 8);

    DFS(adj2, V2);

    DFS_STACK(adj2, V2);

    return 0;
}

void graphInsert(std::vector<int> adj[], int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}


void DFS(std::vector<int> adj[], int V)
{
    std::cout << "\nDFS recursivo: \n";
    std::vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFS_VISIT(u, adj, visited);
}

//UTILIZANDO RECURSIVIDADE
void DFS_VISIT(int u, std::vector<int> adj[], std::vector<bool> &visited)
{
    visited[u] = true;
    std::cout << u << " ";
    for (int i=0; i<adj[u].size(); i++)
        if (visited[adj[u][i]] == false)
            DFS_VISIT(adj[u][i], adj, visited);
}


void DFS_STACK(std::vector<int> adj[], int V){
    std::cout << "\nDFS com pilha: \n";
    std::vector<bool> visited(V, false);
    for (int u=0; u<V; u++)
        if (visited[u] == false)
            DFS_VISIT(u, adj, visited);
}

//UTILIZANDO PILHA
void DFS_STACK_VISIT(int s, std::vector<int> adj[], std::vector<bool> &visited)
{
    std::stack<int> stack; 
    stack.push(s);
 
    while (!stack.empty())
    { 
        int s = stack.top();
        stack.pop();
 
        if (!visited[s])
        {
            std::cout << s << " ";
            visited[s] = true;
        }

        for (auto i = adj[s].begin(); i != adj[s].end(); ++i){
            if (!visited[*i])
                stack.push(*i);
        }
    }
}