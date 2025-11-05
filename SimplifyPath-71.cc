class Solution
{
public:
    string simplifyPath(string path)
    {
        // Stack is to track list of directories
        stack<string> st;

        //=====general case: /home/ed//Dowloads/./Paper/../
        for (int i = 0; i < path.size(); i++)
        {
            // Ignore if we encouter /
            if (path[i] == '/')
                continue;

            string temp;

            // Check what is current directory
            while (i < path.size() && path[i] != '/')
            {
                temp += path[i];
                i++;
            }

            if (temp == ".")
                // Ignore if it is current dir: .
                continue;
            else if (temp == "..")
            {
                // Pop the parent dir if it is back 1 level: ..
                if (!st.empty())
                    st.pop();
            }
            else
            {
                // None of above; add current dir into stack
                st.push(temp);
            }
        }

        string res;
        while (!st.empty())
        {
            res = "/" + st.top() + res; // add path before res
            st.pop();
        }

        //=====base case: /
        if (res.size() == 0)
            return "/";
        return res;
    }
};