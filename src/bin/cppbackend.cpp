#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <queue>

using namespace std;


class hoffmanTree {
  public:

  char data;
  int frequency;
  hoffmanTree *left, *right;

    hoffmanTree(char data, int freq){
      this->data = data;
      this->frequency = freq;
      this->left = nullptr;
      this->right = nullptr;
    }
};

class hoffmanCoding {
  string input, output;
  hoffmanTree *root;

  void printTree(hoffmanTree *root){
      if(!root) return;
        cout << root->data << " : " <<root->frequency<< " - ";
        printTree(root->left);
        printTree(root->right);
      }
    

  //count the frequency of the number
  unordered_map <char, int> frequencyMapping(string &input){
    unordered_map<char, int> frequency;

    for(char character : input){
      frequency[character]++;
    }
    return frequency;
  }

  //build heap from largest to lowest
  hoffmanTree * buildTree(unordered_map<char, int> &frequency){
    struct CompareFrequency {
      bool operator()(hoffmanTree* a, hoffmanTree* b) {
          return a->frequency > b->frequency; // min-heap: smaller frequency = higher priority
      }
    };

    priority_queue<hoffmanTree*, vector<hoffmanTree*>, CompareFrequency> minHeap;
    for(auto pairs : frequency){
      minHeap.push(new hoffmanTree(pairs.first, pairs.second));
    }

    while(minHeap.size() > 1){
      //remove two nodes with the smallest frequency
      hoffmanTree * left = minHeap.top(); minHeap.pop();
      hoffmanTree *right = minHeap.top(); minHeap.pop();

      //create a new node with these two nodes as children
      // and the frequency equal to the sum of their frequencies
      hoffmanTree *newNode = new hoffmanTree('\0', left->frequency + right->frequency);
      newNode->left = left;
      newNode->right = right;

      minHeap.push(newNode);
    }

    hoffmanTree *root = minHeap.top(); // The root of the Huffman tree is the last remaining node in the heap
    printTree(root);

    return minHeap.top();
  }

  // unordered_map<char, string> generateCode(hoffmanTree *root, string str, unordered_map<char, string>& codes){
  // }

  public:
    hoffmanCoding(string input) : input(input), root(nullptr) {
      unordered_map<char, int> frequency = frequencyMapping(input);
      buildTree(frequency);
    }
};

int main(){
  cout<< "hello their! it's backend from c++\n";
  hoffmanCoding hCoding("hello world how are you this is the heap head and the tail of the heap");
  return 0;
}