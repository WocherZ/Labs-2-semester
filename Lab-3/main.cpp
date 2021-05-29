#include "PriorityQueue.hpp"

template<typename T>
void sqr(tree_element<T>* curr){//(для Map)
    curr->m_value = curr->m_value * curr->m_value;
}

template<typename T>
bool is_more_than_20(tree_element<T>* curr){
    if(curr->m_value >= 20)
        return true;
    return false;
}

template<typename T>
bool even_number(tree_element<T>* curr) {
    if (curr->m_value % 2 == 0) return true;
    else return false;
}

string print_bool(bool t) {
    if (t) return "True";
    else return "False";
}

int main() {
    cout << "Hello world!" << endl;
    int value = 6;
    auto queue = new PriorityQueue<int>(value);
    queue->Print();
    queue->Insert(4);
    queue->Insert(8);
    queue->Insert(5);
    queue->Insert(3);
    cout << "First element: " << queue->GetFirst() << endl;
    cout << "Last element: " << queue->GetLast() << endl;
    cout << "Queue: ";
    queue->Print();

    auto queue1 = new PriorityQueue<int>();
    queue1 = queue->SubSequence(1, 3);
    cout << "SubSequence: ";
    queue1->Print();
    cout << "Size: " << queue1->GetSize() << endl;

    cout << print_bool(queue->FindSubSequence(queue1)) << endl;
    cout << print_bool(queue1->FindSubSequence(queue)) << endl;
    cout << print_bool(queue1->FindSubSequence(queue1)) << endl;

    cout << "Use sqr: ";
    queue->Map(sqr);
    queue->Print();
    cout << "Size: " << queue->GetSize() << endl;

    cout << "Use more 15: ";
    queue->Where(is_more_than_20);
    queue->Print();
    cout << "Size: " << queue->GetSize() << endl;

    cout << "Use even number: ";
    queue->Where(even_number);
    queue->Print();
    cout << "Size: " << queue->GetSize() << endl;


    return 0;
}