
#include <iostream>
#include <algorithm>
using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int value) : data(value), left(nullptr), right(nullptr) {}
};

class Node
{
public:
    TreeNode *data;
    Node *next;

    Node(TreeNode *value) : data(value), next(nullptr) {}
};

class Queue
{
private:
    Node *front;
    Node *rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    bool isEmpty()
    {
        return (front == nullptr);
    }

    void enqueue(TreeNode *item)
    {
        Node *newNode = new Node(item);
        newNode->next = nullptr;

        if (front == nullptr)
        {
            front = newNode;
            rear = newNode;
        }
        else
        {
            rear->next = newNode;
            rear = newNode;
        }
    }

    TreeNode *dequeue()
    {
        if (isEmpty())
        {
            cerr << "Error: Queue is empty." << endl;
            return nullptr;
        }

        Node *temp = front;
        TreeNode *item = temp->data;

        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next;
        }

        delete temp;
        return item;
    }
};

class BinaryTree
{
private:
    TreeNode *root;

public:
    BinaryTree() : root(nullptr) {}
    void run();

    TreeNode *insert(int value, TreeNode *node)
    {
        if (node == nullptr)
        {
            return new TreeNode(value);
        }

        if (value < node->data)
        {
            node->left = insert(value, node->left);
        }
        else
        {
            node->right = insert(value, node->right);
        }

        return node;
    }

    TreeNode *create()
    {
        int n, key;
        cout << "Enter the number of nodes: ";
        cin >> n;

        for (int i = 0; i < n; i++)
        {
            cout << "Enter the data: ";
            cin >> key;
            root = insert(key, root);
        }

        return root;
    }

    void inorder(TreeNode *node)
    {
        if (node != nullptr)
        {
            inorder(node->left);
            cout << "\t" << node->data;
            inorder(node->right);
        }
    }

    TreeNode *search(int key, TreeNode *node)
    {
        while (node != nullptr)
        {
            if (node->data == key)
            {
                return node;
            }
            else if (key < node->data)
            {
                node = node->left;
            }
            else
            {
                node = node->right;
            }
        }

        return nullptr;
    }

    TreeNode *findMin(TreeNode *root)
    {
        while (root->left != nullptr)
        {
            root = root->left;
        }
        return root;
    }
    TreeNode *findMax(TreeNode *root)
    {
        while (root->right != nullptr)
        {
            root = root->right;
        }
        return root;
    }

    TreeNode *deleteNode(TreeNode *root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        if (key < root->data)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->data)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }

            TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    TreeNode *mirror(TreeNode *root)
    {
        if (root == nullptr)
        {
            return nullptr;
        }

        TreeNode *temp = root->left;
        root->left = mirror(root->right);
        root->right = mirror(temp);

        return root;
    }

    TreeNode *copy(TreeNode *original)
    {
        TreeNode *duplicate = nullptr;

        if (original != nullptr)
        {
            duplicate = new TreeNode(original->data);
            duplicate->left = copy(original->left);
            duplicate->right = copy(original->right);
        }

        return duplicate;

    //    TreeNode *copy(TreeNode *original)
    // {
    //     if (original == nullptr)
    //     {
    //         return nullptr;
    //     }

    //     TreeNode *duplicate = new TreeNode(original->data);
    //     duplicate->left = copy(original->left);
    //     duplicate->right = copy(original->right);

    //     return duplicate;
    // }
    }

    int height(TreeNode *node)
    {
        if (node == nullptr || (node->left == nullptr && node->right == nullptr))
        {
            return 0;
        }

        int leftHeight = height(node->left);
        int rightHeight = height(node->right);

        return 1 + max(leftHeight, rightHeight);
    }

    void displayLeafNodes(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if (node->left == nullptr && node->right == nullptr)
        {
            cout << "\t" << node->data;
        }

        displayLeafNodes(node->left);
        displayLeafNodes(node->right);
    }

    void displayParentNodesWithChildren(TreeNode *node)
    {
        if (node == nullptr)
        {
            return;
        }

        if ((node->left != nullptr && node->right == nullptr) || (node->left == nullptr && node->right != nullptr) ||
            (node->left != nullptr && node->right != nullptr))
        {
            cout << "\t" << node->data;

            if (node->left != nullptr)
            {
                cout << "\t" << node->left->data;
            }

            if (node->right != nullptr)
            {
                cout << "\t" << node->right->data;
            }

            cout << endl;
        }

        displayParentNodesWithChildren(node->left);
        displayParentNodesWithChildren(node->right);
    }

    void displayLevelWise()
    {
        TreeNode *temp;
        Queue q1;

        if (root == nullptr)
        {
            return;
        }

        q1.enqueue(root);
        cout << "\n"
             << root->data;

        while (!q1.isEmpty())
        {
            cout << "\n";
            Queue q2;

            while (!q1.isEmpty())
            {
                temp = q1.dequeue();

                if (temp->left != nullptr)
                {
                    q2.enqueue(temp->left);
                    cout << " " << temp->left->data;
                }

                if (temp->right != nullptr)
                {
                    q2.enqueue(temp->right);
                    cout << " " << temp->right->data;
                }
            }

            q1 = q2;
        }
    }
 
};
void BinaryTree :: run()
    {
        int choice, key, cnt;
        TreeNode *result;
        TreeNode *copiedRoot = NULL;
        do
        {
            cout << "\nMain menu:\n"
                 << "1. Create\n"
                 << "2. Insert\n"
                 << "3. Display\n"
                 << "4. Search\n"
                 << "5. Delete\n"
                 << "6. Mirror Image\n"
                 << "7. Maximum\n"
                 << "8. Find Depth\n"
                 << "9. Minimum\n"
                 << "10. Display Tree Level-wise\n"
                 << "11. Display Leaf Nodes\n"
                 << "12. Display Parent Nodes with Children\n"
                 << "13. Create Copy\n"
                 << "14. Exit\n"
                 << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
            case 1:
                root = create();
                break;
            case 2:
                cout << "\nEnter the number to insert: ";
                cin >> key;
                root = insert(key, root);
                break;
            case 3:
                cout << "Binary tree:";
                inorder(root);
                break;
            case 4:
                cout << "\nEnter the node to search: ";
                cin >> key;
                result = search(key, root);
                if (result == nullptr)
                {
                    cout << "\nElement " << key << " not present" << endl;
                }
                else
                {
                    cout << "\nElement " << key << " is present" << endl;
                }
                break;
            case 5:
                cout << "\nEnter the node to delete: ";
                cin >> key;
                root = deleteNode(root, key);
                cout << "\nElement deleted successfully!" << endl;
                break;
            case 6:
                root = mirror(root);
                cout << "\nMirror image of the binary tree:";
                inorder(root);
                break;
            case 7:
                result = findMax(root);
                cout << "\nMaximum is " << result->data << endl;
                break;
            case 8:
                cnt = height(root);
                cout << "\nHeight of tree: " << cnt;
                break;
            case 9:
                result = findMin(root);
                cout << "\nMinimum is " << result->data << endl;
                break;
            case 10:
                cout << "\nLevel-wise display:";
                displayLevelWise();
                break;
            case 11:
                cout << "\nLeaf nodes are:";
                displayLeafNodes(root);
                break;
            case 12:
                cout << "\nParent nodes with child nodes are:";
                displayParentNodesWithChildren(root);
                break;
            case 13:
                cout << "\nCopied tree:";
                TreeNode *copiedRoot = copy(root);
                inorder(copiedRoot);
                break;
            case 14:
                return;
            default:
                cout << "\nInvalid choice! Please enter your choice again." << endl;
            }
        } 
        while (choice != 14);
    }
int main()
{
    BinaryTree binaryTree;
    binaryTree.run();   
    return 0;
}


