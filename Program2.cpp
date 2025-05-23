//
// Created by Aung Naing Thu on 5/16/2025.
//

#include <iostream>

using namespace std;

class Question
{
    public:
        int a;
        int b;

    Question(int a, int b)
    {
        this->a = a;
        this->b = b;
    }

    int sum();

};

int Question::sum()
{
    return a + b;
}

int main()
{
    Question q(1, 2);
    int result = q.sum();

    cout << "The sum is: " << result << endl;


    return 0;
}
