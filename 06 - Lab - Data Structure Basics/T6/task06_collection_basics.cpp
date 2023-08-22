/******************************************************************************

Simple examples STL collection basics.

Very Short Version:
 Search for #TODO marks with questions and answer them. (Create answer doc.) :)

Short Version:
 The #TODO marks are questions - answer them in order in a lab notes document. As
 you go save your changes and commit to your repo as evidence of your work.

Longer Version (recommended steps):
    1. Put this file in your repo folders and commit with a message like "No changes
       yet" or similar.
    2. Open this file in your IDE that *must* support debugging. (VS, CLion etc)
    3. Build and run this file. Make sure this works before going on.
    4. Create a lab-notes document for your answers. (Paste the questions provided
       if you want, or discover them as you go.) Save and commit.
    4. Work your way through each of the file #TODO Q. marks in order.
       - Work one section at a time. There are if (false) { ... } blocks to change to
         if (true) get the code to run.
       - Suggest committing your lab notes to your repo as you do each section (minimum).
         This will make a good history of evidence for you!
       - Suggest turning each finished section back to "false" (as it will probably
         speed up compiling time, depending on your setup.)
       - This code file may not change much as you go (simple false/true changes) so you
         may not need to commit it much (depending on what extra changes you decide to make).

There is a simple text file with the questions listed if that helps you with your lab notes.

Written by Clinton Woodward <cwoodward@swin.edu.au>
 for COS30031 Games Programming

This file is for your personal study use only and must not be shared or made
 publicly available.

Updates
 2020-07-08: Cleanup, new questions and comment help.

NOTE: this example code uses C++11 extensions ("auto" in particular)
so you may need to tell your compiler to use at least this standard with a
flag, for example, -std=C++11 or similar.

*/


#include <iostream>
#include <array>
#include <vector>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>

using namespace std;

struct Particle {
    int x, y;
};

class ParticleClass {
public:
    int x, y;

    // ParticleClass(); // works, but random (not set) initial values
    ParticleClass() {
        x = 0;
        y = 0;
        cout << " - ParticleClass() (default) constructor called" << endl;
    }; // default, called by collections
    ParticleClass(int x, int y) {
        this->x = x;
        this->y = y;
        cout << " - ParticleClass(x,y) constructor called" << endl;
    }

    void show() const {
        cout << " - ParticleClass: (" << x << ", " << y << ")" << endl;
    }

    ~ParticleClass() {
        cout << " - ~ParticleClass() destructor called" << endl;
    }
};

// Forward declaration of simple functions
void array_demo_1();
void array_demo_2();
void array_demo_3();

void stack_demo();

void queue_demo();

void list_demo();

void vector_demo();

void showIntArray(const array<int, 3> &arr);

int main() {
    // #TODO: Uncomment each of the _demo function to investigate!!

    //array_demo_1();
    // #TODO: Q.1 There are inside array_demo_1 - answer them there.

    //array_demo_2();
    // #TODO: Q.2 In array_demo_2, explain what a4(a1) does

    //array_demo_3();
    // #TODO: Q.3 No questions for array_demo_3, it's just a demo of Struct/Class use with array.

    //stack_demo();
    // #TODO: Q.4 How do we (what methods) add and remove items to a stack?
    // #TODO: Q.5 A stack has no no [] or at() method - why?

    //queue_demo();
    // #TODO: Q.6 What is the difference between a stack.pop() and a queue.pop() ?

    //list_demo();
    // #TODO: Q.7 Can we access a list value using an int index? Explain.
    // #TODO: Q.8 Is there a reason to use a list instead of a vector?

    vector_demo();
    // #TODO: Q.9 Was max_size and size the same? (Can they be different?)
    // #TODO: Q.10 Which ParticleClass constructor was called?
    // #TODO: Q.11 Were the ParticleClass instances deleted? If so, how?
    // #TODO: Q.12 Was the vector instance deleted? If so, how do you know this?
    // #TODO: Q.13 Your IDE might suggest to use emplace_back instead of push_back. What does this mean?

    return 0;
}

void showIntArray(const array<int, 3> &arr) {
    // #TODO: Extension: Apparently const prevents a copy - quicker performance.
    //  Is this true? How could you tell or what ref/url supports your view?
    cout << " - array<int, 3> contents: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void array_demo_1() {
    // std::array
    // A templated class for "fixed size" arrays (with known internal buffer)
    // - prevents "decay" usage into a pointer (unlike [] types)
    // - maintains array size for us (fixed)
    // - bounds checking
    // - C++ container operations size, begin, end ...
    //   (except size-changing push/pop etc)
    // - can be passed *by value* to a function (others can't)
    //
    // methods?
    //  - iterators: begin, end, rbegin, fend
    //  - capacity: size, max_size, empty
    //  - access: front, back, [], at()
    //  - modifiers: swap
    //
    // Note
    //  - the at() supports bounds checking, [] does not
    //  - the at(index) is range protected (but slower due to getter)

    cout << " << std:array demos!>>" << endl;
    // simple quick std::array example
    array<int, 3> a1 = {8, 77, -50}; // initializer list
    // #TODO: Q.1.1 What do the < and > mean or indicate?
    // #TODO: Q.1.2 Why don't we need to write std:array here? (Is this good?)
    // #TODO: Q.1.3 Explain what the int and 3 indicate in this case?

    if (false) {
        cout << "a1 address: " << hex << &a1 << endl;
        cout << dec; // put back to decimal mode (after being in hex)
        cout << "a1 size: " << a1.size() << endl;
        // Note: array size is fixed when created, so max_size == size
        cout << "a1 max_size: " << a1.max_size() << endl;
        // access (read/write) of elements? using [index]
        cout << "reading a1[0]: " << a1[0];
        cout << "altering ...";
        a1[0] = 42; // the answer
        cout << " it is now: " << a1[0] << endl;
    }

    // Show contents using for, iterator and foreach
    if (false) {
        // ... using plain-old for loop (int i position)
        cout << "a1 contents using plain-old for loop: ";
        for (int i = 0; i < a1.size(); i++) {
            cout << a1[i] << " ";
        }
        cout << endl;

        // ... using explicit C++ std templated iterator
        cout << "a1 contents using a templated iterator: ";
        array<int, 3>::iterator itr;
        for (itr = a1.begin(); itr < a1.end(); itr++) {
            cout << *itr << " ";
        }
        cout << endl;

        // ... using auto to get iterator (whew - much easier)
        cout << "a1 contents using auto provided template iterator: ";
        for (auto itr2 = a1.begin(); itr2 < a1.end(); itr2++) {
            cout << *itr2 << " ";
        }
        cout << endl;
        // #TODO: Q.1.4 In the code above, what is the type of itr2?

        //
        cout << "a1 contents using auto & for-each iterator: " << endl;
        for (auto &v : a1)
            cout << v << " ";
        cout << endl;
        // #TODO: Q.1.5 In the code above, what is the type of v?
        // #TODO: Q.1.6 In the code above, what does the & mean in (auto &v : a1)

        // pass to a function (by value, using const to ensure it is not copied)
        showIntArray(a1);
    }

    // access of array by [index] is not range protected (BAD)
    cout << "What is at [3]? (out of bounds) " << a1[3] << endl;
    // #TODO: Q.1.7 Try this. Why does a1[3] work but at(3) does not?
    if (false)
        cout << "What is at(3)? (out of range exception) " << a1.at(3) << endl;

    // let's use some other container methods
    cout << "front() == " << a1.front() << endl;
    cout << "back() == " << a1.back() << endl;
    //cout << "empty() == " << a1.emtpy() << endl; // Hmm! empty() work? try it

    // #TODO: Extension. Create examples of swap() and fill()
    // a1.swap(s2) and a1.fill(value) also.

    // iterator for loop
    // #TODO: Q.1.8 auto is awesome. What is the actual type of v that it works out for us?
    cout << "Using for with iterator ... " << endl;
    for (auto v = a1.begin(); v != a1.end(); v++)
        cout << " " << *v;
    cout << endl;

    // iterator for-each loop
    // #TODO: Q.1.9 auto is still awesome. What is the actual type of v here?
    cout << "Using for-each (ranged) iterator ... " << endl;
    for (auto &v : a1)
        cout << " " << v;
    cout << endl;

    // sort?
    sort(a1.rbegin(), a1.rend());
    cout << "Reverse Sort() on a1, now ..." << endl;
    showIntArray(a1);
    // #TODO: Q.1.10 How would you do a forward (not reverse) sort?

    // multidimensional array (note the dimension order)
    array<array<int, 2>, 4> a_2d = {{{1, 2}, {3, 4}, {5, 6}, {7, 8}}};
    cout << "2d array access a_2d[2][0] == " << a_2d[2][0] << endl;
    // Hmm ... Vote - are multi-dimensional arrays pretty to create?

    cout << " done." << endl;
}

void array_demo_2() {
    if (true) {
        // array of 5 ints, must state size
        array<int, 5> a1;
        array<int, 4> a2 = {-4, 2, 7, -100};

        cout << "a1 " << hex << &a1 << " " << a1.size() << endl;
        cout << "a2 " << hex << &a2 << " " << a2.size() << endl;

        // new array via copy
        auto a3 = a2; // this is a copy
        // if auto doesn't work (C++11 extension) either configure your compiler
        // or state the type explicitly. (VS2010+ should support it, etc)
        // - array<int, 4> a3 = a2; // equivalent to auto
        // - array<int, 4> z1 = a1; // compile error - different length

        cout << "a3 " << hex << &a3 << " " << a3.size() << endl;
        auto a4(a1); // this works too
        cout << "a4 " << hex << &a4 << " " << a4.size() << endl;
    }
}

void array_demo_3() {
    if (true) {
        // Array of struct Particles
        array<Particle, 3> a1; // random/not initialised values
        array<Particle, 3> a2{}; // initialised values to 0, can write = {} also

        // old school for loop (clear, simple, quick)
        // note: initial values may be random - struct has no default initialiser
        cout << "a1 array of Particles ..." << endl;
        for (int i = 0; i < a1.size(); i++)
            cout << " - Particle: " << i << " (" << a1[i].x << ", " << a1[i].y << ")" << endl;

        cout << "a2 array of Particles, initialised, using for-each ..." << endl;
        for (auto &p: a2)
            cout << " - Particle: (" << p.x << ", " << p.y << ")" << endl;
    }

    if (true) {
        array<ParticleClass, 3> a1;

        cout << "Show a1 array of ParticleClass instance details ... " << endl;
        for (auto &p: a1)
            cout << " - ParticleClass: (" << p.x << ", " << p.y << ")" << endl;

        cout << "Show a1 array of ParticleClass instance details using show() ... " << endl;
        for (auto &p: a1)
            p.show();
    }
}

void stack_demo() {
    // stack (LIFO, container adaptor)
    // - empty, size, back, push_back, pop_back (standard container)
    // - top, push, pop (no [] or at() ...)
    // - will use a deque if container type not specified
    stack<int> s1;
    // push some values onto the stack, last on top()
    cout << "Stack (LIFO) ... " << endl;
    for (int i = 0; i < 5; ++i) s1.push(i);

    cout << "Removing stack elements with pop() ...";
    while (!s1.empty()) {
        cout << ' ' << s1.top(); // last added (newest)
        s1.pop();
    }
    cout << endl;
}

void queue_demo() {
    // queue (FIFO, container adaptor)
    // - empty, size, back, push_back, pop_back (standard container)
    // - front, back, push, pop (no [] or at() ...)
    // - will use a deque if container type not specified
    queue<int> q1;
    // push some values onto the stack, last on top()
    cout << "Queue (FIFO) ... " << endl;
    for (int i = 0; i < 5; ++i) q1.push(i);

    cout << "Removing queue elements with pop() ...";
    while (!q1.empty()) {
        cout << ' ' << q1.front();
        q1.pop(); // front (first, or oldest), not last
    }
    cout << endl;
}

void list_demo() {
    // std::list
    // A sequence container (internally, a doubly-linked list)
    // - specialised for constant time insert/erase at any position
    // - good at insert, extract, move but uses iterator (not uint index)
    // - house-keeping overhead (link details)
    // - iteration in either direction
    list<int> l1;
    list<int>::iterator it;

    // set some initial values:
    cout << "List (double-linked list) ... " << endl;
    for (int i = 1; i <= 5; ++i) l1.push_back(i); // 1 2 3 4 5

    cout << " - list contains:";
    for (auto &i: l1) cout << " " << i;
    cout << endl;

    // modify
    cout << "Insert using iterator access (end() - 1)" << endl;
    it = l1.end();
    --it;
    l1.insert(it, 77);

    // show inserted element
    cout << " - list contains:";
    for (auto &i: l1) cout << " " << i;
    cout << endl;

    // sort?
    cout << "Sort list (using default compare) ... " << endl;
    l1.sort();
    cout << " - list contains:";
    for (auto &i: l1) cout << " " << i;
    cout << endl;
}

void vector_demo() {
    // std::vector
    // A templated class for "dynamic size" arrays
    // - maintains array size for us, (can use pointer offset still)
    // - bounds checking and resize/memory management (+overhead cost)
    // - C++ container operations (size, begin, end ... )

    // methods?
    //  - iterators: begin, end, rbegin, rend (+const iterators)
    //  - capacity: size, max_size, empty, resize, shrink_to_fit, capacity, reserve
    //  - access: front, back, [], at()
    //  - modifiers: assign, emplace*, insert, erase, emplace_back*,
    //               push_back, pop_back, clear, swap

    if (true) {
        // simple quick vector example
        vector<int> v1 = {8, 77, -50}; // initializer list
        cout << "v1 address: " << hex << &v1 << endl;
        cout << dec; // put back to decimal mode (after being in hex)
        cout << "v1 size: " << v1.size() << endl;
        // vector size is not fixed, so max_size <> size (typically)
        cout << "v1 max_size: " << v1.max_size() << endl;

    }

    if (true) {
        vector<ParticleClass> v1;

        v1.push_back(ParticleClass(1, 2));
        v1.push_back(ParticleClass(3, 4));
        v1.push_back(ParticleClass(5, 6));

        cout << "Show v1 vector of ParticleClass instance details using show() ... " << endl;
        for (auto &p: v1)
            p.show();
    }

}



