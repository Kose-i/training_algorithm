#include <iostream>
#include <vector>
#include <functional>

template<typename T>
struct SegmentTree {
    SegmentTree(const int& n, const T& init_): vec(2*n, init_), init_val(init_) {
        int x = 1;
        while (n > x) {
            x *= 2;
        }
        leaf_size = x;
    }
    void update(int pos, T val) {
        pos += leaf_size - 1;
        vec[pos] = val;
        while (pos > 0) {
            pos = (pos - 1) / 2; // parent
            vec[pos] = op(vec[pos*2 + 1], vec[pos*2 + 2]);
        }
    }

    T query(int left, int right) {return query_sub(left, right, 0, 0, leaf_size);}
    private:
    T query_sub(int a, int b, int k, int l, int r) {
        if (r <= a || b <= l) return init_val;
        if (a <= l && r <= b) return vec[k];
        T vl = query_sub(a, b, k*2 + 1, l, (l+r)/2);
        T vr = query_sub(a, b, k*2 + 2, (l+r)/2, r);
        return op(vl, vr);
    }
    std::vector<T> vec;
    const T init_val;
    std::function<T(T, T)> op = [](T l, T r) {return std::min(l, r);};
    int leaf_size; // children cnt
};

int main(int argc, char** argv) {
    std::function<int(int, int)> op = [](int a, int b) {return a;};
    SegmentTree<int> segtree(4, 1001001);
}
