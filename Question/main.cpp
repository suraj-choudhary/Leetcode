//
//  main.cpp
//  Question
//
//  Created by suraj kumar on 24/09/23.
//

#include <iostream>
#include <vector>
#include <stack>

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

void swaping(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}
void sorting(int arr[], int size) {
    
    for(int i = 0; i < size; i++) {
        
        for(int j = i + 1; j < size; j++) {
            if(arr[i] > arr[j]) {
                swaping(&arr[i], &arr[j]);
            }
        }
    }
}

/// this two sum is rleated to two pointer concept
/// - Parameters:
///   - arr: arr
///   - target: target
///   - size: size
void twoSumUsingTwoPointer(int arr[], int target, int size) {
    
    sorting(arr, size);
    
    int start = 0;
    int end = size -1;
    
    while (start <= end) {
        
        int sum = arr[start] + arr[end];
        if(sum == target) {
            printf("%d %d", start, end);
            break;
        } else if(sum > target) {
            end--;
        } else {
            start++;
        }
    }
}


// MARK: Two sum using binary serach:

bool twoSumUsingBinarSearch(int arr[], int low, int high, int key) {
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if(arr[mid] == key) {
            return true;
        }
        if(arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return false;
}

void checkTwoSum(int arr[], int n, int sum) {
    sorting(arr, n);
    
    for(int i = 0; i < n; i++) {
        int searchKey = sum - arr[i];
        if(twoSumUsingBinarSearch(arr, i + 1, n - 1, searchKey)) {
            printf("%d %d", arr[i], searchKey);
        }
    }
    
}

// MARK: Two sum using hasing--

#define MAX 50

vector<int> printPairs(int arr[], int n, int sum) {
    int i, temp;
    int s[MAX] = { 0 };
    vector<int>res;
    for(i = 0; i < n; i++) {
        temp = sum - arr[i];
        if(s[temp] == 1) {
            res.push_back(i);
            break;
        }
        s[arr[i]] = 1;
    }
    return res;
}

/*
 int main() {
 int arr[] = {1, 4, 45, 6, 10, -8 };
 int target = 16;
 int size = sizeof(arr) / sizeof(arr[0]);
 printPairs(arr, size, target);
 }
 */

//9. Palindrome Number

void isPalindrome(int x) {
    int rev = 0;
    int y = x;
    while (x != 0) {
        int temp = x % 10;
        rev = rev * 10 + temp;
        x = x / 10;
    }
    
    if(y == rev) {
        printf("yes");
    } else {
        printf("no");
    }
    
}

/*
 int main() {
 int num = 121;
 isPalindrome(num);
 }
 */

// MARK: 13. Roman to Integer
int value(char r) {
    if(r == 'I') {
        return 1;
    }
    if(r == 'V') {
        return 5;
    }
    if(r == 'X') {
        return 10;
    }
    if(r == 'L') {
        return 50;
    }
    if(r == 'C') {
        return 100;
    }
    if(r == 'D') {
        return 500;
    }
    if(r == 'M') {
        return 1000;
    }
    return -1;
}

int romanToInt(string s) {
    int res = 0;
    for(int i = 0; i < s.length(); i++) {
        int s1 = value(s[i]);
        if(i + 1 < s.size()) {
            int s2  = value(s[i + 1]);
            if(s1 >= s2) {
                res += s1;
            } else {
                res = res + s2 - s1;
                i++;
            }
        } else {
            res = res + s1;
        }
    }
    printf("%d ", res);
    return 0;
}
/*
 int main() {
 string str = "VIII";
 romanToInt(str);
 }
 
 */




//MARK: 14. Longest Common Prefix

string commonPrefixUtil(string str1, string str2) {
    
    string res = "";
    long size = str1.size() > str2.size() ? str1.size() : str2.size();
    for(int i = 0; i < size; i++) {
        if(str1[i] != str2[i]) {
            break;
        }
        res += str1[i];
    }
    return res;
}

string longestCommonPrefix(vector<string>& strs) {
    string temp = strs[0];
    for(int i = 1; i < strs.size(); i++) {
        temp = commonPrefixUtil(temp, strs[i]);
    }
    return temp;
}

/*
 int main() {
 vector<string> str = {"flower", "flow", "flight"};
 longestCommonPrefix(str);
 }
 */

bool isValid(string s) {
    stack<char> stack;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack.push(s[i]);
        } else if (s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if (stack.empty()) {
                return false;
            }
            char openBracket = stack.top();
            stack.pop();
            if ((s[i] == ')' && openBracket != '(') ||
                (s[i] == '}' && openBracket != '{') ||
                (s[i] == ']' && openBracket != '[')) {
                return false;
            }
        }
    }
    return stack.empty();
}

/*
 int main() {
 string str = "()[]{}";
 isValid(str);
 }
 
 */

///21. Merge Two Sorted Lists
struct Node {
    int data;
    struct Node *next;
};

void DisplayNode(struct Node *p) {
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}
struct Node* createLinkedList(int arr[], int size) {
    struct Node *p;
    struct Node *t;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = arr[0];
    p->next = NULL;
    struct Node *head = p;
    for(int i = 1; i < size; i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = arr[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
    return head;
}

/// Description
/// - Parameters: Bruite force
///   - l1: l1 description
///   - l2: l2 description
void MergeTwoLinkedList(struct Node *l1, struct Node *l2) {
    
    vector<int>res;
    
    while (l1 != NULL) {
        res.push_back(l1->data);
        l1 = l1->next;
    }
    while (l2 != NULL) {
        res.push_back(l2->data);
        l2 = l2->next;
    }
    
    sort(res.begin(), res.end());
    
    struct Node *p;
    struct Node *t;
    p = (struct Node*)malloc(sizeof(struct Node));
    p->data = res[0];
    p->next = NULL;
    struct Node *head = p;
    for(int i = 1; i < res.size(); i++) {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = res[i];
        t->next = NULL;
        p->next = t;
        p = t;
    }
    DisplayNode(head);
    
}

/// MergeTwoLinkedListMethod2
/// - Parameters:
///   - list1: list1 description
///   - list2: list2 description
void MergeTwoLinkedListMethod2(struct Node *list1, struct Node *list2) {
    struct Node *third;
    struct Node *last;
    
    if(list1->data < list2->data) {
        third = last = list1;
        list1 = list1->next;
        last->next = NULL;
        
    } else {
        third = last = list2;
        list2 = list2->next;
        last->next = NULL;
    }
    
    while (list1 != NULL && list2 != NULL) {
        if(list1->data < list2->data) {
            last->next = list1;
            last = list1;
            list1 = list1->next;
            last->next = NULL;
        } else {
            last->next = list2;
            last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
    }
    if(list1 != NULL) {
        last->next = list1;
        
    } else {
        last->next = list2;
    }
    DisplayNode(third);
}



struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        struct ListNode *third;
        struct ListNode *last;
        
        if(list1->val < list2->val) {
            third = last = list1;
            list1 = list1->next;
            last->next = NULL;
            
        } else {
            third = last = list2;
            list2 = list2->next;
            last->next = NULL;
        }
        
        while (list1 != NULL && list2 != NULL) {
            if(list1->val < list2->val) {
                last->next = list1;
                last = list1;
                list1 = list1->next;
                last->next = NULL;
            } else {
                last->next = list2;
                last = list2;
                list2 = list2->next;
                last->next = NULL;
            }
        }
        if(list1 != NULL) {
            last->next = list1;
            
        } else {
            last->next = list2;
        }
        return third;
    }
};

/*
 int main() {
 int arr[] = {5,2,4};
 int arr2[] = {3,3,4};
 
 int size2 = sizeof(arr2) / sizeof(arr2[0]);
 int size = sizeof(arr) / sizeof(arr[0]);
 struct Node *list1 = createLinkedList(arr, size);
 printf("\n");
 struct Node *list2 = createLinkedList(arr2, size2);
 
 MergeTwoLinkedListMethod2(list1, list2);
 Solution obj;
 }
 
 */

// MARK: 26. Remove Duplicates from Sorted Array

int removeDuplicates(vector<int>& nums) {
    int start = 0;
    int arr[nums.size()];
    int j = 0;
    while (start < nums.size()) {
        if(nums[start] != nums[start + 1]) {
            arr[j] = nums[start];
            j++;
        }
        start++;
    }
    return 0;
}

/*
 int main() {
 vector<int> arr = {1, 2, 2, 3, 4, 4, 4, 5, 5};
 removeDuplicates(arr);
 }
 */
// MARK: 26. Remove Duplicates from Sorted Array method 2:


int removeDuplicatesMethod2(int arr[], int n) {
    
    int temp[n];
    int j = 0;
    for(int i = 0; i < n - 1; i++) {
        if(arr[i] != arr[j + 1]) {
            temp[j] = arr[i];
        }
        j++;
    }
    temp[j] = arr[n - 1];
    for(int i = 0; i < n; i++) {
        printf("%d ", temp[i]);
    }
    return 0;
}

/*
 int main() {
 int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
 int size = sizeof(arr) / sizeof(arr[0]);
 removeDuplicatesMethod2(arr, size);
 }
 */


int BinarySearch(int arr[], int size, int key) {
    int start = 0;
    int end = size - 1;
    
    for(int i = 0; i < size; i++) {
        int mid = (end - start) / 2;
        if(arr[mid] == key) {
            return arr[mid];
        } else if(arr[mid] > key) {
            end = mid - 1;
        } else {
            start = mid + 1;
        }
    }
    return -1;
}

void removeTheDuplictates(int arr[], int n) {
    
    for(int i = 0; i < n; i++) {
       int value = BinarySearch(arr, n, arr[i]);
       
    }
}

/*
 int main() {
     int arr[] = {1, 2, 2, 3, 4, 4, 4, 5, 5};
     int size = sizeof(arr) / sizeof(arr[0]);
     removeTheDuplictates(arr, size);
 }

 */

void display(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

void removeElement(int arr[], int size, int key) {
    int start = 0;
    for(int i = 0; i < size - 1; i++) {
        if(arr[i] != key) {
            arr[start] = arr[i];
            start++;
        }
    }
    printf("%d ", start);
    display(arr, size);
}


/*
 int main() {
     int arr[] = {3,2,2,3};
     int size = sizeof(arr) / sizeof(arr[0]);
     removeElement(arr, size, 3);
 }

 */

int strStr(string haystack, string needle) {
    
    return 0;
}

int main() {
    string str1 = "sadbutsad";
    string str2 = "sad";
    strStr(str1, str2);
}
