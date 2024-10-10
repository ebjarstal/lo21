#include "iterator.h"

ostream& operator<<(ostream& f, const Person& p) {
    f << p.getName() << " " << p.getSurname() << " " << p.getAge() << "yo";
    return f;
}

bool PersonIterator::isDone() const {
    return current_index >= list.size();
}

Person PersonIterator::next() {
    if (isDone()) throw "end of list reached";
    else return list[++current_index];
}

Person PersonIterator::current() const {
    return list[current_index];
}