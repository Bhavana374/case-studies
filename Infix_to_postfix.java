import java.io.*;
import java.util.*;

public class Solution {

    public static int Precedence(char c){
        if(c=='+'||c=='-')
            return 1;
        else if(c=='*'||c=='/')
            return 2;
        else if(c=='^')
            return 3;
        else
            return -1;  
    }
    public static String infixtopostfix(String s){
        Stack < Character > stack=new Stack < >();
        String result="";
        for(int i=0;i<s.length();i++){
            char ch=s.charAt(i);
            if(Character.isAlphabetic(ch)){
                result+=ch;
            }
            else if(ch=='('){
            stack.push(ch);
            }
            else if(ch==')'){
                while(!stack.isEmpty()&&stack.peek()!='('){
                    result+=stack.peek();
                    stack.pop();
                }
                stack.pop();
            }
            else{
                while(!stack.isEmpty()&&Precedence(ch)<=Precedence(stack.peek())){
                    result+=stack.peek();
                    stack.pop();
                }
                stack.push(ch);
            }
        }
        while(!stack.isEmpty()){
            result+=stack.pop();
        }
        return result;
    }
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        String s=sc.next();
        System.out.print(infixtopostfix(s));
    }
}
