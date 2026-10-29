#include <iostream>
#include <vector>
using namespace std;

class Skiplist
{
    static const int N = 15; // level
    struct Node
    {
        int val;
        vector<Node*> next;

        Node(int _val) : val(_val)
        {
            next.resize(N, nullptr);
        }
    };
    Node* head = nullptr;

    void find(int target, vector<Node*>& pos)
    {
        auto* p = head;
        for (int i = N - 1; i >= 0 ; --i)
        {
            while (p->next[i] != nullptr && p->next[i]->val < target)
            {
                p = p->next[i];
            }
            pos[i] = p;
        }
    }

public:
    Skiplist()
    {
        head = new Node(-1);
    }
    bool search(int target)
    {
        vector<Node*> pos;
        find(target, pos);
        return (pos[0]->next[0] != nullptr && pos[0]->next[0]->val == target);
    }

    void add(int num)
    {
        vector<Node*> pos;
        find(num, pos);
        auto* p = new Node(num);
        for (int i = 0; i < head->next.size() ; ++i)
        {
            p->next[i] = pos[i]->next[i];
            pos[i]->next[i] = p;
            if (rand() % 2 == 1)
            {
                break;
            }
        }
    }

    bool erase(int num)
    {
        vector<Node*> pos;
        find(num, pos);
        for (int i = 0 ; i < head->next.size(); ++i)
        {
            if (pos[i]->next[i] != nullptr pos[i]->next[i]->val == num)
            {

            }
        }
    }
};

int main()
{

}
