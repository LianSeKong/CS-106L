class Course {

private: 
    int score;
    void double_score();
public:
    Course(int score);
    int get_score () const;
    void set_score(int score);
};