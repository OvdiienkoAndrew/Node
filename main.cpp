#include <iostream>
#include <fstream> 


template <typename T>
class Node{
    private:
        void free(){
            if(Node::value!=nullptr){delete Node::value; Node::value = nullptr;}
            if(Node::pLast!=nullptr){Node::pLast = nullptr;}
            if(Node::pNext!=nullptr){Node::pNext = nullptr;}
        }
    protected:
        T* value;
        Node<T>* pNext;
        Node<T>* pLast;
    public:
        Node(T value = T(), Node<T>* pLast = nullptr, Node<T>* pNext = nullptr): value(new T(value)), pLast(pLast), pNext(pNext){}
        ~Node(){if(Node::value!=nullptr){delete Node::value; Node::value = nullptr;}Node::pLast = nullptr;Node::pNext = nullptr;}

        T GetValue()const{return *Node::value;}
        Node<T>* GetPNext()const{return Node::pNext;}
        Node<T>* GetPLast()const{return Node::pLast;}

        void SetValue(T value){*Node::value=value;}
        void SetPNext(Node<T>* pNext){Node::pNext=pNext;}
        void SetPLast(Node<T>* pLast){Node::pLast=pLast;}

        friend std::ostream& operator<<(std::ostream& os, const Node<T>& node){os << node.GetValue();return os;}
        friend std::istream& operator>>(std::istream& is, Node<T>& node){is >> *node.value ;return is;}

        bool operator==(const Node<T>& node)const{return *Node::value == node.GetValue();}
        bool operator!=(const Node<T>& node)const{return *Node::value != node.GetValue();}

        Node(const Node<T>& node){
            Node::value = new T(node.GetValue());
            Node::pLast = nullptr;
            Node::pNext = nullptr;
        }

        Node& operator=(const Node<T>& node){
            if(this == &node) return *this;

            Node::free();
            Node::value = new T(node.GetValue());
            Node::pLast = nullptr;
            Node::pNext = nullptr;

            return *this;
        }
};




int main(){
    Node<int> A,B,C,D,E,F,G,H;
    std::cout << A <<'\n';
    std::cin >> A;
    std::cout << A <<'\n';
    std::cin >> A;
    std::cout << A <<'\n';
    std::cin >> A;
    std::cout << A <<'\n';
}
