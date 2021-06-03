#include <iostream>
#include "collection.h"
#include "repository.h"
#include "bed.h"
#include "chair.h"
#include "table.h"

using std::ifstream;
using std::ofstream;

void Collection::add(Furniture* item) {
    for (auto i = items.begin(); i != items.end(); ++i) {
        if ((*i)->getId() == item->getId()) {
            (*i)->addQty(item->getQty());
            return;
        }
    }

    items.push_back(item);
}

void Collection::remove(long id)
{
    for (auto i = items.begin(); i != items.end(); ++i) {
        if ((*i)->getId() == id) {
            items.erase(i);
            break;
        }
    }
}

void Collection::print(long id)
{
    for (auto i = items.begin(); i != items.end(); ++i)
    {
        if ((*i)->getId() == id)
        {
            (*i)->print(std::cout);
            break;
        }
    }
}

void Collection::save() 
{
    ostream* out = (Repository::getInstance())->getOutput();

    *out << items.size() << std::endl;

    for (auto i = items.begin(); i != items.end(); ++i) {
        (*i)->print(*out);
    }
}

void Collection::load()
{
    istream* in = Repository::getInstance()->getInput();

    int n;
    *in >> n;

    for (auto i = items.begin(); i != items.end(); ++i) {
        std::string tmp;
        *in >> tmp;
        if (tmp == "Bed") {
            Bed* bed = Bed::read(*in);
            add(bed);
        } else if (tmp == "Table") {
            Table *table = Table::read(*in);
            add(table);
        } else if (tmp == "Chair") {
            Chair *chair = Chair::read(*in);
            add(chair);
        }
    }
}