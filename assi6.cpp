
#include <iostream>
#include <stack>
#include <cctype>
using namespace std;

class TreeNode
{
public:
    char val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(char value)
    {
        val = (value);
        left = (nullptr);
        right = (nullptr);
    }
};

class Solution
{
public:
    TreeNode* createTree(const string& exp)
    {
        stack<TreeNode*> st;

        for (char c : exp)
        {
            if (isalpha(c))
            {
                TreeNode* newNode = new TreeNode(c);
                st.push(newNode);
            }
            else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                TreeNode* right = st.top();
                st.pop();
                TreeNode* left = st.top();
                st.pop();

                TreeNode* newNode = new TreeNode(c);
                newNode->left = left;
                newNode->right = right;

                st.push(newNode);
            }
        }

        if (st.empty())
        {
            return nullptr;
        }
        return st.top();
    }

    void printInorderRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        printInorderRecursive(root->left);
        cout << root->val << " ";
        printInorderRecursive(root->right);
    }

    void printInorderNonRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode*> st;
        TreeNode* current = root;

        while (current || !st.empty())
        {
            while (current)
            {
                st.push(current);
                current = current->left;
            }

            current = st.top();
            st.pop();
            cout << current->val << " ";
            current = current->right;
        }
    }

    void printPreorderRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        cout << root->val << " ";
        printPreorderRecursive(root->left);
        printPreorderRecursive(root->right);
    }

    void printPreorderNonRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode*> st;
        st.push(root);

        while (!st.empty())
        {
            TreeNode* current = st.top();
            st.pop();

            cout << current->val << " ";

            if (current->right)
            {
                st.push(current->right);
            }
            if (current->left)
            {
                st.push(current->left);
            }
        }
    }

    void printPostorderRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }
        printPostorderRecursive(root->left);
        printPostorderRecursive(root->right);
        cout << root->val << " ";
    }

    void printPostorderNonRecursive(TreeNode* root)
    {
        if (root == nullptr)
        {
            return;
        }

        stack<TreeNode*> st1, st2;
        st1.push(root);

        while (!st1.empty())
        {
            TreeNode* current = st1.top();
            st1.pop();
            st2.push(current);

            if (current->left)
            {
                st1.push(current->left);
            }
            if (current->right)
            {
                st1.push(current->right);
            }
        }

        while (!st2.empty())
        {
            cout << st2.top()->val << " ";
            st2.pop();
        }
    }
};

int main()
{
    Solution sol;

    string expression;
    cout << "Enter your expression: ";
    cin >> expression;

    int choice;
    cout << "Choose traversal method:\n1. Inorder\n2. Preorder\n3. Postorder\n";
    cin >> choice;

    TreeNode* root = sol.createTree(expression);

    switch (choice)
    {
    case 1:
        cout << "Inorder Traversal:\n";
        cout << "1. Recursive\n2. Non-Recursive\n";
        int subChoice;
        cin >> subChoice;
        switch (subChoice)
        {
        case 1:
            sol.printInorderRecursive(root);
            cout << endl;
            break;
        case 2:
            sol.printInorderNonRecursive(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
        break;
    case 2:
        cout << "Preorder Traversal:\n";
        cout << "1. Recursive\n2. Non-Recursive\n";
        int subChoice2;
        cin >> subChoice2;
        switch (subChoice2)
        {
        case 1:
            sol.printPreorderRecursive(root);
            cout << endl;
            break;
        case 2:
            sol.printPreorderNonRecursive(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
        break;
    case 3:
        cout << "Postorder Traversal:\n";
        cout << "1. Recursive\n2. Non-Recursive\n";
        int subChoice3;
        cin >> subChoice3;
        switch (subChoice3)
        {
        case 1:
            sol.printPostorderRecursive(root);
            cout << endl;
            break;
        case 2:
            sol.printPostorderNonRecursive(root);
            cout << endl;
            break;
        default:
            cout << "Invalid choice.\n";
            break;
        }
        break;
    default:
        cout << "Invalid choice.\n";
        break;
    }

    return 0;
}



