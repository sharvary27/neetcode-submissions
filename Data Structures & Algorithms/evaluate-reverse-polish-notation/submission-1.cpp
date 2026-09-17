class Solution {
public:
    int calculate(string op, int a, int b){
        if(op == "+"){
            return a + b;
        }else if(op == "-"){
            return a - b;
        }else if(op == "*"){
            return a * b;
        }else{
            return a/b;
        }
    }
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        stack<string> st;

        int i = 0;
        while(i < n){

            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "*" && tokens[i] != "/"){
                st.push(tokens[i]);
                i++;
            }else{

            int b = stoi(st.top());
            st.pop();
            int a = stoi(st.top());
            st.pop();

            string ans = to_string(calculate(tokens[i],a, b));

            st.push(ans);
            i++;
            }
        }
        
        return stoi(st.top());

    }
};
