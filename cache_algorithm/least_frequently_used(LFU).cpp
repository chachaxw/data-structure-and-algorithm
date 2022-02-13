/*
 * @Author: Chacha
 * @Date: 2021-02-13 16:21:10
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-02-13 16:21:24
 */

/**
 * LFU缓存算法（https://baike.baidu.com/item/LFU）
 * LRU是Least Frequently Used的缩写，即最不经常使用页置换算法。这个缓存算法使用一个计数器来记录条目被访问的频率。
 * 通过使用LFU缓存算法，最低访问数的条目首先被移除。
 *
 * 实现LFUCache类:
 * 1. LFUCache(int capacity) - 用数据结构的容量 capacity 初始化对象
 * 2. int get(int key) - 如果键 key 存在于缓存中，则获取键的值，否则返回-1
 * 3. void put(int key, int value) - 如果键 key 存在，则变更其值; 如果键不存在，请插入键值对。
 *    当缓存达到其容量capacity时, 则应该在插入新项之前，移除最不经常使用的项。在此问题中，当存在平局(即
 *    即两个或更多个键具有相同使用频率), 应该去除 最近最久未使用 的键
 *
 * 示例:
 * 输入：
 *  ["LFUCache", "put", "put", "get", "put", "get", "get", "put", "get", "get", "get"]
 *  [[2], [1, 1], [2, 2], [1], [3, 3], [2], [3], [4, 4], [1], [3], [4]]
 *  输出：
 *  [null, null, null, 1, null, -1, 3, null, -1, 3, 4]
 *
 *  解释：
 *  // cnt(x) = 键 x 的使用计数
 *  // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）
 *  LFUCache lfu = new LFUCache(2);
 *  lfu.put(1, 1);   // cache=[1,_], cnt(1)=1
 *  lfu.put(2, 2);   // cache=[2,1], cnt(2)=1, cnt(1)=1
 *  lfu.get(1);      // 返回 1
 *                  // cache=[1,2], cnt(2)=1, cnt(1)=2
 *  lfu.put(3, 3);   // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
 *                  // cache=[3,1], cnt(3)=1, cnt(1)=2
 *  lfu.get(2);      // 返回 -1（未找到）
 *  lfu.get(3);      // 返回 3
 *                  // cache=[3,1], cnt(3)=2, cnt(1)=2
 *  lfu.put(4, 4);   // 去除键 1 ，1 和 3 的 cnt 相同，但 1 最久未使用
 *                  // cache=[4,3], cnt(4)=1, cnt(3)=2
 *  lfu.get(1);      // 返回 -1（未找到）
 *  lfu.get(3);      // 返回 3
 *                  // cache=[3,4], cnt(4)=1, cnt(3)=3
 *  lfu.get(4);      // 返回 4
 *                  // cache=[3,4], cnt(4)=2, cnt(3)=3
 *
 *  来源：力扣（LeetCode）https://leetcode-cn.com/problems/lfu-cache
 *
 */

/**
 * 实现方法：双哈希表
 *
 */

#include <list>
#include <iostream>
#include <unordered_map>

using namespace std;

// 缓存的节点信息
struct Node
{
    int key, val, freq;
    Node(int _key, int _val, int _freq) : key(_key), val(_val), freq(_freq) {}
};

class LFUCache
{
private:
    int minfreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int _capacity)
    {
        minfreq = 0;
        capacity = _capacity;
    }

    int get(int key)
    {
    }

    void put(int key, int value)
    {
    }
};

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}
