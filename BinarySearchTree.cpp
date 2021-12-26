#include <iostream>
#include <vector>
#define SPACE 10
using namespace std;
class TreeNode
{
public:
    int value;
    TreeNode *left;
    TreeNode *right;
    TreeNode()
    {
        value = 0;
        left = NULL;
        right = NULL;
    }
    TreeNode(int v)
    {
        value = v;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    TreeNode *root;
    BST()
    {
        root = NULL;
    }
    bool isTreeEmpty()
    {
        if (root == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    void insertNode(TreeNode *new_node)
    {
        if (root == NULL)
        {
            root = new_node;
            cout << "Value Inserted as root node!" << endl;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (new_node->value == temp->value)
                {
                    cout << "Value Already exist,"
                         << "Insert another value!" << endl;
                    return;
                }
                else if (new_node->value < temp->value && (temp->left == NULL))
                {
                    temp->left = new_node;
                    cout << "Value Inserted to the left!" << endl;

                    break;
                }
                else if (new_node->value < temp->value)
                {
                    temp = temp->left;
                }
                else if (new_node->value > temp->value && (temp->right == NULL))
                {
                    temp->right = new_node;
                    cout << "Value Inserted to the right!" << endl;
                    break;
                }
                else
                {
                    temp = temp->right;
                }
            }
        }
    }
    //insert recursive
    TreeNode *insertRecursive(TreeNode *r, TreeNode *new_node)
    {
        if (r == NULL)
        {
            r = new_node;
            cout << "Insertion successful" << endl;
            return r;
        }
        if (new_node->value < r->value)
        {
            r->left = insertRecursive(r->left, new_node);
        }
        else if (new_node->value > r->value)
        {
            r->right = insertRecursive(r->right, new_node);
        }
        else
        {
            cout << "No duplicate values allowed!" << endl;
            return r;
        }
        return r;
    }
    void print2D(TreeNode *r, int space)
    {
        if (r == NULL) // Base case  1
            return;
        space += SPACE;           // Increase distance between levels   2
        print2D(r->right, space); // Process right child first 3
        cout << endl;
        for (int i = SPACE; i < space; i++) // 5
            cout << " ";                    // 5.1
        cout << r->value << "\n";           // 6
        print2D(r->left, space);            // Process left child  7
    }
    //NLR
    void printPreorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        cout << r->value << " ";
        printPreorder(r->left);
        printPreorder(r->right);
    }
    //LNR
    void printInorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        printInorder(r->left);
        cout << r->value << " ";
        printInorder(r->right);
    }
    //LRN
    void printPostorder(TreeNode *r)
    {
        if (r == NULL)
            return;
        printPostorder(r->left);
        printPostorder(r->right);
        // now node last
        cout << r->value << " ";
    }
    TreeNode *iterativeSearch(int v)
    {
        if (root == NULL)
        {
            return root;
        }
        else
        {
            TreeNode *temp = root;
            while (temp != NULL)
            {
                if (v == temp->value)
                {
                    return temp;
                }
                else if (v < temp->value)
                {
                    temp = temp->left;
                }
                else
                {
                    temp = temp->right;
                }
            }
            return NULL;
        }
    }

    TreeNode *recursiveSearch(TreeNode *r, int val)
    {
        if (r == NULL || r->value == val)
            return r;
        else if (val < r->value)
            return recursiveSearch(r->left, val);
        else
            return recursiveSearch(r->right, val);
    }
    int height(TreeNode *r)
    {
        if (r == NULL)
            return -1;
        else
        {
            // compute height of each subtree
            int lheight = height(r->left);
            int rheight = height(r->right);
            //use larger one
            if (lheight > rheight)
                return (lheight + 1);
            else
                return (rheight + 1);
        }
    }

    //print nodes of a given level
    void printGivenLevel(TreeNode *r, int level)
    {
        if (r == NULL)
            return;
        else if (level == 0)
            cout << r->value << " ";
        else //level > 0
        {
            printGivenLevel(r->left, level - 1);
            printGivenLevel(r->right, level - 1);
        }
    }
    void printLevelOrderBFS(TreeNode *r)
    {
        int h = height(r);
        for (int i = 0; i <= h; i++)
            printGivenLevel(r, i);
    }

    TreeNode *minValueNode(TreeNode *node)
    {
        TreeNode *current = node;
        //loop down to find the leftmost leaf
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current;
    }
    TreeNode *deleteNode(TreeNode *r, int v)
    {
        // base case
        if (r == NULL)
        {
            return NULL;
        }
        //if the key is smaller than the roots key then it lies in left subtree
        else if (v < r->value)
        {
            r->left = deleteNode(r->left, v);
        }
        //if the key to be deleted is greater than the roots key
        else if (v > r->value)
        {
            r->right = deleteNode(r->right, v);
        }
        //if the key is same as roots key, then this is the node to be deleted
        else
        {
            //node with only one child or no child
            if (r->left == NULL)
            {
                TreeNode *temp = r->right;
                delete r;
                return temp;
            }
            else if (r->right == NULL)
            {
                TreeNode *temp = r->left;
                delete r;
                return temp;
            }
            else
            {
                //node w/ 2 children; get the smallest in right subtree
                TreeNode *temp = minValueNode(r->right);
                //copy the uccessor node to this node
                r->value = temp->value;
                //delete the inorder successor
                r->right = deleteNode(r->right, temp->value);
            }
        }
        return r;
    }

    vector<int> branchSums(TreeNode *root)
    {
        vector<int> sums;
        calculateBranchSums(root, 0, sums);
        return sums;
    }

    void calculateBranchSums(TreeNode *node, int runningSum, vector<int> &sums1)
    {
        if (node == nullptr)
            return;

        int newRunningSum = runningSum + node->value;
        cout << newRunningSum << endl;
        if (node->left == nullptr && node->right == nullptr)
        {
            sums1.push_back(newRunningSum);
            return;
        }
        calculateBranchSums(node->left, newRunningSum, sums1);
        calculateBranchSums(node->right, newRunningSum, sums1);
    }
};

int main()
{
    BST obj;
    int option, val;

    do
    {
        cout << "What operation do you want to perform? "
             << " Select Option number. Enter 0 to exit." << endl;
        cout << "1. Insert Node" << endl;
        cout << "2. Search Node" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Print/Traversal BST values" << endl;
        cout << "5. Height of Tree" << endl;
        cout << "6. Clear Screen" << endl;
        cout << "0. Exit Program" << endl;

        cin >> option;
        //Node n1;
        TreeNode *new_node = new TreeNode();

        switch (option)
        {
        case 0:
            break;
        case 1:
            cout << "INSERT" << endl;
            cout << "Enter VALUE of TREE NODE to INSERT in BST: ";
            cin >> val;
            new_node->value = val;
            obj.root = obj.insertRecursive(obj.root, new_node);
            obj.insertNode(new_node);
            cout << endl;
            break;

        case 2:
            cout << "SEARCH" << endl;
            cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            new_node = obj.recursiveSearch(obj.root, val);
            if (new_node != NULL)
            {
                cout << "Value found" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 3:
            cout << "DELETE" << endl;
            cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
            cin >> val;
            new_node = obj.iterativeSearch(val);
            if (new_node != NULL)
            {
                obj.deleteNode(obj.root, val);
                cout << "Value Deleted" << endl;
            }
            else
            {
                cout << "Value NOT found" << endl;
            }
            break;
        case 4:
            cout << "PRINT 2D: " << endl;
            obj.print2D(obj.root, 5);
            cout << endl;
            cout << "Print Level Order BFS: \n";
            obj.printLevelOrderBFS(obj.root);
            cout << endl;
            cout << "PRE-ORDER: ";
            obj.printPreorder(obj.root);
            cout << endl;
            cout << "IN-ORDER: ";
            obj.printInorder(obj.root);
            cout << endl;
            cout << "POST-ORDER: ";
            obj.printPostorder(obj.root);
            break;
        case 5:
            cout << "TREE HEIGHT" << endl;
            cout << "Height : " << obj.height(obj.root) << endl;
            break;
        case 6:
            system("cls");
            break;
        case 7:
            obj.branchSums(obj.root);
        default:
            cout << "Enter Proper Option number " << endl;
        }

    } while (option != 0);

    return 0;
}
