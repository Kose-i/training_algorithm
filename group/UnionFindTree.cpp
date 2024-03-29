struct UnionFind {
   vector<int> vec;
   int n_;
   
   UnionFind(const int& n) : n_(n), vec(n) {
     for (int i=0;i<n;++i) vec[i] = i;
   }
   void merge(const int& l, const int& r) {
     int lf = find(l);
     int rf = find(r);
     if (lf < rf) vec[rf] = lf;
     else vec[lf] = rf;
   }
   int find(const int& idx) {
     if (vec[idx] != idx) return vec[idx] = find(vec[idx]);
     return idx;
   }
   bool is_same(const int& l, const int& r) {
     return find(l) == find(r);
   }
 };
