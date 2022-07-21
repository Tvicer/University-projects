#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "TaxReport.h"

class SplayTree
{
protected:
    class Node
    {
    public:
        int key = 0;
        TaxReport* value = nullptr;
        Node* rightptr = nullptr, * leftptr = nullptr, * parentptr = nullptr;

        Node(int key, TaxReport* value)
        {
            this->key = key;
            this->value = value;
            this->leftptr = nullptr;
            this->rightptr = nullptr;
            this->parentptr = nullptr;
        }

    };

    class TwoNodes
    {
    public:
        Node* rightptr = nullptr, * leftptr = nullptr;

        TwoNodes(Node* rightptr, Node* leftptr)
        {
            this->rightptr = rightptr;
            this->leftptr = leftptr;
        }

    };

public:
    SplayTree()
    {
        root = nullptr;
    }

private:
    Node* tryToInsert(int key, TaxReport* value);

    void leftRotate(Node* node); // zag

    void rightRotate(Node* node); // zig

    Node* splay(Node* node);

    Node* find(int key);

    TwoNodes* split(Node* node);

    Node* merge(TwoNodes* nodes);

public:
    Node* insert(int key, TaxReport* value);

    Node* search(int key);

    Node* remove(int key);

    void clear();

    int maxKey();

    void startPrintToFile(std::string filename);

    void startPrintInOrderTraversalToFile(std::string filename);

    void startSearchSurname(std::string surname, std::ofstream& file);

    void startSearchName(std::string name, std::ofstream& file);

    void startSearchPatronymic(std::string patronymic, std::ofstream& file);

    void startSearchCity(std::string city, std::ofstream& file);

    void startSearchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file);

private:
    void continueClear(Node* node);

    void printToFile(std::ofstream& file, Node* node, int depth);

    void printInOrderTraversalToFile(std::ofstream& file, Node* node);

    void searchSurname(std::ofstream& file, Node* node, std::string surname);

    void searchName(std::ofstream& file, Node* node, std::string name);

    void searchPatronymic(std::ofstream& file, Node* node, std::string patronymic);

    void searchCity(std::ofstream& file, Node* node, std::string city);

    void searchDateOfBirth(std::ofstream& file, Node* node, std::vector<int> dateOfBirth);

private:
	Node* root;
};

