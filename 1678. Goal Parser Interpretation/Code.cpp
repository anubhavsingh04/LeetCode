class Solution {
public:
    string interpret(string command) {
        string s="",str;
        for(int i=0;i<command.size();i++){
            s+=command[i];
            if(s=="G"){
                str+="G";
                s="";
            }else if(s=="()"){
                str+="o";
                s="";
            }else if(s=="(al)"){
                str+="al";
                s="";
            }
        }
        return str;
    }
};