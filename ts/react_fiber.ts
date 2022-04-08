/*
 * @Author: Chacha
 * @Date: 2022-04-08 09:55:38
 * @Last Modified by: Chacha
 * @Last Modified time: 2022-04-08 18:05:49
 */
/**
 * React Fiber
 *
 * 介绍
 * React Fiber 是针对旧协调器重写的完全向后兼容的一个版本。React 的这种新的协调算法被称为 Fiber Reconciler。
 * 这个名字来自于 fiber，它经常被用来表示 DOM 树的节点。
 *
 * Fiber 协调器的主要目标是增量渲染，更好更平滑地渲染 UI 动画和手势，以及用户互动的响应性。协调器还允许你将工作分为多个块，
 * 并将渲染工作分为多个帧。它还增加了为每个工作单元定义优先级的能力，以及暂停、重复使用和中止工作的能力。
 *
 * 协调
 * Reconciliation 是两个 DOM 树 diff 的算法。当用户界面第一次渲染时，React 创建了一个节点树。
 * 每个单独的节点都代表 React 元素。它创建了一个虚拟树（被称为 Virtual DOM），是渲染的 DOM 树的副本。
 * 在来自用户界面的任何更新之后，它递归地比较两棵树的每一个树节点。然后，累积的变化被传递给渲染器。
 *
 * 调度
 * 假设我们有一些低优先级的工作（如大型计算函数或最近获取的元素的渲染），和一些高优先级的工作（如动画）。应该有一个选项，
 * 将高优先级的工作优先于低优先级的工作。在旧的堆栈协调器实现中，递归遍历和调用整个更新的树的渲染方法都发生在单个流程中，这可能会导致丢帧。
 * 调度可以是基于时间或基于优先级的。更新应该根据 deadline 来安排，高优先级的工作应该被安排在低优先级的工作之上。
 *
 *
 * Fiber树的遍历
 * 1. 开始：Fiber从最上面的 React 元素开始遍历，并为其创建一个 fiber 节点；
 * 2. 子节点：然后，它转到子元素，为这个元素创建一个 fiber 节点。这样继续下去，直到到达叶子节点；
 * 3. 兄弟节点： 现在，它检查是否有兄弟节点元素。如果有，它就遍历兄弟节点元素，然后再到兄弟姐妹的叶子元素；
 * 4. 返回：如果没有兄弟节点，那么它就返回到父节点。
 *
 */

type TypeOfWork = "div" | "span";

type RefObject = "RefObject";

type mixed = "mixed";

type TypeOfMode = "TypeOfMode";

type SideEffectTag = "SideEffectTag";

type SubtreeTag = "SubtreeTag";

// Fiber 的结构
export type Fiber = {
    // 识别 fiber 类型的标签
    tag: TypeOfWork;

    // child 的唯一标识符
    key: null | string;

    // 元素的值。类型，用于在协调 child 的过程中保存身份。
    elementType: any;

    // 与该 fiber 相关的已解决的 function / class
    type: any;

    // 与该 fiber 相关的当前状态
    stateNode: any;

    // fiber 剩余的字段

    // 处理完这个问题后要返回的 fiber。
    // 这实际上就是 parent。
    // 它在概念上与堆栈帧的返回地址相同。
    return: Fiber | null;

    // 单链表树结构。
    child: Fiber | null;
    sibling: Fiber | null;
    index: number;

    // 最后一次用到连接该节点的引用
    ref:
        | null
        | (((handle: mixed) => void) & { _stringRef?: string })
        | RefObject;

    // 进入处理这个 fiber 的数据。Arguments、Props。
    pendingProps: any; // 一旦我们重载标签，这种类型将更加具体。
    memoizedProps: any; // 用来创建输出的道具。

    // 一个状态更新和回调的队列。
    updateQueue: mixed;

    // 用来创建输出的状态
    memoizedState: any;

    mode: TypeOfMode;

    // Effect
    effectTag: SideEffectTag;
    subtreeTag: SubtreeTag;
    deletions: Array<Fiber> | null;

    // 单链表的快速到下一个 fiber 的副作用。
    nextEffect: Fiber | null;

    // 在这个子树中，第一个和最后一个有副作用的 fiber。
    // 这使得我们在复用这个 fiber 内所做的工作时，可以复用链表的一个片断。
    firstEffect: Fiber | null;
    lastEffect: Fiber | null;

    // 这是一个 fiber 的集合版本。每个被更新的 fiber 最终都是成对的。
    // 有些情况下，如果需要的话，我们可以清理这些成对的 fiber 来节省内存。
    alternate: Fiber | null;
};

type Update = "Update";

type UpdateQueue = "UpdateQueue";

// Hooks 类型结构
export type Hook = {
    memoizedState: any; // 指向当前渲染节点 Fiber, 上一次完整更新之后的最终状态值
    baseState: any; // 初始化 initialState, 已经每次 dispatch 之后 newState
    baseUpdate: Update | null; // 当前需要更新的 Update ，每次更新完之后，会赋值上一个 update，方便 react 在渲染错误的边缘，数据回溯
    queue: UpdateQueue | null; // 缓存的更新队列，存储多次更新行为
    next: Hook | null; // link 到下一个 hooks，通过 next 串联每一 hooks
};
