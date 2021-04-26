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
 * 方法一：哈希表 + 双向链表
 *
 * LRU 缓存机制可以通过哈希表辅以双向链表实现，可以用一个哈希表和一个双向链表维护所有在缓存中的简直队。
 * 1. 双向链表按照被使用的顺序存储这些键值对，靠近头部的键值对是最近使用的，而靠近尾部的键值对是最久未使用的。
 * 2. 哈希表即为普通的哈希映射(HashMap)，通过缓存数据的键映射到其在双向链表中的位置。
 *
 * 我们使用哈希表进行定位，找出缓存项在双向链表中的位置，随后将其移动到双向链表的头部，即可在O(1)的时间内完成 get 或者 put 操作。
 * 具体的方法如下：
 * 1.
 *
 */
