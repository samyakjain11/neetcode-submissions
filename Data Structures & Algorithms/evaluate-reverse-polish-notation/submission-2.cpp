class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        std::stack<int> numbers;
        
        auto isOperator = [](std::string curChar) -> bool {
            return curChar == "+" ||
                    curChar == "-" ||
                    curChar == "*" ||
                    curChar == "/";

        };

        auto compute = [](int left, int right, std::string curChar) -> int {
            if (curChar == "+") return left + right;
            if (curChar == "-") return left - right;
            if (curChar == "/") return left / right;
            if (curChar == "*") return left * right;

            else return 0;
        };

        for (const auto curToken : tokens) {
            if (!isOperator(curToken)) {
                numbers.push(std::stoi(curToken));
            } else {
                int right = numbers.top();
                numbers.pop();
                int left = numbers.top();
                numbers.pop();
                numbers.push(compute(left, right, curToken));
            }
        }

        return numbers.top();

    }
};
