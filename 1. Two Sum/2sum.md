# Two Sum - C++ Solution

This repository contains a C++ solution for the classic **Two Sum** problem, commonly found on algorithmic platforms like LeetCode.

## Problem Statement

Given an array of integers `nums` and an integer `target`, return the indices of the two numbers such that they add up to `target`. 

You may assume that each input would have **exactly one solution**, and you may not use the same element twice. You can return the answer in any order.

## Approach: Two-Pass Hash Table

This solution uses a hash map (`std::unordered_map` in C++) to achieve an efficient runtime. It operates in two separate passes over the array:

1. **Populate the Hash Map (First Pass):** Iterate through the array and map each value to its corresponding index.
2. **Find the Complement (Second Pass):** Iterate through the array a second time. For each element `nums[i]`, calculate its complement (`target - nums[i]`). If the complement exists in the hash map and is *not* the current element itself, we have found our two indices.

## Code Explanation

Here is a step-by-step breakdown of how the logic translates into the code:

*   **Initialization:**
    ```cpp
    unordered_map<int, int> indices;  // val -> index
    ```
    We create a hash map where the **key** is the actual number from the array and the **value** is its index position.

*   **First Pass (Building the Map):**
    ```cpp
    for (int i = 0; i < nums.size(); i++) {
        indices[nums[i]] = i;
    }
    ```
    This iterates through the entire `nums` array. For every number `nums[i]`, it records its index `i` in the hash map. *(Note: If there are duplicate numbers in the array, the map will overwrite previous entries and store the last seen index.)*

*   **Second Pass (Finding the Pair):**
    ```cpp
    for (int i = 0; i < nums.size(); i++) {
        int diff = target - nums[i];
        if (indices.count(diff) && indices[diff] != i) {
            return {i, indices[diff]};
        }
    }
    ```
    We loop through the array a second time. For the current number `nums[i]`, we calculate the value needed to reach the target (`diff`). 
    *   `indices.count(diff)` checks if this required number exists anywhere in our hash map.
    *   `indices[diff] != i` ensures that the found complement is not the exact same element we are currently looking at (satisfying the rule: "you may not use the same element twice").
    *   If both conditions are met, it immediately returns a vector containing the current index `i` and the complement's index.

*   **Fallback Return:**
    ```cpp
    return {};
    ```
    Although the problem statement guarantees a valid answer exists, C++ requires a return value at the end of the function. This handles edge cases where no solution is found by returning an empty vector.

### Complexity Analysis

* **Time Complexity:** $O(n)$
  We iterate through the `nums` array exactly twice. Hash map insertions and lookups take $O(1)$ time on average, making the overall time strictly linear.
* **Space Complexity:** $O(n)$
  The extra space is required for the hash map, which stores at most $n$ key-value pairs (where $n$ is the number of elements in the `nums` array).