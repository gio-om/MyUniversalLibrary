#include <vector>
#include <stack>
#include <cmath>
#include <queue>

using namespace std;

void bubble_sort(vector<int> &v) {
    /* This algorithm compares two adjacent elements and swap them if v[i] > v[i + 1]
     * Time complexity: O(n^2) */
    size_t n = v.size();
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n - k - 1; ++i) {
            if (v[i] > v[i + 1]) {
                swap(v[i], v[i + 1]);
            }
        }
    }
}

void selection_sort(vector<int> &v) {
    /* This algorithm searches for minimum in [k, n - 1] and place it in k-position
    * Time complexity: O(n^2) */
        size_t n = v.size();
    for (int k = 0; k < n - 1; ++k) {
        int min_index = k;
        for (int i = k; i < n; ++i) {
            if (v[min_index] > v[i]) {
                min_index = i;
            }
        }
        if (min_index != k) {
            swap(v[k], v[min_index]);
        }
    }
}

void insertion_sort(vector<int> &v) {
    /* On k-step we have sorted [0, k - 1], then we take v[k] and compare with each previous element (k -1 ... 0)
     * When it is less, than swap
     * Time complexity: O(n^2) */
    size_t n = v.size();
    for (int k = 1; k < n; ++k) {
        int i = k;
        while (i > 0 && v[i - 1] > v[i]) {
            swap(v[i], v[i - 1]);
            --i;
        }
    }
}

void heapsort(vector<int> &v) {
    /* We just create a binary heap, it allows us to take min in O(1) and delete/add element in O(log n)
     * We take min every time and delete it
     * Time complexity: O(n log n) */
    size_t n = v.size();
    priority_queue<int, vector<int>, greater<> > q;
    for (auto el : v) {
        q.push(el);
    }

    for (int i = 0; i < n; ++i) {
        v[i] = q.top();
        q.pop();
    }
}

void quick_sort(vector<int> &v) {
    /* We create stack, where we have borders we need to sort (on start 0 and n - 1)
     * We have 2 pointers and compare their elements with middle element (m)
     * Now we get v[i], that is bigger than v[m] and v[j], that is less than v[m] -> swap them
     * Do it while i <= j
     * Add new sort borders in stack
    Time complexity: O(n log n) */
    int l = 0, r = static_cast<int>(v.size()) - 1, m;
    stack<int> st;
    st.push(l);
    st.push(r);

    do {
        r = st.top();
        st.pop();
        l = st.top();
        st.pop();
        m = (l + r) / 2;
        // 10, 4, 2,   1   , 4, 2, 5
        int i = l;
        int j = r;
        int el = v[m];
        do {
            while(v[i] < el) {
                ++i;
            }
            while (v[j] > el) {
                --j;
            }

            if (i <= j) {
                swap(v[i], v[j]);
                ++i;
                --j;
            }
        } while (i <= j);

        if (l < j) {
            st.push(l);
            st.push(j);
        }
        if (r > i) {
            st.push(i);
            st.push(r);
        }
    } while (!st.empty());
}

void count_sort(vector<int> &v, int max) {
    /* We create a new array, that will store, how much times i-value was in v
     * Time complexity: O(m + n) m - number of available values */
    vector<int> counters(max);
    for (auto el : v) {
        ++counters[el];
    }

    int k = 0;
    for (int i = 0; i < max; ++i) {
        while(counters[i]--) {
            v[k++] = i;
        }
    }
}

void radix_sort(vector<int> &v, int max_digits) {
    /* We use count_sort for each digit by creating a matrix, where we put elements sorted by cur_digit-digit
     * Than rewrite it in this order to v
     * Repeat this procedure max_digits times
     * Time complexity: O(max_digits (n + key)) */
    int key = 10;
    vector<int> counters[key];
    int cur_digit = 1;
    while (cur_digit <= max_digits) {
        for (int el : v) {
            counters[(el / static_cast<int>(pow(key, cur_digit))) % key].push_back(el);
        }

        int k = 0;
        for (int i = 0; i < key; ++i) {
            for (int j : counters[i]) {
                v[k++] = j;
            }
            counters[i].clear();
        }
        ++cur_digit;
    }
}

void merge_sort(vector<int> &v);  // <- first priority

void bucket_sort(vector<int> &v);

void tree_sort(vector<int> &v);

int binary_search(vector<int> &v, int target) {
    /* Searches for target in sorted array
     * Time complexity: O(log n) */
    int l = 0, r = static_cast<int>(v.size()) - 1, m;
    while (l <= r) {
        m = (l +  r) / 2;
        if (v[m] < target) {
            l = m + 1;
        } else if (v[m] > target) {
            r = m - 1;
        } else {
            return m;
        }
    }
    return -1;
}

int lower_bound(vector<int> &v, int target) {
    /* First index of value, not less than target
     * Time complexity: O(log n) */
    int l = 0, r = static_cast<int>(v.size()), m;
    while (l + 1 < r) {  // Пока не соседние
        m = (l + r) / 2;
        if (target <= v[m]) {
            r = m;
        } else {
            l = m + 1;
        }
    }
    return l;
}


int upper_bound(vector<int> &v, int target) {
    /* First index of value, bigger than target
    * Time complexity: O(log n) */
    int l = 0, r = static_cast<int>(v.size()), m;
    while (l + 1 < r) {
        m = (l + r) / 2;
        if (v[m] <= target) {
            l = m;
        } else {
            r = m;
        }
    }
    return r;
}


