#include<iostream>
#include<list>
#include<queue>
#include<vector>

/************************类声明************************/
class Graph {
    int V;                               // 顶点个数
    std::vector<std::list<int>> adj;    // 邻接表 -- 指针
    std::vector<int> indegree;          // 记录每个顶点的入度 -- 指针

    std::queue<int> q;                   // 维护一个入度为0的顶点的集合
public:
    Graph(int num);                   // 构造函数
    ~Graph();                       // 析构函数
    void addEdge(int v, int w);     // 添加边
    bool topological_sort();        // 拓扑排序
};

/************************类定义************************/
Graph::Graph(int num) {
    this->V = num;
    this->adj.resize(num);
    this->indegree.resize(num);
}

Graph::~Graph() {
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
    ++indegree[w];
}

bool Graph::topological_sort() {
    for(int i=0; i<V; ++i) {
      if(indegree[i] == 0)
        q.push(i);         // 将所有入度为0的顶点入队
    }

    int count = 0;             // 计数，记录当前已经输出的顶点数
    while(!q.empty()) {
        int v = q.front();      // 从队列中取出一个顶点
        q.pop();

        std::cout << v << " ";      // 输出该顶点
        ++count;
        // 将所有v指向的顶点的入度减1，并将入度减为0的顶点入栈
        for(auto beg = adj[v].begin(); beg!=adj[v].end(); ++beg)
            if(!(--indegree[*beg]))
                q.push(*beg);   // 若入度为0，则入栈
    }
    std::cout << "\n";

    if(count < V) {
        return false;           // 没有输出全部顶点，有向图中有回路
    } else {
        return true;            // 拓扑排序成功
    }
}
