//Andrew Cantrell OOP Practice 6


#include "json.hpp"
#include "reddit.hpp"

#include <iterator>
#include <iostream>
#include <fstream>
#include <string>

int
main()
{
    std::ifstream inFile;
    inFile.open("json.txt");
    if(!inFile.is_open())
    {
        std::cout << "Error opening file.";
    }
    else
    {
        std::string word; //string for gathering data
        Post post; //post object for gathering author/title data
        std::vector<Post> postVec; //vector of posts
        int postNum = 0; //number for indexing post Vector
        while(inFile >> word)
        {
            //get post author
            if(word == "\"author\":")
            {
                inFile >> word;
                word.erase(0,1);
                word.erase(word.length()-2,2);
                post.author = word;
                
                postVec.push_back(post);
                postNum++;
            }
            //get post title
            if(word == "\"title\":")
            {
                inFile >> word;
                while(word.back() != '"')
                {
                    word += inFile.get();
                }
                post.title = word;
            }
        }
        
        //print post vector
        for(int i = 0; i < postVec.size(); i++)
        {
            std::cout << postVec[i].author << " posted " << postVec[i].title;
            std::cout << "\n";
        }

        //json::Value* val = json::parse(s);
        //std::cout << size(val) << ' ' << height(val) << '\n';
        //std::cout << *val << '\n';

    }
}

