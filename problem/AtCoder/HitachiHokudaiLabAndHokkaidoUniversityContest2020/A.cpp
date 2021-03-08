
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
#define  rep(i,n)   for(int i = 0; i < (n); ++i)
#define rrep(i,n)   for(int i = 1; i <= (n); ++i)
#define drep(i,n)   for(int i = (n)-1; i >= 0; --i)
#define srep(i,s,t) for(int i = s; i < t;  ++i)

struct Edge_Param {
  int from_num, to_num;
  int distance;
};
std::istream& operator>>(std::istream& is, Edge_Param& p) {
  return is >> p.from_num >> p.to_num >> p.distance;
}

struct Node_Param {
  int generate_power;
  int charge_power;
  int consume_power;
};

std::istream& operator>>(std::istream& is, Node_Param& p) {
  return is >> p.generate_power >> p.charge_power >> p.consume_power;
}

struct Pattern_Param {
  int x, pattern;
};

std::istream& operator>>(std::istream& is, Pattern_Param& p) {
  return is >> p.x >> p.pattern;
}

struct Pair {
  int x, y;
};
struct power_status {
  int actual, excess, buy;
};

struct Status {
  Status(int n_grid, int n_ev) {
    rep(i, n_grid) {
      Pair tmp;
      cin >> tmp.x >> tmp.y;
      pent.push_back(tmp);
      power_status tmp_power_state;
      cin >> tmp_power_state.actual >> tmp_power_status.excess >> tmp_power_status.buy;
      power_state.push_back(tmp_power_state);
    }
    rep(i, n_ev) {
      int tmp;
      cin >> tmp;
      carinfo.push_back(tmp);
    }
  }
  std::vector<Pair> pent;
  std::vector<power_status> power_state;
  std::vector<int> carinfo;
};

int main(int argc, char** argv) {
  int node_cnt, edge_cnt;
  cin >> node_cnt >> edge_cnt;

  std::vector<Edge_Param> edges(edge_cnt);
  rep(i, edge_cnt) {
    cin >> edges[i];
  }

  std::vector<Node_Param> nodes(node_cnt);
  rep(i, node_cnt) {
    cin >> nodes[i];
  }

  char day_type {};
  cin >> day_type;

  int n_constant, n_pattern, sigma_power, delta_event;
  double p_event;
  cin >> n_constant >> n_pattern >> sigma_power >> p_event >> delta_event;

  std::vector<std::vector<int>> predict_power(n_pattern, std::vector<int>(n_constant));

  rep(i, n_pattern) {
    rep(j, n_constant) {
      cin >> predict_power[i][j];
    }
  }

  int n_grid, c_init, c_max, v_max, delta_move;
  cin >> n_grid>> c_init>> c_max>> v_max >> delta_move;

  std::vector<Pattern_Param> patterns(n_grid);
  rep(i, n_grid) {
    cin >> patterns[i];
  }
  int n_ev, c_init_ev, c_max_ev, v_max_ev, delta_move_ev;
  cin >> n_ev>> c_init_ev>> c_max_ev>> v_max_ev>> delta_move_ev;

  std::vector<int> pos(n_ev);
  rep(i, n_ev) {
    cin >> pos[i];
  }

  double gamma;
  int T_max;
  cin >> gamma >> T_max;

  rep(i, T_max-1) {
    Status prev_status(n_grid, n_ev);
    prev_status;
  }

}
