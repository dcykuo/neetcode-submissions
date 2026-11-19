class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;

        for (string& token : tokens) {
            if (token == "+" ||
                token == "-" || 
                token == "*" ||
                token == "/" ) {

                    int num2 = st.top();
                    st.pop();
                    int num1 = st.top();
                    st.pop();
                    
                    int result = 0;
                    if (token == "+") {
                        result = num1 + num2;
                    }else if (token == "-") {
                        result = num1 - num2;
                    }else if (token == "*") {
                        result = num1 * num2;
                    }else {
                        result = num1 / num2;
                    }
                    st.push(result);
                }
            else {
                int num = stoi(token);
                st.push(num);
            }
        }
        
        return st.top();
    }
};
