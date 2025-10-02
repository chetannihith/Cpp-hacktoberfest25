# 23. Merge k Sorted Lists

## Problem Description

You are given an array of `k` linked-lists `lists`, each linked-list is sorted in ascending order.

*Merge all the linked-lists into one sorted linked-list and return it.*

### Example 1:

```
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
```

### Example 2:

```
Input: lists = []
Output: []
```

### Example 3:

```
Input: lists = [[]]
Output: []
```

### Constraints:

- `k == lists.length`
- `0 <= k <= 10^4`
- `0 <= lists[i].length <= 500`
- `-10^4 <= lists[i][j] <= 10^4`
- `lists[i]` is sorted in **ascending order**.
- The sum of `lists[i].length` will not exceed `10^4`.

## Approach

This problem can be solved using a min-heap (priority queue) to always pick the smallest element from the current heads of all lists. We maintain a priority queue of size k, where each element is the head of one of the lists. At each step, we extract the minimum element, add it to the result, and push the next element from that list into the priority queue if it exists.

### Time Complexity

- **Time:** O(N log k), where N is the total number of nodes and k is the number of lists.
- **Space:** O(k) for the priority queue.

## Solution

The solution is implemented in C++ using a custom comparator for the priority queue to handle ListNode pointers.
