#include <iostream>
using namespace std;

struct list {
    int inf;
    list *next;
    list *prev;
};

void push (list *&h, list *&t, int x){ // adding an element to the end of the list
    list *r = new list; // creating a new list
    r->inf = x;
    r->next = NULL;
    if (!h && !t){ // if list is empty
        r->prev = NULL; 
        h = r;
    }
    else{
        t->next = r; // t before r
        r->prev = t; // r after t
    }
    t = r;
}

list **make(int *a, int n) {
    list *h = new list{a[0], NULL, NULL}; 
    list *t = h;                          
    list **l = new list*[2];              
    for (int i=1; i<n; i++) push(h, t, a[i]); 
    l[0] = h;                          
    l[1] = t;                           
    return l;
}

void print ( list *h, list *t){
    list *p = h; 
    while (p){ 
        cout << p->inf << " ";
        p = p->next; 
    }
}

list *find ( list *h, list *t, int x){
    list *p = h; 
    while (p){ 
      if (p->inf == x) break; 
      p = p->next; 
    }
    return p; 
}

void insert_after ( list *&h, list *&t, list *r, int y){ 
    list *p = new list; 
        p->inf = y;
        if (r == t){ 
            p->next = NULL;
            p->prev = r; 
            r->next = p;
        t = p; /
    }
    else{
        r->next->prev = p; 
        p->next = r->next;
        p->prev = r; 
        r->next = p;
    }
}

void del_node (list *&h, list *&t, list *r){
    if (r == h && r == t) {
        h = t = NULL;
    }
    else if (r == h){ 
        h = h->next;
        h->prev = NULL;
    }
    else if (r == t){ 
        t = t->prev; 
        t->next = NULL;
    }
    else{
        r->next->prev = r->prev; 
        r->prev->next = r->next; 
    }
    delete r; 
}

void del_list( list *&h, list *&t){ 
    while (h){ 
        list *p = h; 
        h = h->next; 
        h->prev = NULL; 
        delete p;
    }
}

void task1(list *&h, list *&t) {
    list *c = t;
    while (c != nullptr) {
        cout << c->inf << " ";
        c = c->prev;
    }
    cout << endl;
}

void task2(list *&h, list *&t) {
    list *c = t;
    while (c != nullptr) {
        if (c->inf % 2 == 0) {
            cout << c->inf << endl;
            break;
        }
        c = c->prev;
    }
}

void task3(list *&h, list *&t) {
    int min = h->inf;
    list *c = h;
    while (c != nullptr) {
        if (c->inf < min) min = c->inf;
        c = c->next;
    }
    del_node(h, t, find(h, t, min));
    print(h, t);
    cout << endl;
}

void task4(list *&h, list *&t) {
    list *max = h;
    list *c = t;
    while (c != nullptr) {
        if (c->inf > max->inf) max = c;
        c = c->prev;
    }
    insert_after(h, t, max, 0);
    print(h, t);
    cout << endl;
}


int main() {
    int tn, n;
    bool done = false;
    list *h = nullptr;
    list *t = nullptr;
    cout << "n = ";
    cin >> n;
    for (int i=0; i<n; i++) {
        int x;
        cin >> x;
        push(h, t, x);
    }
    while (!done) {
        cout << "Task # 1 to 4: ;
        cin >> tn;
        cout << "========" << endl;
        done = true;
        switch (tn) {
            case 1:
                cout << "1. Reverse the order of the inputs." << endl;
                task1(h, t);
                break;
            case 2:
                cout << "2. Locate the last element that is even" << endl;
                task2(h, t);
                break;
            case 3:
                cout << "3. Remove the first minimum element." << endl;
                task3(h, t);
                break;
            case 4:
                cout << "4. Add a 0 after the final maximum element." << endl;
                task4(h, t);
                break;
            default:
                cout << "UNKNOWN TASK ERROR" << endl;
                done = false;
                break;
        }
        cout << endl;
    }
    return 0;
}
