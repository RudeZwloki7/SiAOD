#include <bits/stdc++.h>
using namespace std;

// Количество предметов
int num;

// Вместимость рюкзака
float capacity;

typedef struct Item {

    float weight; // Вес предмета
    int value; // Стоимость предмета
    int idx; // Индекс предмета
} Item;

typedef struct Node {

    // Верхняя граница: лучший случай
    float ub;

    // Нижняя граница: худший случай
    float lb;

    // Уровень узла в дереве
    int level;

    // Взят ли текущий предмет или нет
    bool flag;

    // Текущая суммарная стоимость
    float tval;

    // Текущий суммарный вес
    float tweight;
} Node;

// Рассчет для верхней границы
float upper_bound(float tval, float tweight, int idx, vector<Item>& arr)
{
    float value = tval;
    float weight = tweight;
    for (int i = idx; i < num; i++) {
        if (weight + arr[i].weight<= capacity) {
            weight += arr[i].weight;
            value -= arr[i].value;
        }
        else {
            value -= (float)(capacity - weight) / arr[i].weight * arr[i].value;
            break;
        }
    }
    return value;
}

// Рассчет для нижней границы
float lower_bound(float tval, float tweight, int idx, vector<Item>& arr)
{
    float value = tval;
    float weight = tweight;
    for (int i = idx; i < num; i++) {
        if (weight + arr[i].weight <= capacity) {
            weight += arr[i].weight;
            value -= arr[i].value;
        }
        else {
            break;
        }
    }
    return value;
}

class comp {
public:
    bool operator()(Node a, Node b) {return a.lb > b.lb;}
};

void assign(Node& a, float ub, float lb, int level, bool flag, float tval, float tweight)
{
    a.ub = ub;
    a.lb = lb;
    a.level = level;
    a.flag = flag;
    a.tval = tval;
    a.tweight = tweight;
}

void knapsack(vector<Item>& arr)
{
    // Сортировка по отношению стоимость/вес
    sort(arr.begin(), arr.end(), [&](Item& a, Item& b) {return a.value / a.weight > b.value / b.weight;});

    // min_lb -> минимальная нижняя граница исследованных узлов
    // final_lb -> минимальная нижняя граница всех путей, достигших последнего уровня
    float min_lb = 0, final_lb = INT_MAX;

    // curr_path -> булевый массив, отображающий взят ли предмет в рюкзак
    // final_path ->  Булевый массив для хранения массива выбранных предметов, когда он достиг последнего уровня
    bool curr_path[num], final_path[num];

    // Очередь с приоритетом для хранения узлов на основе нижних границ
    priority_queue<Node, vector<Node>, comp> pq;

    Node current, left, right;
    current.lb = current.ub = current.tweight= current.tval = current.level = current.flag = 0;
    pq.push(current);
    for (int i = 0; i < num; i++)
        curr_path[i] = final_path[i] = false;

    while (!pq.empty()) {
        current = pq.top();
        pq.pop();

        if (current.ub > min_lb || current.ub >= final_lb) {

            // Если значение лучшего случая для текущего узла менее оптимально, чем min_lb, тогда не исследуем
            // этот путь и final_lb удаляет все пути, чье лучшее значение равно final_lb
            continue;
        }

        // Обновляем путь
        if (current.level != 0)
            curr_path[current.level - 1]= current.flag;

        if (current.level == num) {
            // Достигли последнего уровня
            if (current.lb < final_lb)
                for (int i = 0; i < num; i++)
                    final_path[arr[i].idx] = curr_path[i];
            final_lb = min(current.lb, final_lb);
            continue;
        }

        int level = current.level;

        //правый узел - исключает текущий элемент, текущая стоимость и вес наследуются от родителя
        assign(right, upper_bound(current.tval, current.tweight, level + 1, arr),
               lower_bound(current.tval, current.tweight, level + 1, arr),
               level + 1, false, current.tval, current.tweight);

        // Проверяет, не превышает ли добавление текущего элемента вес рюкзака
        if (current.tweight + arr[current.level].weight <= capacity) {
            //левый узел - включает текущий элемент, текущая стоимость и нижняя граница будут вычисленны
            // с учетом текущего элемента
            left.ub = upper_bound(current.tval - arr[level].value, current.tweight + arr[level].weight, level + 1, arr);

            left.lb = lower_bound(current.tval - arr[level].value, current.tweight + arr[level].weight, level + 1, arr);

            assign(left, left.ub, left.lb, level + 1, true, current.tval - arr[level].value,
                   current.tweight + arr[level].weight);
        }

            // Если левый узел нельзя вставить
        else {
            // Предотвращает добавление левого узла в приоритетную очередь
            left.ub = left.lb = 1;
        }

        // Обновляет нижнюю границу
        min_lb = min(min_lb, left.lb);
        min_lb = min(min_lb, right.lb);

        // Исследование узлов, верхняя граница которых больше min_lb, никогда не дающих оптимального результата
        if (min_lb >= left.ub)
            pq.push(left);
        if (min_lb >= right.ub)
            pq.push(right);
    }

    cout << "Предметы, взятые в рюкзак:\n";
    if (final_lb == INT_MAX)
        final_lb = 0;
    for (int i = 0; i < num; i++)
        cout << final_path[i] << " ";
    cout << "\n";
    cout << "Максимальная стоимость: "
         << (-final_lb) << "\n";
}

int main()
{
    cout<<"Введите количество предметов: ";
    cin>>num;

    cout<<"Введите вместимость рюкзака: ";
    cin>>capacity;

    vector<Item> arr;
    for (int i=0;i<num; i++){
        float tempw;
        int tempv;
        cout<< "Введите вес и стоимость "<< i+1 <<" предмета: ";
        cin>>tempw>>tempv;
        arr.push_back({ tempw, tempv, i});
    }

    knapsack(arr);

    return 0;
}
