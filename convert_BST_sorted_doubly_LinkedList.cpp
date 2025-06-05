#include<iostream> 

using namespace std; 

class Node{
public: 
    int val; 
     Node* left; 
     Node* right; 
     Node(): val(0), left(nullptr), right(nullptr){}
     Node(int _val): val(_val), left(nullptr), right(nullptr){}
     Node(int _val , Node* _left, Node* _right): val(_val), left(_left), right(_right){}
};
class Solution{
private: 

       Node* head; 
       Node* prev; 
       void inOrder(Node* node){
         if(!node) return; 
         inOrder(node->left); 
         if(prev){
           prev->right = node; 
           node->left = prev; 
         }else{
           head= node; 
         }
         prev = node; 
         inOrder(node->right); 
       }
public: 
      Node* treeToDoublyList(Node* root){
        if(!root) return nullptr; 
        prev = nullptr; 
        head = nullptr; 
        inOrder(root); 
        prev->right= head; 
        head->left = prev; 
        return head; 
        
      }
};
int main(){
  /*
         4
        / \
       2   5
      / \
     1   3
    */

    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(5);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    Solution sol;
    Node* head = sol.treeToDoublyList(root);

    // Print circular doubly linked list (first 6 nodes to show the cycle)
    Node* curr = head;
    for (int i = 0; i < 6; ++i) {
        cout << curr->val << " ";
        curr = curr->right;
    }

    return 0;
}
  
