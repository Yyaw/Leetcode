#include <iostream>
#include <string>
#include "data.h"
#include "util/readData.h"

using namespace std;

class Solution {
public:
	vector<string> fullJustify(vector<string> &words, int maxWidth) {
		vector<string> result;
        int begin=0, end=0;
        while (1) {
            string str;
            int strWidth = 0;
            begin = end;
            for (end=begin; end<words.size() && strWidth + end - begin + words[end].size() <= maxWidth; end++) {
                strWidth += words[end].size();
            }
            if (begin == end)
                return vector<string>();
            if (end == words.size()) {
                str = "";
                for (int i = begin; i < end; i++) {
                    str.append(words[i]);
                    str.append(" ");
                }
                if (str.size() > maxWidth) {
                    str = str.substr(0, maxWidth);
                }else {
                    int length = maxWidth - str.size();
                    for (int i=0; i < length; i++)  {
                        str.push_back(' ');
                    }
                }
                result.push_back(str);
                return result;
            }
            int blankNum = maxWidth - strWidth;
            int blank = end - begin - 1;
            if (blank == 0) {
                str = words[begin];
                for (int i=0; i<blankNum; i++) {
                    str.push_back(' ');
                }
                result.push_back(str);
                continue;
            }
            int averageBlank = blankNum / blank;
            int moreOneBlank = blankNum - averageBlank * blank;
            str = words[begin];
            for (int i=0; i<moreOneBlank; i++) {
                for (int j=0; j<=averageBlank; j++)
                    str.push_back(' ');
                str.append(words[++begin]);
            }
            for (int i=begin+1; i<end; i++) {
                for (int j=0; j<averageBlank; j++)
                    str.push_back(' ');
                str.append(words[i]);
            }
            result.push_back(str);
        }
	}
};

int main(int argc, char **argv)
{
    char *file = argv[1];
    vector<string> data = readStringVector(file)[0];
    Solution s;
    vector<string> result = s.fullJustify(data, 16);
    for (string r : result)
        cout << r << endl;
    return 0;
}
