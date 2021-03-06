/**
 * @Author: Chacha
 * @Date: 2021-03-03 16:06:05
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-03-03 17:30:01
 */

/**
 * 堆是一种基于【完全二叉树】的数据结构，可使用数组实现。已堆为原理堆排序算法称为【堆排序】，
 * 基于堆实现堆数据结构为【优先队列】。堆分为【大顶堆】和【小顶堆】：任意节点堆值不大于（小于）
 * 齐父节点堆值。
 *
 * 完全二叉树的定义：设二叉树的深度为 k，若二叉树除第 k 层外的其他各层（第 1 层至 k - 1一层）的节点达到最大个数，
 * 且处于第 k 层的节点都连续集中在最左边，则称此二叉树为完全二叉树。
 *
 * 如 ./heap.png 所示，为包含 1, 4, 2, 6, 8 元素的小顶堆。将堆（完全二叉树）中的结点按层编号，即可映射到右边的数组存储形式。
 *
 */

// 通过使用【优先队列】的【压入 push()】和【弹出 pop()】操作，即可完成堆排序，实现代码如下
#include <queue>

using namespace std;

int main()
{
    // 初始化小顶堆
    priority_queue<int, vector<int>, greater<int>> heap;

    // 元素入堆
    heap.push(1);
    heap.push(4);
    heap.push(2);
    heap.push(6);
    heap.push(8);

    // 元素出堆（从小到大）
    heap.pop(); // -> 1
    heap.pop(); // -> 2
    heap.pop(); // -> 4
    heap.pop(); // -> 6
    heap.pop(); // -> 8

    return 0;
}
