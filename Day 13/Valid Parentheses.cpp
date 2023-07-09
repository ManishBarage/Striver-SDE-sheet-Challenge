bool isValidParenthesis(string expression)
{
    stack<char> s;
    
    for(int i=0;i<expression.size();i++)
    {
        char ch = expression[i];
        
        //if charcter is opening bracket , push in stack
        //if character is closing braket , then check top and pop
        
        if( ch == '(' || ch =='{' || ch == '[')
        {
            //Opening bracket
            s.push(ch);
        }
        else
        {
           //Closing bracket
                if(!s.empty())
                {
                        char top = s.top();
                    
                        if(
                            (ch == ')' && top == '(' ) ||
                            ( ch == '}' && top == '{') ||
                            (ch == ']' && top == '[')
                            
                          )
                        {
                            s.pop(); 
                        }
                        else
                        {
                            return false;
                        }
                }
                else
                {
                    //stack is empty
                    return false;
                }
        }
    }
    
    if(s.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}