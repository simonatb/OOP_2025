#include "Question.h"

Question::Question(const char* text, const char* answer) : Text(text)
{
    strcpy(this->answer, answer);
}

void Question::print(std::ostream& os) const
{
    os << "question: " << this->getText() << "\n" << "answer: " << answer << "\n";
}

Text* Question::clone() const
{
    return new Question(*this);
}
