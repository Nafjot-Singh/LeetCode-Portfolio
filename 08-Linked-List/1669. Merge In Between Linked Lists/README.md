<h2><a href="https://leetcode.com/problems/merge-in-between-linked-lists">1669. Merge In Between Linked Lists</a></h2>

<p>You are given two linked lists: <code>list1</code> and <code>list2</code> of sizes <code>n</code> and <code>m</code> respectively.</p>

<p>Remove <code>list1</code>'s nodes from the <code>a<sup>th</sup></code> node to the <code>b<sup>th</sup></code> node, and put <code>list2</code> in their place.</p>

<p>The blue edges and nodes in the following figure indicate the result:</p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/fig1.png" style="height: 130px; width: 504px;">
<p><em>Build the result list and return its head.</em></p>

<p>&nbsp;</p>
<p><strong class="example">Example 1:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2024/03/01/ll.png" style="width: 609px; height: 210px;">
<pre><strong>Input:</strong> list1 = [10,1,13,6,9,5], a = 3, b = 4, list2 = [1000000,1000001,1000002]
<strong>Output:</strong> [10,1,13,1000000,1000001,1000002,5]
<strong>Explanation:</strong> We remove the nodes 3 and 4 and put the entire list2 in their place. The blue edges and nodes in the above figure indicate the result.
</pre>

<p><strong class="example">Example 2:</strong></p>
<img alt="" src="https://assets.leetcode.com/uploads/2020/11/05/merge_linked_list_ex2.png" style="width: 463px; height: 140px;">
<pre><strong>Input:</strong> list1 = [0,1,2,3,4,5,6], a = 2, b = 5, list2 = [1000000,1000001,1000002,1000003,1000004]
<strong>Output:</strong> [0,1,1000000,1000001,1000002,1000003,1000004,6]
<strong>Explanation:</strong> The blue edges and nodes in the above figure indicate the result.
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>3 &lt;= list1.length &lt;= 10<sup>4</sup></code></li>
	<li><code>1 &lt;= a &lt;= b &lt; list1.length - 1</code></li>
	<li><code>1 &lt;= list2.length &lt;= 10<sup>4</sup></code></li>
</ul>


---

# 🛍️ Merge-In-Between-Linked-Lists | Explained

## Approach 1: Iterative Linked List Modification
### Intuition
This approach works by iteratively traversing the linked list to find the nodes before and after the sub-list to be replaced. It's similar to editing a document where you need to replace a section of text by deleting the existing section and then inserting the new text. The key idea is to update the `next` pointers of the adjacent nodes to effectively "splice" the new list into the original list.

### Algorithm Visualized
```mermaid
graph LR
    A[List 1] -->|a|> B[Node before a]
    B --> C[Node a]
    C --> ... --> D[Node b]
    D --> E[Node after b]
    F[List 2] --> ... --> G[Tail of List 2]
    B -->|updated next|> F
    G -->|updated next|> E
```

### Approach
The algorithm can be broken down into the following steps:
1. Find the node before the sub-list to be replaced (node before `a`).
2. Find the node after the sub-list to be replaced (node after `b`).
3. Delete the sub-list to be replaced by iterating from node `a` to node `b`.
4. Update the `next` pointer of the node before `a` to point to the head of the new list.
5. Update the `next` pointer of the tail of the new list to point to the node after `b`.

### Detailed Code Analysis
Let's dive into the code:
- Lines 12-15: Find the node before the sub-list to be replaced (`node_before_a`). This is done by iterating `a-1` times from the head of the list.
- Lines 17-22: Find the node after the sub-list to be replaced (`current_node`) and delete the sub-list by iterating `b-a+1` times from node `a`. The `temp` variable is used to store the node to be deleted before moving to the next node.
- Lines 24-27: Find the tail of the new list (`list2_tail`) by iterating from the head of `list2` until `NULL` is reached.
- Lines 29-30: Update the `next` pointer of `node_before_a` to point to the head of `list2`, effectively splicing `list2` into `list1`.
- Line 31: Update the `next` pointer of the tail of `list2` to point to `current_node`, completing the merge.

### Code
```c
struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){
    struct ListNode * node_before_a = list1;
    for(int i=1; i<a; i++){
        node_before_a=node_before_a->next;
    }

    struct ListNode * current_node = node_before_a->next;
    for(int i=0; i < (b - a + 1); i++){
        struct ListNode* temp = current_node;
        current_node=current_node->next;
        free(temp);
    }

    struct ListNode * list2_tail = list2;
    while(list2_tail->next != NULL){
        list2_tail = list2_tail->next;
    }

    node_before_a->next=list2;
    list2_tail->next = current_node;

    return list1;
}
```

### Complexity
- **Time:** O(a + (b-a+1) + n), where n is the number of nodes in `list2`. This is because we iterate `a-1` times to find the node before `a`, `b-a+1` times to delete the sub-list, and n times to find the tail of `list2`. However, since a, b, and n are all part of the input, we can simplify the time complexity to O(a + b + n).
- **Space:** O(1), excluding the space required for the input lists. This is because we only use a constant amount of space to store the pointers and variables, regardless of the input size.

## 🕵️‍♂️ Follow-up Questions (Optional)
1. How would you handle the case where `list2` is empty? 
   - In this case, we would still need to update the `next` pointer of `node_before_a` to point to `current_node`, effectively deleting the sub-list and merging the two lists.
2. What if `a` is equal to `b`? 
   - If `a` is equal to `b`, it means we are replacing a single node with `list2`. We would still need to update the `next` pointer of `node_before_a` to point to `list2`, and the `next` pointer of the tail of `list2` to point to the node after `b`.