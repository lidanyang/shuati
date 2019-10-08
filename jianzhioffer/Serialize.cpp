//
// Created by LENOVO on 2019/10/8.
//
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    char *Serialize(TreeNode *root) {
        queue<TreeNode *> q;
        stringstream s;
        if (!root) {
            s << "#!";
            char *res = new char[1024];
            s.str().copy(res, s.str().size(), 0);
            res[s.str().size() + 1] = '\0';
            return res;
        }
        q.push(root);
        s << root->val;
        int count = 1;
        int i = 0;
        bool flag = false;
        while (!q.empty()) {
            i++;
            TreeNode *t = q.front();
            q.pop();

            if (t && t->left) {
                s << " " << t->left->val;
                q.push(t->left);
                flag = true;
            } else {
                s << " #";
                q.push(NULL);
            }
//            cout << s.str() <<endl;
            if (t && t->right) {
                s << " " << t->right->val;
                q.push(t->right);
                flag = true;
            } else {
                s << " #";
                q.push(NULL);
            }
//            cout << s.str() <<endl;
            if (i == count) {
                count = q.size();
                i = 0;
                if (!flag)
                    break;
                flag = false;
            }
//            cout << s.str() <<endl;
        }
        s << '!';
//        cout << s.str().c_str() << endl;
        char *res = new char[s.str().size() + 1];
        s.str().copy(res, s.str().size(), 0);
        res[s.str().size()] = '\0';
        return res;
    }

    TreeNode *Deserialize(char *str) {
        stringstream in(str);
        vector<TreeNode *> v;
        if (str[0] == '#')
            return NULL;
        string outstr;

        while (in >> outstr) {
            if (outstr != "#" && outstr != "#!") {
//                cout << outstr << endl;
                TreeNode *t = new TreeNode(atoi(outstr.c_str()));
                v.push_back(t);
                int parent = v.size() / 2 - 1;
                if (parent >= 0 && 2 * parent + 1 == v.size() - 1) {
                    if (v[parent]) v[parent]->left = t;
                } else if (parent >= 0) {
                    if (v[parent]) v[parent]->right = t;
                }
            } else {
//                cout << outstr << endl;
                TreeNode *t = NULL;
                v.push_back(t);
                int parent = v.size() / 2 - 1;
                if (2 * parent + 1 == v.size() - 1) {
                    if (v[parent]) v[parent]->left = t;
                } else {
                    if (v[parent]) v[parent]->right = t;
                }
            }
        }
        return v[0];
    }
};

TreeNode *buildTree(){
    char n[64] = {0};
    scanf("%s", &n);
    getchar();
    if(n[0] == '#')
        return NULL;
    else{
        TreeNode *t = new TreeNode(atoi(n));
        t->left = buildTree();
        t->right = buildTree();
        return t;
    }
}

#if 0
class Solution {
public:
    char* Serialize(TreeNode *root) {
        ostringstream out;
        if(root){
            queue<TreeNode* > q;
            q.push(root);
            while(!q.empty()){
                TreeNode* p = q.front();
                q.pop();
                if(p){
                    out << p->val << " "; // stream默认以空格作为分隔符
                    q.push(p->left);
                    q.push(p->right);
                }else{
                    out << "# ";
                }
            }
        }
        char* res = new char[out.str().length()+1];
        strcpy(res, const_cast<char*>(out.str().c_str()));
        return res;
    }
    TreeNode* Deserialize(char *data) {
        istringstream in(data);
        string node_str;
        if(!(in >> node_str)){
            return NULL;
        }
        TreeNode* root = new TreeNode(atoi(node_str.c_str()));
        TreeNode* node = root;
        queue<TreeNode* > q;
        q.push(node);
        while(!q.empty()){
            TreeNode* p = q.front();
            q.pop();
            // 左结点
            if(!(in >> node_str)){
                break;
            }
            if(node_str != "#"){
                node = new TreeNode(atoi(node_str.c_str()));
                p->left = node;
                q.push(node);
            }
            // 右结点
            if(!(in >> node_str)){
                break;
            }
            if(node_str != "#"){
                node = new TreeNode(atoi(node_str.c_str()));
                p->right = node;
                q.push(node);
            }
        }
        return root;
    }
};
#endif

int main(){
//    TreeNode *root = buildTree();
    Solution s;
//    char * res = s.Serialize(root);
//    cout << res << endl;
    TreeNode *t = s.Deserialize("8 6 10 5 7 9 11 # # # # # # # #!fdsaf");
//    res = s.Serialize(t);
//    cout << res << endl;
    return 0;
}

