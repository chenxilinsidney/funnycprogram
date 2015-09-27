#ifndef __ITEM_HPP_
#define __ITEM_HPP_
#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;

class Item
{
public:
    Item(string name,
            string description,
            double price,
            bool vegetarian) :
        name_(name),
        description_(description),
        price_(price),
        vegetarian_(vegetarian) { }
    string getName() {
        return name_;
    }
    string getDescription() {
        return description_;
    }
    double getPrice() {
        return price_;
    }
    bool isVegetarian() {
        return vegetarian_;
    }
private:
    string name_;
    string description_;
    double price_;
    bool vegetarian_;
};

class Iterator
{
public:
    virtual bool hasNext() = 0;
    virtual Item next() = 0;
};

class DinerMenuIterator;
class PancakeHouseMenu
{
public:
    PancakeHouseMenu() {
        addItem("A","AA", 1.0, 1);
        addItem("B","BB", 2.0, 1);
        addItem("C","CC", 3.0, 0);
        addItem("D","DD", 4.0, 1);
    }
    void addItem(string name,
            string description,
            double price,
            bool vegetarian) {
        Item newItem = Item(name, description, price, vegetarian);
        menuItem.push_back(newItem);
    }
    const list<Item>& getMenuItem() {
        return menuItem;
    }
private:
    list<Item> menuItem;
};

class DinerMenu
{
public:
    DinerMenu() {
        addItem("A","AA", 1.0, 1);
        addItem("B","BB", 2.0, 1);
        addItem("C","CC", 3.0, 0);
        addItem("D","DD", 4.0, 1);
    }
    void addItem(string name,
            string description,
            double price,
            bool vegetarian) {
        Item newItem = Item(name, description, price, vegetarian);
        menuItem.push_back(newItem);
    }
    const vector<Item>& getMenuItem() {
        return menuItem;
    }
    Iterator* createIterator() {
        Iterator* iterator = new DinerMenuIterator(menuItem);
        return iterator;
    }
private:
    vector<Item> menuItem;
};


class DinerMenuIterator : public Iterator
{
public:
    DinerMenuIterator(vector<Item> items) :
        items_(items), position_(0) {}
    bool hasNext() {
        if (items_.size() <= position_ + 1 || items_.size() == 0) 
            return false;
        else
            return true;
    }
    Item next() {
        Item item = items_[position_];
        position_++;
        return item;
    }
private:
    vector<Item> items_;
    size_t position_;
};
class Waittress
{
public:
    Waittress() {}
    void PrintMenu() {
        Iterator* iterator = dinerMenu.createIterator();
        while (iterator->hasNext())
            cout << "item : " << iterator->next().getName() << endl;
    }
private:
    PancakeHouseMenu pancakeHouseMenu;
    DinerMenu dinerMenu;
};


#endif  // __ITEM_HPP_
