#include<iostream>
#include<vector>
#include<unordered_map>
#include<algorithm>
#include<sstream>

struct Node{
    std::string name;
    std::vector<Node*> children;
    bool root;
    std::unordered_map<std::string,std::string> attributes;
};

Node* createNode(std::string name,std::unordered_map<std::string,std::string> attributes){
    Node* newNode = new Node();
    newNode->name = name;
    newNode->attributes = attributes;

    return newNode;
}

void trimStr (std::string &str){
    str.erase(std::remove(str.begin(),str.end(),'<'),str.end());
    str.erase(std::remove(str.begin(),str.end(),'>'),str.end());
}

std::vector<Node*> tagStack;
std::vector<Node*> nodes;

void addChildren(){
    if(tagStack.size() > 1){
        Node* parent = tagStack[tagStack.size() - 2];
        Node* children = tagStack[tagStack.size() - 1];

        parent->children.push_back(children);

    } else {
        tagStack[0]->root = true;
    }

    tagStack.pop_back();
}

void parserHrml(std::string &str){
     trimStr(str);
    if(str[0] == '/'){
        addChildren();
    } else {
       
        size_t pos = str.find(' ');

        std::string tagName = str.substr(0,pos);

        std::unordered_map<std::string,std::string> attributes;

        while(pos < str.size()){
            pos = str.find_first_not_of(' ', pos);
            size_t eqPos = str.find('=',pos);

            std::string key = str.substr(pos,eqPos - pos-1);

            pos = eqPos + 1;

            size_t startQoute = str.find('"',pos);
            size_t endQoute = str.find('"',startQoute+1);

            std::string value = str.substr(startQoute+1,endQoute - startQoute-1);

            pos = endQoute+1;

            attributes[key] = value;
        }

        Node* node = createNode(tagName,attributes);
        tagStack.push_back(node);
        nodes.push_back(node);

    }
}

Node* searchGraph(std::vector<std::string> tags){
    bool isRoot = false;
    Node* current = nullptr;
    for(int i = 0; i < nodes.size(); ++i){
        if(nodes[i]->name == tags[0]){
            isRoot = nodes[i]->root;
            current = nodes[i];
            break;
        }
    }

    if(!isRoot){
        return nullptr;
    }

    if(tags.size() == 1){
        return current;
    }

    Node* result = nullptr;
    for(int i = 1; i < tags.size(); ++i){
        if(current->children.empty()){
            result = nullptr;
            break;
        }
        for(int j = 0; j < current->children.size(); ++j){
            if(current->children[j]->name == tags[i]){
                current = current->children[j];
                result = current;
                break;
            }
        }
    }

    return result;
}

int main(){
    std::string input;
    int n,q;

    std::cin >> n >> q;
    std::cin.ignore();

    for(int i = 0; i < n;  ++i){
        std::getline(std::cin,input);
        parserHrml(input);
    }


    for(int i = 0; i < q; i++){
        std::string query;
        std::cin >> query;

        std::vector<std::string> tags;

        size_t posTillde = query.find('~');

        std::string keyQuery = query.substr(posTillde+1);

        std::string queryTags = query.substr(0,posTillde);

        size_t dotPos = queryTags.find('.');
        if(dotPos == std::string::npos){
            tags.push_back(queryTags);
        }
        size_t pos = 0;

        while(dotPos != std::string::npos){
            dotPos = queryTags.find('.',pos);
            if(pos < queryTags.size() ){
                std::string tag = queryTags.substr(pos,dotPos - pos);
                pos = dotPos + 1;
                tags.push_back(tag);

            } else{
                break;
            }
        }

        Node* result = searchGraph(tags);
        if(result != nullptr){
            bool isValid = false;
            for(const auto &attr : result->attributes){
                if(attr.first == keyQuery){
                    isValid = true;
                }
            }
            if(isValid){
                std::cout << result->attributes[keyQuery] << std::endl;
            } else {
                std::cout << "Not Found!" << std::endl;

            }
        } else {
            std::cout << "Not Found!" << std::endl;
        }
    }




    return 0;

}