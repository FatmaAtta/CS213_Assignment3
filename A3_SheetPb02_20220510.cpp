// File name: A2_SheetPb02_20220510.cpp
// Purpose: compare the similarity between a document and a query sentence
// Author(s): Fatma Mahmoud Atta
// ID(s): 20220510
// Section: S9
// Date: December 3 2023
// Version: 1
#include <bits/stdc++.h>
#include <fstream>
using namespace std;

void lower_case(string &s){
    for(char &c:s){
        c= tolower(c);
    }
}

void token(string &word){
    if(ispunct(word.back())){
        word=word.substr(0,word.size()-1);
    }
    lower_case(word);
}
class StringSet{
    vector<string>words;
public:
    StringSet(string file_name);
    StringSet(string s,char c); //second parameter is to differentiate between the two constructors
    double similarity(StringSet s);
    void pop(string s);
    void clear();
    void print();
    int size();
    void push(string s);
    vector<string> get_words(){
        return words;
    }
    StringSet operator*(StringSet str2){
        vector<string>s2=str2.get_words();
        StringSet common("",'q');
        for(string s : s2){
            auto it=find(words.begin(),words.end(),s);
            if(it==words.end()){
                common.words.push_back(s);
            }
        }
        return common;
    }
    StringSet operator+(StringSet str){
        vector<string>s2=str.get_words();
        StringSet merge("",'q');
            for(string s:words){
                if(find(merge.words.begin(),merge.words.end(),s)==merge.words.end()){
                    merge.words.push_back(s);
                }
            }
            for(string s:s2){
                if(find(merge.words.begin(),merge.words.end(),s)==merge.words.end()){
                    merge.words.push_back(s);
                }
            }
        return merge;
    }
};

int main() {
    StringSet document("text");
    StringSet query("this is the query set of words to test",'q');
    StringSet common("",'q');
    StringSet merge("",'q');
    cout<<"Document words:\n";
    document.print();
    cout<<"\n\n";
    cout<<"Query words:\n";
    query.print();
    cout<<"The document size= "<<document.size()<<"\n";
    cout<<"\n\n";
    document.push("trying the push method");
    common=document*query;
    cout<<"\n";
    cout<<"Common words:\n";
    common.print();
    cout<<"\n\n";
    document.pop("text");
    merge=document+query;
    cout<<"Combined words:\n";
    merge.print();
    cout<<"\n\n";
    cout<<"Similarity= "<<document.similarity(query)<<"\n";
    document.clear();
    query.clear();
    cout<<"Testing the clear method\n";
    cout<<"Document words:\n";
    document.print();
    cout<<"Query words:\n";
    query.print();
}

StringSet::StringSet(string file_name) {
    file_name+=".txt";
    fstream file(file_name,ios::in);
    if(file.is_open()){
        string line;
        while(getline(file,line)){
            istringstream word_stream(line);
            string word;
            while(word_stream >> word){
                token(word);
                words.push_back(word);
            }
        }
        file.close();
    }
    else{
        cerr<<"File cannot be opened\n";
    }
}

StringSet::StringSet(string s, char c) {
    istringstream word_stream(s);
    string word;
    while(word_stream >> word){
        token(word);
        words.push_back(word);
    }
}
void StringSet::print() {
    for(string s:words){
        cout<<s<<"\n";
    }
}
void StringSet::push(string s) {
    istringstream word_stream(s);
    string word;
    while(word_stream >> word){
        token(word);
        words.push_back(word);
    }
}
void StringSet::pop(string s){
    token(s);
    auto it=remove(words.begin(), words.end(), s);
    words.erase(it,words.end());
}
void StringSet::clear() {
    words.clear();
}
int StringSet::size() {
    return words.size();
}
double StringSet::similarity(StringSet s) {
    StringSet common("",'q');
    StringSet merge("",'q');
    common=(*this)*s;
    merge=(*this)+s;
    int common_size=common.size();
    int doc_size=this->size();
    int q_size=s.size();
    double calc=(common_size)/(sqrt(doc_size*q_size));
    return calc;
}
