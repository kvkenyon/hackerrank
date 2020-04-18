#include <cmath>
#include <cstdio>
#include <iterator>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;

    unordered_map<string, unordered_map<string, string>> attributes;
    unordered_map<string, unordered_set<string>> children;
    vector<string> stack;

    const string delims{" <>=\"/"};
    string line;

    string::size_type begIdx, endIdx;

    string tagName;
    for (int i = 0; i < n + 1; ++i) {
        getline(cin, line);

        if (line == "") continue;

        // find the start of tag
        begIdx = line.find_first_not_of(delims);
        // find the end of tag
        endIdx = line.find_first_of(delims, begIdx);

        tagName = line.substr(begIdx, endIdx - 1);

        if (attributes.find(tagName) == attributes.end()) {
            attributes[tagName] = {};
        }

        string::size_type isEndTag = tagName.find(">");

        if (isEndTag == string::npos) {
            // start tag

            if (stack.size() != 0) {
                string parent = stack.back();
                if (children.find(parent) == children.end()) {
                    children[parent] = {};
                }
                children[parent].insert(tagName);
            }

            stack.push_back(tagName);

            // continue parsing line for attr:value pairs
            begIdx = line.find_first_not_of(delims, endIdx + 1);
            endIdx = line.find_first_of(delims, begIdx);

            while (begIdx != string::npos) {
                string key = line.substr(begIdx, endIdx - begIdx);

                begIdx = line.find_first_not_of(delims, endIdx + 1);
                endIdx = line.find_first_of(delims, begIdx);

                string value = line.substr(begIdx, endIdx - begIdx);

                begIdx = line.find_first_not_of(delims, endIdx + 1);
                endIdx = line.find_first_of(delims, begIdx);
                attributes[tagName].emplace(key, value);
            } 

        } else {
            // end tag
            stack.pop_back();
        }

    }

    for (int i = 0; i < q; ++i) {
       getline(cin, line); 

        const string queryDelims = "~.";

        string::size_type pos = 0;
        string token;
        string attrName;
        vector<string> tagChain;
        while((pos = line.find(".")) != string::npos) {
            token = line.substr(0, pos);
            tagChain.push_back(token);
            line.erase(0, pos + 1);
        }

        bool isValid = true;

        string::size_type tilde = line.find("~");
        token = line.substr(0, tilde);

        if (tagChain.empty()) {
            // Make sure it's a root tag
            // i.e. has no children
            for (auto& elem : children) {
                if (elem.second.find(token) != elem.second.end()) {
                    cout << "Not Found!" << endl;
                    isValid = false;
                }
            }
            if (!isValid) continue;
        }

        tagChain.push_back(token);

        attrName = line.substr(tilde + 1);

        string parent = "";

        for (string tagName : tagChain) {
           if (parent == "") {
               parent = tagName;
               if (attributes.find(parent) == attributes.end()) {
                    cout << "Not Found!" << endl;
                    isValid = false;
                    break;
               }
           } else {
               if (children[parent].find(tagName) == children[parent].end()) {
                    cout << "Not Found!" << endl;
                    isValid = false;
                    break;
               }

               parent = tagName;
           }
        }

        if (isValid) {
            if (attributes[parent].find(attrName) != attributes[parent].end()) {
                cout << attributes[parent][attrName] << endl;;
            } else {
                cout << "Not Found!" << endl;
            }
        }
    }

    return 0;
}

