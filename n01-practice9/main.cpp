#include <iostream>
#include <Windows.h>
#include <vector>
#include <ctime>

using namespace std;

class Node {

    Node(int num) {
        number = num;
        next_ptr = nullptr;
    }

    friend class QueueLL;

public:
    int number;
    int priority;
    Node *next_ptr;
};


//Очередь на линейном односвязном списке
class QueueLL {
private:
    Node *head;    // Начало очереди
    int count = 0; // Количество узлов очереди
public:

    QueueLL() { head = nullptr; } // Инициализация очереди

    int getCount() { return count; } // Получение количества узлов очереди

    bool isEmpty() { return head == nullptr; }  // Проверка, пуста ли очередь

    bool isFilled() { return head != nullptr; }  // Проверка, заполнена ли очередь

    int getNodeValue(Node *p) { return p->number; } // Получение значения узла очереди

    void setNodeValue(Node *p, int val) { p->number = val; } // Установка значения узла очереди

    Node *getFirst() { return head; } // Получение корневого узла очереди

    Node *getLast();      // Получение последнего узла очереди

    Node *Next(Node *);      // Переход к следующему узлу

    Node *Add(int);    //Добавление узла очереди

    Node *Delete();    // Удаление узла очереди

    void Print();        // Вывод значений узлов очереди
};


Node *QueueLL::Add(int num) {
    Node *elem = new Node(num);
    elem->number = num;
    count++;
    Node *node = getLast();
    if (node == nullptr && head == nullptr) // Добавление нового корня
    {
        elem->next_ptr = nullptr;
        head = elem;
        return elem;
    }
    node->next_ptr = elem;
    elem->next_ptr = nullptr;
    return elem;
}

Node *QueueLL::Delete() {
    Node *node = getFirst();
    if (node == nullptr) { return nullptr; } // В списке нет узлов
    count--;
    head = node->next_ptr;
    delete node;
    return head;

}


Node *QueueLL::Next(Node *node) {
    if (isEmpty()) return nullptr;
    return node->next_ptr;
}


Node *QueueLL::getLast() {
    Node *p = head;
    while (Next(p) != nullptr)
        p = Next(p);
    return p;
}


void QueueLL::Print() {
    if (isEmpty()) {
        cout << "Очередь пуста" << endl;
        return;
    }
    Node *p = head;
    do {
        cout << getNodeValue(p) << " ";
        p = Next(p);
    } while (p != nullptr);
    cout << endl;
}

//Очередь на массиве
class QueueDA {

public:
    vector<int> my_queue;

    void addElem(int elem) {
        my_queue.push_back(elem);
    }

    int deleteElem() {
        int temp = *my_queue.begin();
        my_queue.erase(my_queue.begin());
        return temp;
    }

    int getElem() {
        return *my_queue.begin();
    }

    bool isEmpty() {
        return my_queue.empty();
    }

    bool isFilled() {
        return !my_queue.empty();
    }

    void printQueue() {
        cout << "Очередь: " << endl;
        for (auto it = my_queue.begin(); it < my_queue.end(); it++) {
            cout << *it << " ";
        }
        cout << endl;
    }
};

//Очередь с приоритетом

typedef struct node {
    int number;
    int time;
    int priority;

    struct node *next_ptr;

} PNode;

// Создание нового узла
PNode *newNode(int t, int p, int num) {
    PNode *temp = (PNode *) malloc(sizeof(PNode));
    temp->time = t;
    temp->number = num;
    temp->priority = p;
    temp->next_ptr = nullptr;

    return temp;
}

//Получение значение первого элемента в очереди
int peek(PNode **head) {
    return (*head)->number;
}

//Удаление первого элемента очереди
void pop(PNode **head) {
    PNode *temp = *head;
    (*head) = (*head)->next_ptr;
    free(temp);
}

// Добавление элемента в конец очереди
void push(PNode **head, int time_, int p, int num) {
    PNode *start = (*head);

    PNode *temp = newNode(time_, p, num);

    if ((*head)->priority > p) {
        temp->next_ptr = *head;
        (*head) = temp;
    } else {
        while (start->next_ptr != nullptr &&
               start->next_ptr->priority < p) {
            start = start->next_ptr;
        }

        temp->next_ptr = start->next_ptr;
        start->next_ptr = temp;
    }
}

//Проверка на пустоту очереди
int isEmpty(PNode **head) {
    return (*head) == nullptr;
}


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(CP_UTF8);

    cout << "Очередь на линейном списке: " << endl;

    QueueLL queueLl;

    if (queueLl.isEmpty())
        cout << "Очередь пуста" << endl;

    for (int i = 1; i < 10; i++)
        queueLl.Add(rand() % 100);
    queueLl.Print();
    queueLl.Delete();
    cout << "Первый элемент удален." << endl;
    queueLl.Print();

    if (queueLl.isFilled())
        cout << "Очередь полна" << endl;

    cout << "Первый элемент очереди: " << (queueLl.getFirst())->number << endl;
    cout << "Последний элемент очереди: " << (queueLl.getLast())->number << endl;


    cout << "Очередь на масиве: " << endl;

    QueueDA *queueDa = new QueueDA;

    queueDa->addElem(56);
    queueDa->addElem(97);
    queueDa->addElem(11);
    queueDa->addElem(28);

    queueDa->printQueue();

    cout << "Число " << queueDa->deleteElem() << " удалено из очереди\n";

    queueDa->printQueue();

    cout << "Очередь с приоритетом: " << endl;

    PNode *pq = newNode(5, 1, 10036);
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        push(&pq, rand() % 15 + 5, rand() % 3 + 1, rand() % 90000 + 10000);
    }


    int allMTime = 0, allKTime = 0, allRTIme = 0;

    while (!isEmpty(&pq)) {
        cout << "Номер заявки: " << peek(&pq) << ", приоритетность: ";

        switch (pq->priority) {
            case 1:
                allMTime += pq->time;
                cout << "менеджер - ";
                break;
            case 2:
                allKTime += pq->time;
                cout << "контролер - ";
                break;
            case 3:
                allRTIme += pq->time;
                cout << "рабочий - ";
                break;
            default:
                break;
        };
        cout << pq->priority << ", время на обработку заявки: " << pq->time << " минут." << endl;
        pop(&pq);
    }

    cout << endl;
    cout << "Время выполнения всех заявок для менеджеров: " << allMTime << " минут" << endl;
    cout << "Время выполнения всех заявок для контролеров: " << allKTime << " минут" << endl;
    cout << "Время выполнения всех заявок для рабочих: " << allRTIme << " минут" << endl;

}






