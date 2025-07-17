#include <iostream>

class Node { // объект ()
  public:
    double data;
    Node* next;   // указатель на следующий объект списка 
  public:
    Node(double data): data(data), next(nullptr) {
        //std::cout << "Created Node -> " << this << "\n";
    }

    ~Node() {
        //std::cout << "Deleted Node -> " << this << "\n";
    }
};

class OneLinkedList { // список
  public: 
    Node* head, * tail; // указатели на первый объект и на последний объект списка
  
  public:
    OneLinkedList() {       // констуктор
        this->head = this->tail = nullptr;
        //std::cout << "Created OneLinkedList -> " << this << "\n";
    }

    ~OneLinkedList() {      // дестуктор
        while(head != nullptr) {
            pop_front();
        }
        //std::cout << "Deleted OneLikedList -> " << this << "\n";
    }

    void pop_front() {      // метод удаления первого объекта в списке
        if(head == nullptr) {
            return;
        }
        if(head == tail) {
            delete tail;
            head = tail = nullptr;
            return;
        }
        Node* node = head;
        head = node->next;
        delete node;
    }

    void push_back(double data) {   // метод добавления объекта в конец списка
        Node* node = new Node(data); // указатель на добавляемый объект
        if(head == nullptr) { // если объектов еще нет
            head = node;      // то первому объекту присваивается адрес добавляемого объекта
        }
        if(tail != nullptr) { // если последний объект существует
            tail->next = node; // то его указателю на следующий объект присваивается адрес добавлемого объекта
        }
        tail = node;    // теперь последний объект = добавляемый объект
    }

    void push_front(double data) {      // метод добавления объекта в начало списка
        Node* node = new Node(data); // указатель на добавляемый объект
        node->next = head;              // теперь первй объект становится первым объектом
        head = node;
        if(tail == nullptr) {
            tail = node;
        }
    }

    void pop_back() {       // метод удаления псоледнего obъекта списка
        if(tail == nullptr) {
            return;             // удалять нечего
        }
        if(head == tail) {
            delete tail;    // удаление единственного объекта
            head = tail = nullptr;
            return;
        }
        //если объектов 2 и более:
        Node* node = head;          // бегунок начиная с первого объекта
        for(; node->next != tail; node = node->next);   // бегунок дохоходит до предпоследнего объекта и останавдивается на нем
        // удаляем последний объект и память о нём:
        node->next = nullptr;
        delete tail;
        tail = node;        // объект, который был предпоследним, становится последним
    }

    Node* getAt(int k) {        // метод возвращает объект списка по индексу k
        if(k < 0) {
            return nullptr;
        }
        Node* node = head;      // бегунок начиная с первого объекта
        int n (0);              // счетчик индексов
        // пока 1) хотя бы один объект существует
        //      2) счетчик не достиг искомого индекса
        //      3) не достигнут последний объект
        // бегунок передвигает по объектам, а счетчик инкрементируется:
        while(node && n != k && node->next) {
            node = node->next;
            n++;
        }
        return (n == k) ? node : nullptr;   // возвращается найденный объект либо 0
    }

    void insert(int k, double data) {      // вставка объекта после индекса k
        Node* left = getAt(k);
        if(left == nullptr) {
            return;
        }
        Node* right = left->next;
        Node* node = new Node(data);
        left->next = node;
        node->next = right;
        if(right->next == nullptr) {
            tail = node;
        }        
    }

    void erase(int k) {     // удаление элемента с индексом k
        if(k < 0) {
            return;
        }
        if(k == 0) {
            pop_front();
            return;
        }
        Node* left (getAt(k - 1));
        Node* node (left->next);
        if(node == nullptr) {
            return;
        }
        Node* right (node->next);
        left->next = right;
        if(node = tail) {
            tail = left;
        }
        delete node;
        
    }
};