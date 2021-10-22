#include <iostream>

struct A {
    A(int value) : value(value) {}
    int value;
};

A operator+(const A &first, const A &second) {
    return A(first.value + second.value);
}

struct B {
    B(int value) : value(value) {}
    int value;
    B operator+(const B &other) const {
    return B(value + other.value);
    }
};

struct C {
    C(int value) : value(value) {}
    int value;

    C operator+(const C &other) const {
        return C(value + other.value);
    }
};

/* // Uncomment me
C operator+(const C &first, const C &second) {
    return C(first.value + second.value);
}*/

struct Point {
    /* explicit */ Point(double x = 0, double y = 0) : x(x), y(y) {}
    Point operator+(const Point &other);
    double x;
    double y;
};

Point Point::operator+(const Point &other) {
    return Point(x + other.x, y + other.y);
}

/* // Uncomment me
Point operator+(const Point &first, const Point &other) {
    return Point(first.x + other.x, first.y + other.y);
} */

class Printable {
public:
    Printable(int value) : value(value) {}
private:
    int value;
    friend std::ostream &operator<<(std::ostream &stream, const Printable &obj);
};

std::ostream &operator<<(std::ostream &stream, const Printable &obj) {
    stream << obj.value; // для этого и нужен friend.
    return stream;
}

struct Summable {
    Summable(int value) : value(value) {}

    Summable operator+(const Summable &other) const;
    Summable &operator+=(const Summable &other);

    int value;
};

Summable Summable::operator+(const Summable &other) const {
    return Summable(value + other.value);
}

Summable &Summable::operator+=(const Summable &other) {
    value += other.value;
    return *this;
}

struct Reversable {
    Reversable(int value) : value(value) {}
    Reversable operator-() const;

    int value;
};

Reversable Reversable::operator-() const {
    return Reversable(-value);
}

/* // Uncomment me
Reversable operator-(const Reversable &obj) {
    return Reversable(-obj.value);
}
} */

struct Incrementable {
    Incrementable(int value) : value(value) {}

    Incrementable &operator+=(const Incrementable &other) {
        value += other.value;
        return *this;
    }

    Incrementable operator++(int) {
        std::cout << "Incrementable++\n";
        Incrementable tmp = *this;
        *this += 1;
        return tmp;
    }

    Incrementable &operator++() {
        std::cout << "++Incrementable\n";
        *this += 1;
        return *this;
    }

    int value;
};

struct Comparable {
    Comparable(int first, int second) : first(first), second(second) {}

    int first;
    int second;
};

bool operator<(const Comparable &left, const Comparable &right) {
    return left.first < right.first ||
        (left.first == right.first && left.second < right.second);
}

int main() {
    {
        A a = 10;
        A b = 20;
        A c = a + b; // работает!
    }

    {
        B a = 10;
        B b = 20;
        B c = a + b;
    }

    {
        C a = 10;
        C b = 20;
        C c = a + b;
    }

    {
        double offset = 20;
        Point base_point = Point(10, 20);
        Point offset_point = base_point + offset; // РАБОТАЕТ, но не так, как ожидается
        // Point new_offset_point = offset + base_point; // НЕ КОМПИЛИРУЕТСЯ
    }

    {
        Printable obj(10);
        std::cout << obj << std::endl;
    }

    {
        Summable first(10);
        Summable second(20);
        Summable result = first + second;

        std::cout << result.value << "\n";
        result += first;

        std::cout << result.value << "\n";
    }

    {
        Reversable obj(10);
        Reversable reversed = -obj;

        std::cout << reversed.value << "\n";
    }

    {
        Incrementable obj(10);
        Incrementable first = obj++;
        Incrementable second = ++obj;

        std::cout << "first = " << first.value << " second = " << second.value << ". Object = " << obj.value << "\n";
    }

    {
        Comparable first(10, 20);
        Comparable second(10, 30);
        std::cout << (first < second) << std::endl;
        // std::cout << (first > second) << std::endl;
    }
}
