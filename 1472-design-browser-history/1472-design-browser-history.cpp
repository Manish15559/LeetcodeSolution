

class BrowserHistory {
public:
    struct ListNode {
        // public:
        string val;
        ListNode* prev;
        ListNode* next;
        ListNode(string val) {
            this->val = val;
            this->prev = NULL;
            this->next = NULL;
        }
        ListNode(string val, ListNode* prev, ListNode* next) {
            this->val = val;
            this->prev = prev;
            this->next = next;
        }
    };
    ListNode* head;
    ListNode* curr;

    BrowserHistory(string homepage) {
        head = new ListNode(homepage);
        curr = head;
    }
    void clearForwardHistory(ListNode* node) {

        while (node != NULL) {
            ListNode* nextNode = node->next;

            delete node;
            node = nextNode;
        }
    }

    void visit(string url) {

        clearForwardHistory(curr->next);
        curr->next = new ListNode(url);
        curr->next->prev = curr;
        curr = curr->next;
    }

    string back(int steps) {

        while (curr != head && steps > 0) {
            curr = curr->prev;
            steps--;
        }

        return curr->val;
    }

    string forward(int steps) {

        while (curr->next != NULL && steps > 0) {
            curr = curr->next;
            steps--;
        }
        return curr->val;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */