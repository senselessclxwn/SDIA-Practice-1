#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
#include <cctype>
#include <unordered_set>

using namespace std;

void task1() {
    cout << "Task 1: Basic operations analysis" << endl;
    
    vector<int> numbers = {8, 3, 12, 7, 15, 4, 9, 6};
    
    int max_num = numbers[0];
    for (int i = 1; i < numbers.size(); i++) {
        if (numbers[i] > max_num) {
            max_num = numbers[i];
        }
    }
    cout << "Max element: " << max_num << " (O(n))" << endl;
    
    int sum = 0;
    for (int i = 0; i < numbers.size(); i++) {
        sum += numbers[i];
    }
    cout << "Sum: " << sum << " (O(n))" << endl;
    
    int target = 7;
    bool found = false;
    for (int i = 0; i < numbers.size(); i++) {
        if (numbers[i] == target) {
            found = true;
            break;
        }
    }
    cout << "Number " << target << " found: " << (found ? "yes" : "no") << " (O(n))" << endl;
}

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void task2() {
    cout << "Task 2: Sorting algorithms comparison" << endl;
    
    vector<int> arr1 = {64, 34, 25, 12, 22, 11, 90};
    vector<int> arr2 = arr1;
    
    bubbleSort(arr1);
    insertionSort(arr2);
    
    cout << "Bubble sort: ";
    for (int i = 0; i < arr1.size(); i++) {
        cout << arr1[i] << " ";
    }
    cout << "(O(n^2))" << endl;
    
    cout << "Insertion sort: ";
    for (int i = 0; i < arr2.size(); i++) {
        cout << arr2[i] << " ";
    }
    cout << "(O(n^2) worst, O(n) best)" << endl;
}

string secondLargest(vector<string> strs) {
    if (strs.size() < 2) return "";
    
    string first = strs[0];
    string second = "";
    
    for (int i = 1; i < strs.size(); i++) {
        if (strs[i] > first) {
            second = first;
            first = strs[i];
        } else if (strs[i] > second && strs[i] != first) {
            second = strs[i];
        }
    }
    return second;
}

string secondLargestSorted(vector<string> strs) {
    if (strs.size() < 2) return "";
    
    vector<string> temp = strs;
    sort(temp.begin(), temp.end());
    
    string largest = temp[temp.size()-1];
    for (int i = temp.size()-2; i >= 0; i--) {
        if (temp[i] != largest) {
            return temp[i];
        }
    }
    return "";
}

void task3_1() {
    cout << "Task 3.1: Second largest string" << endl;
    
    vector<string> fruits = {"apple", "banana", "cherry", "date", "elderberry"};
    
    string result1 = secondLargest(fruits);
    string result2 = secondLargestSorted(fruits);
    
    cout << "Array: ";
    for (string fruit : fruits) cout << fruit << " ";
    cout << endl;
    
    cout << "Method 1 (O(n)): " << result1 << endl;
    cout << "Method 2 (O(n log n)): " << result2 << endl;
}

bool palindromeTwoPointers(string s) {
    string clean = "";
    for (int i = 0; i < s.length(); i++) {
        if (isalnum(s[i])) {
            clean += tolower(s[i]);
        }
    }
    
    int left = 0;
    int right = clean.length()-1;
    while (left < right) {
        if (clean[left] != clean[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

bool palindromeReverse(string s) {
    string clean = "";
    for (char c : s) {
        if (isalnum(c)) {
            clean += tolower(c);
        }
    }
    
    string reversed = clean;
    reverse(reversed.begin(), reversed.end());
    return clean == reversed;
}

void task3_2() {
    cout << "Task 3.2: Palindrome check" << endl;
    
    string text = "A man, a plan, a canal, Panama";
    
    bool result1 = palindromeTwoPointers(text);
    bool result2 = palindromeReverse(text);
    
    cout << "Text: " << text << endl;
    cout << "Method 1 (O(n)): " << (result1 ? "yes" : "no") << endl;
    cout << "Method 2 (O(n)): " << (result2 ? "yes" : "no") << endl;
}

int uniqueElementsCount(vector<int> nums) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
        bool duplicate = false;
        for (int j = 0; j < i; j++) {
            if (nums[i] == nums[j]) {
                duplicate = true;
                break;
            }
        }
        if (!duplicate) {
            count++;
        }
    }
    return count;
}

int uniqueElementsHash(vector<int> nums) {
    unordered_set<int> unique_set;
    for (int num : nums) {
        unique_set.insert(num);
    }
    return unique_set.size();
}

void task3_3() {
    cout << "Task 3.3: Unique elements count" << endl;
    
    vector<int> nums = {1, 2, 3, 4, 4, 5};
    
    int result1 = uniqueElementsCount(nums);
    int result2 = uniqueElementsHash(nums);
    
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "Method 1 (O(n^2)): " << result1 << endl;
    cout << "Method 2 (O(n)): " << result2 << endl;
}

int missingPositiveBruteForce(vector<int> nums) {
    for (int i = 1; i <= nums.size() + 1; i++) {
        bool found = false;
        for (int num : nums) {
            if (num == i) {
                found = true;
                break;
            }
        }
        if (!found) {
            return i;
        }
    }
    return 1;
}

int missingPositiveOptimized(vector<int> nums) {
    unordered_set<int> num_set;
    for (int num : nums) {
        if (num > 0) {
            num_set.insert(num);
        }
    }
    
    for (int i = 1; i <= nums.size() + 1; i++) {
        if (num_set.find(i) == num_set.end()) {
            return i;
        }
    }
    return 1;
}

void task3_4() {
    cout << "Task 3.4: Smallest missing positive" << endl;
    
    vector<int> nums = {1, 2, 0, -1, 3};
    
    int result1 = missingPositiveBruteForce(nums);
    int result2 = missingPositiveOptimized(nums);
    
    cout << "Array: ";
    for (int num : nums) cout << num << " ";
    cout << endl;
    
    cout << "Method 1 (O(n^2)): " << result1 << endl;
    cout << "Method 2 (O(n)): " << result2 << endl;
}

void showMenu() {
    cout << "Choose task:" << endl;
    cout << "1 - Basic operations" << endl;
    cout << "2 - Sorting algorithms" << endl;
    cout << "3 - Second largest string" << endl;
    cout << "4 - Palindrome check" << endl;
    cout << "5 - Unique elements" << endl;
    cout << "6 - Missing positive" << endl;
    cout << "0 - Exit" << endl;
    cout << "Your choice: ";
}

int main() {
    int choice;
    
    do {
        showMenu();
        cin >> choice;
        
        switch (choice) {
            case 1:
                task1();
                break;
            case 2:
                task2();
                break;
            case 3:
                task3_1();
                break;
            case 4:
                task3_2();
                break;
            case 5:
                task3_3();
                break;
            case 6:
                task3_4();
                break;
            case 0:
                cout << "Exit" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
        cout << endl;
    } while (choice != 0);
}