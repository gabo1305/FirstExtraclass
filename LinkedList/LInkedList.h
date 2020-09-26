//
// Created by gabriel on 25/9/20.
//

#ifndef INC_1EXTRACLASS_LINKEDLIST_H
#define INC_1EXTRACLASS_LINKEDLIST_H


#include <iostream>

/**
 * @class Nodo linked list
 * @brief Implementacion de la clase nodo.
 */
template<class T>
class Node{
public:

    T data;
    Node* next;
    Node(T data){
        this->data = data;
        this->next = nullptr;
    }
};

/**
 * @class implementacion de lista enlazada
 * @brief Aqui se encuentras todos los metodos necesarios
 */
template<class T>
class LinkedList{
public:

    /**
     * @brief Constructor
     */
    LinkedList(){
        this->head = nullptr;
        this->size = 0;
    }
    /**
     * @brief Verifica si la lista estia vacia
     * @return True si la lista es vacia, si no esta vacia retorna False
     */
    bool isEmpty(){
        return head == nullptr;
    }

    /**
     *@brief Destructor
     */
    ~LinkedList() = default;

    /**
     *@brief Agrega un nuevo nodo al final de la lista
     * @param data
     */

    void addNode(T data){
        if(head== nullptr){
            head =  new Node<T>(data);
            size++;
        }else{
            Node<T> *current = head;
            while(current->next != nullptr){
                current = current->next;
            }
            current->next = new Node<T>(data);
            size++;
        }
    }

    /**
     *@brief Elimina un nodo segun una posicion dada
     * @param index
     */
    void remove(int index){
        if(size == 1){
            head = nullptr;
            size = 0;
        }else if(index == 0){
            head = head->next;
            size--;
        }else{
            int i = 0;
            Node<T> *current = head;
            while(i < index -1){
                current = current->next;
                i++;
            }
            current->next = current->next->next;
            size--;
        }
    }

    /**
     * @brief Devuelve el tamano
     * @return
     */
    int getSize(){
        return this->size;
    }

    /**
     * @brief Devuelve un nodo de una posicion dada
     * @param index
     *
     */

    Node<T>* get(int index){
        if(index>=size){
            return nullptr;
        }else{
            int current{0};
            Node<T>* temp = head;
            for(current; current < index;current++){
                temp = temp->next;
            }
            return temp;
        }
    }
/**
 * @brief obtiene el nodo en la posicion final
 * @return
 */
    T getLast(){
        Node<T> *current = head;
        while(current->next != nullptr){
            current = current->next;

        }
        return current;
    }

private:
    Node<T>* head;
    int size{};

};
#endif //INC_1EXTRACLASS_LINKEDLIST_H
