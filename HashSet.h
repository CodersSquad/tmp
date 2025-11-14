
const int SIMPLE = 1;
const int LINEAR_PROBING = 2;
const int ROBIN_HOOD = 3;

struct HashNode {
  int data;
  HashNode* next;
};

class HashSet {
 public:
  HashSet(int capacity, int method = SIMPLE);
  ~HashSet();
  void add(int value);
  void clear();
  bool contains(int value) const;
  void printBucket(int value);
  void printHashSet();
  int hash(int value) const;
 private:
  HashNode** elements; // an array of HashNode* (an array of pointers!)
  int mysize;
  int capacity;
  int method;
  int getIndexOf(int value) const;
  void rehash();
};
