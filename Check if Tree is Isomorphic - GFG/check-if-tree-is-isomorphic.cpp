//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/

class Solution{
  public:
    // Return True if the given trees are isomotphic. Else return False.
    bool isIsomorphic(Node *root1,Node *root2)
    {
       // Both roots are NULL, trees isomorphic by definition 
         if (root1 == NULL && root2 == NULL) 
            return true; 
  
 // Exactly one of the root1 and root2 is NULL, trees not isomorphic 
         if (root1 == NULL || root2 == NULL) 
            return false; 
            
         if (root1->data != root2->data) 
    return false; 
  
 // There are two possible cases for root1 and root2 to be isomorphic 
 // Case 1: The subtrees rooted at these nodes have NOT been "Flipped". 
 // Both of these subtrees have to be isomorphic, hence the && 
 // Case 2: The subtrees rooted at these nodes have been "Flipped" 
bool a = isIsomorphic(root1->left,root2->left) && isIsomorphic(root1->right,root2->right);//mano same hi h nodes 
bool b = isIsomorphic(root1->left,root2->right) && isIsomorphic(root1->right,root2->left);//swap krne ki jrurt pdi to 
 return a || b;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s1,s2;
		getline(cin,s1);
		getline(cin,s2);
		Node* root1 = buildTree(s1);
		Node* root2 = buildTree(s2);
		Solution obj;
		if(obj.isIsomorphic(root1,root2))
		    cout<<"Yes"<<endl;
		else
		    cout<<"No"<<endl;
    }
    return 0;
}

// } Driver Code Ends