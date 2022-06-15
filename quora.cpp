#include <bits/stdc++.h>
#include "user.cpp"
#include <string>
using namespace std;
template <typename T>
class Quora{
    struct node{
        T data;
        node *left, *right;
        node(T s, node l, node r):data(s), left(l), right(r){}
        node(){
            left = right = NULL;
        }
    };
    node *root, *nullnode;
    void insert(T x, node *&t);
    void splay(T x, node *&t);
    void answer(node *t);
    void print(node *t);
    void srl(node *&t);
    void srr(node *&t);
    void dis_ques(node *t);
    public:
        Quora(){
            nullnode = new node;
            nullnode->left = nullnode->right = NULL;
            root = nullnode;
        }
        void insert(T x){
            insert(x, root);
        }
        void display(){
            answer(root);
        }
        void dis_ques(){
            dis_ques(root);
        }
};
template <typename T>
void Quora<T>::dis_ques(node *t){
    cout <<root->data<<endl;
}
template <typename T>
void Quora<T>::answer(node *t){
    if (t->left==nullnode && t->right==nullnode){
        cout << "No answers posted till now" << endl;
    }
    else{
        print(t->left);
        print(t->right);
    }
}
static int ans_no = 0;
template <typename T>
void Quora<T>::print(node *t){
    if (t!=nullnode){
        print(t->left);
        cout << "\t\t\t\t\t\t\t\t" << ++ans_no << ") " << t->data << endl;
        print(t->right);
    }
}
template <typename T>
void Quora<T>::srl(node *&t){
    node *k = t->left;
    t->left = k->right;
    k->right = t;
    t = k;
}
template <typename T>
void Quora<T>::srr(node *&t){
    node *k = t->right;
    t->right = k->left;
    k->left = t;
    t = k;
}
template <typename T>
void Quora<T>::splay(T x, node *&t){
    node *ltmax, *rtmin, header;
    ltmax = &header;
    rtmin = &header;
    while (x!=t->data){
        if (x<t->data){
            if (t->left==nullnode){
                break;
            }
            else if (t->left->left!=nullnode && x<t->left->data){
                srl(t);
            }
            rtmin->left = t;
            rtmin = t;
            t = t->left;
        }
        else if (x>t->data){
            if (t->right==nullnode){
                break;
            }
            else if (t->right->right!=nullnode && x>t->right->data){
                srr(t);
            }
            ltmax->right = t;
            ltmax = t;
            t = t->right;
        }
    }
    ltmax->right = t->left;
    rtmin->left = t->right;
    t->left = header.right;
    t->right = header.left;
}
template <typename T>
void Quora<T>::insert(T x, node *&t){
    node *newnode = NULL;
    if (newnode==NULL){
        newnode = new node;
        newnode->data = x;
        newnode->left = newnode->right = nullnode;
    }
    if (root==nullnode){
        root = newnode;
        newnode->left = newnode->right = nullnode;
    }
    else{
        T ques = root->data;
        splay(x, root);
        if (x<root->data){
            newnode->left = root->left;
            newnode->right = root;
            root->left = nullnode;
            root = newnode;
        }
        else if (x>root->data){
            newnode->right = root->right;
            newnode->left = root;
            root->right = nullnode;
            root = newnode;
        }
        splay(ques, root);
    }
}
int main(){
    vector<string> set_ques;
    int choice, qn, log_opt;
	static int ct=0;
    string data, ques, name, pass;
    Quora<string> q[1000];
    User<string> u;
    u.insert("somu", "wjbergg");
    u.insert("surenther", "qjfbwgri");
    u.insert("jothi", "hawjb");
    u.insert("ananthi", "irrviu");
    q[ct].insert("what is unit of length?");
    q[ct].insert("The unit of length is meter");
    q[ct].insert("Unit is meter");
    q[ct].insert("Metre. It's metre");
    ct++;
    q[ct].insert("can we implement oops concept in Java?");
    q[ct].insert("Yes we can implement oops concept in Java");
    q[ct].insert("Yes we can");
    q[ct].insert("absolutely yes");
    q[ct].insert("I think, it is possiible to implement oops in Java");
    ct++;
    q[ct].insert("Is Stranger Things good to watch?");
    q[ct].insert("One of the best series I've watched");
    q[ct].insert("No it's a bad series");
    q[ct].insert("Eagerly waiting to watch 5th season of this season!");
    ct++;
    q[ct].insert("How was your day?");
    q[ct].insert("It's an ordinary day");
    q[ct].insert("This is one of the most memorable day!!");
    q[ct].insert("Not a bad day");
    ct++;
    cout << "\n\n\n\t\t\t\t\t\t\t\tWELCOME TO CROWDSOURCED Q&A PLATFORM" << endl;
    cout << "\n\t\t\t\t\t\t\t\t\t"<<"  "<<"[1] Login\n\t\t\t\t\t\t\t\t\t"<<"  "<<"[2] Signup\n";
    cout << "\n\t\t\t\t\t\t\t\tEnter option: ";
    cin >> log_opt;
    if (log_opt==1){
        cout << "\n\t\t\t\t\t\t\t\t\t"<< "  " <<"LOGIN!\n\n";
        cout << "\t\t\t\t\t\t\t\tEnter your name to login: ";
        cin >> name;
        if (u.search(name)==1){
            cout << "\n\t\t\t\t\t\t\t\tSuccessfully logged in!\n\n";
            while (1){
                cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                cout<<"\t\t\t\t\t\t\t\t[1] Post question \n\t\t\t\t\t\t\t\t[2] Display Question \n\t\t\t\t\t\t\t\t[3] Answer the question \n\t\t\t\t\t\t\t\t[4] See answer for question\n\t\t\t\t\t\t\t\t[5] Exit\n"<<endl;
                cout<<"\t\t\t\t\t\t\t\tEnter choice: ";
                cin>>choice;
                cout << endl;
                if (choice==1){
                    cout << "\t\t\t\t\t\t\t\tAsk a question: ";
                    cin >> ws;
                    getline(cin, ques);
                    q[ct].insert(ques);
                    ct++;
                    set_ques.push_back(ques);
                    cout << endl;
                }
                else if (choice==2){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tThe Questions asked by others"<<endl;
                        for (int i=0; i<ct; i++){
                            cout << "\t\t\t\t\t\t\t\t" << i + 1 << ") ";
                            q[i].dis_ques();
                        }
                    }
                    cout<<endl;
                }
                else if (choice==3){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tEnter question number to post answer: ";
                        cin>>qn;
                        if (qn<ct+1){
                            cout<<"\t\t\t\t\t\t\t\tEnter answer for question "<<qn<<" :";
                            cin>>ws;
                            getline(cin, data);
                            q[qn-1].insert(data);
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                        }
                    }
                    cout << endl;
                }
                else if (choice==4){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tEnter question number to see answer: ";
                        cin>>qn;
                        cout<<endl;
                        cout<<"\t\t\t\t\t\t\t\tThe Question is "<<endl;
                        cout << "\t\t\t\t\t\t\t\t";
                        q[qn-1].dis_ques();
                        cout<<endl;
                        cout<<"\t\t\t\t\t\t\t\tThe answers for this question are "<<endl;
                        if (qn<ct+1){
                            q[qn-1].display();
                            ans_no = 0;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                        }
                    }
                    cout<<endl;
                }
                else if (choice==5){
                    cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                    cout << "\n\t\t\t\t\t\t\t\tThank for visting our platform!";
                    exit(0);
                }
                else{
                    cout<<"\t\t\t\t\t\t\t\tWrong choice"<<endl;
                }
            }
        }
        else{
            cout << "\n\t\t\t\t\t\t\t\tThe Account doesn't exist. Create your new account!\n";
            cout << "\n\t\t\t\t\t\t\t\t\t"<< "  " <<"SIGNUP!\n" << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your name to signup: ";
            cin >> name;
            cout << "\t\t\t\t\t\t\t\tEnter password: ";
            cin >> pass;
            if (u.search(name)!=1){
                u.insert(name, pass);
                cout << "\n\t\t\t\t\t\t\t\tSuccessfully Signed up!\n" << endl;
                while (1){
                    cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                    cout<<"\t\t\t\t\t\t\t\t[1] Post question \n\t\t\t\t\t\t\t\t[2] Display Question \n\t\t\t\t\t\t\t\t[3] Answer the question \n\t\t\t\t\t\t\t\t[4] See answer for question\n\t\t\t\t\t\t\t\t[5] Exit\n"<<endl;
                    cout<<"\t\t\t\t\t\t\t\tEnter choice: ";
                    cin>>choice;
                    cout << endl;
                    if (choice==1){
                        cout << "\t\t\t\t\t\t\t\tAsk a question: ";
                        cin >> ws;
                        getline(cin, ques);
                        q[ct].insert(ques);
                        ct++;
                        set_ques.push_back(ques);
                        cout << endl;
                    }
                    else if (choice==2){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe Questions asked by others"<<endl;
                            for (int i=0; i<ct; i++){
                                cout << "\t\t\t\t\t\t\t\t" << i + 1 << ") ";
                                q[i].dis_ques();
                            }
                        }
                        cout<<endl;
                    }
                    else if (choice==3){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tEnter question number to post answer: ";
                            cin>>qn;
                            if (qn<ct+1){
                                cout<<"\t\t\t\t\t\t\t\tEnter answer for question "<<qn<<" :";
                                cin>>ws;
                                getline(cin, data);
                                q[qn-1].insert(data);
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                            }
                        }
                        cout << endl;
                    }
                    else if (choice==4){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tEnter question number to see answer: ";
                            cin>>qn;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tThe Question is "<<endl;
                            cout << "\t\t\t\t\t\t\t\t";
                            q[qn-1].dis_ques();
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tThe answers for this question are "<<endl;
                            if (qn<ct+1){
                                q[qn-1].display();
                                ans_no = 0;
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                            }
                        }
                        cout<<endl;
                    }
                    else if (choice==5){
                        cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                        cout << "\n\t\t\t\t\t\t\t\tThank for visting our platform!";
                        exit(0);
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tWrong choice\n"<<endl;
                    }
                }
            }
            else{
                cout << "\n\t\t\t\t\t\t\t\tThe account already exists. Create your new account\n";
                cout << "\n\t\t\t\t\t\t\t\t\t"<< "  " <<"SIGNUP!\n" << endl;
                cout << "\t\t\t\t\t\t\t\tEnter your name to signup: ";
                cin >> name;
                cout << "\t\t\t\t\t\t\t\tEnter password: ";
                cin >> pass;
                if (u.search(name)!=1){
                    u.insert(name, pass);
                    cout << "\n\t\t\t\t\t\t\t\tSuccessfully Signed up!\n" << endl;
                    while (1){
                        cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                        cout<<"\t\t\t\t\t\t\t\t[1] Post question \n\t\t\t\t\t\t\t\t[2] Display Question \n\t\t\t\t\t\t\t\t[3] Answer the question \n\t\t\t\t\t\t\t\t[4] See answer for question\n\t\t\t\t\t\t\t\t[5] Exit\n"<<endl;
                        cout<<"\t\t\t\t\t\t\t\tEnter choice: ";
                        cin>>choice;
                        cout << endl;
                        if (choice==1){
                            cout << "\t\t\t\t\t\t\t\tAsk a question: ";
                            cin >> ws;
                            getline(cin, ques);
                            q[ct].insert(ques);
                            ct++;
                            set_ques.push_back(ques);
                            cout << endl;
                        }
                        else if (choice==2){
                            if (ct==0){
                                cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tThe Questions asked by others"<<endl;
                                for (int i=0; i<ct; i++){
                                    cout << "\t\t\t\t\t\t\t\t" << i + 1 << ") ";
                                    q[i].dis_ques();
                                }
                            }
                            cout<<endl;
                        }
                        else if (choice==3){
                            if (ct==0){
                                cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tEnter question number to post answer: ";
                                cin>>qn;
                                if (qn<ct+1){
                                    cout<<"\t\t\t\t\t\t\t\tEnter answer for question "<<qn<<" :";
                                    cin>>ws;
                                    getline(cin, data);
                                    q[qn-1].insert(data);
                                }
                                else{
                                    cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                                }
                            }
                            cout << endl;
                        }
                        else if (choice==4){
                            if (ct==0){
                                cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tEnter question number to see answer: ";
                                cin>>qn;
                                cout<<endl;
                                cout<<"\t\t\t\t\t\t\t\tThe Question is "<<endl;
                                cout << "\t\t\t\t\t\t\t\t";
                                q[qn-1].dis_ques();
                                cout<<endl;
                                cout<<"\t\t\t\t\t\t\t\tThe answers for this question are "<<endl;
                                if (qn<ct+1){
                                    q[qn-1].display();
                                    ans_no = 0;
                                }
                                else{
                                    cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                                }
                            }
                            cout<<endl;
                        }
                        else if (choice==5){
                            cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                            cout << "\n\t\t\t\t\t\t\t\tThank for visting our platform!";
                            exit(0);
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tWrong choice\n"<<endl;
                        }
                    }
                }
            }
        }
    }
    else if (log_opt==2){
        cout << "\n\t\t\t\t\t\t\t\t\t"<< "  " <<"SIGNUP!\n" << endl;
        cout << "\t\t\t\t\t\t\t\tEnter your name to signup: ";
        cin >> name;
        cout << "\t\t\t\t\t\t\t\tEnter password: ";
        cin >> pass;
        if (u.search(name)!=1){
            u.insert(name, pass);
            cout << "\n\t\t\t\t\t\t\t\tSuccessfully Signed up!\n" << endl;
            while (1){
                cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                cout<<"\t\t\t\t\t\t\t\t[1] Post question \n\t\t\t\t\t\t\t\t[2] Display Question \n\t\t\t\t\t\t\t\t[3] Answer the question \n\t\t\t\t\t\t\t\t[4] See answer for question\n\t\t\t\t\t\t\t\t[5] Exit\n"<<endl;
                cout<<"\t\t\t\t\t\t\t\tEnter choice: ";
                cin>>choice;
                cout << endl;
                if (choice==1){
                    cout << "\t\t\t\t\t\t\t\tAsk a question: ";
                    cin >> ws;
                    getline(cin, ques);
                    q[ct].insert(ques);
                    ct++;
                    set_ques.push_back(ques);
                    cout << endl;
                }
                else if (choice==2){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tThe Questions asked by others"<<endl;
                        for (int i=0; i<ct; i++){
                            cout << "\t\t\t\t\t\t\t\t" << i + 1 << ") ";
                            q[i].dis_ques();
                        }
                    }
                    cout<<endl;
                }
                else if (choice==3){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tEnter question number to post answer: ";
                        cin>>qn;
                        if (qn<ct+1){
                            cout<<"\t\t\t\t\t\t\t\tEnter answer for question "<<qn<<" :";
                            cin>>ws;
                            getline(cin, data);
                            q[qn-1].insert(data);
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                        }
                    }
                    cout << endl;
                }
                else if (choice==4){
                    if (ct==0){
                        cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tEnter question number to see answer: ";
                        cin>>qn;
                        cout<<endl;
                        cout<<"\t\t\t\t\t\t\t\tThe Question is "<<endl;
                        cout << "\t\t\t\t\t\t\t\t";
                        q[qn-1].dis_ques();
                        cout<<endl;
                        cout<<"\t\t\t\t\t\t\t\tThe answers for this question are "<<endl;
                        if (qn<ct+1){
                            q[qn-1].display();
                            ans_no = 0;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                        }
                    }
                    cout<<endl;
                }
                else if (choice==5){
                    cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                    cout << "\n\t\t\t\t\t\t\t\tThank for visting our platform!";
                    exit(0);
                }
                else{
                    cout<<"\t\t\t\t\t\t\t\tWrong choice\n"<<endl;
                }
            }
        }
        else{
            cout << "\n\t\t\t\t\t\t\t\tThe account already exists\n";
            cout << "\n\t\t\t\t\t\t\t\t\t"<< "  " <<"SIGNUP!\n" << endl;
            cout << "\t\t\t\t\t\t\t\tEnter your name to signup: ";
            cin >> name;
            cout << "\t\t\t\t\t\t\t\tEnter password: ";
            cin >> pass;
            if (u.search(name)!=1){
                u.insert(name, pass);
                cout << "\n\t\t\t\t\t\t\t\tSuccessfully Signed up!\n" << endl;
                while (1){
                    cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                    cout<<"\t\t\t\t\t\t\t\t[1] Post question \n\t\t\t\t\t\t\t\t[2] Display Question \n\t\t\t\t\t\t\t\t[3] Answer the question \n\t\t\t\t\t\t\t\t[4] See answer for question\n\t\t\t\t\t\t\t\t[5] Exit\n"<<endl;
                    cout<<"\t\t\t\t\t\t\t\tEnter choice: ";
                    cin>>choice;
                    cout << endl;
                    if (choice==1){
                        cout << "\t\t\t\t\t\t\t\tAsk a question: ";
                        cin >> ws;
                        getline(cin, ques);
                        q[ct].insert(ques);
                        ct++;
                        set_ques.push_back(ques);
                        cout << endl;
                    }
                    else if (choice==2){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tThe Questions asked by others"<<endl;
                            for (int i=0; i<ct; i++){
                                cout << "\t\t\t\t\t\t\t\t" << i + 1 << ") ";
                                q[i].dis_ques();
                            }
                        }
                        cout<<endl;
                    }
                    else if (choice==3){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tEnter question number to post answer: ";
                            cin>>qn;
                            if (qn<ct+1){
                                cout<<"\t\t\t\t\t\t\t\tEnter answer for question "<<qn<<" :";
                                cin>>ws;
                                getline(cin, data);
                                q[qn-1].insert(data);
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                            }
                        }
                        cout << endl;
                    }
                    else if (choice==4){
                        if (ct==0){
                            cout << "\t\t\t\t\t\t\t\tThere is no questions yet" << endl;
                        }
                        else{
                            cout<<"\t\t\t\t\t\t\t\tEnter question number to see answer: ";
                            cin>>qn;
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tThe Question is "<<endl;
                            cout << "\t\t\t\t\t\t\t\t";
                            q[qn-1].dis_ques();
                            cout<<endl;
                            cout<<"\t\t\t\t\t\t\t\tThe answers for this question are "<<endl;
                            if (qn<ct+1){
                                q[qn-1].display();
                                ans_no = 0;
                            }
                            else{
                                cout<<"\t\t\t\t\t\t\t\tThe question with that number doesn't exists"<<endl;
                            }
                        }
                        cout<<endl;
                    }
                    else if (choice==5){
                        cout << "\t\t\t\t\t\t\t******************************************************\t\t\t\n" << endl;
                        cout << "\n\t\t\t\t\t\t\t\tThank for visting our platform!";
                        exit(0);
                    }
                    else{
                        cout<<"\t\t\t\t\t\t\t\tWrong choice\n"<<endl;
                    }
                }
            }
        }
    }
    return 0;
}