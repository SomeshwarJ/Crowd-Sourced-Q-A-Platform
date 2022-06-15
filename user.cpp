#include <bits/stdc++.h>
using namespace std;
template <typename T>
class User{
    struct node{
        string name, pass;
        node *left, *right;
        int height;
        node(string n, string p, node *l, node *r, int h):name(n), pass(p), left(l), right(r), height(h){}
    };
    node *root;
    int height(node *t);
    void insert(string n, string p, node *&t);
    int search(string n, node *t);
    void print(node *t);
    void srl(node *&t);
    void srr(node *&t);
    void drl(node *&t);
    void drr(node *&t);
    public:
        User(){
            root = NULL;
        }
        void insert(string n, string p){
            insert(n, p, root);
        }
        int search(string n){
            return search(n, root);
        }
        void print(){
            print(root);
        }
};
template <typename T>
void User<T>::print(node *t){
    if (t!=NULL){
        print(t->left);
        cout << t->name << " " << t->pass << endl;
        print(t->right);
    }
}
template <typename T>
int User<T>::search(string n, node *t){
    if (t==NULL){
        // cout << "Not found" << endl;
        return 0;
    }
    else if (t->name==n){
        //cout << "The name " << n << " is found" << endl;
        return 1;
    }
    else if (n<t->name){
        return search(n, t->left);
    }
    else if (n>t->name){
        return search(n, t->right);
    }
    return 0;
}
template <typename T>
int User<T>::height(node *t){
    return t == NULL ? -1 : t->height;
}
template <typename T>
void User<T>::srl(node *&t){
    node *k = t->left;
    t->left = k->right;
    k->right = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    k->height = max(height(k->left), height(k->right)) + 1;
    t = k;
}
template <typename T>
void User<T>::srr(node *&t){
    node *k = t->right;
    t->right = k->left;
    k->left = t;
    t->height = max(height(t->left), height(t->right)) + 1;
    k->height = max(height(k->left), height(k->right)) + 1;
    t = k;
}
template <typename T>
void User<T>::drl(node *&t){
    srr(t->left);
    srl(t);
}
template <typename T>
void User<T>::drr(node *&t){
    srl(t->right);
    srr(t);
}
template <typename T>
void User<T>::insert(string n, string p, node *&t){
    if (t==NULL){
        t = new node(n, p, NULL, NULL, -1);
    }
    else if (n<t->name){
        insert(n, p, t->left);
        if (height(t->left)-height(t->right)==2){
            if (n<t->left->name){
                srl(t);
            }
            else{
                drl(t);
            }
        }
    }
    else if (n>t->name){
        insert(n, p, t->right);
        if (height(t->right)-height(t->left)==2){
            if (n>t->right->name){
                srr(t);
            }
            else{
                drr(t);
            }
        }
    }
    else{
        cout << "Name is already exists. Try another name" << endl;
    }
    t->height = max(height(t->left), height(t->right)) + 1;
}