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

// MARK: Find the Index of the First Occurrence in a String
int strStr(string str1, string str2) {
    
    long n = str1.length();
    long m = str2.length();
    
    for(int i = 0; i < n; i++) {
        int temp = i;
        int j = 0;
        for(j = 0; j < m; j++) {
            
            if(str1[temp] != str2[j]) {
                break;
            }
            temp++;
        }
        if(j == m) {
            printf("%d ", i);
        }
    }
    return 0;
}

/*
 int main() {
 string str1 = "takeyouforward";
 string str2 = "forward";
 strStr(str1, str2);
 }
 
 */

// MARK: 35. Search Insert Position
int searchInsert(int arr[], int size, int target) {
    int i;
    
    for(i = 0; i < size; i++) {
        if(arr[i] == target) {
            return i;
        } else if(arr[i] > target) {
            return i;
        }
    }
    return i;
}

/*
 int main() {
 int arr[] = {1,3,5,6};
 int size = sizeof(arr) /sizeof(arr[0]);
 int target = 2;
 searchInsert(arr, size, target);
 }
 */

// MARK: 58. Length of Last Word

int lengthOfLastWord(string s) {
    
    int start = 0;
    
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == ' ') {
            start = 0;
            continue;
        } else {
            start++;
        }
    }
    printf("%d ", start);
    return 0;
}

int lengthOfLastWord2(string s) {
    
    int start = 0;
    long end = s.size() - 1;
    
    while (end >= 0 && s[end] == ' ') {
        end--;
    }
    while (end >= 0 && s[end] != ' ') {
        start++;
        end--;
    }
    return 0;
}
/*
 int main() {
 string str =  "   fly me   to   the moon  ";
 lengthOfLastWord2(str);
 }
 */


// MARK: 66. Plus One
vector<int> plusOne(vector<int>arr, long n1) {
    long n = n1 - 1;
    while (n >= 0) {
        if(arr[n] != 9) {
            arr[n]++;
            n--;
            break;
        } else {
            arr[n] = 0;
            n--;
        }
    }
    return arr;
}

vector<int> plusOne(vector<int>& digits) {
    long n = digits.size();
    for (long i = n - 1; i >= 0; i--) {
        if (digits[i] != 9) {
            digits[i]++;
            return digits;
        } else {
            digits[i] = 0;
        }
    }
    
    digits.insert(digits.begin(), 1);
    return digits;
}

/*
 int main() {
 vector<int>res = {1, 2, 3};
 long size = res.size();
 vector<int>res1 = plusOne(res, size);
 for(int i = 0; i < res1.size(); i++) {
 printf("%d ", res1[i]);
 }
 }
 
 */
string addBinary(string a, string b) {
    
    int carry = 0;
    string res = "";
    
    long maxLen = std::max(a.length(), b.length());
    
    for(int i = 0; i < maxLen; i++) {
        int f = i < a.length() ? a[a.length() - i - 1] - '0' : 0;
        int s = i < b.length() ? b[b.length() - i - 1] - '0' : 0;
        
        int sum = f + s + carry;
        carry = sum / 2;
        res = std::to_string(sum % 2) + res;
        
    }
    if (carry > 0) {
        res = "1" + res;
    }
    return res;
}

/*
 int main() {
 string a = "11";
 string b = "11";
 addBinary(a, b);
 }
 */


/// Description
/// - Parameter x: x description
int mySqrt(int x) {
    int ans = 1;
    for(int i = 1; i <= x; i++) {
        if(i * i <= x) {
            ans = i;
        } else {
            break;
        }
    }
    return ans;
}

/// Description
/// - Parameter x: x description
int mySqrtMethod2(int x) {
    int start = 0;
    int end = x;
    int ans = 0;
    
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if(mid <= x / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}

/*
 int main() {
 int x = 16;
 mySqrtMethod2(x);
 }
 
 */
// MARK: 70. Climbing Stairs

int climbStairs(int n) {
    if (n <= 0) {
        return 0;
    } else if (n == 1) {
        return 1;
    } else if (n == 2) {
        return 2;
    } else {
        return climbStairs(n - 1) + climbStairs(n - 2);
    }
}

/*
 int main() {
     int n = 3;
     int a = climbStairs(n);
     printf("%d ", a);
 }
 */


// MARK: 83. Remove Duplicates from Sorted List


void deleteDuplicates(Node *head, int size) {
    
    struct Node *current = head;
    struct Node *next;
    
    while (current->next != NULL) {
        if(current->data == current->next->data) {
            next = current->next->next;
            free(current->next);
            current->next = next;
        } else {
            current = current->next;
        }
    }
    DisplayNode(head);
}

/*
 int main() {
     int arr[] = {1,1,2};
     int size = sizeof(arr) / sizeof(arr[0]);
     struct Node *list = createLinkedList(arr, size);
     deleteDuplicates(list, size);
 }
 */
///Subarray with given sum

/*
 N = 5, S = 12
 A[] = {1,2,3,7,5}
 Output: 2 4
 */

void subarraySum(int arr[], int size, int target) {
   
    int sum = 0;
    int start = 0;
    for(int i = 0; i < size; i++) {
        while (sum > target && start < i) {
            sum = sum - arr[start];
            start++;
        }
        if(sum == target) {
            printf("%d %d", start, i);
            break;
        }
        sum = sum + arr[i];
    }
}
/*
 int main() {
     int arr[] = {1,2,3,7,5};
     int sum = 12;
     int size = sizeof(arr) / sizeof(arr[0]);
     subarraySum(arr, size, sum);
 }
 
 */
///560. Subarray Sum Equals K
/*
 Input: nums = [1,2,3], k = 3
 Output: 2
 */

int toatlSubarraySum(int arr[], int size, int k) {
    int sum = arr[0];
    int count = 0;
    for(int i = 1; i < size; i++) {
        int start = 0;
        
        while (sum > k && start < size) {
            sum = sum - arr[start];
            start++;
        }
        if(sum == k) {
            count += 1;
            printf("%d ", count);
        }
        sum += arr[i];
    }
    return 0;
}

/*
 int main() {
     int arr[] = {1,2,3,7,5};
     int sum = 12;
     int size = sizeof(arr) / sizeof(arr[0]);
     toatlSubarraySum(arr, size, sum);
 }

 */

// MARK: Merge Sorted Array:

void merge(vector<long>& nums1, long m, vector<long>& nums2, long n) {
    int i = 0;
    int j = 0;
    int k = 0;
    long arrs[m + n];
    while (i < m) {
        arrs[k++] = nums1[i++];
    }
    while (j < n) {
        arrs[k++] = nums2[j++];
    }
    
    for (long l = 0; l < n + m; l++) {
        printf("%ld ", arrs[l]);
    }
}

 int main() {
     vector<long>arr1 = {1,2,3,0,0,0};
     long m = arr1.size();
     vector<long>arr2 = {2,5,6};
     long n = arr2.size();
     merge(arr1, m, arr2, n);
     
 }
