#include <iostream>
#include <vector>
using namespace std;


struct Point{
    double x;
    double y;

    friend istream& operator >> (istream &in, Point &point){
        in >> point.x;
        in >> point.y;
        return in;
    }
};


struct Node{
    int data;
    Node *nextAddress;
};

class List{

private:
    Node *head;
    Node *tail;


public:
    List(){
        head = nullptr;
        tail = nullptr;
    }
    //метод проверки головы списка, использую при заполнении.
    bool isEmpty(){
        return head == nullptr;
    }

    // метод проверки, существует ли элемент(по значению) в списке.
    bool isInList(int value){
        Node *currentData = head;
        while(currentData) {
            if (currentData->data == value) {
                return true;
            } else {
                currentData = currentData->nextAddress;
            }
        }
        return false;
    }

    //метод добавления новых элементов в список.
    void addNode(int value){
        Node *newNode = new Node;
        newNode->data = value;
        newNode->nextAddress = nullptr;
        if (isEmpty()){
            head = newNode;
            tail = newNode;
            return;
        }
        tail->nextAddress = newNode;
        tail = newNode;
    }

    //метод добавления нового элемента в начало списка, аналог push_front
    void addFrontNode(int value){
        Node *newHead = new Node;
        newHead->data = value;
        newHead->nextAddress = head;
        head = newHead;
        head->data = value;
        if (tail == nullptr){
            tail = head;
        }
    }

    //метод удаления элемента из списка по заданому значению.
    void deleteNode(int value){
        Node *temp = head;
        Node *element;
        if (head and head->data == value){
            element = head;
            head = head->nextAddress;
            delete element;
            return;
        }
        while (temp->nextAddress){
            if (temp->nextAddress->data == value){
                element = temp->nextAddress;
                temp->nextAddress = element->nextAddress;
                delete element;
                break;
            }
            temp = temp->nextAddress;
        }
    }

    // метод добавление нового элемента в список, после его полного заполнения.
    void addNewNode(int x, int position){
        if (position == 0){
            addFrontNode(x);
        }
        else {
            Node *previous = this->head;
            for (int i = 0; i < position - 1; i++){
                previous = previous->nextAddress;
            }
            Node *newNode = new Node;
            newNode->data = x;
            newNode->nextAddress = previous->nextAddress;
            previous->nextAddress = newNode;
        }
    }

    //метод смены местами двух элементов списка.
    void swapNode(int firstValue, int secondValue) {
        Node *temp = head;
        Node *tempSecond = head;
        Node *element = nullptr;
        Node *elementSecond = nullptr;
        if (head and head->data == firstValue) {
            while (temp) {
                if (temp->nextAddress->data == secondValue) {
                    element = temp->nextAddress;
                    head->data = secondValue;
                    element->data = firstValue;
                    return;
                }
                temp = temp->nextAddress;
            }
        }
        else if (head and head->data == secondValue) {
            while (temp->nextAddress) {
                if (temp->nextAddress->data == firstValue) {
                    element = temp->nextAddress;
                    head->data = firstValue;
                    element->data = secondValue;
                    return;
                }
                temp = temp->nextAddress;
            }
        }
        else{
            while (temp->nextAddress){
                if (temp->nextAddress->data == firstValue){
                    element = temp->nextAddress;
                    break;
                }
                temp = temp -> nextAddress;
            }

            while (tempSecond->nextAddress){
                if (tempSecond->nextAddress->data == secondValue){
                    elementSecond = tempSecond -> nextAddress;
                    break;
                }
                tempSecond = tempSecond->nextAddress;
            }
            element->data = secondValue;
            elementSecond->data = firstValue;
        }
    }

    //метод вывода всего списка
    void print(){
        Node *currentData = head;
        while(currentData){
            cout << currentData->data << ' ';
            currentData = currentData->nextAddress;
        }
    }
};

int main(){
    List list;
    vector<int> subList;
    int listElement;
    while (cin >> listElement){
        subList.push_back(listElement);
    }
    unsigned subListSize = subList.size();
    for (int i = 0; i < subListSize - 2; i ++){
        list.addNode(subList[i]);
    }
    list.swapNode(subList[subListSize - 2] ,subList[subListSize - 1]);
    list.print();
}