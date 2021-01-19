
#include <iostream>
#include <vector>
// I have implemented a basic binary tree structure which is not sorted in order to try my function. 
// Basically we will determine where any node will be put for the construction of the structure.
// I am imitating the binary tree given as an example in the readme file.

static int max = 0;
static std::vector<int> list;

class Node {

public:
	int data;
	Node* right;
	Node* left;
	
	Node(int dataIn) :data(dataIn), right(nullptr), left(nullptr) {}

};

// since this is not the conventional binary tree in which smaller values are assigned to the left of the node
// and bigger values are assigned to the right of the node, insert functions are manual and we determine where to put.
	void Insert_to_left(Node* head,Node* node) {
		if (!head->left) {
			head->left = node;
		}
		else {
			std::cout << "No space on the left" << std::endl;
		}
	}

	void Insert_to_right(Node* head, Node* node) {
		if (!head->right) {
			head->right = node;
		}
		else {
			std::cout << "No space on the right" << std::endl;
		}
	}
/////////////////////////////////////////////

	

	std::vector<int> Largest(Node* pRoot, Node* head,std::vector <int> branch,int sum= 0) {
	
		 sum+= head->data;
		branch.push_back(sum);
		int max = 0;
		std::vector <int> Rbranch=branch, Lbranch=branch;
		if (head->right != nullptr) {
			 Rbranch = Largest(head,head->right,branch,sum);
		}
		if (head->left != nullptr) {
			 Lbranch = Largest(head,head->left,branch,sum);
		}

		int Rsum = Rbranch.back();
		int Lsum = Lbranch.back();
		if (Rsum > Lsum) { branch = Rbranch; }
		else { branch = Lbranch; }

		if (head == pRoot) {
			std::cout << "Branch with the maximum sum is: ";
			for (int i = 0; i < branch.size(); i++) {
				if (!i) {
					std::cout << branch[i] << " ";
				}
				else {
					std::cout << branch[i] - branch[i - 1]<< " ";
				}
			}
			std::cout << "-> SUM = " << branch.back() << std::endl;
		}
     
		return branch;
}





void main()
{
	Node* pRoot = new Node(5);
	
	// left branch of the root
	Insert_to_left(pRoot, new Node(4));
	Insert_to_left(pRoot->left, new Node(11));
	Insert_to_left(pRoot->left->left, new Node(7));
	Insert_to_right(pRoot->left->left, new Node(2));


	// right branch of the root
	Insert_to_right(pRoot, new Node(8));
	Insert_to_right(pRoot->right, new Node(4));
	Insert_to_left(pRoot->right, new Node(13));
	Insert_to_right(pRoot->right->right, new Node(1));

	// Function will print out the branch which has maximum sum.
	std::vector <int> branch;
	Largest(pRoot, pRoot, branch);
}