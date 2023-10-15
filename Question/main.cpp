//
//  main.cpp
//  Question
//
//  Created by suraj kumar on 24/09/23.
//

#include <iostream>
#include <vector>

using namespace::std;

void SubArrayWithSum(int arr[], int size, int target) {
    int sum = arr[0];
    
    for(int i = 1; i < size; i++) {
        int start = 0;
        while (sum > target && start < i - 1) {
            sum = sum - arr[start];
        }
        if(sum == target) {
            printf("%d %d", start + 1, i);
            break;
        }
        sum += arr[i];
    }
}

// Bruite force


void subArrayMethod(int arr[], int size, int target) {
    
    for(int i = 0; i < size; i++) {
        int currentSum = arr[i];
        if(currentSum == target) {
            printf("sum found at index: %d", i);
            return;
        } else {
            for(int j = i + 1; j < size; j++) {
                currentSum += arr[j];
                if(currentSum == target) {
                    printf("%d %d", i, j);
                    return;
                }
            }
        }
    }
}

/*
 int main() {
 int arr[] = {15, 2, 4, 8, 9, 5, 10, 23};
 int size = sizeof(arr) / sizeof(arr[0]);
 int sum = 23;
 subArrayMethod(arr, size, sum);
 
 }
 */


// MARK: Missing Number:

int missingNumber(int arr[], int n) {
    
    int total = (n + 1) * (n + 2) / 2; //n(n + 1) / 2
    for(int i = 0; i < n; i++) {
        total -= arr[i];
    }
    return total;
}

//Bruite force for missing element in the array:

void missingNo(int arr[], int size, int n) {
    
    for(int i = 1; i <= n; i++) {
        int flag = 0;
        
        for(int j = 0; j < size; j++) {
            if(arr[j] == i) {
                flag = 1;
                break;
            }
        }
        if(flag == 0) {
            printf("%d ", i);
        }
    }
}

// MARK: Kadane's Algorithm

void maxSubarraySum(int arr[], int n) {
    int maxSum = INT_MIN;
    int cMax = 0;
    for(int i = 0; i < n; i++) {
        cMax += arr[i];
        if(cMax > maxSum) {
            maxSum = cMax;
        }
        if(cMax < 0) {
            cMax = 0;
        }
    }
    printf("%d ", maxSum);
    
}

// MARK: Bruite force:

void findMaxSubArray(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int i = 0; i < n - 1; i++) {
        int subArraySum = 0;
        for(int j = i; j < n - 1; j++) {
            
            for(int k = i; k <= j; k++) {
                subArraySum += arr[k];
            }
        }
    }
}

// MARK: using two nested loop:

void findMaxSubArray1(int arr[], int n) {
    int maxSum = INT_MIN;
    for(int i = 0; i < n; i++) {
        int currentSum = 0;
        for(int j = i; j < n; j++) {
            currentSum += arr[j];
            if(currentSum > maxSum) {
                maxSum = currentSum;
            }
        }
    }
    printf("%d ", maxSum);
}

// MARK: Minimum number of jumps: Recursive approach


int minJumps(int arr[], int start, int end) {
    if(start >= end) {
        return 0;
    }
    int minJump = INT_MAX;
    for(int i = 1; i <= arr[start] && i < end; i++) {
        int jumpCount = 1 + minJumps(arr, start + i, end);
        if(jumpCount < minJump) {
            minJump = jumpCount;
        }
    }
    return minJump;
}



/// minimum jump to reach the end of array
/// - Parameters:
///   - arr: arr
///   - size: size of array
void maxReach(int arr[], int size) {
    
    int maxReach = arr[0];
    int steps = arr[0];
    int jump = 1;
    
    for(int i = 1; i < size; i++) {
        if(i == size - 1) {
            printf("%d ", jump);
            break;
        }
        
        maxReach = max(maxReach, i + arr[i]);
        steps--;
        if(steps == 0) {
            jump++;
            if(i >= maxReach) {
                return;
            }
            steps = maxReach - i;
        }
        
    }
}

/*
 int main() {
     int arr[] = {1, 3, 5, 8, 10, 2, 6, 7, 6, 8, 9};
     int size = sizeof(arr) / sizeof(arr[0]);
     maxReach(arr, size);
 }
 */
// MARK: Leetcode easy:

/// Two sum:
/// Input: nums = [2,7,11,15], target = 9
/// Output: [0,1]
///Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].

vector<int> twoSum(vector<int>&nums, int target) {
    vector<int> res;
    
    for(int i = 0; i < nums.size(); i++) {
        for(int j = i + 1; j < nums.size(); j++) {
            
            if(nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }
    return {0, 0};
}

///Two Sum using Sorting and Two-Pointers technique:


void twoSumUsingTwoPointer(int arr[], int target) {
    
}


int main() {
    int arr[] = {2,7,11,15};
    int target = 9;
    int size = sizeof(arr) / sizeof(arr[0]);
    
}
