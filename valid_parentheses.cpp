class Solution {
public:
    bool isValid(string s) {
       vector <char> heap_s;
       int size = s.size();
       
       if (size == 0) {
           return true;
       } else if (size%2 == 1) {
           return false;
       }
       
       for (int index = 0; index < size; index++) {
           switch (s[index]) {
               case '(':
               case '[':
               case '{':
                   heap_s.push_back(s[index]);
                   break;
               case ')':
                   if ((heap_s.empty()) || heap_s.back() != '(') { 
                       return false;
                   } else {
                       heap_s.pop_back();
                       break;
                   }
               case ']':
                   if ((heap_s.empty()) || heap_s.back() != '[') { 
                       return false;
                   } else {
                       heap_s.pop_back();
                       break;
                   }    
                case '}':
                   if ((heap_s.empty()) || heap_s.back() != '{') { 
                       return false;
                   } else {
                       heap_s.pop_back();
                       break;
                   }   
               default:
                   return false;
           }
       }
        return heap_s.empty();
       
    }
};
