static const int _=[]{ios::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class RandomizedSet {
public:
  RandomizedSet() {
  }
  bool insert(int val) {
    if (hash.find(val) == hash.end()) {
      vect.push_back(val);
      hash[val] = vect.size() - 1;
      return true;
    }
    return false;
  }
  bool remove(int val) {
    auto node = hash.find(val);
    if (node != hash.end()) {
      int pos = node->second;

      swap(vect[pos], vect.back());
      hash[vect[pos]] = pos;

      vect.erase(vect.end() - 1);
      hash.erase(node);

      return true;
    }
    return false;
  }
  int getRandom() {
    return vect[rand() % vect.size()];
  }
private:
  vector<int> vect;
  unordered_map<int, int> hash;
};