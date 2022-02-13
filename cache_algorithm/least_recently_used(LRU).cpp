/*
 * @Author: Chacha
 * @Date: 2021-04-26 10:07:24
 * @Last Modified by: Chacha
 * @Last Modified time: 2021-04-26 18:21:10
 */

/**
 * LRU缓存算法（https://baike.baidu.com/item/LRU）
 * LRU是Least Recently Used的缩写，即最近最少使用，是一种常用的页面置换算法，选择最近最久未使用的页面予以淘汰。
 *
 *
 * 实现 LRUCache类：
 * 1. LRUCache(int capacity) 以正整数作为容量 capacity 初始化 LRU 缓存
 * 2. int get(int key)
 * 3. void put(int key, int value) 如果关键字已经存在，则变更其数据值；如果关键字不存在，则插入该组「关键字-下值」。
 * 当缓存容量达到上限时，它应该在写入新数据之前删除最久未使用的数据值，从而为新的数据值保留出空间。
 *
 * 示例：
 *
 * 输入
 * ["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
 * [[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
 *
 * 输出
 * [null, null, null, 1, null, -1, null, -1, 3, 4]
 *
 * 解释
 * LRUCache lRUCache = new LRUCache(2);
 * lRUCache.put(1, 1); // 缓存是 {1=1}
 * lRUCache.put(2, 2); // 缓存是 {1=1, 2=2}
 * lRUCache.get(1);    // 返回 1
 * lRUCache.put(3, 3); // 该操作会使得关键字 2 作废，缓存是 {1=1, 3=3}
 * lRUCache.get(2);    // 返回 -1 (未找到)
 * lRUCache.put(4, 4); // 该操作会使得关键字 1 作废，缓存是 {4=4, 3=3}
 * lRUCache.get(1);    // 返回 -1 (未找到)
 * lRUCache.get(3);    // 返回 3
 * lRUCache.get(4);    // 返回 4
 *
 * 来源：https://leetcode-cn.com/problems/lru-cache
 *
 */

/**
 *  实现方法：哈希表 + 双向链表
 *
 * LRU 缓存机制可以通过哈希表辅以双向链表实现，可以用一个哈希表和一个双向链表维护所有在缓存中的键值对。
 * 1. 双向链表按照被使用的顺序存储这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
 * 2. 哈希表即为普通的哈希映射(HashMap)，通过缓存数据的键映射到其在双向链表中的位置。
 *
 * 我们使用哈希表进行定位，找出缓存项在双向链表中的位置，随后将其移动到双向链表的头部，即可在O(1)的时间内完成 get 或者 put 操作。
 * 具体的方法如下：
 * 1. 对于 get 操作，首先判断 key 是否存在：
 *   a. 如果 key 不存在，则返回 -1；
 *   b. 如果 key 存在，则 key 对应的节点是最近被使用的节点。通过哈希表定位到该节点在双向链表的位置，
 *      并将其移动到双向链表的头部，最后返回该节点的值。
 * 2. 对于 put 操作，首先判断 key 是否存在：
 *   a. 如果 key 不存在，使用 key 和 value 创建一个新的节点，在双向链表的头部添加该节点，并将 key 和该节点添加进哈希表中。
 *      然后判断双向链表的节点数是否超出容量，如果超出容量，则删除双向链表的尾部节点，并删除哈希表中对应的项
 *   b. 如果 key 存在，则与 get 操作类似，先通过哈希表定位，再将对应的节点的值更新为 value，并将该节点移到双向链表的头部。
 *
 * 上述操作中，访问哈希表的时间复杂度为 O(1)，在双向链表的头部添加节点、在双向链表的尾部删除节点的复杂度也为 O(1)。
 * 而将一个节点移到双向链表的头部，可以分成「删除该节点」和「在双向链表的头部添加节点」两步操作，都可以在 O(1) 时间内完成。
 *
 * NOTE:
 * 在双向链表的实现中，使用一个伪头部(dummy head)和伪尾部(dummy tail)标记界限，这样在添加节点和删除节点的时候就不需要检查相邻的节点是否存在
 *
 * 复杂度：
 * 时间复杂度：对于 put 和 get 操作都是O(1);
 * 空间复杂度：O(Capacity)，因为哈希表和双向链表最多存储 capacity + 1个元素
 *
 */

#include <iostream>
#include <unordered_map>

using namespace std;

// 双向链表结构体
struct DLinkedNode
{
    int key, value;
    DLinkedNode *prev;
    DLinkedNode *next;
    DLinkedNode() : key(0), value(0), prev(nullptr), next(nullptr) {}
    DLinkedNode(int _key, int _value) : key(_key), value(_value), prev(nullptr), next(nullptr) {}
};

class LRUCache
{
private:
    /* data */
    unordered_map<int, DLinkedNode *> cache;
    DLinkedNode *head;
    DLinkedNode *tail;
    int size;
    int capacity;

public:
    LRUCache(int _capacity) : capacity(_capacity), size(0)
    {
        head = new DLinkedNode();
        tail = new DLinkedNode();
        head->next = tail;
        tail->prev = head;
    };

    int get(int key)
    {
        // 如果 key 不存在，则返回 -1
        if (!cache.count(key))
        {
            return -1;
        }

        DLinkedNode *node = cache[key];

        moveToHead(node);

        return node->value;
    }

    void put(int key, int value)
    {
        if (!cache.count(key))
        {
            // 如果 key 不存在，创建一个新的节点
            DLinkedNode *node = new DLinkedNode(key, value);
            // 添加 node 到哈希表
            cache[key] = node;

            // 将节点添加到双向链表头部
            addToHead(node);
            ++size; // Cache size 加一

            if (size > capacity)
            {
                // 如果超出容量，则删除双向链表的尾部节点
                DLinkedNode *removed = removeTail();
                // 同时删除哈希表中对应的项
                cache.erase(removed->key);
                // 删除节点 removed，防止内存泄漏
                delete removed;
                --size; // Cache size 减一
            }
        }
        else
        {
            // 如果 key 存在，先通过哈希表定位，再修改 value，并移到头部
            DLinkedNode *node = cache[key];
            node->value = value;
            moveToHead(node);
        }
    }

    // 添加到双向链表头部
    void addToHead(DLinkedNode *node)
    {
        node->prev = head;
        node->next = head->next;
        head->next->prev = node;
        head->next = node;
    }

    // 从双向链表移除节点
    void removeNode(DLinkedNode *node)
    {
        node->prev->next = node->next;
        node->next->prev = node->prev;
    }

    // 移动到双向链表头部，即先做移除节点操作(调用removeNode)，然后添加到双向链表头部(调用addToHead)
    void moveToHead(DLinkedNode *node)
    {
        removeNode(node);
        addToHead(node);
    }

    // 移除双向链表尾部节点
    DLinkedNode *removeTail()
    {
        DLinkedNode *node = tail->prev;
        removeNode(node);
        return node;
    }
};

int main(int argc, const char **argv)
{
    LRUCache *lruCache = new LRUCache(2);

    lruCache->put(1, 1);
    lruCache->put(2, 2);

    std::cout << "lruCache->get(1) = " << lruCache->get(1) << std::endl;
    std::cout << "lruCache->get(2) = " << lruCache->get(2) << std::endl;

    lruCache->put(3, 3);

    std::cout << "lruCache->get(1) = " << lruCache->get(1) << std::endl;
    std::cout << "lruCache->get(2) = " << lruCache->get(2) << std::endl;
    std::cout << "lruCache->get(3) = " << lruCache->get(3) << std::endl;

    return 0;
}
