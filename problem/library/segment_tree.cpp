#include <iostream>
#include <vector>
#include <functional>

/*
Build  O(n log n)
Search O(log n)
*/
template<typename T>
class segment_tree {

  private:
    int tree_node_size;
    int val_idx;
    std::vector<T> segment_data;
    std::function<T(T, T)> op;
    T initialize_val;

    T search_helper(const int& left, const int& right, const int& limit_left, const int& limit_right, const int& idx) {//[left, right]
      //op(segment_tree[left:right])
      if (left<=limit_left && limit_right<=right) return segment_data[idx];
      else if (right<limit_left) return initialize_val;
      else if (limit_right<left) return initialize_val;
      //std::cout << limit_left <<':'<< limit_right << '\n';
      return op(search_helper(left, right, limit_left, (limit_left+limit_right)/2, idx*2+1), search_helper(left, right, (limit_left+limit_right)/2+1, limit_right, idx*2+2));
    }
  public:
    //void print() {
    //  std::cout << "seg-data:";
    //  for (auto i = 0;i < tree_node_size;++i) {
    //    std::cout << segment_data[i] << ' ';
    //  }
    //  std::cout << '\n';
    //}
    segment_tree(const int& n, const T& init_val, std::function<T(T, T)> f) :tree_node_size(0), op(f), initialize_val(init_val) {
      int cnt {1};
      tree_node_size += cnt;
      val_idx = 1;
      while (cnt<=n) {
        cnt<<=1;
        val_idx = tree_node_size;
        tree_node_size += cnt;
      }
      segment_data.reserve(tree_node_size);
      for (auto i = 0;i < tree_node_size;++i) {
        segment_data[i] = initialize_val;
      }
    }
    void init_set_data(std::vector<T>& val) {
      for (auto i = 0;i < val.size();++i) {
        segment_data[val_idx+i] = val[i];
        update(i, val[i]);
      }
    }
    void update(const int& idx, const T& val) {
      int update_index = idx + val_idx;
      segment_data[update_index] = val;
      while (update_index != 0) {
        update_index = update_index/2;
        if (op(segment_data[update_index*2+1], segment_data[update_index*2+2]) != segment_data[update_index]) {
          segment_data[update_index] = op(segment_data[update_index*2+1], segment_data[update_index*2+2]);
        } else {
          break;
        }
      }
    }
    T search(const int& left, const int& right) {
      return search_helper(left, right, 0, tree_node_size-val_idx, 0);
    }
};

//int main(int argc, char** argv) {
//
//  std::function<int(int,int)> max_func = [](int a, int b){return std::max(a,b);};
//  segment_tree<int> segtree(3,0,max_func);
//  std::vector<int> t {3, 2, 1};
//
//  segtree.init_set_data(t);
//
//  std::cout << segtree.search(0, 3) << '\n';
//}
