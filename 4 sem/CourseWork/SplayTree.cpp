#include "SplayTree.h"



SplayTree::Node* SplayTree::tryToInsert(int key, TaxReport* value)
{
    bool flag = false;
    Node* node = this->root;
    Node* newNode = new Node(key, value);

    while (flag == false)
    {
        if (key != node->key)
        {
            if (key < node->key)
            {
                if (node->leftptr == nullptr)
                {
                    node->leftptr = newNode;
                    newNode->parentptr = node;
                    flag = true;
                    splay(newNode);
                    return this->root;
                }
                else
                    node = node->leftptr;
            }
            else
            {
                if (key > node->key)
                {
                    if (node->rightptr == nullptr)
                    {
                        node->rightptr = newNode;
                        newNode->parentptr = node;
                        flag = true;
                        splay(newNode);
                        return this->root;
                    }
                    else
                        node = node->rightptr;
                }
            }
        }
        else
        {
            flag = true;
            //std::cout << "Repeat = " << newNode->key << std::endl;
            return nullptr;
        }
    }
}


SplayTree::Node* SplayTree::insert(int key, TaxReport* value)
{
    if (this->root == nullptr)
    {
        this->root = new Node(key, value);
        return this->root;
    }
    else
    {
        return tryToInsert(key, value);
    }
}



void SplayTree::leftRotate(Node* node) // zag
{
    Node* right = node->rightptr;
    Node* parent = node->parentptr;
    if (node->parentptr != nullptr)
    {
        if (node->parentptr->leftptr == node)
            node->parentptr->leftptr = right;
        else
            node->parentptr->rightptr = right;
    }
    Node* tmp = nullptr;
    tmp = node->rightptr->leftptr;
    node->rightptr->leftptr = node;
    node->rightptr = tmp;
    node->parentptr = right;
    right->parentptr = parent;
    if (node->rightptr != nullptr)
        node->rightptr->parentptr = node;
}



void SplayTree::rightRotate(Node* node) // zig
{
    Node* left = node->leftptr;
    Node* parent = node->parentptr;
    if (node->parentptr != nullptr)
    {
        if (node->parentptr->leftptr == node)
            node->parentptr->leftptr = left;
        else
            node->parentptr->rightptr = left;
    }
    Node* tmp = nullptr;
    tmp = node->leftptr->rightptr;
    node->leftptr->rightptr = node;
    node->leftptr = tmp;
    node->parentptr = left;
    left->parentptr = parent;
    if (node->leftptr != nullptr)
        node->leftptr->parentptr = node;
}



SplayTree::Node* SplayTree::splay(Node* node)
{
    while (node->parentptr != nullptr)
    {
        if (node == node->parentptr->leftptr)
            if (node->parentptr->parentptr == nullptr)
                rightRotate(node->parentptr);
            else if (node->parentptr == node->parentptr->parentptr->leftptr)
            {
                rightRotate(node->parentptr->parentptr);
                rightRotate(node->parentptr);
            }
            else
            {
                rightRotate(node->parentptr);
                leftRotate(node->parentptr);
            }
        else
            if (node->parentptr->parentptr == nullptr)
                leftRotate(node->parentptr);
            else if (node->parentptr == node->parentptr->parentptr->rightptr)
            {
                leftRotate(node->parentptr->parentptr);
                leftRotate(node->parentptr);
            }
            else
            {
                leftRotate(node->parentptr);
                rightRotate(node->parentptr);
            }
    }
    this->root = node;
    return this->root;
}



SplayTree::Node* SplayTree::find(int key)
{
    Node* node = this->root;

    while (node != nullptr)
    {
        if (key == node->key)
            return node;
        else
        {
            if (key > node->key)
                node = node->rightptr;
            else
                node = node->leftptr;
        }
    }
    return nullptr;
}



SplayTree::TwoNodes* SplayTree::split(Node* node)
{
    if ((node != nullptr) && ((node->rightptr != nullptr) || (node->leftptr != nullptr)))
    {
        TwoNodes* nodes = new TwoNodes(node->rightptr, node->leftptr);

        if (node->leftptr != nullptr)
        {
            node->leftptr->parentptr = nullptr;
            this->root = node->leftptr;
        }

        if (node->rightptr != nullptr)
        {
            node->rightptr->parentptr = nullptr;
            this->root = node->rightptr;
        }

        delete node;
        return nodes;
    }
    else
        return nullptr;
}



SplayTree::Node* SplayTree::merge(TwoNodes* nodes)
{
    if (nodes->rightptr == nullptr)
        return nodes->leftptr;
    else if (nodes->leftptr == nullptr)
        return nodes->rightptr;
    else
    {
        Node* minOfMax = nodes->rightptr;
        while (minOfMax->leftptr != nullptr)
        {
            minOfMax = minOfMax->leftptr;
        }

        splay(minOfMax);
        minOfMax->leftptr = nodes->leftptr;
        nodes->leftptr->parentptr = minOfMax;

        return minOfMax;
    }
}



SplayTree::Node* SplayTree::search(int key)
{
    Node* node = find(key);
    if (node != nullptr)
        splay(node);
    return this->root;
}



SplayTree::Node* SplayTree::remove(int key)
{
    Node* node = search(key);

    TwoNodes* nodes = split(node);

    if (nodes != nullptr)
    {
        this->root = merge(nodes);

        return this->root;
    }
    else
        return nullptr;
}



void SplayTree::clear()
{
    continueClear(this->root);
    this->root = nullptr;
}



int SplayTree::maxKey()
{
    Node* node = root;
    while (node->rightptr != nullptr)
    {
        node = node->rightptr;
    }
    return node->key;
}



void SplayTree::continueClear(Node* node)
{
    if (node != nullptr)
    {
        continueClear(node->rightptr);
        continueClear(node->leftptr);
        delete node->value;
        delete node;
    }
}



void SplayTree::startPrintToFile(std::string filename)
{
    Node* node = root;
    std::ofstream outputFile;
    outputFile.open(filename);
    int depth = 0;
    printToFile(outputFile, node, depth);
    outputFile.close();
}



void SplayTree::startPrintInOrderTraversalToFile(std::string filename)
{
    Node* node = root;
    std::ofstream outputFile;
    outputFile.open(filename);

    printInOrderTraversalToFile(outputFile, node);

    outputFile.close();
}



void SplayTree::startSearchSurname(std::string surname, std::ofstream& file)
{
    Node* node = root;

    searchSurname(file, node, surname);
}



void SplayTree::startSearchName(std::string name, std::ofstream& file)
{
    Node* node = root;

    searchName(file, node, name);
}



void SplayTree::startSearchPatronymic(std::string patronymic, std::ofstream& file)
{
    Node* node = root;

    searchPatronymic(file, node, patronymic);
}



void SplayTree::startSearchCity(std::string city, std::ofstream& file)
{
    Node* node = root;

    searchCity(file, node, city);
}


void SplayTree::startSearchDateOfBirth(std::vector<int> dateOfBirth, std::ofstream& file)
{
    Node* node = root;

    searchDateOfBirth(file, node, dateOfBirth);
}



void SplayTree::printToFile(std::ofstream& file, Node* node, int depth)
{
    if (node != nullptr)
    {
        file << "Key: " << node->key << " depth = " << depth << std::endl;
        if (node->rightptr != nullptr)
            file << "Right: key = " << node->rightptr->key << " parent = " << node->rightptr->parentptr->key << std::endl;
        if (node->leftptr != nullptr)
            file << "Left: key = " << node->leftptr->key << " parent = " << node->leftptr->parentptr->key << std::endl;
        if (node->parentptr != nullptr)
            file << "Parent: key = " << node->parentptr->key << std::endl;
        file << "\n\n";
        depth++;
        printToFile(file, node->leftptr, depth);
        printToFile(file, node->rightptr, depth);
    }
}



void SplayTree::printInOrderTraversalToFile(std::ofstream& file, Node* node)
{
    if (node != nullptr)
    {
        printInOrderTraversalToFile(file, node->leftptr);
        node->value->printTaxReportToFile(file);
        printInOrderTraversalToFile(file, node->rightptr);
    }
}



void SplayTree::searchSurname(std::ofstream& file, Node* node, std::string surname)
{
    if (node != nullptr)
    {
        searchSurname(file, node->leftptr, surname);

        if(!node->value->surname.compare(surname))
            node->value->printTaxReportToFile(file);

        searchSurname(file, node->rightptr, surname);
    }
}



void SplayTree::searchName(std::ofstream& file, Node* node, std::string name)
{
    if (node != nullptr)
    {
        searchName(file, node->leftptr, name);

        if (!node->value->name.compare(name))
            node->value->printTaxReportToFile(file);

        searchName(file, node->rightptr, name);
    }
}



void SplayTree::searchPatronymic(std::ofstream& file, Node* node, std::string patronymic)
{
    if (node != nullptr)
    {
        searchPatronymic(file, node->leftptr, patronymic);

        if (!node->value->patronymic.compare(patronymic))
            node->value->printTaxReportToFile(file);

        searchPatronymic(file, node->rightptr, patronymic);
    }
}



void SplayTree::searchCity(std::ofstream& file, Node* node, std::string city)
{
    if (node != nullptr)
    {
        searchCity(file, node->leftptr, city);

        if (!node->value->city.compare(city))
            node->value->printTaxReportToFile(file);

        searchCity(file, node->rightptr, city);
    }
}



void SplayTree::searchDateOfBirth(std::ofstream& file, Node* node, std::vector<int> dateOfBirth)
{
    if (node != nullptr)
    {
        searchDateOfBirth(file, node->leftptr, dateOfBirth);

        if ((node->value->DateOfBirth[0] == dateOfBirth[0]) && (node->value->DateOfBirth[1] == dateOfBirth[1]) && (node->value->DateOfBirth[2] == dateOfBirth[2]))
            node->value->printTaxReportToFile(file);

        searchDateOfBirth(file, node->rightptr, dateOfBirth);
    }
}