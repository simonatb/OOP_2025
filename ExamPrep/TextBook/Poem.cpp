#include "Poem.h"

void Poem::copyFrom(const Poem& other)
{
    keys = new char* [other.count];
    this->count = count;
    for (size_t i = 0; i < count; i++) {
        keys[i] = new char[strlen(other.keys[i]) + 1];
        strcpy(keys[i], other.keys[i]);
    }
}

void Poem::free()
{
    for (size_t i = 0;i < count; i++) {
        delete[] keys[i];
    }
    delete[] keys;
    count = 0;
}

Poem::Poem(size_t count, const char* text) : count(count), Text(text)
{
    keys = new char* [count] {nullptr};
}

Poem::Poem(const Poem& other) : Text(other){
    copyFrom(other);
}

Poem& Poem::operator=(const Poem& other)
{
    if (this != &other) {
        Text::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Poem::~Poem()
{
    free();
}

void Poem::print(std::ostream& os) const {
    os << this->getText() << '\n';
    os << "{ ";

    for (size_t i = 0; i < count; i++)
    {
        os << keys[i];
        if (i != count - 1)
        {
            os << ", ";
        }
    }

    os << " }" << "\n";
}