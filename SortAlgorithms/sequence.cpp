#include <vector>
#include <unordered_map>
#include "sorts.h"
#include "prints.h"

using namespace std;

vector<int> compress(vector<int> v) {
    unordered_map<int, int> m;
    vector<int> b = v;
    quick_sort(v);
    print(v);
    for (int &x : b) {
        if (!m.count(x)) {
            m[x] = static_cast<int>(m.size());
        }
    }

    for (int &x : v) {
        x = m[x];
    }
    return v;
}
