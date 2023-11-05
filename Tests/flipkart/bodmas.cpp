#include <iostream>
#include <vector>
#include <string>
#include <set>

class Solution {
private:
    std::string apply(std::string Operator, std::string op1, std::string op2) {
        int a = std::stoi(op1);
        int b = std::stoi(op2);
        return Operator == "A" ? std::to_string(a + b)
            : (Operator == "S" ? std::to_string(a - b) : std::to_string(a * b));
    }

    std::vector<std::string> applyAll(std::vector<std::string>& tokens, std::string Operator) {
        std::vector<std::string> res;
        for (size_t i = 0; i < tokens.size(); ++i) {
            if (Operator == tokens[i]) {
                res.back() = apply(Operator, res.back(), tokens[++i]);
            } else {
                res.push_back(tokens[i]);
            }
        }
        return res;
    }

    int evaluate(std::vector<std::string>& tokens, std::string order) {
        for (char c : order) {
            tokens = applyAll(tokens, std::string(1, c));
        }
        return std::stoi(tokens[0]);
    }

    std::vector<std::string> tokenize(std::string s) {
        std::vector<std::string> res;
        std::string sb;
        for (char c : s) {
            if (c == '+' || c == '-' || c == '*') {
                res.push_back(sb);
                sb.clear();
                res.push_back(c == '+' ? "A" : (c == '-' ? "S" : "M"));
            } else {
                sb.push_back(c);
            }
        }
        res.push_back(sb);
        return res;
    }

public:
    int gradeMarks(std::string expression, std::vector<int>& studentAnswers) {
        std::vector<std::string> tokens = tokenize(expression);
        int correctAnswer = evaluate(tokens, "MAS");
        std::vector<std::string> incorrectOrders = { "MSA", "AMS", "ASM", "SAM", "SMA" };
        std::set<int> closeAnswers;

        for (const std::string& order : incorrectOrders) {
            int answer = evaluate(tokens, order);
            if (answer != correctAnswer) {
                closeAnswers.insert(answer);
            }
        }

        int sum = 0;
        for (int studentAnswer : studentAnswers) {
            sum += (studentAnswer == correctAnswer ? 5 : (closeAnswers.count(studentAnswer) ? 2 : 0));
        }
        return sum;
    }
};

int main() {
    Solution solution;
    std::string expression = "3A4S2M5";
    std::vector<int> studentAnswers = { 15, 14, 13 };
    int result = solution.gradeMarks(expression, studentAnswers);
    std::cout << "Total Score: " << result << std::endl;
    return 0;
}