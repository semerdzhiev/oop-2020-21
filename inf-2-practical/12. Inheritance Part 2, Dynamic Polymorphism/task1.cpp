#include <string>
#include <stdexcept>
#include <vector>
#include <iostream>

class Question
{
public:
    virtual void ask() = 0;
    virtual int grade() = 0;
};

enum class YesNoAnswer
{
    NO,
    YES
};

class YesNoQuestion : public Question
{
public:
    YesNoQuestion(const std::string &question_text, YesNoAnswer correct_answer, int points) : question_text{question_text}, correct_answer{correct_answer}, points{points} {}
    void ask() final
    {
        std::cout << question_text << std::endl;
        std::string answer;
        std::cin >> answer;
        if (answer == "yes")
        {
            user_answer = YesNoAnswer::YES;
        }
        else if (answer == "no")
        {
            user_answer = YesNoAnswer::NO;
        }
        else
            throw std::invalid_argument("unknown answer");
    }
    int grade() final
    {
        return correct_answer == user_answer ? points : 0;
    }

private:
    std::string question_text{};
    int points{};
    YesNoAnswer correct_answer{};
    YesNoAnswer user_answer{};
};

class MultipleChoice : public Question
{
public:
    MultipleChoice(const std::string &question_text, const std::vector<std::string> &answers, const std::vector<std::string> &correct_answers, int points_by_correct_answer) : question_text{question_text},
                                                                                                                                                                               answers{answers},
                                                                                                                                                                               correct_answers{correct_answers},
                                                                                                                                                                               points_by_correct_answer{points_by_correct_answer}
    {
    }
    void ask() final
    {
        std::cout << question_text << std::endl;
        for (int i = 0; i < answers.size(); i++)
        {
            std::cout << answers[i] << std::endl;
        }
        std::string answer;
        while (answer != "done")
        {
            user_answers.push_back(answer);
        }
    }

    int grade() final
    {
        int points{0};
        for (int i = 0; i < user_answers.size(); i++)
        {
            for (int j = 0; j < correct_answers.size(); i++)
            {
                if (user_answers[i] == correct_answers[i])
                {
                    points += points_by_correct_answer;
                    break;
                }
            }
        }
        return points;
    }

private:
    std::string question_text{};
    std::vector<std::string> answers{};
    std::vector<std::string> correct_answers{};
    std::vector<std::string> user_answers{};
    int points_by_correct_answer;
};

class OpenQuestion : public Question
{
public:
    OpenQuestion(const std::string &question_text, int points) : question_text{question_text}, points{points} {}
    void ask() final
    {
        std::cout<<question_text<<std::endl;
        std::cin>>user_answer;
    }
    int grade() final
    {
        std::cout<<question_text<<std::endl<<user_answer<<std::endl;
        int percentage;
        std::cin>>percentage;
        return (percentage)/(100.0)*points;
    }
private:
    std::string question_text;
    std::string user_answer;
    int points;
};

class Test
{
public:
    void add_question(Question* question)
    {
        questions.push_back(question);
    }
    void do_test()
    {
        for(int i=0; i<questions.size(); i++)
        {
            questions[i]->ask();
        }
    }
    int grade_test()
    {
        int points{0};
        for(int i=0; i<questions.size(); i++)
        {
            points += questions[i]->grade();
        }
        return points;
    }
private:
    std::vector<Question*> questions;
};

int main()
{
    Question* yes_no_question = new YesNoQuestion("yes no question", YesNoAnswer::YES, 5);

    std::vector<std::string> answers;
    answers.push_back("answer1");
    answers.push_back("answer2");
    answers.push_back("answer3");
    std::vector<std::string> corect_answers;
    corect_answers.push_back("answer1");
    corect_answers.push_back("answer3");
    Question* multiple_choice = new MultipleChoice("multiple choice question", answers, corect_answers, 1);

    Question* open_question = new OpenQuestion("open question", 10);

    Test test{};
    test.add_question(yes_no_question);
    test.add_question(multiple_choice);
    test.add_question(open_question);

    test.do_test();
    std::cout<<test.grade_test()<<std::endl;
    return 0;
}