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
 * 定义两个哈希表，第一个 freq_table 以频率 freq 为索引，每个索引存放一个双向链表，这个链表里存放所有使用频率为 freq 的缓存,
 * 缓存里存放三个信息，分别为键 key, 值 val 和 使用频率 freq。第二个 key_table 以键值 key 为索引，每个索引存放对应缓存在
 * freq_table 中链表里的内存地址，这样我们就能利用两个哈希表来使得两个操作的时间复杂度均为 O(1)。同时需要记录一个当前缓存最少
 * 使用的频率minFreq, 这是为了删除操作服务的。
 *
 * 对于 get(key) 操作，我们能通过索引 key 在 key_table 中找到缓存在 freq_table 中的链表的内存地址，如果不存在直接返回 -1,
 * 否则我们能获取到对应缓存的相关信息，这样我们就能知道缓存的键值还有使用频率，直接返回 key 对应的值即可。
 * 但是我们注意到 get 操作后这个缓存的使用频率加一了，所以我们需要更新缓存在哈希表 freq_table 中的位置。已知这个缓存的键 key，
 * 值 value，以及使用频率 freq，那么该缓存应该存放到 freq_table 中 freq + 1 索引下的链表中。所以我们在当前链表中 O(1)
 * 删除该缓存对应的节点，根据情况更新 minFreq 值，然后将其 O(1) 插入到 freq + 1 索引下的链表头完成更新。插入到链表头，
 * 其实是为了保证缓存在当前链表中从链表头到链表尾的插入时间是有序的，为下面的删除操作服务。
 *
 * 对于 put(key, value) 操作，我们先通过索引 key在 key_table 中查看是否有对应的缓存，如果有的话，其实操作等价于 get(key)
 * 操作，唯一的区别就是我们需要将当前的缓存里的值更新为 value。如果没有的话，相当于是新加入的缓存，如果缓存已经到达容量，
 * 需要先删除最近最少使用的缓存，再进行插入。
 *
 * 先考虑插入，由于是新插入的，所以缓存的使用频率一定是 1，所以我们将缓存的信息插入到 freq_table 中 1 索引下的列表头即可，
 * 同时更新 key_table[key] 的信息，以及更新 minFreq = 1。
 *
 * 对于删除操作，由于我们实时维护了 minFreq，所以我们能够知道 freq_table 里目前最少使用频率的索引，同时因为我们保证了链表
 * 中从链表头到链表尾的插入时间是有序的，所以 freq_table[minFreq] 的链表中链表尾的节点即为使用频率最小且插入时间最早的节点，
 * 我们删除它同时根据情况更新 minFreq ，整个时间复杂度均为 O(1)。
 *
 * 复杂度：
 * 时间复杂度：get 时间复杂度 O(1)，put 时间复杂度 O(1)。由于两个操作从头至尾都只利用了哈希表的插入删除还有链表的插入删除，
 * 且它们的时间复杂度均为 O(1)，所以保证了两个操作的时间复杂度均为O(1)。
 * 空间复杂度：
 * O(capacity)，其中 capacity 为 LFU 的缓存容量。哈希表中不会存放超过缓存容量的键值对。
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
    int minFreq, capacity;
    unordered_map<int, list<Node>::iterator> key_table;
    unordered_map<int, list<Node>> freq_table;

public:
    LFUCache(int _capacity)
    {
        minFreq = 0;
        capacity = _capacity;
        key_table.clear();
        freq_table.clear();
    }

    int get(int key)
    {
        if (capacity == 0)
            return -1;

        auto item = key_table.find(key);

        if (item == key_table.end())
            return -1;

        list<Node>::iterator node = item->second;
        int val = node->val, freq = node->freq;
        freq_table[freq].erase(node);

        // 如果当前链表为空，我们需要在哈希表中删除，且更新minFreq
        if (freq_table[freq].size() == 0)
        {
            freq_table.erase(freq);
            if (minFreq == freq)
                minFreq += 1;
        }

        // 插入到 freq + 1 中
        freq_table[freq + 1].push_front(Node(key, val, freq + 1));
        key_table[key] = freq_table[freq + 1].begin();

        return val;
    }

    void put(int key, int value)
    {
        if (capacity == 0)
            return;

        auto item = key_table.find(key);

        if (item == key_table.end())
        {
            // 如果缓存已满，需要进行删除操作
            if (key_table.size() == capacity)
            {
                // 通过 minFreq 获取 freq_table[minFreq] 链表的末尾节点
                auto item2 = freq_table[minFreq].back();
                key_table.erase(item2.key);
                freq_table[minFreq].pop_back();

                if (freq_table[minFreq].size() == 0)
                {
                    freq_table.erase(minFreq);
                }
            }

            freq_table[1].push_front(Node(key, value, 1));
            key_table[key] = freq_table[1].begin();
            minFreq = 1;
        }
        else
        {
            list<Node>::iterator node = item->second;
            int freq = node->freq;
            freq_table[freq].erase(node);

            if (freq_table[freq].size() == 0)
            {
                freq_table.erase(freq);
                if (minFreq == freq)
                    minFreq += 1;
            }

            freq_table[freq + 1].push_front(Node(key, value, freq + 1));
            key_table[key] = freq_table[freq + 1].begin();
        }
    }
};

int main(int argc, char const *argv[])
{
    // cnt(x) = 键 x 的使用计数
    // cache=[] 将显示最后一次使用的顺序（最左边的元素是最近的）

    LFUCache lfu = LFUCache(2);

    lfu.put(1, 1); // cache=[1,_], cnt(1)=1
    lfu.put(2, 2); // cache=[2,1], cnt(2)=1, cnt(1)=1

    std::cout << "lru.get(1) = " << lfu.get(1) << std::endl; // 返回 1
                                                             // cache=[1,2], cnt(2)=1, cnt(1)=2
    lfu.put(3, 3);                                           // 去除键 2 ，因为 cnt(2)=1 ，使用计数最小
                                                             // cache=[3,1], cnt(3)=1, cnt(1)=2
    std::cout << "lru.get(2) = " << lfu.get(2) << std::endl; // 返回 -1（未找到）
    std::cout << "lru.get(3) = " << lfu.get(3) << std::endl; // 返回 3

    return 0;
}
