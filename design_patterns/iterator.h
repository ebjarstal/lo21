#ifndef LO21_ITERATOR_H
#define LO21_ITERATOR_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Person {
private:
    string name;
    string surname;
    unsigned int age;
public:
    Person(string n, string s, unsigned int a) : name(n), surname(s), age(a) {}

    inline string       getName()    const { return name; }
    inline string       getSurname() const { return surname; }
    inline unsigned int getAge()     const { return age; }
};

class PersonIterator {
private:
    vector<Person> list;
    size_t current_index;
public:
    explicit PersonIterator(const vector<Person>& l) : list(l), current_index(0) {}

    bool   isDone()  const;
    Person current() const;
    Person next();
};

class Group {
private:
    vector<Person> group;
public:
    explicit Group(vector<Person> g) : group(g) {}

    inline PersonIterator first() const { return PersonIterator(group); }
    inline void addPerson(const Person& p) { group.push_back(p); }
    inline size_t getSize() const { return group.size(); }
};

ostream& operator<<(ostream& f, const Person& p);

#endif //LO21_ITERATOR_H
