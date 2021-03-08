/*
 * @Author: Chacha
 * @Date: 2021-03-07 22:08:23
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-07 23:00:37
 */

/**
 * 图是一种非线性数据结构，由【节点(定点) vertex】和【边 edge】组成，每条边连接一对定点。根据边的方向有无，
 * 图可以分为【有向图】和【无向图】。
 * 如 ./graph.png 所示，该无向图的 顶点 和 边 集合分别为：
 * 1. 顶点集合：vertices = {1, 2, 3, 4, 5}
 * 2. 边集合：edges = {{1, 2}, {1, 3}, {1, 4}, {1, 5}, {2, 4}, {3, 5}, {4, 5}}
 *
 * 表示上述图的方法有两种：
 * 1. 邻接矩阵：使用数组 vertices 存储顶点，邻接矩阵 edges 存储边；edges[i][j] 代表节点 i+1 和 节点 j+1之间是否有边。
 *          vertices=[1,2,3,4,5]
 *
 *              ⎡0  1  1  1  1⎤
 *              ⎢1  0  0  1  0⎥
 *      edges = ⎢1  0  0  0  1⎥
 *              ⎢1  1  0  0  1⎥
 *              ⎣1  0  1  1  0⎦
 *
 */

// 代码表示上述数据结构​
int vetices[5] = {1, 2, 3, 4, 5};
int edges[5][5] = {{0, 1, 1, 1, 1},
                   {1, 0, 0, 1, 0},
                   {1, 0, 0, 0, 1},
                   {1, 1, 0, 0, 1},
                   {1, 0, 1, 1, 0}};

/**
 * 2. 邻接表：使用数组 vetices 存储顶点，邻接表 edges 存储边。edges 为一个二维容器，第一维 i 代表顶点索引，
 * 第二维 edges[i] 存储次顶点对应的边集合；例如 edges[0] = [1, 2, 3, 4] 代表 vertices[0] 的边集合为[1, 2, 3, 4]。
 *         vertices=[1,2,3,4,5]
 *
 *              ⎡[1  2  3  4]⎤
 *              ⎢[0  3]      ⎥
 *      edges = ⎢[0  4]      ⎥
 *              ⎢[0  1  4]   ⎥
 *              ⎣[0 2 3]     ⎦
 */

// 代码表示上述数据结构​
int vertices1[5] = {1, 2, 3, 4, 5};
vector<vector<int>> edges1;

vector<int> edge_1 = {1, 2, 3, 4};
vector<int> edge_2 = {0, 3};
vector<int> edge_3 = {0, 4};
vector<int> edge_4 = {0, 1, 4};
vector<int> edge_5 = {0, 2, 3};
edges1.push_back(edge_1);
edges1.push_back(edge_2);
edges1.push_back(edge_3);
edges1.push_back(edge_4);
edges1.push_back(edge_5);

/**
 * 邻接矩阵 VS 邻接表 ：
 * 邻接矩阵的大小只与节点数量有关，即 N^2，其中 N 为节点数量。因此，当边数量明显少于节点数量时，使用邻接矩阵存储图会造成较大的内存浪费。
 * 因此，邻接矩阵 适合存储稠密图（顶点较少、边较多），邻接表 适合存储稀疏图（顶点较多、边较少）。
 */
