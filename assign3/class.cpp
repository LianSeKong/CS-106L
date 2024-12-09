#include "class.h"


Course::Course(int score) {
    this->score = score;
}

void Course::double_score() {
    this->score *= 2;
}

int Course::get_score () const {
    return this->score;
}

void Course::set_score(int score) {
    this->score = score;
}


