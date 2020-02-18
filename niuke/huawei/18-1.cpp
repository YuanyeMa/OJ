#include <cstdio>
#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<sstream>
 
int stringtoint(string str){
    stringstream ss;
    ss<<str;
    int x;
    ss>>x;
    return x;
}
 
vector<int> toint(string str){
    vector<int> res;
    string temp;
    int ele;
    for(int i=0;i<str.length();i++){
        if(str[i]!='.'){
            temp.push_back(str[i]);
        }
        else{
            ele=stringtoint(temp);
temp.clear();
            res.push_back(ele);
        }
    }
    ele=stringtoint(temp);
    res.push_back(ele);
    return res;
}
 
bool maskisvalid(vector<int> res){
    if(res.size()!=4)
        return false;
    if(res[0]==255){
        if(res[1]==255){
            if(res[2]==255){
                if(res[3]==254||res[3]==252||res[3]==248||res[3]==240||res[3]==224||res[3]==192||res[3]==128||res[3]==0){
                    return true;
                }
                else{
                    return false;
                }
            }
            else{
                if(res[2]==254||res[2]==252||res[2]==248||res[2]==240||res[2]==224||res[2]==192||res[2]==128||res[2]==0){
                    if(res[3]==0){
                        return true;
                    }
                    else{
                        return false;
                    }
                }
            }
        }
        else{
            if(res[1]==254||res[1]==252||res[1]==248||res[1]==240||res[1]==224||res[1]==192||res[1]==128||res[1]==0){
                if(res[3]==0&&res[2]==0){
                    return true;
              }
                else{
                     return false;
                    }
             }
        }           
    }
    else{
            if(res[0]==254||res[0]==252||res[0]==248||res[0]==240||res[0]==224||res[0]==192||res[0]==128){
                if(res[3]==0&&res[2]==0&&res[1]==0){
                    return true;
              }
}
                else{
                     return false;
            }      
    }
    return false;
}
 
int main(){
	freopen("ip.in", "r", stdin);
	//freopen("ip-1.out", "w", stdout);
    string str;
int* res=new int[7];
    for(int j=0;j<7;j++)
        res[j]=0;
    while(cin>>str){
         string ipstring;
         string maskstring;
        vector<int> ip,mask;
        int i=0;
        for(;str[i]!='~';i++){
            ipstring.push_back(str[i]);
        }
        i++;
        for(;i<str.length();i++){
            maskstring.push_back(str[i]);
        }
        ip=toint(ipstring);
        mask=toint(maskstring);
            if(maskisvalid(mask)){
            if(ip[1]>=0&&ip[1]<=255&&ip[2]>=0&&ip[2]<=255&&ip[3]>=0&&ip[3]<=255){
                if(ip[0]>=1&&ip[0]<=126){
                    res[0]++;
                    if(ip[0]==10)
                        res[6]++;
                }
                else if(ip[0]>=128&&ip[0]<=191){
                    res[1]++;
                    if(ip[0] == 172 && ip[1] >= 16 && ip[1] <= 32)
                        res[6]++;
                }
                else if(ip[0]>=192&&ip[0]<=223){
                    res[2]++;
                    if(ip[0] == 192 && ip[1] == 168)
                        res[6]++;
                }
                else if(ip[0]>=224&&ip[0]<=239){
                    res[3]++;
                }
                else if(ip[0]>=240&&ip[0]<=255){
                    res[4]++;
                }  
            } 
        }
            else{
		cout<<res[5]<<" "<<ipstring<<" "<<maskstring<<endl;
                res[5]++;
            }
    }
        cout<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<" "<<res[4]<<" "<<res[5]<<" "<<res[6]<<endl;
        return 0;
}
